#ifndef CAR_H
#define CAR_H

#include <math.h>

#include "point.h"
#include "velocity.h"

class Car
{
private:
	short steeringWheel;
	Point point;
	Velocity velocity;
	float rotation;
	short color;
	short frozen;
	bool it;
	short tauntTime;

public:
	Car()
	{
		steeringWheel = 0;
		rotation = 0;
		frozen = 0;
		it = false;
		tauntTime = 0;
	}

	void initialize(short x, short y, short z)
	{
		point.setX(x);
		point.setY(z);
		color = z;
	}

	void up()
	{
		if (steeringWheel == -1)
			rotation -= 5;
		if (steeringWheel == 1)
			rotation += 5;
		if (!frozen)
		{
			point.addY(6 * cos(0.0174533 * rotation));
			point.addX(6 * sin(0.0174533 * rotation));
		}
	}
	void down()
	{
		if (steeringWheel == -1)
			rotation += 4;
		if (steeringWheel == 1)
			rotation -= 4;
		if (!frozen)
		{
			point.addY(-3 * cos(0.0174533 * rotation));
			point.addX(-3 * sin(0.0174533 * rotation));
		}
	}
	void left()
	{
		if (!frozen)
			steeringWheel = -1;
	}
	void right()
	{
		if (!frozen)
			steeringWheel = 1;
	}

	void draw()
	{
		if (frozen)
			drawCar(point, rotation, 2);
		else
			drawCar(point, rotation, color);
		if (it)
			drawCircle(point, 7);
		if (tauntTime)
		{
			Point taunt(point.getX() - 40, point.getY() + 35);
			drawText(taunt, "You're it!");
		}

	}

	void advance()
	{
		if (point.getX() > 650 || point.getX() < -650)
			wrapSides();
		if (point.getY() > 400 || point.getY() < -400)
			wrapUpDown();
		draw();
		if (frozen)
			frozen--;
		if (tauntTime)
			tauntTime--;
	}

	void freeze()
	{
		if (!frozen)
			frozen = 360;
	}

	void isIt()
	{
		if (it)
		{
			tauntTime = 60;
		}
		it = !it;
	}

	void align()
	{
		steeringWheel = 0;
	}
	void wrapSides()     { point.setX(-point.getX()); }
	void wrapUpDown()    { point.setY(-point.getY()); }
	Point getPoint()     { return point;              }
	short getDirection() { return rotation;           }

};

#endif