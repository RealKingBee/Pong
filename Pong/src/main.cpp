#include <raylib.h>
#include <iostream>
#include "Ball.h"

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

	// Keep the game running until the window close button or the escape key is pressed 
	while (!WindowShouldClose())
	{
		// Update any variables here before drawing

		// Do all of our drawing in here
		ClearBackground(BLACK);
		BeginDrawing();

		DrawText("Hello James!", 50, 50, 24, BLUE);

		DrawCircle(ball.xPos, ball.yPos, ball.ballRadius, WHITE);
		ball.Move();
		
		DrawFPS(10, 10);
		EndDrawing();
	}

	// Close the window
	CloseWindow();

	return 0;
}