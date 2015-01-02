#include"game.hpp"


void Game::setup()
{
	
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Untitled");
	window->setFramerateLimit(60);

	clock = new sf::Clock();
	//load tile sheet
	tile_sheet.loadFromFile("assets/gfx/tiles/basic1.png");
	//treating the single tile in the tiles directory as 1x1 sprite sheet
	map.load_sprites(&tile_sheet,1,64,64,64,64);
	
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
}

void Game::draw()
{
	window->clear();
	//test draw of sprite from map sprite array
	window->draw(map.sprites[0]);

	window->display();
}
