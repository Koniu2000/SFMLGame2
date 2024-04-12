#include "Enemy.h"

Enemy::Enemy(sf::RenderTarget* WindowTarget)
{
	InitEnemyShape(WindowTarget);
}

void Enemy::EnemyRender(sf::RenderTarget* WindowTarget)
{
	WindowTarget->draw(EnemyShape);
}

void Enemy::EnemyUpdate()
{
	EnemyShape.move(0.f, MovementSpeed);
}

sf::FloatRect Enemy::GetBounds()
{
	return EnemyShape.getGlobalBounds();
}

void Enemy::InitEnemyShape(sf::RenderTarget* WindowTarget)
{
	EnemyShape.setRadius(static_cast<float>(rand() % 80 + 10));
	EnemyShape.setFillColor(sf::Color::Yellow);
	MovementSpeed = static_cast<float>(rand() % 3 + 1);
	EnemyShape.setPosition(static_cast<float>(rand() % WindowTarget->getSize().x) - EnemyShape.getGlobalBounds().width, 0);
}
