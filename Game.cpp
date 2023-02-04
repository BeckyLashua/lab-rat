/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This is the implementation file for the Game 
 * class which runs the entire game simulation for the Lab
 * Rat Escape. It contains a simulate() method which runs the 
 * game from start to exit, which calls several other helper
 * methods that display options to the user, updates the rat
 * pack that carries the items, changes spaces, updates the
 * visited status of every space visited. It also has get and
 * set methods for all of it's data member variables. 
***************************************************************/
#include "Game.hpp"


// This is the constructor. It initializes all of the starting 
//variables and Space pointers. 
Game::Game() {
  cage = new Cage();
  labFloor = new LabFloor();
  closet = new Closet();
  vent = new Vent();
  breakRoom = new BreakRoom();
  office = new Office();
  outside = new Outside();

  hasPack = false;
  status = "inside";
}


// This is the class destructor. It frees the memory used by the 
// Space pointers. 
Game::~Game() {
  delete cage;
  delete labFloor;
  delete closet;
  delete vent;
  delete breakRoom;
  delete office;
  delete outside;
}


// GET AND SET METHODS FOR DATA MEMBER VARIABLES
std::vector<std::string> Game::getRatPack() {
  return this->ratPack;
}

int Game::displayCageMenu() {
  return 0;
}

int Game::displayLabMenu() {
  return 0;
}

int Game::displayUtilityMenu() {
  return 0;
}

int Game::displayVentMenu() {
  return 0;
}

int Game::displayBreakRoomMenu() {
  return 0;
}

int Game::displayOfficeMenu() {
  return 0;
}


// This displays the introductory message and rules to the player.
void Game::displayIntro() {
  // Display intro and aim of game to user
  std::cout << "\nWelcome to Lab Rat Escape\u2122!\n";
  std::cout << "\nYou are a lab rat who has been trapped in a labratory room cage!\n"
            << "But today is your lucky day.\n"
            << "It looks like the lab assistant, silly Ivan,\n"
            << "drank too much last night\n"
            << "and he just fell asleep at his desk.\n"
            << "And silly Ivan accidentally left the cage door open!!\n"
            << "Hurry. This is your chance to finally escape!!\n"
            << "\nYour goal is to make it outside of the labratory building\n"
            << "before Ivan wakes up from his nap!\n"
            << "And remember, every time you change spaces you lose time,\n"
            << "so dont backtrack too often.\n"
            << "You also lose time when you have to redo any attempts at challenges.\n"
            << "So with all of that in mind, let's go!\n";
}



// This method sets up the entire game by pointing each of the
// space objects' directional pointers at the apt spaces (or NULL)
void Game::setUpSpace() {
  this->currentLocation = this->cage;

  this->cage->setBottom(this->labFloor);

  this->labFloor->setTop(this->cage);
  this->labFloor->setRight(this->closet);

  this->closet->setLeft(this->labFloor); 
  this->closet->setTop(this->vent);
  
  this->vent->setBottom(this->closet);
  this->vent->setLeft(this->breakRoom); 
  this->vent->setRight(this->office);  

  this->breakRoom->setRight(this->vent); 

  this->office->setLeft(this->vent);
  this->office->setRight(this->outside);
}


// This method asks the user if they would like to take the rat pack
// from the cage. It gives a different message depending on if it
// is the start of the game or a repeated visit to the cage.
void Game::retrieveRatPack() {
  // If cage is being revisited..
  if (!cage->getVisited()) {
    std::cout << "\nYour cagemate has offered you a rat pack made out of a sleeping canopy.\n"
              << "It can only fit 2 items at a time (You are a tiny rat, after all!).\n";
  } else {
    std::cout << "\nYou have made it back to the rat cage.\n";
  }

  // Asks user if they would like to take rat pack 
  std::string sec1 = "\nWould you like to take the rat pack?\n";
  std::string sec2 = "1. Sure! Thanks, rattie brosiff.\n";
  std::string sec3 = "2. Nah, I'm good. I'm too cool to carry around a rat pack.\n";
  std::string prompt = sec1 + sec2 + sec3;
  
  // If they pick it up now, they will have the pack to carry items
  // If not, they might need to come back later. 
  int choice = getInt(prompt,1,2);
  if (choice == 1) {
    hasPack = true;
  }  
}


// This method displays whatever is inside the rat pack, if anything.
void Game::displayPack() {
  if (!hasPack) {
    std::cout << "Oh no! You don't have a rat pack.\nYou will need to go back to the cage and get it if you want to carry items.\n";
  } else {
    std::cout << "\nInventory in your rat pack: \n";
    // First checks if rat pack is empty
    if (ratPack.size() == 0) {
      std::cout << "Your rat pack is empty.\n";
    } else {
      for (unsigned int i = 0; i < ratPack.size(); i++) {
        std::cout << ratPack[i] << std::endl;
      }
    }
  }
}


// This method chooses an item from the pack and returns it
int Game::chooseFromPack() {
  if (!hasPack) {
    std::cout << "Oh no! You don't have a rat pack.\nYou will need to go back to the cage and get it if you want to carry items.\n";
    return -1;
  } else {
    std::string prompt = "\nChoose from pack: \n";
    for (unsigned int i = 0; i < ratPack.size(); i++) {
      prompt += std::to_string(i+1) + ". " + ratPack[i] + "\n";
    }
    int choice = getInt(prompt, 1, ratPack.size());
    return choice;
  }
}


