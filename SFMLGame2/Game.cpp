#include "Game.h"
#include <iostream>
#include <sstream>

Game::Game()
{
	InitWindow();
	InitFont();
	InitText();
	MaxSpawnTime = 10.f;
	SpawnTime = MaxSpawnTime;
	MaxEnemies = 10;
	Time = 0.1f;
	BoolEndGame = false;
}

Game::~Game()
{
	delete window;
}

const bool Game::IsRunning()
{
	return window->isOpen();
}

void Game::GameRender()
{
	window->clear();

	player.PlayerRender(window);
	RenderHealth();

	for (auto i : Enemies)
	{
		i.EnemyRender(window);
	}

	if (BoolEndGame == true)
	{
		window->draw(EndGameText);
	}

	window->display();
}

void Game::GameUpdate()
{
	PollEvents();

	if (BoolEndGame == false)
	{
		player.PlayerUpdate(window);
		SpawnEnemies();

		for (auto& i : Enemies)
		{
			i.EnemyUpdate();
		}

		DeleteEnemies();
		EndGame();
		UpdateHealth();
	}
}

void Game::SpawnEnemies()
{
	if (SpawnTime < MaxSpawnTime)
	{
		SpawnTime += Time;
		ExtentEnemies += 0.1f;
		std::cout << Time << std::endl;
		if (ExtentEnemies > 70.f)
		{
			Time += 0.1f;
			ExtentEnemies = 0;
			MaxEnemies += 1;
		}
	}
	else
	{
		if (Enemies.size() < MaxEnemies)
		{
			Enemies.push_back(Enemy(window));
			SpawnTime = 0.f;
		}
	}
}

void Game::DeleteEnemies()
{
	for (int i = 0; i < Enemies.size(); i++)
	{
		if (Enemies[i].GetBounds().top >= window->getSize().y)
		{
			Enemies.erase(Enemies.begin() + i);
			player.AddPoint();
		}
		else if (player.GetBounds().intersects(Enemies[i].GetBounds()))
		{
			Enemies.erase(Enemies.begin() + i);
			player.TakeDamage(1);
		}
	}
}

void Game::EndGame()
{
	if (player.GetHealth() <= 0)
	{
		BoolEndGame = true;
	}
}

void Game::UpdateHealth()
{
	std::stringstream ss;

	ss << "Health: " << player.GetHealth() << "/10" << std::endl;
	ss << "Points: " << player.GetPoints() << std::endl;

	HealthText.setString(ss.str());
}

void Game::RenderHealth()
{
	window->draw(HealthText);
}

void Game::PollEvents()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				window->close();
			}
			break;
		}
	}
}

void Game::InitWindow()
{
	videoMode = sf::VideoMode(800, 600);
	window = new sf::RenderWindow(videoMode, "Game 2");
	window->setFramerateLimit(144);
}

void Game::InitFont()
{
	if (!TextFont.loadFromFile("Font/Minecraft.ttf"))
	{
		std::cout << "Fail to load font!" << std::endl;
	}
}

void Game::InitText()
{
	HealthText.setFont(TextFont);
	HealthText.setCharacterSize(20);
	HealthText.setFillColor(sf::Color::White);

	EndGameText.setFont(TextFont);
	EndGameText.setCharacterSize(48);
	EndGameText.setFillColor(sf::Color::Red);
	EndGameText.setOutlineColor(sf::Color::White);
	EndGameText.setOutlineThickness(1.f);
	EndGameText.setPosition(300, 100);
	EndGameText.setString("You Lost!");
}
