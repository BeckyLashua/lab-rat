/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the implementation file for the LabFloor
 * class,which is a derived class of Space. It has one additional
 * method called breakIntoBox() which returns true when the 
 * player is able to successfully opens box. It also
 * has it's own version of the pure virtual function, 
 * specialAction(). 
***************************************************************/
#include "LabFloor.hpp"

LabFloor::LabFloor() : Space() {
  this->name = "labFloor";
  items.push_back("scalpel");
  items.push_back("test tube");
}


int LabFloor::specialAction(std::vector<std::string>& pack) {
  std::cout << "\nThere is a box of items in the corner of the lab room floor\n"
            << "that can be opened if you enter in the right number between\n"
            << "1 and 100.\n"
            << "Maybe there is something in there that you need.\n"
            << "You get 7 guesses per attempt.\n";
  int steps = 0;
  bool brokenIn = false;
  while (!brokenIn) { // after first attempt, adds steps until box is broken into
    if (brokenIntoBox()) {
      brokenIn = true;
    } else {
      std::cout << "\nYou didn't guess the correct number in 7 attempts.\n"
                << "Keep on trying!\nHurry!\n";
      steps++;
    }
  }
  return steps;
}


bool LabFloor::brokenIntoBox() {
  std::string prompt = "\nEnter 1 to try to open the box!\n";
  getInt(prompt,1,1);
  int attempts = 0;
  int randomNum = generateRandom(1,100);
  while (attempts < 7) {
    int guess = getInt("\nEnter an integer between 1 and 100\n",1,100);
    if (guess == randomNum) {
      std::cout << "\nYou guessed the right number!\n"
                << "You can now access items in the box.\n";
      return true;
    } else if (guess > randomNum) {
      std::cout << "Your guess is too high.\n";
    } else {
      std::cout << "Your guess is too low.\n";  
    }
    attempts++;
  }
  return false;
}