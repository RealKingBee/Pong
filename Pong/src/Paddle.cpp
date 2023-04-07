#include "Paddle.h"
#include <Ball.h>

//Custom constructor for Paddle
Paddle::Paddle(Vector2 position, float width, float height, Color color)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->width = width;
	this->height = height;
	this->color = color;
	this->speed = 5;
}

//Movement for paddles via key inputs
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

//Draws the paddle
void Paddle::Draw()
{
	DrawRectangleRec(GetRect(), color);
}

//Rectangle struct that is put into the paddle draw function. This sets the size of the paddle
Rectangle Paddle::GetRect()
{
	return Rectangle{ position.x, position.y, width, height };
}


