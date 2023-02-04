/*************************************************************** 
 * Program Name: FINAL PROJECT: Lab Rat Escape!
 * Author: Rebecca Lashua
 * Date: 12/06/2019
 * Description: This program implements a game representing a 
 * lab rat escape out of a labratory building. The object of 
 * the game is to make it outside of the building alive without
 * either getting killed or running out of steps. It containes
 * a Game class that simulates the game itself, an abstract 
 * class called Space that provides overall implementation for 
 * the derived classes, BreakRoom, Cage, Closet, Vent, LabFloor,
 * Office, and Outside. The player is taken through a journey
 * between spaces, as they have to defeat challenges in each 
 * space before they can pick up items or move to the next 
 * space. This program also contains utility files the implement
 * the menu, random number generation, and input validation 
 * functions needed to run the program. 
***************************************************************/
#include <iostream>
#include "Game.hpp"
#include "utility.hpp"

int main() {
  Game game;

  if (playProgram() == 1) {
    do {
      std::cout << std::endl;
      game.simulate();
    } while (playProgram() == 1);
  }

  return 0;
}