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

void draw_board(Checker* game) {
	std::cout<<"\e[5;5H\e[33m1  2  3  4  5  6  7  8\e[23;5H1  2  3  4  5  6  7  8"
		"\e[7;2HA\e[9;2HB\e[11;2HC\e[13;2HD\e[15;2HE\e[17;2HF\e[19;2HG\e[21;2HH"
		"\e[7;29HA\e[9;29HB\e[11;29HC\e[13;29HD\e[15;29HE\e[17;29HF\e[19;29HG\e[21;29HH";
	if(game) {
	for(int l=6;l<22;l++) {
		for(int c=4;c<28;c++) {
			std::cout<<"\e["<<l<<";"<<c<<"H\e[4"<<((l-6)%4<2?((c-4)%6<3?7:0):((c-4)%6<3?0:7))<<"m";
			if(((l-6)%4<2?(c-4)%6==4:(c-4)%6==1)) {
				if(game->getField((l-6)/2,(c-4)/3)) {
					std::cout<<"\e[1m\e[3"<<(game->getField((l-6)/2,(c-4)/3)->color==white?2:1);
					std::cout<<((l-6)%2==0?(game->getField((l-6)/2,(c-4)/3)->king?"O":" "):"O");
				} else
					std::cout<<" ";
			} else
				std::cout<<" ";

		}
	}
	} else
		std::cout<<"\e[14;5H\e[1m\e[31mERROR! No current game!";
	std::cout<<"\e[0m\e[24;1H";
}

void startgame(int players) {
	std::cout<<"\e[H\e[J\e[1m\e[34m\e[1;30H*******************\e[2;31HChecker Board Game\e[3;30H*******************\e[0m\e[24;1H";
	Checker* game=new Checker;
	draw_board(game);
	//TODO: insert board drawing code here
	
	std::cin.getline(NULL,0);
	std::cout<<"\e[H\e[J\e[0m";
}
