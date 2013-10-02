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
public:
	std::valarray<int> curpos;
	
	Token();
	Token(tcolor);
	~Token();
	void upgrade();
	tcolor get_Color();
	bool is_King();
};
}

#endif /*CHECK_TOKEN_INCL__*/
/*EOF: token.hpp*/
