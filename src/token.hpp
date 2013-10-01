/****
 * token.hpp
 * Token Definitons
 * by ghostshadow
 ****/

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
/*EOF: token.hpp*/
