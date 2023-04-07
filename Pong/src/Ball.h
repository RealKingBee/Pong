#pragma once
#include "raylib.h"
#include "Paddle.h"
class Ball
{
public:
	Ball();
	void Draw();
	void MoveBall();
	void Reset();
	void Update(Paddle& leftPaddle, Paddle& rightPaddle);
	int ballRadius;
	float moveX;
	float moveY;
	float xPos;
	float yPos;
	int playerScore1;
	int playerScore2;
	int checkColl;
	int (*GetScore)(int playerScore);

private:

protected:


};

