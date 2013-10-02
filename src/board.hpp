/****
 * board.hpp
 * Board Definitions
 * by ghostshadow
 ****/

#ifndef CHECK_BOARD_INCL__
#define CHECK_BOARD_INCL__

#include "std_incl.hpp"
#include "token.hpp"

namespace Checker {
class Board {
private:
	Token *board[8][8];
public:
	Board();
	~Board();
	void put_Token(std::valarray<int> *,Token *);
	Token *get_Token(std::valarray<int> *);
	Token *remove_Token(std::valarray<int> *);
};
}

#endif /*CHECK_BOARD_INCL__*/
/*EOF: board.hpp*/
