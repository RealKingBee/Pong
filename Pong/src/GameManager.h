#pragma once
class GameManager
{
public:
	GameManager();
	void Pause();
	void Reset();
	void GameOver();
	void GameRun();
	void MainMenu();
	void UpdateScore();

	bool inMenu;
	bool isGameOver;

private:


protected:


};