#include "GameManager.h"
#include "Ball.h"

GameManager::GameManager()
{

}

void GameManager::Pause()
{

}

void GameManager::Reset()
{

}

void GameManager::GameOver()
{

}

void GameManager::Run()
{
	Ball ball;
	Paddle leftPaddle({ 20, 100 }, 10, 100, WHITE);
	Paddle rightPaddle({ 770, 100 }, 10, 100, WHITE);

	while (!WindowShouldClose())
	{
		ClearBackground(BLACK);
		BeginDrawing();

		//Updates paddles and ball movement
		leftPaddle.Move(KEY_W, KEY_S);
		rightPaddle.Move(KEY_UP, KEY_DOWN);
		ball.Update(leftPaddle, rightPaddle);

		//Draws the game objects
		leftPaddle.Draw();
		rightPaddle.Draw();
		ball.Draw();
		EndDrawing();
	}
	CloseWindow();
}
