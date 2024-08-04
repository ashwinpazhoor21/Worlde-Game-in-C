**Score Guess**:
To implement to this method I will compare a guessed word to a secret word and determine how well the guess matches. I will first initialize the variables to track the exact matches and the total letter counts. I will then use the first loop to check each letter in the guess against the secret word. I will mark the exact matches with "g". Then for the second loop I will check for the non matching characters and mark y if the letter exists elsewhere in the word, otherwise I will mark X. Lastly, I will null terminate the result string, and will return whether the guess is a match. 


**Valid Guess:**
To implement valid guiess I will be checking if the guessed word in present in the vocabulary. I will loop through the vocabulary array and then compare each word in the vocabulary with the guess. I will then return true if a match is found, otherwise I will return false. 

**Load Vocabulary:**
To implement this problem I will be loading a list of five letter words from a file into an array. I will first start by opening the file for reading and then initilizing an array to hold the words. I will then loop through each line in the file reading the 5 letter words and duplicate each word and add it into the array. Next, I will be reallocating that memory as needed to accomdate the new words. Lastly, I will close the file and return the array of words read. 


**Free vocabulary**:
To implement this problem I will be freeing all the memory allocated for the vocabulary. First I will loop through each word in the vocabulary array. I will then free the memory that is allocated for each word. Lastly, I will free the memory for the allocated array itself.
