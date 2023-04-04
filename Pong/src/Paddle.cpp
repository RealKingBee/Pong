#include "Paddle.h"
#include <Ball.h>


Paddle::Paddle(Vector2 position, float width, float height, Color color)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->width = width;
	this->height = height;
	this->color = color;
	//this->speed = 3;
}


void Paddle::Move()
{

}

void Paddle::Draw()
{
	DrawRectangle(position.x, position.y, width, height, color);
}


