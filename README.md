# 🎮 Tic-Tac-Toe in C

A graphical Tic-Tac-Toe game built in **C** using **Raylib**, featuring multiple AI difficulty levels, including an unbeatable AI powered by the **Minimax algorithm**.

Play against the computer or challenge a friend in local multiplayer!

## ✨ Features

- 🎨 **Graphical Interface** — Interactive menus and a visual game board powered by Raylib.
- 🤖 **Player vs AI** — Challenge the computer with different levels of difficulty.
- 🧠 **Minimax Algorithm** — Play against an AI that evaluates possible game outcomes to make optimal decisions.
- 🎚️ **Multiple Difficulty Levels** — From random moves to optimal play.
- 👥 **Local Multiplayer** — Play against another person on the same device.
- 🏆 **Win and Draw Detection** — Automatically detects winning combinations and ties.
- 🖱️ **Mouse Controls** — Navigate the interface and select board positions using the mouse.

## 🧠 AI Difficulty Levels

The game offers different AI behaviors to accommodate different skill levels.

### 🟢 Easy
The AI selects moves randomly without considering winning or blocking opportunities.

**Best for:** Beginners and casual games.

### 🟡 Medium
The AI prioritizes winning when possible and blocks the player's immediate winning moves. Otherwise, it chooses a random legal move.

**Best for:** Players learning basic strategies.

### 🔴 Hard
The AI follows a strategic decision order:
- Win whenever possible.
- Block the player's winning move.
- Take the center.
- Prefer corners.
- Choose an available side when necessary.

**Best for:** Players looking for a greater challenge.

### ⚫ Impossible
The AI uses the **Minimax algorithm** to evaluate possible future game states and select an optimal move.

In standard Tic-Tac-Toe, optimal play guarantees that the AI will never lose. The best possible outcome for the player is a draw.

**Best for:** Testing your strategy against an unbeatable opponent.

## 🕹️ How to Play

1. Launch the game.
2. Use the graphical menu to select a game mode and difficulty.
3. In Player vs AI mode, take turns against the computer.
4. In local multiplayer mode, play against another person.
5. Click an available square to place your mark.
6. Complete a horizontal, vertical, or diagonal line of three marks to win.

The game automatically detects victories and draws.

## 🧩 Project Structure

The project separates game logic from graphical interface code.

```text
Tic-Tac-Toe/
└── UI/
    ├── main.c
    ├── game/
    │   ├── game.c
    │   └── game.h
    ├── UI/
    │   ├── design.c
    │   └── design.h
    ├── assets/
    └── fonts/
```

- **`main.c`** — Application entry point and main game flow.
- **`game/game.c`** — Game logic, player moves, AI decisions, and win/draw detection.
- **`game/game.h`** — Game declarations and shared definitions.
- **`UI/design.c`** — Graphical interface, rendering, and user interaction using Raylib.
- **`UI/design.h`** — Interface declarations and shared definitions.
- **`assets/`** — Images and other graphical resources.
- **`fonts/`** — Fonts used by the interface.

## 🛠️ Technologies and Concepts

- **C** — Core programming language.
- **Raylib** — Graphics, rendering, input handling, and window management.
- **Minimax** — Adversarial search for optimal AI decisions.
- **Game State Management** — Board representation and turn handling.
- **Arrays and Structures** — Organizing board data and game state.
- **Functions and Modular Design** — Separating gameplay from presentation.
- **Conditional Logic and Recursion** — Implementing game rules and Minimax evaluation.
- **Random Number Generation** — Supporting less predictable AI behavior at lower difficulty levels.

## 🚀 Future Improvements

Potential extensions for the project include:

- Score tracking and match statistics.
- Additional visual effects and animations.
- Sound effects and background music.
- Improved menus and user experience.
- More advanced game modes and customization.
- Cross-platform build and distribution.

---

> Developed as a C programming project to explore game development, AI decision-making, and graphical interfaces with Raylib.
