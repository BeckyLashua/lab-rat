/******************************************************************************
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description. This is the header file for general menu and input 
 * validation functions that can be used for different programs. It contains 
 * getInt() methods that validate integer user inputs, a getString() method 
 * that validates string user inputs, a runAgain() method that executes at the 
 * end of every run, and a startProgram() method that prompts the user to run 
 * the program or quit.It also has a generateRandom() function to 
 * generate a random int between the min and max values.
*******************************************************************************/
#ifndef UTILITY
#define UTILITY

#include <cmath>
#include <limits>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Function prototypes
int getInt(string prompt);
int getInt(string prompt, int lowerbound, int upperbound);
string getString(string prompt, const string acceptableInputs[], int acceptableInputsSize);
bool playAgain();
int playProgram();
int startProgram(string program);
int generateRandom(int,int);

#endif
