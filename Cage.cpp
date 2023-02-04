/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the implementation file for the Cage 
 * class,which is a derived class of Space. It has one additional
 * method called makeJump() which returns true when the 
 * player is able to successfully drink water. It also
 * has it's own version of the pure virtual function, 
 * specialAction(). 
***************************************************************/
#include "Cage.hpp"

Cage::Cage() : Space() {
  this->name = "cage";
}


int Cage::specialAction(std::vector<std::string>& pack) {
  std::cout << "\nYou are dehydrated and need to drink water.\n"
            << "But silly Ivan placed the water bottle too high.\n"
            << "Try to reach the water within three jumps.\n"
            << "If you can't make it in three jumps,\n"
            << "you will have to try again and waste more time.\n";
  bool hasWon = false;
  int steps = 0;
  while (!hasWon) { // adds to step count until jump is made (after first attempt)
    if (makeJump()) { 
      hasWon = true;
    } else {
      std::cout << "\nYou couldn't make the jump in 3 attempts.\n"
                << "You wasted time.\nTry again.\n"
                << "And hurry! I think I heard silly Ivan stirring!\n";
      steps++;
    }
  } 
  return steps; 
}


bool Cage::makeJump() {
  std::string prompt = "\nEnter 1 to jump.\n";
  int chance = generateRandom(1,10);
  int attempts = 1;
  while (getInt(prompt,1,1) == 1 && attempts < 3) {
    attempts++;
      if (chance >= 8) {
        std::cout << "\nYay!\nYou reached the water!\n";
        return true;
    } else {
      std::cout << "\nOh man. You didn't jump high enough.\n";
      chance = generateRandom(1,10);
    }
  }
  return false;
}
