#include "Paddle.h"
#include <Ball.h>


Paddle::Paddle(Vector2 position, float width, float height, Color color)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->width = width;
	this->height = height;
	this->color = color;
	this->speed = 5;
}

void Paddle::Move(int up, int down)
{
	if (IsKeyDown(up) && position.y > 0)
	{
		position.y -= speed;
	}

	if (IsKeyDown(down) && position.y < GetScreenHeight() - height)
	{
		position.y += speed;
	}

}

void Paddle::Draw()
{
	 DrawRectangle(position.x, position.y, width, height, color);
}


