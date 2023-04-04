#pragma once
#include <raylib.h>
class Paddle
{
public:
	Paddle(Vector2 position, float width, float height, Color color);
	void Move();
	void Draw();


private:
	Vector2 position;
	float speed;
	Color color;
	int width;
	int height;

protected:


};



