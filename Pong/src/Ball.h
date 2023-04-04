#pragma once
#include "raylib.h"
#include "Paddle.h"
class Ball
{
public:
	Ball();
	void Move(Paddle& leftPaddle, Paddle& rightPaddle);
	//bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);
	int ballRadius;
	int moveX;
	int moveY;
	float xPos;
	float yPos;

private:

protected:


};



