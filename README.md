# Hide and Seek Maze Game - C++ Console Application

## Overview

The **Hide and Seek Maze Game** is a **C++ console-based game** where two players compete in a **10x10 maze**. One player **hides** in the maze, and the other player **searches for them within a time limit**.

## Features

- **10x10 Maze Generation**: Fixed map with walls and paths.
- **Two-Player Mode**: One player hides, the other searches.
- **Real-Time Input Handling**: Player moves using **arrow keys**.
- **Time Limit**: Player 2 must find Player 1 **within 20 seconds**.
- **Win/Lose Conditions**:
  - **Player 2 Wins** if they find the hidden player.
  - **Player 1 Wins** if time runs out.
  - **Player 2 Can Quit** using `Q`.

## Installation

### **1. Clone the Repository**

```bash
git clone https://github.com/yourusername/Hide-and-Seek-Maze-Game.git
cd Hide-and-Seek-Maze-Game
```

### **2. Compile the Game**

Using **g++ (GCC Compiler)**:

```bash
g++ hide_and_seek_game.cpp -o hide_and_seek_game.exe
```

Or, using **Visual Studio (MSVC)**:

```bash
cl hide_and_seek_game.cpp /EHsc
```

## Running the Game

```bash
./hide_and_seek_game.exe
```

## How to Play

1. **Player 1 Chooses a Hiding Spot**

   - Enters **X, Y coordinates** on a **10x10 grid**.

2. **Player 2 Searches the Maze**

   - Uses **Arrow Keys (**``**)** to move.
   - Press `Q` to **quit the game**.
   - Must find the hidden player **before time runs out**.

3. **Winning Conditions**

   - If **Player 2 finds the hiding spot**, they **win**.
   - If **Player 2 runs out of time**, **Player 1 wins**.

## Example Gameplay

```
Player 1, choose a spot to hide (enter X and Y coordinates): 3 5
Press any key to start the game!

Time left: 20 seconds
Player 2, use arrow keys to move. Press Q to quit.

[After moving around]
Congratulations! You found the hidden spot! Player 2 wins!
```

## Future Enhancements

- **Random Maze Generation** for a new layout every time.
- **AI Opponent Mode** where Player 2 is controlled by AI.
- **Multiplayer Network Support** for online play.

## License

This project is licensed under the **MIT License**.

## Contributions

Contributions are welcome! To contribute:

1. Fork the repository.
2. Create a new branch (`feature-new-feature`).
3. Commit and push your changes.
4. Open a pull request.

## Contact

For any questions or support, please open an issue on GitHub.

