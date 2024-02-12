"use strict";

let randomNum = Math.trunc(Math.random() * 20 + 1);

let score = 20;

let highscore = 0;

const displayMessage = function (message) {
  document.querySelector(".message").textContent = message;
};

const checkBtn = function () {
  const guess = Number(document.querySelector(".guess").value);
  console.log(guess);
  if (!guess) {
    displayMessage("⛔ No Number Inputted");
  } else if (randomNum === guess) {
    displayMessage("🎉 Congratulations");
    document.querySelector(".number").textContent = randomNum;
    document.querySelector(".number").style.width = "20rem";
    document.querySelector("body").style.backgroundColor = "#60b347";
    if (score > highscore) {
      highscore = score;
      document.querySelector(".highscore").textContent = highscore;
    }
  } else if (guess !== randomNum) {
    if (score > 1) {
      displayMessage(
        guess > randomNum
          ? "You need to go lower 📉"
          : "You need to go higher 📈"
      );
      score--;
      document.querySelector(".score").textContent = score;
    } else {
      displayMessage("You lose...");
      document.querySelector("body").style.backgroundColor = "#8B0000";
      document.querySelector(".score").textContent = 0;
    }
  }
};
const againBtn = function () {
  score = 20;
  randomNum = Math.trunc(Math.random() * 20 + 1);
  document.querySelector(".number").style.width = "15rem";
  document.querySelector("body").style.backgroundColor = "#222";
  displayMessage("Start guessing...");
  document.querySelector(".score").textContent = score;
  document.querySelector(".number").textContent = "?";
  document.querySelector(".guess").value = "";
};
document.querySelector(".check").addEventListener("click", checkBtn);
document.querySelector(".again").addEventListener("click", againBtn);
