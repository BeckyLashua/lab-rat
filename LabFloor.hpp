/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the specification file for the LabFloor
 * class,which is a derived class of Space. It has one additional
 * method called breakIntoBox() which returns true when the 
 * player is able to successfully opens box. It also
 * has it's own version of the pure virtual function, 
 * specialAction(). 
***************************************************************/
#ifndef LABFLOOR
#define LABFLOOR
#include "Space.hpp"
#include <iostream>


class LabFloor : public Space {
  public:
    LabFloor();
    int specialAction(std::vector<std::string>& pack);
    bool brokenIntoBox();
};

#endif