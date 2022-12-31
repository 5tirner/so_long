# so_long

`SO_LONG`\
Welcome to `SO_LONG`,\
a 2D top-down or profile game where the player's goal is to collect every collectible present on the map and escape using the shortest possible route.

`Controls`\
Use the W, A, S, and D keys or the arrow keys to move the main character around the map.\
The player can move in the four directions: up, down, left, and right.\
The player cannot move into walls or off the map.

`Graphic management`\
The game will be displayed in a GUI window created using the MiniLibX library.\
The window management must remain smooth, allowing the player to change to another window,\
minimize the game window, and so on.

`Map`\
The map is constructed with three components:\
walls, collectibles, and free space.\
The map can be composed of only these five characters:

0: empty space.\
1: wall.\
C: collectible.\
E: map exit.\
P: player's starting position.

The map must contain one exit, at least one collectible,\
and one starting position to be valid.\
If the map contains duplicate characters (exit/start), an error message will be displayed.

The map must be rectangular and closed/surrounded by walls.\
If it is not, the program will return an error.

The program will check if there is a valid path in the map.\
The player must be able to parse any kind of map as long as it respects the above rules.

If any misconfiguration of any kind is encountered in the map file, the program will exit in a clean way, displaying an error message.

`Playing the game`\
To play the game, run the program with a valid map file as an argument.\
The player's goal is to collect every collectible present on the map and escape through the exit,\
using the shortest possible route. The game will end when the player has collected all the collectibles and reached the exit,\
or when the player quits the game.
