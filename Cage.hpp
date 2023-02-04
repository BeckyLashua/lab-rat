/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the specfication file for the Cage 
 * class,which is a derived class of Space. It has one additional
 * method called makeJump() which returns true when the 
 * player is able to successfully drink water. It also
 * has it's own version of the pure virtual function, 
 * specialAction(). 
***************************************************************/
#ifndef CAGE
#define CAGE
#include "Space.hpp"
#include <iostream>
#include "utility.hpp"


class Cage : public Space {
  public:
    Cage();
    int specialAction(std::vector<std::string>& pack);
    bool makeJump();
};

#endif