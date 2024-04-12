#pragma once

#include <vector>
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	Game();
	~Game();
	const bool IsRunning();
	void GameRender();
	void GameUpdate();
	void SpawnEnemies();
	void DeleteEnemies();
	void EndGame();
	void UpdateHealth();
	void RenderHealth();

private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	sf::Text HealthText;
	sf::Text EndGameText;
	sf::Font TextFont;

	Player player;
	std::vector<Enemy> Enemies;
	float MaxSpawnTime;
	float SpawnTime;
	float Time;
	int MaxEnemies;
	float ExtentEnemies;
	bool BoolEndGame;

	void PollEvents();
	void InitWindow();
	void InitFont();
	void InitText();
};

