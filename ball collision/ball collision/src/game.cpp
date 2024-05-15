#pragma once
#include "game.h"


void Update(sf::RenderWindow& window, sf::CircleShape& center,sf::CircleShape& player)
{
	// move the ball
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player.move(0.0f, -4.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player.move(-4.0f, 0.0f);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player.move(0.0f, 4.0f);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player.move(4.0f, 0.0f);

	// collision logic
	float deltaXSquared = player.getPosition().x - center.getPosition().x;
	deltaXSquared *= deltaXSquared;

	float deltaYSquared = player.getPosition().y - center.getPosition().y;
	deltaYSquared *= deltaYSquared;

	float radiusSumSquared = center.getRadius() + player.getRadius();
	radiusSumSquared *= radiusSumSquared;

	if (deltaXSquared + deltaYSquared <= radiusSumSquared)
	{
		std::cout << "Collision detected" << std::endl;
		player.setFillColor(sf::Color::Blue);
	}

}

void Draw(sf::RenderWindow& window, sf::CircleShape& center, sf::CircleShape& player)
{
	window.clear();
	window.draw(center);
	window.draw(player);
	window.display();
}