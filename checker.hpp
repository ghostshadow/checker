
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

	Checker();
	void move(player,int,int,int,int);
	stone* getField(int,int);
	player getTurn() {return hasturn;}
private:
	stone* board[7][7];
	player hasturn;
	int pwstones,pbstones; //remaining Stones of the players (white,black)
	char lastturns[8][7]; //lastturns[t]="A1->B2";
};



