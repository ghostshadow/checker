/****
 * main.cpp
 * by ghostshadow
 ****/
/*********************************
 * Checkers for POSIX Terminals 
 *********************************/

#include "std_incl.hpp"
#include "check_err.hpp"
#include "board.hpp"
#include "token.hpp"
#include "game.hpp"

/*
 * Expecting terminal to be at least 80x24 chars
 */

int main(int argc,char** argv) {
	std::cout<<"\e[H\e[J\e[1m\e[34m*********************\n Welcome to Checker!\n*********************\n\e[0m\n";
	bool retry;
	char* tmp=(char*)malloc(81);
	int players;
	do {
		retry=false;
		std::cout<<"please chose if you want to\nplay alone [1], play against another player [2] : ";
		std::cin.getline(tmp,80);
		if(isdigit(tmp[0]))
			players=atoi(tmp);
		else
			players=-1;
		Checker::Game *game;
		switch(players) {
		case 0: /*cpu vs cpu */
		case 1: /* player vs cpu */
		case 2: /* player vs player */
			game=new Checker::Game;
			game->init();
			game->run(players);
			break;
		default:
			std::cerr<<players<<" is not a valid entry!\n";
			retry=true;
		}
	} while(retry);
	return 0;
}

