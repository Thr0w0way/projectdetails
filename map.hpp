#ifndef MAP_HPP
#define MAP_HPP
#include"tile.hpp"
#include<SFML/Graphics.hpp>

class Map{
	public:
		//2d map
		Tile map[100][100];
		//sprite array which tile class references
		sf::Sprite sprites[100];
		//constructor
		Map();
		//method for loading sprites into internal array
		int load_sprites(sf::Texture *in_texture,int no_of_sprites,int grid_w,int grid_h,int sheet_w, int sheet_h);	
};	
#endif
