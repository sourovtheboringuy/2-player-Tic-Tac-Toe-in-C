Tic-Tac-Toe Game in C

A simple two-player console-based Tic-Tac-Toe game implemented in C. This project allows two players to play the classic Tic-Tac-Toe game in the terminal, alternating between 'X' and 'O'. It features a 3x3 grid, move validation, win detection, and a draw condition.
Features

    2 Player Gameplay: Players alternate turns to place their 'X' or 'O' on the board.
    Move Validation: Ensures players select valid positions on the board.
    Win Detection: Automatically detects when a player wins by forming a line of 3 'X's or 'O's horizontally, vertically, or diagonally.
    Draw Detection: The game detects when the board is full and no player has won, resulting in a draw.
    Clean Console Output: The game board is displayed in a clean and readable format after every move.

How to Play

Run the game:

    ./tic_tac_toe

    Player 1 uses 'X' and Player 2 uses 'O'.
    Players take turns to enter a number between 1 and 9 to place their mark in the corresponding position on the grid.
    The game will display the updated board after every move and announce the winner or a draw at the end.

Example

Welcome to Tic-Tac-Toe!

 Player X, enter a move (1-9): 1
  X | 2 | 3
  --|---|---
  4 | 5 | 6
  --|---|---
  7 | 8 | 9

 Player O, enter a move (1-9): 5
  X | 2 | 3
  --|---|---
  4 | O | 6
  --|---|---
  7 | 8 | 9

 Player X, enter a move (1-9): 2
  X | X | 3
  --|---|---
  4 | O | 6
  --|---|---
  7 | 8 | 9

 Player O, enter a move (1-9): 9
  X | X | 3
  --|---|---
  4 | O | 6
  --|---|---
  7 | 8 | O

 Player X, enter a move (1-9): 3
  X | X | X
  --|---|---
  4 | O | 6
  --|---|---
  7 | 8 | O

Player X wins!
