let gameOver = false;

function playGame(playerData) {
  if (gameOver) {
    return;
  }
  document
    .querySelector("." + playerData + "Container")
    .classList.add("selected-suit");
  console.log(`Player memilih: ${playerData}`);
  let comData = comChoice();
  console.log(`Com memilih : ${comData}`);

  checkWin(playerData, comData);
  gameOver = true;
  //   return playerData;
}

function comChoice() {
  let suitChoices = ["rock", "paper", "scissors"];
  let comData = suitChoices[Math.floor(Math.random() * suitChoices.length)];
  document
    .querySelector("." + comData + "ComContainer")
    .classList.add("selected-suit");
  return comData;
}

function checkWin(player, com) {
  document.querySelector(".start-status").remove();

  if (player == "rock" && com == "scissors") {
    document.querySelector(".suit-status").classList.add("win-status");
    console.log("PLAYER 1 WIN");
    showStatus("PLAYER 1 WIN");
  } else if (player == "paper" && com == "rock") {
    document.querySelector(".suit-status").classList.add("win-status");
    console.log("PLAYER 1 WIN");
    showStatus("PLAYER 1 WIN");
  } else if (player == "scissors" && com == "paper") {
    document.querySelector(".suit-status").classList.add("win-status");
    console.log("PLAYER 1 WIN");
    showStatus("PLAYER 1 WIN");
  } else if (player == com) {
    document.querySelector(".suit-status").classList.add("draw-status");
    console.log("DRAW");
    showStatus("DRAW");
  } else {
    document.querySelector(".suit-status").classList.add("win-status");
    console.log("COM WIN");
    showStatus("COM WIN");
  }
}

function showStatus(status) {
  document.querySelector(".suit-status").innerHTML = `<h1> ${status} </h1>`;
}
