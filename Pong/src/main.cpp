#include <raylib.h>
#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "GameManager.h"

static const int s_ScreenWidth = 800;
static const int s_ScreenHeight = 450;

int main()
{
	// Initialize the window
	InitWindow(s_ScreenWidth, s_ScreenHeight, "Pong");

	// Set the game to run at 60 fps
	SetTargetFPS(60);

	//declare new ball
	//Ball ball;
	//Paddle leftPaddle({ 20, 100 }, 10, 100, WHITE);
	//Paddle rightPaddle({ 770, 100 }, 10, 100, WHITE);
	GameManager gameManager;


	// Keep the game running until the window close button or the escape key is pressed 
	//while (!WindowShouldClose())
	//{
		// Update any variables here before drawing

		// Do all of our drawing in here
		//ClearBackground(BLACK);
		//BeginDrawing();
		gameManager.Run();
		////Updates paddles and ball movement
		//leftPaddle.Move(KEY_W, KEY_S);
		//rightPaddle.Move(KEY_UP, KEY_DOWN);
		//ball.Update(leftPaddle, rightPaddle);
		//
		////Draws the game objects
		//leftPaddle.Draw();
		//rightPaddle.Draw();
		//ball.Draw();

		//ball.CheckCollisionCircleRec({ ball.yPos, ball.xPos }, ball.ballRadius, { 20, 100, 10, 100 });




		//DrawFPS(10, 10);
		//EndDrawing();
	//}

	// Close the window
	//CloseWindow();

	return 0;
};