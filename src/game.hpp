/****
 * game.hpp
 * Game Definitions
 * by ghostshadow
 ****/

#ifndef CHECK_GAME_INCL__
#define CHECK_GAME_INCL__

#include "std_incl.hpp"
#include "token.hpp"
#include "board.hpp"

namespace Checker {
class Game {
private:
	Board *gameboard;
	int remwhite,remblack;
	tcolor nextturn;
	char lastturns[8][8];

	void draw_Board();
public:
	Game();
	~Game();
	void init();
	void run(int);
	void move(std::valarray<int> *,std::valarray<int> *);
};
}

#endif /*CHECK_GAME_INCL__*/
/*EOF: game.hpp*/
