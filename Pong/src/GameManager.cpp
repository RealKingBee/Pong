#include "GameManager.h"
#include "Ball.h"

//Default constructor
GameManager::GameManager()
{
	this->leftPaddle = new Paddle({ 20, 180 }, 10, 100, RED);
	this->rightPaddle = new Paddle({ 770, 180 }, 10, 100, BLUE);
	this->ball = new Ball();
	this->inMenu = true;
	this->isPaused = false;
	this->isGameOver = false;
	this->shouldExit = false;
}

//Destructor for new objects
GameManager::~GameManager()
{
	delete ball;
	delete leftPaddle;
	delete rightPaddle;
}

//Game loop plus game state selection
void GameManager::GameRun()
{
	//Paddle leftPaddle({ 20, 100 }, 10, 100, RED);
	//Paddle rightPaddle({ 770, 100 }, 10, 100, BLUE);

	while (!WindowShouldClose())
	{
		//Menu access
		if (inMenu == true)
		{
			MainMenu();
		}

		//Pause menu access via input
		if (IsKeyPressed(KEY_P))
		{
			isPaused = true;
			Pause();
		}

		//Game over access and trigger
		if (isGameOver == true)
		{
			GameOver();
		}
		if (ball->playerScore1 == 10 || ball->playerScore2 == 10)
		{
			isGameOver = true;
		}

		BeginDrawing();

		ClearBackground(BLACK);

		//Instanciates paddles and ball main functions
		leftPaddle->Move(KEY_W, KEY_S);
		rightPaddle->Move(KEY_UP, KEY_DOWN);
		ball->Update(*leftPaddle, *rightPaddle);

		//Draws the game objects
		DrawText("Press P to Pause", GetScreenWidth() - 95, GetScreenHeight() - 12, 2, WHITE);
		leftPaddle->Draw();
		rightPaddle->Draw();
		ball->Draw();

		EndDrawing();
	}
	CloseWindow();
}

//Pause the game to select menu options
void GameManager::Pause()
{
	while (isPaused == true)
	{
		ClearBackground(BLACK);
		BeginDrawing();

		//Drawn text for menu options
		DrawText("PAUSED", GetScreenWidth() / 6, GetScreenHeight() / 4, 50, WHITE);

		DrawTextEx(GetFontDefault(), "-SPACE- ", { (float)GetScreenWidth() / 6, (float)GetScreenHeight() / 2 }, 25, 5, WHITE);
		DrawTextEx(GetFontDefault(), "RESUME", { (float)GetScreenWidth() / 2.5f, (float)GetScreenHeight() / 2 }, 25, 5, RED);

		DrawTextEx(GetFontDefault(), "-R- ", { (float)GetScreenWidth() / 6, (float)GetScreenHeight() / 2 + 30 }, 25, 5, WHITE);
		DrawTextEx(GetFontDefault(), "RESTART", { (float)GetScreenWidth() / 2.5f, (float)GetScreenHeight() / 2 + 30 }, 25, 5, RED);

		DrawTextEx(GetFontDefault(), "-ESC- ", { (float)GetScreenWidth() / 6, (float)GetScreenHeight() / 2 + 60 }, 25, 5, WHITE);
		DrawTextEx(GetFontDefault(), "QUIT", { (float)GetScreenWidth() / 2.5f, (float)GetScreenHeight() / 2 + 60 }, 25, 5, RED);

		//Resume
		if (IsKeyPressed(KEY_SPACE))
		{
			isPaused = false;
		}

		//Restart
		if (IsKeyPressed(KEY_R))
		{
			isPaused = false;
			ResetGame();
		}

		// Quit
		if (IsKeyPressed(KEY_ESCAPE))
		{
			isPaused = false;
		}

		EndDrawing();
	}
}
//Draws main menu and asks to start the game with spacebar press
void GameManager::MainMenu()
{
	while (inMenu == true)
	{
		ClearBackground(BLACK);
		BeginDrawing();

		DrawText("BRANDON ANGELL C++ PONG ", GetScreenWidth() / 2 - 380, GetScreenHeight() / 2 - 200, 30, RED);
		DrawText("MAIN MENU", GetScreenWidth() / 2 - 380, GetScreenHeight() / 2 - 50, 50, WHITE);
		DrawText("Press SPACE to PLAY", GetScreenWidth() / 2 - 380, GetScreenHeight() / 2 + 50, 25, WHITE);

		if (IsKeyPressed(KEY_SPACE))
		{
			inMenu = false;
		}
		EndDrawing();
	}
}

//Reset game features for a fresh play
void GameManager::ResetGame()
{
	ball->playerScore1 = 0;
	ball->playerScore2 = 0;
	leftPaddle->position.y = 180;
	rightPaddle->position.y = 180;
	ball->ResetBall();
}

//Game over screen that displays and calculates the winner
void GameManager::GameOver()
{
	while (isGameOver == true)
	{
		ClearBackground(BLACK);
		BeginDrawing();

		//Initializes game over screen depending on outcome of the game
		if (ball->playerScore1 >= 10)
		{
			DrawText("GAME OVER", GetScreenWidth() / 6, GetScreenHeight() / 2.5, 75, RED);
			DrawText("Player 1 Wins", GetScreenWidth() / 6, (GetScreenHeight() / 3) / 2, 35, RED);
			DrawText("ENTER to MAIN MENU", GetScreenWidth() / 6, (GetScreenHeight() + 200) / 2, 35, WHITE);
		}
		else
		{
			DrawText("GAME OVER", GetScreenWidth() / 6, GetScreenHeight() / 2.5, 75, BLUE);
			DrawText("Player 2 Wins", GetScreenWidth() / 6, (GetScreenHeight() / 3) / 2, 35, BLUE);
			DrawText("ENTER to MAIN MENU", GetScreenWidth() / 6, (GetScreenHeight() + 200) / 2, 35, WHITE);
		}

		//Enter button resets the game and returns to main menu
		if (IsKeyPressed(KEY_ENTER))
		{
			ResetGame();
			isGameOver = false;
			inMenu = true;
			MainMenu();
		}
		EndDrawing();
	}
}

