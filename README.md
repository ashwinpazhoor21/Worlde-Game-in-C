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

### Data Structures

The project uses dynamic data structures to manage game state and player interactions:

- **Arrays**: Used to store the list of valid 5-letter words and to manage the player's guesses.
- **Structs**: Employed to encapsulate the properties of each word, such as the word itself and the associated feedback colors for each letter.
- **Linked Lists**: Utilized for advanced management of game states and undo functionality (if implemented).

These data structures facilitate efficient searching, matching, and feedback generation, allowing the game to process player guesses and provide appropriate responses.

### Usage

To compile and run the game:

```bash
$ make
$ ./wordle_game