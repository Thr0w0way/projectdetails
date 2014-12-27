
#include <SFML/Graphics.hpp>

class Game
{
	private:
		sf::RenderWindow *window;
		sf::Clock *clock;

	public:
	void setup()
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 600), "Untitled");
		window->setFramerateLimit(60);

		clock = new sf::Clock();
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

	void draw()
	{
		window->clear();

		//

		window->display();
	}
};
