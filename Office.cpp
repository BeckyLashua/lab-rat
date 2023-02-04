/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the implementation file for the Office
 * class,which is a derived class of Space. It has one additional
 * method called outrun() which returns true when the 
 * player is able to successfully outrun the cat. It also
 * has it's own version of the pure virtual function, 
 * specialAction(). 
***************************************************************/
#include "Office.hpp"


Office::Office() : Space() {
  this->name = "office";
}


int Office::specialAction(std::vector<std::string>& pack) {
  std::cout << "\nYou have finally made it to the last room, the office.\n";
  std::cout << "It looks like there is a doggie door the leads to the outside.\n"
            << "You are so close to freedom!\n"
            << "Can't you smell it already?\n"
            << "Of course you can.\n"
            << "Because you are a rat.\n"
            << "And rats have fantastic smell.\n"
            << "Be proud.\n"
            << "\nBut look!! Your worst nightmare has come true.\n"
            << "There is a cat sitting in the window sill.\n"
            << "And it has spotted you.\n"
            << "Your only options are to distract it with catnip or to outrun it.\n"
            << "If you throw catnip at it, you will guarantee yourself an escape!\n"
            << "But if you run for it, you will only have a 30% chance of escaping.\n"
            << "If you don't manage to outrun the cat, you will instantly lose.\n";

  std::string sec1 = "\nWhat do you want to do?\n";
  std::string sec2 = "1. Use catnip to distract cat.\n";
  std::string sec3 = "2. Take a chance and try to out run the cat.\n";
  std::string prompt = sec1 + sec2 + sec3; 
  // Tries to find catnip in rat pack
  bool hasCatNip = false;
  int catnipIndex;
  for (unsigned int i = 0; i < pack.size(); i++) {
    if (pack[i] == "cat nip") {
      hasCatNip = true;
      catnipIndex = i;
    }
  }
  // Chooses to use cat nip or run for it
  int choice = getInt(prompt, 1, 2);
  if (choice == 1 && !hasCatNip) { // for case of no cat nip in pack
    std::cout << "\nUnfortunately, you don't have any catnip.\n"
              << "You have no choice but to run for it.\n";
    std::string prompt = "\nEnter 1 to run for it.\n";
    getInt(prompt,1,1); 
    if (outrun()) { // if outrun, return no steps
      return 0;
    } else {
      return -1; // returns flagging number that indicates death
    }
  } else if (choice == 1 && hasCatNip) {
    std::cout << "\nYou threw your catnip at the cat and successfully distracted it!\n";
    this->items.push_back("cat nip");
    pack.erase(pack.begin() + catnipIndex);
    return 0;
  } else {
    if (outrun()) {
      return 0;
    } else {
      return -1;
    }
  }
}


bool Office::outrun() {
  int randomChance = generateRandom(1,10);
  if (randomChance > 7) {
  std::cout << "\nWow! You have successfully outrun the cat\n" 
            << "and made it to the doggie door.\n"
            << "You are one impressive rat.\n";
    return true;
  } else {
    std::cout << "You have been caught by the cat!\n"
              << "Your end is here. :( \n"
              << "Rats!"
              << "GAME OVER\n";
      return false;
  }  
}