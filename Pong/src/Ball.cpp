#include "Ball.h"


Ball::Ball()
{
	this->xPos = (float)GetScreenWidth() / 2;
	this->yPos = (float)GetScreenHeight() / 2;
	this->moveX = 3;
	this->moveY = 3;
}

void Ball::Move()
{
	xPos += moveX;
	yPos += moveY;

	if (xPos > GetScreenWidth())
	{
		moveX = -moveX;
	}

	if (xPos < 0)
	{
		moveX = -moveX;
	}

	if (yPos > GetScreenHeight())
	{
		yPos = GetScreenHeight();
		moveY = -moveY;
	}

	if (yPos < 0)
	{
		yPos = 0;
		moveY = -moveY;
	}




}





