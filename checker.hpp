
#include <signal.h>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <new>

enum player {white,black};

typedef struct {
	player color;
	bool king;
} stone;

class Checker {
public:
	class invalidTurn {};

	Checker() {}
	~Checker() {}
	void newgame();
	void move(player,int,int,int,int);
	stone* getField(int,int);
	player getTurn() {return hasturn;}
private:
	stone* board[7][7];
	player hasturn;
	
};



