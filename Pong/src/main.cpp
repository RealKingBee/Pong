#include <raylib.h>
#include <iostream>
#include "Ball.h"
#include "Paddle.h"

static const int s_ScreenWidth = 800;
static const int s_ScreenHeight = 450;

int main()
{
	// Initialize the window
	InitWindow(s_ScreenWidth, s_ScreenHeight, "Raylib Game Template");

	// Set the game to run at 60 fps
	SetTargetFPS(60);

	//declare new ball
	Ball ball;
	Paddle leftPaddle({ 20, 100 }, 10, 100, WHITE);
	Paddle rightPaddle({ 770, 100 }, 10, 100, WHITE);


	// Keep the game running until the window close button or the escape key is pressed 
	while (!WindowShouldClose())
	{
		// Update any variables here before drawing

		// Do all of our drawing in here
		ClearBackground(BLACK);
		BeginDrawing();

		leftPaddle.Move(KEY_W, KEY_S);
		rightPaddle.Move(KEY_UP, KEY_DOWN);

		leftPaddle.Draw();
		rightPaddle.Draw();

		//ball.CheckCollisionCircleRec({ ball.yPos, ball.xPos }, ball.ballRadius, { 20, 100, 10, 100 });

		DrawCircle(ball.xPos, ball.yPos, ball.ballRadius, WHITE);
		ball.Move(leftPaddle, rightPaddle);

		//if (CheckCollisionCircleRec({ ball.yPos, ball.xPos }, ball.ballRadius, { 20, 100, 10, 100 }))
		//{
		//	std::cout << "hit" << std::endl;;
		//	ball.moveX -= 1;
		//}
		
		DrawFPS(10, 10);
		EndDrawing();
	}

	// Close the window
	CloseWindow();

	return 0;
};