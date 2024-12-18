#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
   int number = stoi(argv[1]);
   string filler = argv[2];
   string pattern = argv[3];
   // Length of the pattern
   int patternLength = pattern.length();
   // Initial length of the filler pattern
   int fillerLength = number - patternLength;
   // Loop through all rows
   for (int ir = 0; ir < number; ir++) {
      // Print the filler characters
      for (int ic = 0; ic < fillerLength; ic++) {
          cout << filler;
      }
      // ic < (number - ir) limits the characters to fit the currently allowed
      // column width. 
      // ic < patternLength makes sure the loop does not exceed the 
      // length of the pattern string
      for (int ic = 0; ic < patternLength && ic < number - ir; ic++) {
         cout << pattern[ic];
      }
      cout << endl;
      if (fillerLength > 0) {
         fillerLength--;
      }
      // If fillerLength is < 0 we want to shift out the leftmost symbol
      // of our pattern.
      else if (!pattern.empty()) {
         // Shift out the first character of the pattern
         pattern = pattern.substr(1); 
         patternLength--;
      }
    }
    return 0;
}

