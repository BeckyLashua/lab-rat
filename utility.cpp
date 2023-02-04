/******************************************************************************
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description. This is the implementation file for general menu and input 
 * validation functions that can be used for different programs. It contains 
 * getInt() methods that validate integer user inputs, a getString() method 
 * that validates string user inputs, a playAgain() method that executes at the 
 * end of every run, and a startProgram() method that prompts the user to play 
 * the program or quit. It also has a generateRandom() function to 
 * generate a random int between the min and max values. 
*******************************************************************************/
#include "utility.hpp"


/********************************************************************* 
* Description: This function takes a string parameter and then repeatedly 
* asks the user that prompt for the correct input until is has been 
* validated as an integer. It returns that valid integer.  
*********************************************************************/
int getInt(string prompt) {
  string data;
  int output = 0;
  bool negative = false;
  while (true) {
    cout << prompt << endl;
    getline(cin, data);  // reads in the entire input from user
    bool success = true;
    for (string::size_type i = 0; i < data.size(); i++) {
      char digit = data[i];  // iterates over each digit in input
      if (digit == '-' && i == 0) { // checks to see if it is negative
        negative = true;
      } 
      else if (digit < '0' || digit > '9') { // makes sure it's not a letter
        cout << "Invalid input. Input must be an integer." << endl;
        success = false;   // if it is a letter then the input is invalid
        break;
      }
      else {
        output *= 10;  // for each new num we see  multiply previous by 10
        output += digit - '0'; // adds additional int to input variable
      }
    } 
    if (success) { //returns output, negative if negative is true
      if (negative) {
        return -output;
      }
      else {
	      return output;
      } 
    }
  }
}


/********************************************************************* 
* Description: This function  takes a string parameter that is a prompt
* for the user, and until it gets a valid value integer within the 
* bounds of the two integer parameter values, it prompts the user to 
* provied the valid input, and then returns that input when it has 
* been received.  
*********************************************************************/
int getInt(string prompt, int lowerbound, int upperbound) {
  while (true) {
    int data = getInt(prompt);
    if (data >= lowerbound && data <= upperbound) {
      return data;
    }
    cout << "Invalid. Only values accepted are those between " 
        << lowerbound << " and " << upperbound << endl;
  }
}


/********************************************************************* 
* Description: This funtion  takes a string parameter that is a prompt
* for the user, an array of valid user inputs, and the size of that 
* array, and then repeatedly prompts the user for valid input within
* that array until it gets it, and then returns the valid input. Note: If acceptableInputSize == 0, data will just 
returned
*********************************************************************/
string getString(string prompt, const string acceptableInputs[], int acceptableInputsSize) {
  while (true) {
    cout << prompt << endl;
    string data;
    getline(cin, data);
    if (acceptableInputsSize == 0) {
      return data;
    }
    for (int i = 0; i < acceptableInputsSize; i++) {
      if (acceptableInputs[i] == data) {
        return data;
      }
    }
    cout << "'" << data << "' is not an accepted value\n";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}


/********************************************************************* 
* Description: This function takes no parameters and returns true if the
* user wants to play the program again and false if not.   
*********************************************************************/
bool playAgain() {
  int size = 4;
  string validInputs[] = {"Y", "y", "N", "n"};
  string replayPrompt = "Would you like to continue playing(Y/N)?\n";

  string response = getString(replayPrompt, validInputs, size);
  if (response == "y" || response == "Y") {
    return true;
  }
  return false;
}


/********************************************************************* 
* Description: This function takes no parameters  and asks the user if 
* they would like to PLAY or QUIT. It returns 1 if they want to run it 
* and 2 if they want to quit.   
*********************************************************************/
int playProgram() {
  cout << endl;
  // Ask for the users input until they give an answer of 1 or 2
  string prompt = "Enter 1 to PLAY\nEnter 2 to QUIT\n";

  return (getInt(prompt, 1, 2));
}


/********************************************************************* 
* Description: This function takes a string parameter that represents
* the name of the program and asks the user if they would like to 
* run the program or quit. It returns 1 if they want to run it and 2 
* if they want to quit.   
*********************************************************************/
int startProgram(string programName) {
  // Ask for the users input until they give an answer of 1 or 2
  string prompt = "Would you like to play " + programName + 
    " or quit?\n(Enter 1 to play " + programName + "\nEnter 2 to quit.\n";

  return (getInt(prompt, 1, 2));
}


/***********************************************************************
* Description: This helper function takes two integer params and returns
* a random integer within that range.  
***********************************************************************/
int generateRandom(int min, int max) {
  return rand() % ((max+1) - min) + min;
}
