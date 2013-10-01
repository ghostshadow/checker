/****
 * token.hpp
 * Token Definitons
 * by ghostshadow
 ****/

#ifndef CHECK_TOKEN_INCL__
#define CHECK_TOKEN_INCL__

#include "std_incl.hpp"

namespace Checker {

enum tcolor{white=1,black};

class Token {
private:
	bool king;
	tcolor color;
	std::valarray<int> curpos(2);
public:
	Token();
	~Token();
	void move_to(std::valarray<int> *);
	void set_curpos(std::valarray<int> *);
};
}

#endif /*CHECK_TOKEN_INCL__*/
/*EOF: token.hpp*/
