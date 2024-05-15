#pragma once
#include "game.h"

void Update(sf::RenderWindow& window, sf::RectangleShape& player)
{
	float XOffset = 5;
	float YOffset = 5;

	// player movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.move(0, -YOffset);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.move(-XOffset, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player.move(0, YOffset);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.move(XOffset, 0);
	}

	// edge detection
	if (player.getPosition().x >= window.getSize().x)
	{
		player.setPosition(0, player.getPosition().y);
	}
	if (player.getPosition().y >=  window.getSize().y)
	{
		player.setPosition(player.getPosition().x, 0);
	}
	if (player.getPosition().x < 0)
	{
		player.setPosition(window.getSize().x, player.getPosition().y);
	}
	if (player.getPosition().y < 0)
	{
		player.setPosition(player.getPosition().x, window.getSize().y);
	}

	// mouse input for player position reset
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		player.setPosition(250, 250);
	}

}

void Draw(sf::RenderWindow& window, sf::RectangleShape& player)
{
	window.clear();
	window.draw(player);
	window.display();
}