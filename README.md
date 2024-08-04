# Wordle Game Implementation

## Description

This project involves implementing a playable version of the popular word-guessing game, Wordle, in C. The game includes the following features:

### Features

- **Word Guessing Game**: Players guess a secret 5-letter word. The game provides feedback using colored squares:
  - **Gray**: Letter is not in the secret word.
  - **Yellow**: Letter is in the secret word but in a different position.
  - **Green**: Letter is in the correct position.
- **Valid Guesses**: Guesses must be valid 5-letter English words from a predefined list.

### Key Files

- **`wordle_game.c`**: Contains the main function for running the game.
- **`wordle_lib.c`**: Contains the functions to be implemented.
- **`wordle_lib.h`**: Header file with function declarations.
- **`Makefile`**: Builds the project.

### Usage

To compile and run the game:

```bash
$ make
$ ./wordle_game
