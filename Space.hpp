/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the specification file for the Space 
 * class. It contains many get and set methods for it's data
 * member variables. Each Space object has 4 directional
 * pointers that either point toward another space or NULL. It
 * has a pure virtual function, specialAction() that is 
 * personalized by each of its derived classes and a 
 * displayLocation() method that displays the adjacent spaces
 * surrounding the space (that are not NULL).
***************************************************************/
#ifndef SPACE
#define SPACE
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "utility.hpp"


class Space {
  protected:
    Space* top;
    Space* right;
    Space* left;
    Space* bottom;
    std::string name;
    std::vector<std::string> items;
    bool visited;

  public:
    Space(); // Constructor
    virtual ~Space() = default; // destructor
    virtual int specialAction(std::vector<std::string>& pack) = 0;
    std::vector<std::string> displayLocation();
    Space* getTop() const;
    void setTop(Space*);
    Space* getBottom() const;
    void setBottom(Space*);
    Space* getLeft() const;
    void setLeft(Space*);
    Space* getRight() const;
    void setRight(Space*);
    std::string getName() const;
    void setName(std::string);
    std::vector<std::string>& getItems();
    void addItem(std::string);
    void removeItem(std::string);
    void displayItems();
    std::string chooseFromItems();
    bool getVisited();
    void setVisited(bool);
};

#endif