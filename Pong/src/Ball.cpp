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
	this->checkCollCount = 0;
	this->playerScore1 = 0;
	this->playerScore2 = 0;
}

//Draw ball position, size and colour
void Ball::Draw()
{
	DrawCircle(xPos, yPos, ballRadius, YELLOW);
}

//Default ball movement 
void Ball::MoveBall()
{
	xPos += moveX;
	yPos += moveY;
}

//Resets ball after score and determines what direction the ball starts
void Ball::ResetBall()
{
	if (xPos > GetScreenWidth() / 2)
	{
		xPos = GetScreenWidth() / 2;
		yPos = GetScreenHeight() / 2;
		moveX = 3;
		moveY = 3;
		checkCollCount = 0;
	}
	else
	{
		xPos = GetScreenWidth() / 2;
		yPos = GetScreenHeight() / 2;
		moveX = -3;
		moveY = -3;
		checkCollCount = 0;
	}
}

//Moves the ball, checks for collision and updates score
//References the paddle constructor and asks a variable to be assigned to it
//Paddle constructor then has individual parameters
void Ball::Update(Paddle& leftPaddle, Paddle& rightPaddle)
{
	//Movement for ball
	MoveBall();

	//Player score text
	DrawText(TextFormat("%i", playerScore1), GetScreenWidth() / 2 + -20, 5, 20, RED);
	DrawText(TextFormat("%i", playerScore2), GetScreenWidth() / 2 + +15, 5, 20, BLUE);
	DrawRectangle(GetScreenWidth() / 2, 0, 2.5f, 30, WHITE);

	//Collision checks with borders and updates score for screen width collision
	if (xPos > GetScreenWidth() - ballRadius)
	{
		playerScore1 += 1;
		std::cout << playerScore1 << std::endl;

		ResetBall();
	}

	if (xPos < 0 + ballRadius)
	{
		playerScore2 += 1;

		std::cout << playerScore2 << std::endl;

		ResetBall();
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
			checkCollCount += 1;
			if (checkCollCount >= 2)
			{
				moveX += -0.4f;
				checkCollCount = 0;
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
			//Increase speed on the second paddle collision
			checkCollCount += 1;
			moveX *= -1.0f;
			if (checkCollCount >= 2)
			{
				moveX += -0.4f;
				checkCollCount = 0;
				std::cout << "Ball speed increased." << std::endl;
			}
			std::cout << "hit" << std::endl;;
	
		}
	}

}


