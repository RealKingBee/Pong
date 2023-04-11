#pragma once
#include "Ball.h"
class GameManager
{
public:
	Ball* ball;
	Paddle* leftPaddle;
	Paddle* rightPaddle;
	GameManager();
	~GameManager();
	void Pause();
	void GameOver();
	void GameRun();
	void MainMenu();
	void ResetGame();
	bool inMenu;
	bool isPaused;
	bool isGameOver;

private:


protected:


};