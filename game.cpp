#include"game.hpp"


void Game::setup()
{
	
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Untitled");
	window->setFramerateLimit(60);

	clock = new sf::Clock();
	//load tile sheet
	tile_sheet.loadFromFile("assets/gfx/tiles/chartileset.png");
	map.load_sprites(&tile_sheet,256,8,8,128,128);
	
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
	//test draw of sprites from map sprite array
	window->draw(map.sprites[1]);
	map.sprites[72].setPosition(8,0);
	window->draw(map.sprites[72]);
	map.sprites[69].setPosition(16,0);
	window->draw(map.sprites[69]);
	map.sprites[76].setPosition(24,0);
	window->draw(map.sprites[76]);
	map.sprites[76].setPosition(32,0);
	window->draw(map.sprites[76]);
	map.sprites[79].setPosition(40,0);
	window->draw(map.sprites[79]);

	window->display();
}
