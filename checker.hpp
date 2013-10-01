
#include <signal.h>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <iostream>
#include <new>

enum player {white,black};

typedef struct {
	player color;
	bool king;
} stone;

class Checker {
public:
	class invalidTurn {
	public:
		const char *code;
		invalidTurn(const char *errcode) {this->code=errcode;}
	};

	Checker();
	void move(player,int,int,int,int);
	stone* getField(int,int);
	player getTurn() {return this->hasturn;}
	int getRemaining(player ply) {return (ply==white?this->pwstones:this->pbstones);}
	void getLastTurn(char*,int) ;
private:
	stone* board[8][8];
	player hasturn;
	int pwstones,pbstones; //remaining Stones of the players (white,black)
	char lastturns[8][7]; //lastturns[t]="A1->B2";
};



