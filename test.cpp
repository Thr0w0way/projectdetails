
#include "isometricdemo.cpp"
/*this file contains a main function which loads the
* isometric demo class instead of the game class
* I had to make one anyway to test the demo so 
* I thought I might as well leave it here
*/
int main()
{
	IsometricDemo game;

	game.setup();
	game.loop();

	return 0;
}
