/****
 * game.hpp
 * Game Definitions
 * by ghostshadow
 ****/

#ifndef CHECK_GAME_INCL__
#define CHECK_GAME_INCL__

#include "std_incl.hpp"

namespace Checker {
class Game {
private:
	Board *gameboard;
public:
	Game();
	~Game();
	void init();
	//TODO: Stuff
};
}

#endif /*CHECK_GAME_INCL__*/
/*EOF: game.hpp*/
