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
	GameManager gameManager;
	gameManager.inMenu = true;
	gameManager.isGameOver = false;

	gameManager.MainMenu();
	gameManager.GameRun();
};