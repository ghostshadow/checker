
#include "checker.hpp"

Checker::Checker() {
	//initialize empty
	for(int y=0;y<8;y++)
		for(int x=0;x<8;x++)
			this->board[y][x]=NULL;
	//put start config of player black
	for(int y=0;y<3;y++) {
		for(int x=0;x<8;x+=2) {
			this->board[y][(y%2?x+1:x)]=new stone;
			this->board[y][(y%2?x+1:x)]->color=black;
			this->board[y][(y%2?x+1:x)]->king=false;
		}
	}
	//put start config of player white
	for(int y=7;y>4;y--) {
		for(int x=0;x<8;x+=2) {
			this->board[y][(y%2?x+1:x)]=new stone;
			this->board[y][(y%2?x+1:x)]->color=white;
			this->board[y][(y%2?x+1:x)]->king=false;
		}
	}
	//initialize remaining stones and start player
	this->hasturn=white;
	this->pwstones=12;
	this->pbstones=12;
}

void Checker::move(player color,int sl,int sc,int tl,int tc) {
	if(sl<8||sl>=0||sc<8||sc>=0||tl<8||tl>=0||tc<8||tc>=0)
		throw Checker::invalidTurn("OOB");	//Out of Board
	if(!this->board[sl][sc])
		throw Checker::invalidTurn("NS");	//No Stone
	stone *mover=this->board[sl][sc];
	if(mover->color==white?sl>tl:sl<tl&&mover->king==false)
		throw Checker::invalidTurn("NKB");	//No King Backmove
	
	//TODO: Move Code
	return;

}

void Checker::getLastTurn(char* targ,int last) {
	if(last<8&&last>=0)
		strncpy(targ,(const char*)&(this->lastturns[last]),7);
	else
		throw std::out_of_range("oor");
}

stone* Checker::getField(int l,int c) {
	if(l<8&&l>=0&&c<8&&l>=0)
		return this->board[l][c];
	return NULL;
}

