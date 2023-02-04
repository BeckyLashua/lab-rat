/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the specification file for the Office
 * class,which is a derived class of Space. It has one additional
 * method called dodgeSpider() which returns true when the 
 * player is able to successfully outrun the spider. It also
 * has it's own version of the pure virtual function, 
 * specialAction(). 
***************************************************************/
#ifndef VENT
#define VENT
#include "Space.hpp"
#include <iostream>


class Vent : public Space {
  public:
    Vent();
    int specialAction(std::vector<std::string>& pack);
    bool dodgeSpider();
};

#endif