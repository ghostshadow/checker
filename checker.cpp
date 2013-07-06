
#include "checker.hpp"

void Checker::newgame() {
	for(int y=0;y<8;y++)
		for(int x=0;x<8;x++)
			this->board[y][x]=NULL;
	for(int y=0;y<3;y++) {
		for(int x=0;x<8;x+=2) {
			this->board[y][y%2?x+1:x]=new stone;
			this->board[y][y%2?x+1:x]->color=black;
			this->board[y][y%2?x+1:x]->king=false;
		}
	}
	for(int y=7;y>4;y--) {
		for(int x=0;x<8;x+=2) {
			this->board[y][y%2?x+1:x]=new stone;
			this->board[y][y%2?x+1:x]->color=white;
			this->board[y][y%2?x+1:x]->king=false;
		}
	}
	this->hasturn=white;
}
