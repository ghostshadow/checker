/****
 * board.cpp
 * Board Methods
 * by ghostshadow
 ****/

#include "board.hpp"

Checker::Board::Board() {
	for(int l=0;l<8;l++) {
		for(int c=0;c<8;c++) {
			this->board[l][c]=NULL;
		}
	}
}

void Checker::Board::put_Token(std::valarray<int> *tposp,Token *token) {
	if(tposp->size()!=2)
		throw(std::length_error("Board_Pos_2D_only"));
	if((*tposp)[0]<0 || (*tposp)[0]>=8 || (*tposp)[1]<0 || (*tposp)[1]>=8)
		throw(std::range_error("Board_Pos_Out_Of_Board"));
	this->board[(*tposp)[1]][(*tposp)[0]]=token;
	token->curpos=*tposp;
}

Checker::Token *Checker::Board::get_Token(std::valarray<int> *posp) {
	if(posp->size()!=2)
		throw(std::length_error("Board_Pos_2D_only"));
	if((*posp)[0]<0 || (*posp)[0]>=8 || (*posp)[1]<0 || (*posp)[1]>=8)
		throw(std::range_error("Board_Pos_Out_Of_Board"));
	return this->board[(*posp)[1]][(*posp)[0]];
}

Checker::Token *Checker::Board::remove_Token(std::valarray<int> *posp) {
	Token *tmp=this->get_Token(posp);
	this->put_Token(posp,NULL);
	return tmp;
}

