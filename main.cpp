/*********************************
 * Checkers for POSIX Terminals 
 *********************************/

#include "checker.hpp"

/*
 * Expecting terminal to be at least 80x24 chars
 */

void startgame(int);

int main(int argc,char** argv) {
	std::cout<<"\e[H\e[J\e[1m\e[34m*********************\n Welcome to Checker!\n*********************\n\e[0m\n";
	bool retry;
	char* tmp=(char*)malloc(80);
	int players;
	do {
		retry=false;
		std::cout<<"please chose if you want to\nplay alone [1], play against another player [2] : ";
		std::cin.getline(tmp,79);
		if(isdigit(tmp[0]))
			players=atoi(tmp);
		else
			players=-1;
		switch(players) {
		case 0: /*cpu vs cpu */
		case 1: /* player vs cpu */
		case 2: /* player vs player */
			startgame(players);
			break;
		default:
			std::cerr<<players<<" is not a valid entry!\n";
			retry=true;
		}
	} while(retry);
	return 0;
}

void startgame(int players) {
	std::cout<<"\e[H\e[J\e[1m\e[34m\e[1;30H*******************\e[2;31HChecker Board Game\e[3;30H*******************\e[0m\e[24;1H";

	//TODO: insert board drawing code here
	
	std::cin.getline(NULL,0);
	std::cout<<"\e[H\e[J\e[0m";
}
