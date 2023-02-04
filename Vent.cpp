/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the implementation file for the Office
 * class,which is a derived class of Space. It has one additional
 * method called dodgeSpider() which returns true when the 
 * player is able to successfully outrun the spider. It also
 * has it's own version of the pure virtual function, 
 * specialAction(). 
***************************************************************/
#include "Vent.hpp"

Vent::Vent() : Space() {
  this->name = "vent";
  items.push_back("stickie note");
  items.push_back("hair pin");
}


int Vent::specialAction(std::vector<std::string>& pack) {
  std::cout << "\nThere is a deadly radioactive spider in the vent!\n"
            << "Seriously?\n"
            << "First you have to deal with a drunk guinea pig.\n"
            << "And now this?\n"
            << "This place is nuts.\n"
            << "\nYou don't want to let it get close to you\n" 
            << "and bite you with it's radioactive bite!\n"
            << "The only way to beat the spider is with a sharp weapon!\n"
            << "If you don't have a weapon, you could always take a chance\n"
            << "at dodging the spider and running past it.\n"
            << "But you chance instant death if the spider bites you!\n";

  std::string sec1 = "\nWhat would you like to do?\n";
  std::string sec2 = "1. Use a weapon on the spider.\n";
  std::string sec3 = "2. Run past and dodge the spider. Wish me luck!\n";
  std::string prompt = sec1 + sec2 + sec3;

  int choice = getInt(prompt,1,2);
  if (choice == 1) {
    if (pack.size() == 0) {
      std::cout << "\nYou don't have anything in your rat pack.\n";
      std::cout << "You have no choice but to try to dodge the spider!\n";
      if (dodgeSpider()) {
        return 0;
      } else {
        std::cout << "The spider's bite killed you!\n"
                  << "Rats!\n"
                  << "GAME OVER\n";
        return -1;
      }
    } else {
      for (unsigned int i = 0; i < pack.size(); i++) {
        std::cout << (i+1) << ": " << pack[i] << std::endl;
      }
      int selected = getInt("\nChoose which weapon\n",1,pack.size());
      if (pack[selected-1] == "scalpel") {
        std::cout << "\nYou used your scalpel to kill off the spider!\n"
                  << "Right on!\nYou are free to move on!\n";
        pack.erase(pack.begin() + (selected-1));
        this->items.push_back("scalpel");
        return 0;
      } else {
        std::cout << "\nThis isn't a weapon that can be used against a spider.\n"
                  << "You took too long to find the right weapon.\n"
                  << "The spider bit you!\n";
        this->items.push_back(pack[selected-1]);
        pack.erase(pack.begin() + (selected-1));
        return - 1;
      }
    }
  } else {
    if (dodgeSpider()) {
        return 0;
      } else {
        std::cout << "The spider's bite killed you!\n"
                  << "Rats!\n"
                  << "GAME OVER\n";
        return - 1;
      }
  }
}


bool Vent::dodgeSpider() {
  int randomNum = generateRandom(1,2);
  getInt("\nEnter 1 to dodge the spider and run past it!\n", 1, 2);
  if (randomNum == 2) {
    std::cout << "\nYou successfully doged the spider and ran past it!\n"
              << "The spider has left the vent.\nPhew.\n"
              << "That was a close call.\n"
              << "Let's hope you don't have to deal with anymore drunk or radioactive creatures.\n";
    return true;
  } 
  std::cout << "\nYour dodge failed.\nThe spider managed to bite you!\n";
  return false;
}
