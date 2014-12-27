
#include <SFML/Graphics.hpp>

class IsometricDemo
{
	private:

		sf::RenderWindow *window;
		sf::Clock *clock;

		// these are just placeholder assets
		sf::Texture *tile_texture;
		sf::Sprite *tile_sprite;

	public:

	void setup()
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 600), "Untitled");
		window->setFramerateLimit(60);

		clock = new sf::Clock();

		// textures are apparently stored in the graphic card's memory rather than RAM
		tile_texture = new sf::Texture();
		tile_texture->loadFromFile("assets/gfx/tiles/basic1.png");

		// sprites are used to position and draw textures
		tile_sprite = new sf::Sprite();
		tile_sprite->setTexture(*tile_texture);
		tile_sprite->setColor(sf::Color(255, 255, 255, 255));
	}

	void loop()
	{
		int dt = clock->restart().asMilliseconds();

		while (window->isOpen())
		{
			update(dt);
			draw();
			sf::sleep(sf::milliseconds(1));
		}
	}

	void update(int deltaTime)
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

	// TODO rewrite these functions to work with sf::Sprite::setOrigin(x, y)
	sf::Vector2i *cartesianPosFromGridPos(int gridX, int gridY, int tileWidth, int tileHeight)
	{
		return new sf::Vector2i(\
			(gridX - gridY) * tileWidth,\
			(gridX + gridY) * tileHeight / 2\
		);
	}

	sf::Vector2i *gridPosFromCartesianPos(int cartX, int cartY, int tileWidth, int tileHeight)
	{
		return new sf::Vector2i(\
			(2 * cartY / tileHeight + cartX / tileWidth) / 2,\
			(2 * cartY / tileHeight - cartX / tileWidth) / 2\
		);
	}

	void draw()
	{
		window->clear();

		// dimensions of the map
		int map_width = 5;
		int map_height = 10;

		// dimensions of the tile's foreground (excluding background / top part)
		int tileWidth = 32;
		int tileHeight = 32;

		// coordinates of top/center of screen
		int startX = 400, startY = 0;

		// draw out map
		for (int x = 0; x < 5; ++x)
			for (int y = 0; y < 10; ++y)
			{
				// calculate absolute position (sf::Vector2<int>* aka sf::Vector2i)
				auto pos = cartesianPosFromGridPos(x, y, tileWidth, tileHeight);

				// adjust offsets
				pos->x += startX;
				pos->y += startY;

				tile_sprite->setPosition(pos->x, pos->y);
				window->draw(*tile_sprite);
			}

		// draw something at mouse pos

		// get mouse pos
		auto mousePosCartesian = sf::Mouse::getPosition(*window);

		// remove offsets
		mousePosCartesian.x -= startX;
		mousePosCartesian.y -= startY;

		// get mouse's grid pos
		auto mousePosGrid = gridPosFromCartesianPos(mousePosCartesian.x, mousePosCartesian.y, tileWidth, tileHeight); // pass arguments without offsets

		// get absolute position of mouse's grid pos
		auto mousePosLockedToGrid = cartesianPosFromGridPos(mousePosGrid->x, mousePosGrid->y, tileWidth, tileHeight);

		// add offsets
		mousePosLockedToGrid->x += startX;
		mousePosLockedToGrid->y += startY;

		// draw tile at mouse
		tile_sprite->setPosition(mousePosLockedToGrid->x, mousePosLockedToGrid->y);
		window->draw(*tile_sprite);

		window->display();
	}
};
