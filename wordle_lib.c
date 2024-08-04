#include "wordle_lib.h"
#include <string.h>
#include <stdlib.h>

// Most of the code that you're going to have to implement goes in here.
// Feel free to add more helper functions if necessary.

// Returns true if the guess is an exact match with the secret word, but
// more importantly, fills in the result with the following:
// - 'x' goes in a slot if the corresponding letter in the guess does not appear
//   anywhere in the secret word
// - 'y' goes in a slot if the corresponding letter in the guess appears in the
//   secret word, but not in the corresponding slot
// - 'g' goes in a slot if the corresponding letter in the guess appears in the
//   corresponding slot in the secret word.
//   You can assume that result points at enough memory for a string of length
//   5. (ie, at least 6 bytes long)
bool score_guess(char *secret, char *guess, char *result) {
  // TODO(you): finish this function
  bool exact_match = true;
  int secret_letter_count[26] = {0};
  int guess_letter_count[26] = {0};

  for(int i = 0; i < 5; i++){
	  if(guess[i] == secret[i]){
		  result[i] = 'g';
	  } else {
		  result[i] = '_';
		  exact_match = false;
	  }

	  secret_letter_count[secret[i] - 'a']++;

	  guess_letter_count[guess[i] - 'a']++;

  }


  for(int i = 0; i < 5; i++){
	  if(result[i] != 'g'){
		  if(secret_letter_count[guess[i] - 'a'] > 0){
			  result[i] = 'y';
			  secret_letter_count[guess[i] - 'a']--;
		  } else {
			  result[i] = 'x';
		  }
           }
 }

  result[5] = '\0';

  return exact_match;
 
}

// Returns true if the specified guess is one of the strings in the vocabulary,
// and false otherwise. num_words is the length of the vocabulary.
// A simple linear scan over the strings in vocabulary is fine for our purposes,
// but consider: could you do this search more quickly?
bool valid_guess(char *guess, char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
  for(size_t i = 0; i < num_words; i++){
		  if(strcmp(guess, vocabulary[i]) == 0){
				  return true;
		 }
  }
  return false;
}

// Returns an array of strings (so, char **), where each string contains a word
// from the specified file. The file is assumed to contain 5-letter words, one
// per line.
// Also, this function sets the value pointed at by *num_words to be the number
// of words read.
// This will need to allocate enough memory to hold all of the char* pointers --
// so you will keep track of the size of your char** array and then use realloc
// to make the array larger over time, so that you have enough space for the
// dynamically-growing array of char *.
// Use fopen to open the input file for reading,
// strdup (or strndup) to make copies of each word read from that file, and
// fclose to close the file when you are done reading from it.
// Each element of the array should be a single five-letter word,
// null-terminated.
char **load_vocabulary(char *filename, size_t *num_words) {
  // TODO(you): finish this function
  FILE *file = fopen(filename, "r");

  if(!file){
	  perror("Could not open file");
	  return NULL;
  }

  char **vocabulary = NULL;
  char word[6];
  size_t size = 0; 
  *num_words = 0;


  while(fscanf(file, "%5s", word) == 1){
	  char *word_copy = strdup(word);
	  if(!word_copy){
		  perror("Failed to duplicate word");
		  free_vocabulary(vocabulary, *num_words);
		  fclose(file);
		  return NULL;
	  }
	  size++;

	  char **temp = realloc(vocabulary, size * sizeof(char *));

	  if(!temp){
		  perror("Failed to reallocate memory");
		  free(word_copy);
		  free_vocabulary(vocabulary, *num_words);
	          fclose(file);
		  return NULL;
	  }


	  vocabulary = temp;

	  vocabulary[*num_words] = word_copy;
	  (*num_words)++;

  }

  fclose(file);

  return vocabulary;
}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
  for(size_t i = 0; i < num_words; i++){
	  free(vocabulary[i]);
  }
  free(vocabulary);
}
