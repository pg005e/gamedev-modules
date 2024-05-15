#include "game.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Window", sf::Style::Close, settings);
	window.setFramerateLimit(60);

	sf::CircleShape center(40.f);
	center.setOrigin(40, 40);
	center.setPosition(250, 250);
	center.setFillColor(sf::Color::Red);

	sf::CircleShape player(40.f);
	player.setOrigin(40, 40);
	player.setPosition(40, 40);

	while (window.isOpen())
	{
		sf::Event myEvent;
		while (window.pollEvent(myEvent))
		{
			if (myEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		Update(window, center, player);
		Draw(window, center, player);

	}
}