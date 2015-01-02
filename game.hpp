//Header file for game class
#ifndef GAME_HPP
#define GAME_HPP
#include<SFML/Graphics.hpp>
#include"map.hpp"

class Game
{
	private:
		sf::RenderWindow *window;
		sf::Clock *clock;
		//tilesheet
		sf::Texture tile_sheet;
	public:
		//game map
		Map map;
		void setup();
		void loop();
		void update(int deltaTime);
		void draw();
};
#endif
