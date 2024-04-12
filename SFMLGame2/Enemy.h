#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Enemy
{
public:
	Enemy(sf::RenderTarget* WindowTarget);
	void EnemyRender(sf::RenderTarget* WindowTarget);
	void EnemyUpdate();
	sf::FloatRect GetBounds();


private:
	sf::CircleShape EnemyShape;
	float MovementSpeed;

	void InitEnemyShape(sf::RenderTarget* WindowTarget);
};

