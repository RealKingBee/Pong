#include "Ball.h"
#include <iostream>


Ball::Ball()
{
	this->xPos = GetScreenWidth() / 2;
	this->yPos = GetScreenHeight() / 2;
	this->moveX = 3;
	this->moveY = 3;
	this->ballRadius = 10;
}

void Ball::Move(Paddle& leftPaddle, Paddle& rightPaddle)
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

	if (CheckCollisionCircleRec({ yPos, xPos }, ballRadius, { leftPaddle.position.x, leftPaddle.position.y, leftPaddle.width, leftPaddle.height }))
	{
		std::cout << "hit" << std::endl;;
		moveX -= 1;
	}

	if (CheckCollisionCircleRec({ yPos, xPos }, ballRadius, { rightPaddle.position.x, rightPaddle.position.y, rightPaddle.width, rightPaddle.height }))
	{
		std::cout << "hit" << std::endl;;
		moveX -= 1;
	}

}

//bool Ball::CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec)
//{
//	std::cout << "hit" << std::endl;;
//}

