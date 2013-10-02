/****
 * game.cpp
 * Game Implementation
 * by ghostshadow
 ****/

#include "game.hpp"
#include "check_err.hpp"

Checker::Game::Game() {
	this->gameboard=NULL;
	this->remwhite=0;
	this->remblack=0;
	this->nextturn=(tcolor)0;
}

void Checker::Game::init() {
	this->gameboard=new Board();
	std::valarray<int> pos(0,2);
	for(int l=0;l<8;l++) {
		for(int c=0;c<8;c++) {
			pos[0]=c;
			pos[1]=l;
			if((l%2>0 && c%2>0) || (l%2==0 && c%2==0)) {
				if(l<3)
					this->gameboard->put_Token(&pos,new Token(white));
				else if(l>4)
					this->gameboard->put_Token(&pos,new Token(black));
			}
		}
	}
	this->remwhite=12;
	this->remblack=12;
	this->nextturn=white;
}

/*TODO: turn drawed board right side up*/
void Checker::Game::draw_Board() {
	std::cout<<"\e[5;5H\e[33m1  2  3  4  5  6  7  8\e[23;5H1  2  3  4  5  6  7  8"
		"\e[7;2HA\e[9;2HB\e[11;2HC\e[13;2HD\e[15;2HE\e[17;2HF\e[19;2HG\e[21;2HH"
		"\e[7;29HA\e[9;29HB\e[11;29HC\e[13;29HD\e[15;29HE\e[17;29HF\e[19;29HG\e[21;29HH";
	std::valarray<int> pos(2);
	for(int l=6;l<22;l++) {
		for(int c=4;c<28;c++) {
			std::cout<<"\e["<<l<<";"<<c<<"H\e[4"<<((l-6)%4<2?((c-4)%6<3?0:7):((c-4)%6<3?7:0))<<"m";
			if(((l-6)%4<2?(c-4)%6==1:(c-4)%6==4)) {
				pos[0]=(c-4)/3;
				pos[1]=(l-6)/2;
				if(this->gameboard->get_Token(&pos)) {
					std::cout<<"\e[1m\e[3"<<((this->gameboard->get_Token(&pos)->get_Color()==white)?2:1)<<"m";
					std::cout<<(((l-6)%2==0)?(this->gameboard->get_Token(&pos)->is_King()?"O":" "):"O");
				} else
					std::cout<<" ";
			} else
				std::cout<<" ";

		}
	}
}

void Checker::Game::run(int players) {
	bool running=true;
	char *tmp=(char*)malloc(81);
	while(running) {
		std::cout<<"\e[H\e[J\e[1m\e[34m\e[1;30H*******************\e[2;31HChecker Board Game\e[3;30H*******************\e[0m\e[24;1H";
		this->draw_Board();
		std::cout<<"\e[5;35H\e[40m\e[37mTurn has: \e[1m\e[3"<<(this->nextturn==white?"2mwhite":"1mblack")<<"\e[39m\e[22m";
		std::cout<<"\e[7;35H\e[40m\e[37mRemaining:\e[8;37H\e[1m\e[32mwhite "<<this->remwhite;
		std::cout<<"\e[9;37H\e[1m\e[31mblack "<<this->remblack;
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
				std::valarray<int> spos(2),tpos(2);
				spos[0]=(tmp[1]-0x30);
				spos[1]=(tmp[0]<0x5B?tmp[0]-0x41:tmp[0]-0x61);
				tpos[0]=(tmp[5]-0x30);
				tpos[1]=(tmp[4]<0x5B?tmp[4]-0x41:tmp[4]-0x61);
				this->move(&spos,&tpos);
			}
			catch(Turn_Error) {
				std::cout<<"Invalid Turn!\n";
				continue;
			}
			std::cout.flush();
			std::cin.getline(NULL,0);
		}
		
	}
	std::cout<<"\e[H\e[J\e[0m";
}

void Checker::Game::move(std::valarray<int> *spos,std::valarray<int> *tpos) {
	/*TODO: Movecode*/
}
