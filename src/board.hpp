/****
 * board.hpp
 * Board Definitions
 * by ghostshadow
 ****/

namespace Checker {
class Board {
private:
	Token *board[8][8];
public:
	void put_Token(std::valarray<int> *,Token *);
	Token *get_Token(std::valarray<int> *);
	Token *remove_Token(std::valarray<int> *);
};
}
/*EOF: board.hpp*/
