const express = require("express");
const expressLayouts = require("express-ejs-layouts");
var fs = require("fs");
const app = express();
app.use(expressLayouts);
app.set("view engine", "ejs");
app.use(express.static("public"));
const port = process.env.PORT || 3000;
// global.baseurl = `http://localhost:${port}`;
global.baseurl = "https://multi-bingo.herokuapp.com";
app.use("/", require("./routes/index"));
const cors = require("cors");
app.use(cors());

let gameCodes = [];
let gameSockets = [];

const genUniqueCode = () => {
  let x = Math.random().toString(36).slice(6);
  x = "a" + x.toLowerCase().substr(0, 6);
  if (gameCodes.includes(x)) {
    return genUniqueCode();
  } else {
    return x;
  }
};

const server = app.listen(port, () => {
  console.log(`Server started on port ${port}`);
});

const socket = require("socket.io");
const io = socket(server, { cors: { origin: "*" } });

const initListenes = (soc) => {
  // Default
  soc.on("disconnect", () => {
    gameSockets.forEach((s, i) => {
      if (s[Object.keys(s)].host == soc) {
        if (s[Object.keys(s)].client != null) {
          s[Object.keys(s)].client.emit("exit", "");
        }
        gameSockets.splice(i, 1);
        gameCodes.splice(i, 1);
      } else if (s[Object.keys(s)].client == soc) {
        s[Object.keys(s)].host.emit("pause", "");
        s[Object.keys(s)].client = null;
      }
    });
  });

  soc.on("reqCode", (pin) => {
    let code = "";
    if (pin.length == 0) {
      code = genUniqueCode();
    } else {
      let flg = true;
      let config = fs.readFileSync("config.bin", "utf8");
      config = config.replace(/(\r\n|\n|\r)/gm, "");
      config = config.split(";");
      for (let i = 0; i < config.length; i++) {
        if (config[i].length > 0) {
          let x = config[i].split("=");
          if (x[0] === pin) {
            if (!gameCodes.includes(x[1])) {
              code = x[1];
              flg = false;
            }
            break;
          }
        }
      }
      if (flg) {
        code = genUniqueCode();
      }
    }
    let socObj = {};
    socObj[code] = {
      host: soc,
      client: null,
      gStarted: false,
    };
    gameSockets.push(socObj);
    gameCodes.push(code);
    soc.emit("gameCode", code);
  });

  soc.on("connectClient", (code) => {
    if (gameCodes.includes(code)) {
      let i = gameCodes.indexOf(code);
      if (i >= 0) {
        if (gameSockets[i][code].client == null) {
          gameSockets[i][code].client = soc;
          soc.emit("clientConnected", "true");
          if (!gameSockets[i][code].gStarted) {
            gameSockets[i][code].host.emit("partnerConnected", "ok");
            gameSockets[i][code].gStarted = true;
          } else {
            gameSockets[i][code].host.emit("partnerReConnected", "ok");
          }
          console.log(gameSockets[i]);
        } else {
          soc.emit("clientConnected", "false");
        }
      } else {
        soc.emit("clientConnected", "false");
      }
    } else {
      soc.emit("clientConnected", "false");
      console.log("Game code not found on server!");
    }
  });

  soc.on("setName", (data) => {
    let i = gameCodes.indexOf(data.code);
    if (i >= 0) {
      if (data.type == "host") {
        if (gameSockets[i][data.code].client != null) {
          gameSockets[i][data.code].client.emit("getName", data.name);
        }
      } else {
        if (gameSockets[i][data.code].host != null) {
          gameSockets[i][data.code].host.emit("getName", data.name);
        }
      }
    }
  });

  soc.on("cutNum", (data) => {
    let i = gameCodes.indexOf(data.code);
    if (i >= 0) {
      if (data.type == "host") {
        if (gameSockets[i][data.code].client != null) {
          gameSockets[i][data.code].client.emit("receivedCut", data.num);
        }
      } else {
        if (gameSockets[i][data.code].host != null) {
          gameSockets[i][data.code].host.emit("receivedCut", data.num);
        }
      }
    }
  });

  soc.on("sendBB", (data) => {
    let i = gameCodes.indexOf(data.code);
    if (i >= 0) {
      if (data.type == "host") {
        if (gameSockets[i][data.code].client != null) {
          gameSockets[i][data.code].client.emit("receivedBB", data.cnt);
        }
      } else {
        if (gameSockets[i][data.code].host != null) {
          gameSockets[i][data.code].host.emit("receivedBB", data.cnt);
        }
      }
    }
  });

  soc.on("askRestart", (data) => {
    let i = gameCodes.indexOf(data.code);
    if (i >= 0) {
      if (gameSockets[i][data.code].client != null) {
        gameSockets[i][data.code].client.emit("askedRestart", "true");
      }
    }
  });

  soc.on("checkWin", (data) => {
    let i = gameCodes.indexOf(data.code);
    if (i >= 0) {
      if (data.type == "host") {
        if (gameSockets[i][data.code].client != null) {
          let obj = {};
          obj.host = data.bbCnt;
          gameSockets[i][data.code].client.emit("askBB", obj);
          console.log("HOST: ", obj);
        }
      } else {
        if (gameSockets[i][data.code].host != null) {
          let obj = {};
          obj.client = data.bbCnt;
          gameSockets[i][data.code].host.emit("askBB", obj);
          console.log("CLIENT: ", obj);
        }
      }
    }
  });

  soc.on("finalizeWin", (data) => {
    let i = gameCodes.indexOf(data.code);
    if (i >= 0) {
      let hCount = data.data.host;
      let cCount = data.data.client;
      console.log("HCount: ", hCount);
      console.log("CCount: ", cCount);
      let client = gameSockets[i][data.code].client;
      let host = gameSockets[i][data.code].host;
      let flg1 = null;
      let flg2 = null;
      if (hCount == cCount) {
        flg1 = 0;
        flg2 = 0;
      } else if (hCount > cCount) {
        flg1 = 1;
        flg2 = -1;
      } else if (hCount < cCount) {
        flg1 = -1;
        flg2 = 1;
      }
      if (client != null && host != null) {
        host.emit("win", flg1);
        client.emit("win", flg2);
      }
    }
  });

  soc.on("sendMessage", (data) => {
    let i = gameCodes.indexOf(data.code);
    if (i >= 0) {
      if (data.type == "host") {
        if (gameSockets[i][data.code].client != null) {
          gameSockets[i][data.code].client.emit("msgReceived", data.msg);
        }
      } else {
        if (gameSockets[i][data.code].host != null) {
          gameSockets[i][data.code].host.emit("msgReceived", data.msg);
        }
      }
    }
  });

  soc.on("sendVibe", (data) => {
    let i = gameCodes.indexOf(data.code);
    if (i >= 0) {
      if (data.type == "host") {
        if (gameSockets[i][data.code].client != null) {
          gameSockets[i][data.code].client.emit("gotVibe", "");
        }
      } else {
        if (gameSockets[i][data.code].host != null) {
          gameSockets[i][data.code].host.emit("gotVibe", "");
        }
      }
    }
  });

  soc.on("sendReact", (data) => {
    let i = gameCodes.indexOf(data.code);
    if (i >= 0) {
      if (data.type == "host") {
        if (gameSockets[i][data.code].client != null) {
          gameSockets[i][data.code].client.emit("gotReact", data.r);
        }
      } else {
        if (gameSockets[i][data.code].host != null) {
          gameSockets[i][data.code].host.emit("gotReact", data.r);
        }
      }
    }
  });
};

io.sockets.on("connection", (soc) => {
  initListenes(soc);
});
