#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Player
{
public:
	Player();

	void PlayerRender(sf::RenderTarget* WindowTarget);
	void PlayerUpdate(sf::RenderTarget* WindowTarget);
	void TakeDamage(int dmg);
	void AddPoint();
	int GetHealth();
	int GetPoints();
	sf::FloatRect GetBounds();

private:
	sf::RectangleShape PlayerShape;
	float MovementSpeed;
	int Health;
	int Points;

	void PlayerMovement();
	void WindowCollision(sf::RenderTarget* WindowTarget);
};

