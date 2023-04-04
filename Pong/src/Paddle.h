#pragma once
#include <raylib.h>

class Paddle
{
public:
	Paddle(Vector2 position, float width, float height, Color color);
	void Move(int up, int down);
	void Draw();
	Vector2 position;
	float width;
	float height;


private:
	Color color;
	float speed;
	int up;
	int down;

protected:


};



