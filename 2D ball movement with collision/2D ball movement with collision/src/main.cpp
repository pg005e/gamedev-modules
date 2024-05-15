#include <SFML/Graphics.hpp>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(500, 500), "My Window", sf::Style::Close, settings);
	window.setFramerateLimit(60);

	sf::CircleShape player(30.f);
	player.setOrigin(30, 30);
	player.setPosition(40, 50);
	player.setFillColor(sf::Color(72, 93, 62));

	sf::CircleShape obstacle(30.f);
	obstacle.setOrigin(30, 30);
	obstacle.setPosition(window.getSize().x - obstacle.getRadius(), 50);
	obstacle.setFillColor(sf::Color(231, 208, 183));

	while (window.isOpen())
	{
		sf::Event myEvent;
		while (window.pollEvent(myEvent))
		{
			if (myEvent.type == sf::Event::Closed)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		static float XOffset = 8;

		float deltaXSquared = player.getPosition().x - obstacle.getPosition().x;
		deltaXSquared *= deltaXSquared;

		float deltaYSquared = player.getPosition().y - obstacle.getPosition().y;
		deltaYSquared *= deltaYSquared;

		float radiusSumSquared = player.getRadius() + obstacle.getRadius();
		radiusSumSquared *= radiusSumSquared;
		
		if (player.getPosition().x >= window.getSize().x - player.getRadius() || player.getPosition().x <= player.getRadius() || deltaXSquared + deltaYSquared <= radiusSumSquared)
		{
			XOffset = -XOffset;
		}

		player.move(XOffset, 0);
		obstacle.move(-XOffset, 0);

		window.clear();
		window.draw(player);
		window.draw(obstacle);
		window.display();
	}
}