//Header file for game class
#ifndef GAME_HPP
#define GAME_HPP
#include<SFML/Graphics.hpp>

class Game
{
	private:
		sf::RenderWindow *window;
		sf::Clock *clock;
	public:
		void setup();
		void loop();
		void update(int deltaTime);
		void draw();
};
#endif
