#include "Ball.h"


Ball::Ball()
{
	this->xPos = (float)GetScreenWidth() / 2;
	this->yPos = (float)GetScreenHeight() / 2;
	this->moveX = 3;
	this->moveY = 3;
	this->ballRadius = 10;
}

void Ball::Move()
{
	xPos += moveX;
	yPos += moveY;

	if (xPos > GetScreenWidth() - ballRadius)
	{
		moveX = -moveX;
	}

	if (xPos < 0 + ballRadius)
	{
		moveX = -moveX;
	}

	if (yPos > GetScreenHeight() - ballRadius)
	{
		moveY = -moveY;
	}

	if (yPos < 0 + ballRadius)
	{
		moveY = -moveY;
	}




}





