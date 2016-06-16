/*************************************************************
 * File: game.cpp
 * Author: Nathan Tagg
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *************************************************************/

#include "game.h"

#include <list>
#include <iostream>
#include <math.h>

using namespace std;

/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
{
	car.initialize(400, 0, 0);
	carTwo.initialize(-400, 0, 1);
	cooldown = 0;
	cooldownTwo = 0;
	cooldownThree = 0;
	if (random(1, 10) % 2)
		car.isIt();
	else
		carTwo.isIt();
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
}


/****************************************
 * ADVANCE
 ***************************************/
void Game :: advance()
{
	car.advance();
	carTwo.advance();
	for(list<Bullet*> :: iterator it = bullets.begin(); it != bullets.end(); ++it)
	{
		if ((*it)->isAlive())
			(*it)->advance();
		else
		{
			delete * it;
			it = bullets.erase(it);
		}
	}
	for (list<Bullet*> :: iterator it = bullets.begin(); it != bullets.end(); ++it)
    {
    	if ((*it)->getPoint() - car.getPoint() < 15 && (*it)->getLife() < 28)
    		car.freeze();
    	if ((*it)->getPoint() - carTwo.getPoint() < 15 && (*it)->getLife() < 28)
    		carTwo.freeze();
	}
	if (car.getPoint() - carTwo.getPoint() < 30 && !cooldownThree)
	{
		car.isIt();
		carTwo.isIt();
		cooldownThree = 30;
	}
	if (cooldownThree > 0)
	{
		cooldownThree--;
	}


}

 /****************************************
 * HANDLE INPUT
 ***************************************/
 void Game :: handleInput(const Interface & ui)
 {
 	if (ui.isUp())
 		car.up();
 	if (ui.isDown())
 		car.down();
 	if (ui.isRight())
 		car.right();
 	if (ui.isLeft())
 		car.left();
 	if (!ui.isLeft() && !ui.isRight())
 		car.align();
 	 if (ui.isS())
 		carTwo.up();
 	if (ui.isX())
 		carTwo.down();
 	if (ui.isC())
 		carTwo.right();
 	if (ui.isZ())
 		carTwo.left();
 	if (!ui.isZ() && !ui.isC())
 		carTwo.align();

 	if (ui.isSpace() && cooldown <= 0)
 	{
 		Bullet * newBullet = new Bullet;
 		newBullet->fire(car.getPoint(), car.getDirection());
 		bullets.push_back(newBullet);
 		cooldown = 10;
 	}

 	if (ui.isA() && cooldownTwo <= 0)
 	{
		Bullet * newBullet = new Bullet;
 		newBullet->fire(carTwo.getPoint(), carTwo.getDirection());
 		bullets.push_back(newBullet);
 		cooldownTwo = 10;
 	}

 	if (cooldown > 0)
	 	cooldown--;
	if (cooldownTwo > 0)
		cooldownTwo--;
 }