// This method removes an item form the rat pack
void Game::removeFromPack() {
  if (!hasPack) {
    std::cout << "Oh no! You don't have a rat pack.\nYou will need to go back to the cage and get it if you want to carry items.\n";
  } else if (ratPack.size() == 0) {
    std::cout << "\nYour rat pack is empty.\nThere is nothing to remove.\n";
  } else {
    int item = chooseFromPack(); 
    std::string itemName = ratPack[item-1];
    currentLocation->addItem(itemName); 
    std::cout << "You have removed your " << itemName << " from your pack and left it in the " << currentLocation->getName() << ".\n";
    ratPack.erase(ratPack.begin() + (item-1));
  }
}


// This method adds an item to the rat pack
void Game::addToPack(std::string item) {
  if (!hasPack) {
    std::cout << "Oh no! You don't have a rat pack.\nYou will need to go back to the cage and get it if you want to carry items.\n";
  } else if (ratPack.size() >= 2) {
    std::cout << "\nYou can't add anything to your rat pack.\n"
              << "Your rat pack can only carry 2 items at a time.\n"
              << "Remove an item if you would like to add a new item.\n";
  } else {
    ratPack.push_back(item);
    std::cout << "\n" << item << " has been added to your rat pack.\n";
    currentLocation->removeItem(item);
    currentLocation->displayItems();
  }
}


// This item picks up an item if the player has the rat pack
// If the rat pack is full, a message is displayed. 
void Game::pickUpItem() {
  if (!hasPack) {
    std::cout << "You can't pick up any items if you dont have a rat pack!\n"
              <<"You will need to go back to the cage and get it if you want to carry items.\n";
  }
  if (currentLocation->getItems().size() == 0) {
    std::cout << "\nThere are no items in the " << currentLocation->getName() << " to pick up.\n";
  } else {
    std::string item = currentLocation->chooseFromItems();
    if (item != "") {
      addToPack(item);
    }
  }
}


// This method changes the location of the character. 
void Game::changeSpace() {
  // Chooses which space depending on what is available. 
  std::string prompt = "\nWhich space would you like to go to?\n";
  std::vector<std::string> options = currentLocation->displayLocation();
  int choice = getInt(prompt, 1, options.size());
  std::string location = options[choice-1];
  std::cout << "\nYour current location: " << location << std::endl;
  
  // Updates currentLocation to that space
  if (location == "cage") {
    currentLocation = cage;
  } else if (location == "labFloor") {
    currentLocation = labFloor;
  } else if (location == "closet") {
    currentLocation = closet;
  } else if (location == "vent") {
    currentLocation = vent;
  } else if (location == "breakRoom") {
    currentLocation = breakRoom;
  } else if (location == "office") {
    currentLocation = office;
  } else if (location == "outside") {
    currentLocation = outside;
  }
}


// This method displays the main menu for the user and 
// returns the users choice
int Game::mainMenu() {
  // Menu for items
  std::string sec1 = "\nWhat would you like to do next?\n"; 
  std::string sec2 = "1. Remove something from rat pack.\n";
  std::string sec3 = "2. Pick up item.\n";
  std::string sec4 = "3. Display inventory.\n";
  std::string sec5 = "4. Move on to next space.\n";
  std::string prompt = sec1 + sec2 + sec3 + sec4 + sec5;
  int choice = getInt(prompt, 1, 4);
  return choice;
}


// This method simulates the entire game from start to exit
void Game::simulate() {
  setUpSpace();

  displayIntro();
  
  int steps = 0;
  int maxSteps = 8;
  while (currentLocation != outside) {
    // Performs special action for space only when first visited
    if (!currentLocation->getVisited()) { 
      if (currentLocation->getName() == "cage") {
        retrieveRatPack();
      }
      int addedSteps;
      if (hasPack) {
        addedSteps = currentLocation->specialAction(ratPack);  
      } else { // In case player didn't take rat pack
        std::vector<std::string> emptyPack; 
        addedSteps = currentLocation->specialAction(emptyPack);
      }
      // Adds steps from redoing challenges to step count
      if (addedSteps == -1) {
        return;
      } else {
        steps += addedSteps;
      }
    } 
   
    // Covers the case of going back to get rat pack
    if (currentLocation->getVisited() && currentLocation->getName() == "cage") { 
      if (!hasPack) {
        retrieveRatPack();
      }
    } 

    // Now time to pick up items or reorganize iventory
    int choice = mainMenu();
    while (choice != 4) {
      if (choice == 1) {
        removeFromPack();
      } else if (choice == 2) {
        pickUpItem();
      } else if (choice == 3) {
        displayPack();
      }
      choice = mainMenu();
    }

    // Once player enters 4 for changing space
    // Updates space and steps
    currentLocation->setVisited(true);
    changeSpace();
    if (steps > maxSteps) {
      std::cout << "\nOh no! Ivan woke up from his nap!\n"
                << "You took too long to get out.\n"
                << "You've been caught!\nGAME OVER.\n";
      return;
    }
    steps++;
    std::cout << "Steps taken so far: " << steps << std::endl;
  } 
  // Once outside, game is won! 
  outside->specialAction(ratPack); 
}