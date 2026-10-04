# Tic-Tac-Toe
## 🎮 **Tic-Tac-Toe in C**

  A console-based Tic-Tac-Toe game written in C featuring:

✅ Player vs AI mode

✅ Multiple difficulty levels

✅ Input validation (no letters allowed)

✅ Win and tie detection

✅ Clean board rendering


## 🧠 Difficulty Levels

The game includes different AI difficulties with increasing intelligence.

🟢 Easy

The AI plays random moves only.

It does not try to win or block the player.

Very easy to beat.

🟡 Medium

The AI tries to win if possible.

It blocks the player's winning move.

Otherwise, it plays randomly.

Provides a balanced challenge.

🔴 Hard

The AI uses strategy:

Win if possible

Block player

Take center

Take corners

Take sides

Much harder to defeat.


## 🖥️ How to Play

Board positions:

0 1 2

3 4 5

6 7 8

Choose a number between 0 and 8 to make your move.

## 🧩 Project Structure

main() → Game loop

Initialize() → Initializes the board

ShowTab() → Displays the board

play() → Handles player input

IAplay() → AI decision logic

victory() → Checks winner

tied() → Checks draw

legalPlay() → Validates moves


## 🧠 Concepts Used

2D arrays

Structures (typedef struct)

Loops and conditionals

Input validation

Random number generation (rand)

Basic AI logic


## 🚀 Future Improvements

Minimax algorithm (unbeatable AI)

Score tracking

Multiplayer mode

Better UI

Cross-platform

---

>  *Developed as a C programming practice project.*
