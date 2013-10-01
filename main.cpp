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
			std::cout<<"\e["<<l<<";"<<c<<"H\e[4"<<((l-6)%4<2?((c-4)%6<3?0:7):((c-4)%6<3?7:0))<<"m";
			if(((l-6)%4<2?(c-4)%6==1:(c-4)%6==4)) {
				if(game->getField((l-6)/2,(c-4)/3)) {
					std::cout<<"\e[1m\e[3"<<((game->getField((l-6)/2,(c-4)/3)->color==white)?2:1)<<"m";
					std::cout<<(((l-6)%2==0)?((game->getField((l-6)/2,(c-4)/3)->king)?"O":" "):"O");
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
	Checker* game=new Checker;
	bool running=true;
	char *tmp=(char*)malloc(81);
	while(running) {
		std::cout<<"\e[H\e[J\e[1m\e[34m\e[1;30H*******************\e[2;31HChecker Board Game\e[3;30H*******************\e[0m\e[24;1H";
		draw_board(game);
		std::cout<<"\e[5;35H\e[40m\e[37mTurn has: \e[1m\e[3"<<(game->getTurn()==white?"2mwhite":"1mblack")<<"\e[39m\e[22m";
		std::cout<<"\e[7;35H\e[40m\e[37mRemaining:\e[8;37H\e[1m\e[32mwhite "<<game->getRemaining(white);
		std::cout<<"\e[9;37H\e[1m\e[31mblack "<<game->getRemaining(black);
		std::cout<<"\e[11;35H\e[22m\e[37mLast Moves:";
		std::cout<<"\e[24;1H\e[0m";
		std::cin.getline(tmp,80);
		if(0==strncasecmp("quit",tmp,4)||0==strncasecmp("q",tmp,1)||0==strncasecmp("exit",tmp,4)) {
			running=false;
			continue;
		}
		if(isalpha(tmp[0])&&isdigit(tmp[1])&&tmp[2]=='-'&&tmp[3]=='>'&&isalpha(tmp[4])&&isdigit(tmp[5])) {
			try {
				std::cout<<"Trying Move "<<(tmp[0]<0x5B?tmp[0]-0x41:tmp[0]-0x61)<<":"<<(tmp[1]-0x30)<<" -> "<<(tmp[4]<0x5B?tmp[4]-0x41:tmp[4]-0x61)<<":"<<(tmp[5]-0x30)<<"\n";
				game->move(game->getTurn(),(tmp[0]<0x5B?tmp[0]-0x41:tmp[0]-0x61),(tmp[1]-0x30),(tmp[4]<0x5B?tmp[4]-0x41:tmp[4]-0x61),(tmp[5]-0x30));
			}
			catch(Checker::invalidTurn) {
				std::cout<<"Invalid Turn!\n";
				continue;
			}
			std::cout.flush();
			std::cin.getline(NULL,0);
		}
	}
	std::cout<<"\e[H\e[J\e[0m";
}
