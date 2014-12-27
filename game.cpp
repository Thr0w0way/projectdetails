#include"game.hpp"

void Game::setup()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Untitled");
	window->setFramerateLimit(60);

	clock = new sf::Clock();
}
void Game::loop()
{
	int dt = clock->restart().asMilliseconds();

	while (window->isOpen())
	{
		update(dt);
		draw();
		sf::sleep(sf::milliseconds(1));
	}
}
void Game::update(int deltaTime)
{
	// parse events
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				if ((event.key.code == sf::Keyboard::Escape) || (event.key.code == sf::Keyboard::F4 && event.key.alt))
					window->close();
				break;
			case sf::Event::Closed:
				window->close();
				break;
		}
	}
	//
}

void Game::draw()
{
	window->clear();

	//

	window->display();
}
