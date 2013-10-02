/****
 * token.cpp
 * Token Implementation
 * by ghostshadow
 ****/

#include "token.hpp"

Checker::Token::Token(tcolor color) {
	this->color=color;
	this->king=false;
	this->curpos.resize(2);
}

Checker::Token::Token() {
	this->color=(tcolor)0;
	this->king=false;
	this->curpos.resize(2);
}

void Checker::Token::upgrade() {
	if(!(this->king))
		this->king=true;
}

Checker::tcolor Checker::Token::get_Color() {
	return this->color;
}

bool Checker::Token::is_King() {
	return this->king;
}

