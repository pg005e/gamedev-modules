#include "game.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "My Window", sf::Style::Close);
	window.setFramerateLimit(60);

	sf::RectangleShape player(sf::Vector2f(30, 30));

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

		Update(window, player);
		Draw(window, player);

	}
}