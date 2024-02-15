"use strict";
const player0Element = document.querySelector(".player--0");
const player1Element = document.querySelector(".player--1");
const score0Element = document.querySelector("#score--0");
const score1Element = document.getElementById("score--1");
const currentScore0Element = document.getElementById("current--0");
const currentScore1Element = document.getElementById("current--1");
const diceElement = document.querySelector(".dice");
const btnNew = document.querySelector(".btn--new");
const btnRoll = document.querySelector(".btn--roll");
const btnHold = document.querySelector(".btn--hold");

let scores;
let currentScore;
let activePlayer;
let stillPlaying;

const newGame = function () {
  scores = [0, 0];
  currentScore = 0;
  activePlayer = 0;
  stillPlaying = true;
  score0Element.textContent = 0;
  score1Element.textContent = 0;
  diceElement.classList.add("hidden");
  currentScore0Element.textContent = 0;
  currentScore1Element.textContent = 0;
  player0Element.classList.remove("player--winner");
  player1Element.classList.remove("player--winner");
  player0Element.classList.add("player--active");
  player1Element.classList.remove("player--active");
};
newGame();

const switchPlayer = function () {
  document.getElementById(`current--${activePlayer}`).textContent = 0;
  currentScore = 0;
  activePlayer = activePlayer === 0 ? 1 : 0;
  player0Element.classList.toggle("player--active");
  player1Element.classList.toggle("player--active");
};

const rollDice = function () {
  if (stillPlaying) {
    const dice = Math.trunc(Math.random() * 6) + 1;

    //**display dice**
    diceElement.classList.remove("hidden");
    diceElement.src = `dice-${dice}.png`;

    if (dice != 1) {
      currentScore += dice;
      document.getElementById(`current--${activePlayer}`).textContent =
        currentScore;
    } else {
      scores[activePlayer] = 0;
      document.getElementById(`score--${activePlayer}`).textContent =
        scores[activePlayer];
      switchPlayer();
    }
  }
};

const scoreHold = function () {
  if (stillPlaying) {
    scores[activePlayer] += currentScore;
    document.getElementById(`score--${activePlayer}`).textContent =
      scores[activePlayer];
    if (scores[activePlayer] >= 100) {
      stillPlaying = false;
      diceElement.classList.add("hidden");
      document
        .querySelector(`.player--${activePlayer}`)
        .classList.add("player--winner");
      document
        .querySelector(`.player--${activePlayer}`)
        .classList.remove("player--active");
    } else {
      switchPlayer();
    }
  }
};

btnRoll.addEventListener("click", rollDice);
btnHold.addEventListener("click", scoreHold);
btnNew.addEventListener("click", newGame);
