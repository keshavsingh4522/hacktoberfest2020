'use strict';

let secretNumber = Math.floor(Math.random() * 100) + 1;
// revealGuess(secretNumber); //for testing purposes
let score = 20;
let highscore = 0;

const checkText = document.querySelector('.check').textContent;

function generateRandomNumber() {
  let randomNumber = Math.floor(Math.random() * 100) + 1;
  return randomNumber;
}

function displayMessage(message) {
  document.querySelector('.message').textContent = message;
}

function updateHighscore(highscore) {
  document.querySelector('.highscore').textContent = highscore;
}

function revealGuess(secretNumber) {
  document.querySelector('.number').textContent = secretNumber;
}

function changeBgColor(backgroundColor) {
  document.querySelector('body').style.backgroundColor = backgroundColor;
}

function updateScore(score) {
  document.querySelector('.score').textContent = score;
}

function emptyGuessBox() {
  document.querySelector('.guess').value = "";
}

const gameLogic = function () {

  let guess = Number(document.querySelector('.guess').value);

  if (!guess) {
    displayMessage('⛔ No Number');
  }


  else if (guess === secretNumber) {
    if (score > highscore) {
      displayMessage('🎉 Correct');
      highscore = score;
      updateHighscore(highscore);
    }

    revealGuess(secretNumber);
    changeBgColor('#60b347');
    document.querySelector('.number').style.width = '30rem';
  }


  else if (guess !== secretNumber) {
    if (score > 1) {
      score--;
      updateScore(score);
      if (guess - secretNumber <= 5 && guess - secretNumber >= 0 ) displayMessage('🤏 Little bit High');
      else if (secretNumber - guess <= 5 && secretNumber - guess >=0) displayMessage('🤏 Little bit Low');
      else {
        displayMessage(guess > secretNumber ? '📈 Too High' : '📉 Too Low');
      }
      emptyGuessBox();
    }
    else {
      displayMessage('💥 You have lost the Game');
    }
  }
};

document.querySelector('.check').addEventListener('click', gameLogic);


document.querySelector('.again').addEventListener('click', function () {
  secretNumber = Math.floor(Math.random() * 20) + 1;
  displayMessage('Start guessing...');
  score = 20;
  updateScore(score);
  changeBgColor('#222');
  document.querySelector('.number').style.width = '15rem';
  emptyGuessBox()
  document.querySelector('.number').textContent = '?';
  // revealGuess(secretNumber); // for testing purposes

})
