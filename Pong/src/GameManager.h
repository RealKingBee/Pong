#pragma once
#include "Ball.h"
class GameManager
{
public:
	Ball* ball;
	GameManager();
	~GameManager();
	void Pause();
	void GameOver();
	void GameRun();
	void MainMenu();
	void ResetGame();
	Paddle* leftPaddle;
	Paddle* rightPaddle;
	bool inMenu;
	bool isPaused;
	bool isGameOver;
	bool shouldExit;

private:


protected:


};