/*************************************************************
 * Header File: GAME
 * Author: Nathan Tagg
 *************************************************************/

#ifndef GAME_H
#define GAME_H

#include <list>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "car.h"
#include "bullet.h"

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   /*********************************************
    * Constructor / Destructor
    * Initializes / Terminates the game
    *********************************************/
   Game(Point tl, Point br);
   ~Game();
   
   // Advance
   void advance();

   // Handle Input
   void handleInput(const Interface & ui);

private:
   Point topLeft;
   Point bottomRight;
   Car car;
   short cooldown;
   Car carTwo;
   short cooldownTwo;
   std::list<Bullet*> bullets;
   short cooldownThree;
};

#endif /* GAME_H */
