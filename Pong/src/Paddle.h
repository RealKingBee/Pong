#pragma once
#include <raylib.h>

class Paddle
{
public:
	Paddle(Vector2 position, float width, float height, Color color);
	void Move(int up, int down);
	void Draw();
	Rectangle GetRect();
	Vector2 position;
	float width;
	float height;
	Color color;
	float speed;

private:

protected:

};


