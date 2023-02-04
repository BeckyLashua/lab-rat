/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the implementation file for the BreakRoom 
 * class,which is a derived class of Space. It has one additional
 * method called breakIntoSafe() which returns true when the 
 * player is able to successfully break into the safe. It also
 * has it's own version of the pure virtual function, 
 * specialAction(). 
***************************************************************/
#include "BreakRoom.hpp"

BreakRoom::BreakRoom() : Space() {
  this->name = "breakRoom";
  items.push_back("cat nip");
  items.push_back("thumb tack");
}


int BreakRoom::specialAction(std::vector<std::string>& pack) {
  std::cout << "\nThe coast is clear.\n"
            << "There are no radioactive or drunk creatures here.\n"
            << "But the break room doesn't lead to outside.\n"
            << "You are going to have to go back to the vent\n"
            << "But before you go, there is a safe in on the counter.\n"
            << "There was a stickie note with a passcode written on it,\n"
            << "but nobody knows where it has gone.\n"
            << "Perhaps a draft swept it up into the vent earlier this morning.\n";
  std::string prompt = "\nEnter 1 to try to open the safe.\n";
  getInt(prompt,1,1);
  // Tries to find stickie note in rat pack
  bool found = false;
  int stickieIndex;
  for (unsigned int i = 0; i < pack.size(); i++) {
    if (pack[i] == "stickie note") {
      found = true;
      stickieIndex = i;
    }
  }
  if (found) { // Case for if player has stickie note in rat pack
    std::cout << "\nYay, you have the stickie note with the passcode on it!\n"
              << "You have entered the passcode and opened the safe.\n"
              << "You are now able to take items if you would like!\n";
    pack.erase(pack.begin() + stickieIndex);
    this->items.push_back("stickie note");
  } else { // Case for when the player doesn't have a stickie note in pack
    bool brokenInto = false;
    int steps = 0;
    std::cout << "\nOh no! You don't have the stickie note.\n";
    std::cout << "That is okay. You can still take 10 guesses.\n";
    std::cout << "But if you can't guess it within 10 tries, you will lose time.\n";
    std::cout << "Hurry! Ivan might be waking up soon!\n";
    int randomNum = generateRandom(100,999);
    while (!brokenInto) { // Adds steps to step count until safe is broken into
      if (breakIntoSafe(randomNum)) {
        brokenInto = true;
      } else {
        std::cout << "You didn't guess the number in time\n"
                  << "You need to try again!\n";
        steps++;
      }
    }
    return steps;
  }
  return 0; // no added step points to return
}


bool BreakRoom::breakIntoSafe(int randomNumber) {
  int attempts = 0;
  while (attempts < 10) {
    int guess = getInt("\nEnter an integer between 100 and 999\n",100,999);
    if (guess == randomNumber) {
      std::cout << "\nYou guessed the right number!\nYou can now access items in the safe.\n";
      return true;
    } else if (guess > randomNumber) {
      std::cout << "Your guess is too high.\n";
    } else {
      std::cout << "Your guess is too low.\n";  
    }
    attempts++;
  }
  std::cout << "\nYou ran out of attempts.\n";
  return false;
}