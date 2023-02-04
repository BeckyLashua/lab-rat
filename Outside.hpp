/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the specification file for the Outside
 * class,which is a derived class of Space. Once this space is
 * reached without using too many steps, the game has been won. 
***************************************************************/
#ifndef OUTSIDE
#define OUTSIDE
#include "Space.hpp"
#include <iostream>


class Outside : public Space {
  public:
    Outside();
    int specialAction(std::vector<std::string>& pack);
};

#endif

