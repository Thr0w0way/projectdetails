Todo list for rpg game
=================

Tools:
--------
* gcc/mingw = compiler
* sfml = multimedia library
* codeblocks/visual studio = ide
* tiled = map editor

Todo:
--------
(in no particular order)
- check out `isometricdemo.cpp` for a demo on how we can draw the isometric stuff and how to get coordinates from/to the grid or absolute cartesian values
  - to run the demo edit `main.cpp` to include `isometricdemo.cpp` and replace the line `Game game;` with `IsometricDemo game`
- ~~main game loop (there's this: https://love2d.org/forums/viewtopic.php?f=4&p=37556#p37442 and this: https://love2d.org/wiki/love.run to draw inspiration from)~~
- reading map data (the Tiled map format is just XML either gzipped or zlibbed and then Base64'd) ~~& drawing out maps~~
  - I suggest rapidxml for parsing XML (it's small and just werks)
- pick a tileset - for now I'm using this: http://opengameart.org/sites/default/files/Tiles_0.zip just to learn how to properly draw everything
- rewrite everything eventually to one consistent coding style (mostly just pointer/ref usage, `.` and `->`)
- ~~a story would be nice~~
- we need to finalize map details (e.g. the size of the map,etc)

Story
------
I kind of thought of a story its very rough at the moment if you don't like it we can always change it.
Its kindof based in a legend of zelda style where you have to beat bosses to gain components of something
which you need to use to fight the final boss. So you're told by your elder( or grandfather or something)
that to gain fame and fortune you must make a game, and to do this you have to collect three interlocking 
gems, each one repersenting an element of the game (programming,art,music) to get these you have to fight
their respective bosses. when you have collected all the gems you take them back to your elder who as it 
turns out was using you to make the game and intends to steal it for himself, at this point the final boss 
battle occurs between you and your elder after which the game ends.
- I'm okay with this!
