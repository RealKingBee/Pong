#include "GameManager.h"
#include "Ball.h"

GameManager::GameManager()
{
	inMenu = true;
	isGameOver = false;
}

void GameManager::MainMenu()
{
	while (inMenu == true)
	{
		ClearBackground(BLACK);
		DrawText("MAIN MENU", GetScreenWidth() / 6, GetScreenHeight() / 4, 50, WHITE);
		DrawText("Press SPACE to go to game", GetScreenWidth() / 6, GetScreenHeight() / 2, 25, WHITE);
		BeginDrawing();

		if (IsKeyPressed(KEY_SPACE))
		{
			inMenu = false;
		}
		EndDrawing();
	}
}

void GameManager::UpdateScore()
{

}

//Pause the game to select menu options
void GameManager::Pause()
{

}

void GameManager::Reset()
{

}

//Game over screen that displays and calculates the winner
void GameManager::GameOver()
{
	while (isGameOver == true)
	{
		ClearBackground(BLACK);
		BeginDrawing();

		DrawText("GAME OVER", GetScreenWidth() / 6, GetScreenHeight() / 2, 75, RED);

		if (IsKeyPressed(KEY_ENTER))
		{
			isGameOver = false;
		}
		EndDrawing();

	};
	CloseWindow();
}

//Function that contains the whilst playing the game features
void GameManager::GameRun()
{
	Ball ball;
	Paddle leftPaddle({ 20, 100 }, 10, 100, WHITE);
	Paddle rightPaddle({ 770, 100 }, 10, 100, WHITE);

	while (!WindowShouldClose())
	{
		if (inMenu)
		{
			MainMenu();
		}
		if (IsKeyPressed(KEY_P))
		{
			inMenu = true;
		}

		if (isGameOver)
		{
			GameOver();
		}
		if (ball.playerScore1 == 10 || ball.playerScore2 == 10)
		{
			isGameOver = true;
		}

		BeginDrawing();

		ClearBackground(BLACK);

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
