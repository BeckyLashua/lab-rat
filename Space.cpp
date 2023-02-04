/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the implementation file for the Space 
 * class. It contains many get and set methods for it's data
 * member variables. Each Space object has 4 directional
 * pointers that either point toward another space or NULL. It
 * has a pure virtual function, specialAction() that is 
 * personalized by each of its derived classes and a 
 * displayLocation() method that displays the adjacent spaces
 * surrounding the space (that are not NULL).
***************************************************************/
#include "Space.hpp"

Space::Space() {
  this->top = NULL;
  this->bottom = NULL;
  this->right = NULL;
  this->left = NULL;

  visited = false;
  srand(time(NULL));
}


std::vector<std::string> Space::displayLocation() {
  std::cout << "\nYour current location: " << this->name << std::endl;
  std::vector<std::string> options;

  if (this->top != NULL) {
    options.push_back(this->top->getName());
  } 
  if (this->bottom != NULL) {
    options.push_back(this->bottom->getName());
  }
  if (this->left != NULL) {
    options.push_back(this->left->getName());
  }
  if (this->right != NULL) {
    options.push_back(this->right->getName());
  }
  
  std::cout << "\nAdjacent spaces you can move to:\n";
  for (unsigned int i = 0; i < options.size(); i++) {
    std::cout << (i+1) << ": " << options[i] << std::endl;
  }
  return options;
}


// GET AND SET METHODS FOR DATA MEMBER VARIABLES
Space* Space::getTop() const {
  return this->top;
}

void Space::setTop(Space* top) {
  this->top = top;
}

Space* Space::getBottom() const {
  return this->bottom;
}

void Space::setBottom(Space* bottom) {
  this->bottom = bottom;
}

Space* Space::getLeft() const {
  return this->left;
}

void Space::setLeft(Space* left) {
  this->left = left;
}

Space* Space::getRight() const {
  return this->right;
}

void Space::setRight(Space* right) {
  this->right = right;
}

std::string Space::getName() const {
  return this->name;
}

void Space::setName(std::string name) {
  this->name = name;
}

std::vector<std::string>& Space::getItems() {
  return items;
}

void Space::addItem(std::string item) {
  items.push_back(item);
}

bool Space::getVisited() {
  return this->visited;
}

void Space::setVisited(bool truth) {
  this->visited = truth;
}


// This method removes item from space
void Space::removeItem(std::string item) {
  for (unsigned int i = 0; i < items.size(); i++) {
    if (items[i] == item) {
      items.erase(items.begin() + i);
    }
  }
}


// This method displays all items in space
void Space::displayItems() {
  if (items.size() == 0) {
    std::cout << "\nThere are no items left in " << name << std::endl;
  } else {
    std::cout << "\nDisplaying items in " << name << ":\n";
    for (unsigned int i = 0; i < items.size(); i++) {
      std::cout << items[i] << std::endl;
    }
  }
}


// This method chooses from items in room and returns choice
std::string Space::chooseFromItems() {
  if (items.size() == 0) {
    std::cout << "\nThere are no items in " << name << ".\n";
    return "";
  } else {
    std::string prompt = "\nChoose from items in " + name + ": \n";
    for (unsigned int i = 0; i < items.size(); i++) {
      prompt += std::to_string(i+1) + ". " + items[i] + "\n";
    }
    int choice = getInt(prompt, 1, items.size());
    return items[choice-1];
  }
}

