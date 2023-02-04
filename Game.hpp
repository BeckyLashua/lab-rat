/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the specification file for the Game 
 * class which runs the entire game simulation for the Lab
 * Rat Escape. It contains a simulate() method which runs the 
 * game from start to exit, which calls several other helper
 * methods that display options to the user, updates the rat
 * pack that carries the items, changes spaces, updates the
 * visited status of every space visited. It also has get and
 * set methods for all of it's data member variables. 
***************************************************************/
#ifndef GAME
#define GAME
#include <string>
#include <iostream>
#include "Space.hpp"
#include "Cage.hpp"
#include "Closet.hpp"
#include "BreakRoom.hpp"
#include "LabFloor.hpp"
#include "Office.hpp"
#include "Vent.hpp"
#include "Outside.hpp"
#include "utility.hpp"


class Game {
  private:
    Space *cage;
    Space *labFloor;
    Space *closet;
    Space *vent;
    Space *breakRoom;
    Space *office;
    Space *outside;
    Space *currentLocation;
    std::vector<std::string> ratPack;
    bool hasPack;
    std::string status;
    
  public:
    Game(); // Constructor
    ~Game(); // Destructor
    std::vector<std::string> getRatPack();
    int displayCageMenu();
    int displayLabMenu();
    int displayUtilityMenu();
    int displayVentMenu();
    int displayBreakRoomMenu();
    int displayOfficeMenu(); 
    void displayIntro();
    void setUpSpace();
    void retrieveRatPack();
    void displayPack();
    int chooseFromPack();
    void removeFromPack();
    void addToPack(std::string);
    void changeSpace();
    void simulate(); 
    void pickUpItem();
    int mainMenu();
};

#endif