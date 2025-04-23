#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  if (phrase.length() == 0){
    return 0;
  }
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass){
  bool has_upper = false;
  bool has_lower = false;
  for (
    int counter = 0;
    counter < pass.length();
    counter++
  )
  {
    if (isupper(pass[counter])){
      has_upper = true;
    }
    else if (islower(pass[counter])){
      has_lower = true;
    }

    // if both upper and lower case letters are found, return true
    if (has_upper && has_lower){
      return true;
    }
  }
  return false;
}