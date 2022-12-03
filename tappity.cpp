#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
// Notes: test constructor sets reference
tappity::tappity(std::string reference)
{
  reference_phrase = reference;
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
  user_input_phrase = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  return std::abs((int)(reference_phrase.length()) - (int)(user_input_phrase.length()));
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.

// Notes: 
double tappity::accuracy()
{
  float accuracy;
  double possible_correct = (double)reference_phrase.length();
  int user_phrase_size = user_input_phrase.length();
  double correctCounter = 0;

  for (int i = 0; i < user_phrase_size; i++) {
    if (i >= possible_correct) {
      break;
    } else if (user_input_phrase[i] == reference_phrase[i]) {
      correctCounter++;
    } 
  }

  return 100.0*(correctCounter/possible_correct);
}


/*
hello there  (size 11)

hello there mate     (size 16) 
possible correct is 11







*/