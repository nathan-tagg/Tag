#ifndef BULLET_H
#define BULLET_H

#include "uiDraw.h"
#include "point.h"
#include "velocity.h"

#include <iostream>
#include <math.h>


using namespace std;

class Bullet
{
private:
	bool alive;
	short life;
	short rotation;
	Point point;
	Velocity velocity;
public:
	Bullet()  {};
	~Bullet() {};

	void fire(Point pt, short direction)
	{
		point = pt;
		alive = true;
		rotation = -direction + 90;
		velocity.setDX(cos(0.0174533 * (-direction + 90)) * 25); 
		velocity.setDY(sin(0.0174533 * (-direction + 90)) * 25);
		life =  30;
	}

	void advance() 
	{ 
		point.addX(velocity.getDX()); 
		point.addY(velocity.getDY());
		if (point.getX() > 650 || point.getX() < -650)
			wrapSides();
		if (point.getY() > 400 || point.getY() < -400)
			wrapUpDown();
		life--;
		if (life <= 0)
			kill();
		if (alive)
			draw();
	};

	void draw() 
	{ 
		drawPolygon(point, 5, 2, rotation);
	};

	void kill() 
	{ 
	    alive = false; 
    };

	void wrapSides()     { point.setX(-point.getX()); }
	void wrapUpDown()    { point.setY(-point.getY()); }
	Point getPoint()     { return point;              }
	short getLife()      { return life;				  }
	bool isAlive() { return alive; };
};
#endif
