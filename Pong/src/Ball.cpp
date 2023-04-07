#include "Ball.h"
#include <iostream>

//Default constructor
Ball::Ball()
{
	this->xPos = GetScreenWidth() / 2;
	this->yPos = GetScreenHeight() / 2;
	this->moveX = 3;
	this->moveY = 3;
	this->ballRadius = 5;
	playerScore1 = 0;
	playerScore2 = 0;
	checkColl = 0;
}

//Draw ball position, siz and colour
void Ball::Draw()
{
	DrawCircle(xPos, yPos, ballRadius, WHITE);
}

//Resets ball after score and determines what direction the ball starts
void Ball::Reset()
{
	if (xPos > GetScreenWidth() / 2)
	{
		xPos = GetScreenWidth() / 2;
		yPos = GetScreenHeight() / 2;
		moveX = 3;
		moveY = 3;
		checkColl = 0;
	}
	else
	{
		xPos = GetScreenWidth() / 2;
		yPos = GetScreenHeight() / 2;
		moveX = -3;
		moveY = -3;
		checkColl = 0;
	}
}

//Moves the ball, checks for collision and updates score
void Ball::Update(Paddle& leftPaddle, Paddle& rightPaddle)
{
	//Movement for ball
	yPos += moveY;
	xPos += moveX;

	//Player score text
	DrawText(TextFormat("Score = %i", playerScore1), 10, 10, 20, RED);
	DrawText(TextFormat("Score = %i", playerScore2), 670, 10, 20, BLUE);

	//Collision checks with borders and updates score for screen width collision
	if (xPos > GetScreenWidth() - ballRadius)
	{
		playerScore1 += 1;

		std::cout << playerScore1 << std::endl;

		Reset();
	}

	if (xPos < 0 + ballRadius)
	{
		playerScore2 += 1;

		std::cout << playerScore2 << std::endl;

		Reset();
	}

	if (yPos > GetScreenHeight() - ballRadius)
	{
		moveY = -moveY;
	}

	if (yPos < 0 + ballRadius)
	{
		moveY = -moveY;
	}

	//Collision checks for ball and paddle
	if (CheckCollisionCircleRec({ xPos, yPos }, ballRadius, leftPaddle.GetRect()))
	{

		if (moveX < 0)
		{
			//Increase in speed on the second paddle collision
			checkColl += 1;
			if (checkColl >= 2)
			{
				moveX += -0.4f;
				checkColl = 0;
				std::cout << "Ball speed increased." << std::endl;
			}
			moveX *= -1.0f;
			std::cout << "hit" << std::endl;;
		}
	}

	if (CheckCollisionCircleRec({ xPos, yPos }, ballRadius, rightPaddle.GetRect()))
	{
		if (moveX > 0)
		{
			//Increase in speed on the second paddle collision
			checkColl += 1;
			moveX *= -1.0f;
			if (checkColl >= 2)
			{
				moveX += -0.4f;
				checkColl = 0;
				std::cout << "Ball speed increased." << std::endl;
			}
			std::cout << "hit" << std::endl;;

		}
	}

}

