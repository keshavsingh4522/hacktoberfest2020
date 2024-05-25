const { promises: fs } = require("fs");

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const question = (query) =>
  new Promise((resolve) => rl.question(query, resolve));

const run = async () => {
  try {
    const input = await question(
      "Menu \n 1. Write File \n 2. Read File \n\n Menu : "
    );
    if (input == 1) {
      const name = await question("Enter Your Name : ");
      const age = await question("Eter Your Age : ");
      const biodata = { name, age };

      const rawData = await fs.readFile("data/file.json", "utf-8");
      const data = JSON.parse(rawData);
      data.push(biodata);

      await fs.writeFile("data/file.json", JSON.stringify(data));
      console.log("File Written");
    } else if (input == 2) {
      const data = await fs.readFile("data/file.json", "utf-8");
      console.log(JSON.parse(data));
    }
    rl.close();
  } catch (err) {
    console.error("Error : ", err);
  }
};

run();
