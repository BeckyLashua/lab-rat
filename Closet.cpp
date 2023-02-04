/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the implemenation file for the Closet
 * class,which is a derived class of Space. It has one additional
 * method called rollDie() which returns true when the 
 * player is able to successfully roll a higher die. It also
 * has it's own version of the pure virtual function, 
 * specialAction(). 
***************************************************************/
#include "Closet.hpp"

Closet::Closet() : Space() {
  this->name = "closet";
  items.push_back("rubbing alcohol");
  items.push_back("syringe");
}


int Closet::specialAction(std::vector<std::string>& pack) {
  std::cout << "\nOdd! There is a guinea pig hiding in the closet!\n"
            << "He says that silly Ivan left his cage door open as well!\n"
            << "Oh goodness, the guinea pig is drunk too.\n"
            << "Oh no, he is already on his second bottle of rubbing alcohol.\n"
            << "Shameful.\n"
            << "What is with all of these alcoholics in this lab??\n"
            << "Anyway...\n"
            << "He says he will not allow anybody past him,\n"
            << "unless they can beat him in a game of dice rolls.\n"
            << "You get 3 rolls per game.\n"
            << "If you can't beat him, you'll have to play until you do!\n"
            << "Each extra play is wasted time.\n";
  int steps = 0;
  bool hasWon = false;
  while (!hasWon) { // after first attempt, adds steps until right roll
    if (rollDie()) {
      hasWon = true;
    } else {
      steps++;
    }
  }
  return steps;
}


bool Closet::rollDie() {
  std::string prompt = "\nEnter 1 to roll your dice.\n";
  int attempts = 0;
  while (attempts < 3 && getInt(prompt,1,1) == 1) {
    int computerNum = generateRandom(4,12);
    int playerNum = generateRandom(4,12);
    std::cout << "The guinea pig rolled a " << computerNum << std::endl;
    std::cout << "You rolled a " << playerNum << std::endl;
    if (playerNum > computerNum) {
      std::cout << "\nYour roll beats his roll!\nYou win!\nYou are now free to move on!\n";
      return true;
    } 
    attempts++;
  }
  std::cout << "\nYou couldn't beat the guinea pig.\nTry again.\n";
  return false;
}