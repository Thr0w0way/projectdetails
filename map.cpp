#include"map.hpp"
Map::Map(){
	//map constructor
	
}
/* load sprites from spritesheet constructor
 * takes the spritesheet (in_texture)
 * the size of the individual sprites int the sprite sheet(grid_w,grid_h)
 * the number of sprites (no_of_sprites)
 * and the width and height of the spritesheet(sheet_h,sheet_w)
 */
int Map::load_sprites(sf::Texture *in_texture,int no_of_sprites,int grid_w,int grid_h,int sheet_w, int sheet_h){
	int counter;
	int x = 0;
	int y = 0;
	if(no_of_sprites > 100)return 0;
	for(counter = 0;counter < no_of_sprites;counter++){
		if(x == sheet_w){
			x = 0;
			y += grid_h;
		}
		sprites[counter].setTexture(*in_texture);
		sprites[counter].setTextureRect(sf::IntRect(x, y,grid_w, grid_h));
		x += grid_w;
	}
	return 1;	
}
