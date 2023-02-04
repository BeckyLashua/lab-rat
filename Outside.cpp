/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the implementation file for the Outside
 * class,which is a derived class of Space. Once this space is
 * reached without using too many steps, the game has been won. 
***************************************************************/
#include "Outside.hpp"

Outside::Outside() : Space() {
  this->name = "outside";
}


int Outside::specialAction(std::vector<std::string>& pack) {
  std::cout << "\nYou made it outside before Ivan woke up!\n"
            << "Congrats! You win the game!\n"
            << "Scurry on and live your best rattie life. :)\n";
  return true;
}


