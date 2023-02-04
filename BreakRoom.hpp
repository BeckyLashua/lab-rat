/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the header file for the BreakRoom class,
 * which is a derived class of Space. It has one additional
 * method called breakIntoSafe() which returns true when the 
 * player is able to successfully break into the safe. It also
 * has it's own version of the pure virtual function, 
 * specialAction(). 
***************************************************************/
#ifndef BREAKROOM
#define BREAKROOM
#include "Space.hpp"
#include <iostream>


class BreakRoom : public Space {
  public:
    BreakRoom();
    int specialAction(std::vector<std::string>& pack);
    bool breakIntoSafe(int);
};

#endif