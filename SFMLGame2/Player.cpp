#include "Player.h"

Player::Player()
{
	MovementSpeed = 2.f;
	Health = 10;
	Points = 0;
	PlayerShape.setSize(sf::Vector2f(20.f, 20.f));
	PlayerShape.setFillColor(sf::Color::Blue);
	PlayerShape.setPosition(400, 300);
}

void Player::PlayerRender(sf::RenderTarget* WindowTarget)
{
	WindowTarget->draw(PlayerShape);
}

void Player::PlayerUpdate(sf::RenderTarget* WindowTarget)
{
	PlayerMovement();

	WindowCollision(WindowTarget);
}

void Player::TakeDamage(int dmg)
{
	Health -= dmg;
}

int Player::GetHealth()
{
	return Health;
}

int Player::GetPoints()
{
	return Points;
}

void Player::AddPoint()
{
	Points += 1;
}

sf::FloatRect Player::GetBounds()
{
	return PlayerShape.getGlobalBounds();
}

void Player::PlayerMovement()
{
	//Movement Left & Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		PlayerShape.move(-MovementSpeed, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		PlayerShape.move(MovementSpeed, 0.0f);
	}

	//Movement Up & Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		PlayerShape.move(0.f, -MovementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		PlayerShape.move(0.f, MovementSpeed);
	}

}

void Player::WindowCollision(sf::RenderTarget* WindowTarget)
{
	//Left & Right Window Collision
	if (PlayerShape.getGlobalBounds().left <= 0.f)
	{
		PlayerShape.setPosition(0.f, PlayerShape.getGlobalBounds().top);
	}
	else if (PlayerShape.getGlobalBounds().left + PlayerShape.getSize().x >= WindowTarget->getSize().x)
	{
		PlayerShape.setPosition(WindowTarget->getSize().x - PlayerShape.getSize().x, PlayerShape.getGlobalBounds().top);
	}

	if (PlayerShape.getGlobalBounds().top <= 0.f)
	{
		PlayerShape.setPosition(PlayerShape.getGlobalBounds().left, 0);
	}
	else if (PlayerShape.getGlobalBounds().top + PlayerShape.getSize().y >= WindowTarget->getSize().y)
	{
		PlayerShape.setPosition(PlayerShape.getGlobalBounds().left, WindowTarget->getSize().y - PlayerShape.getSize().y);
	}
}
