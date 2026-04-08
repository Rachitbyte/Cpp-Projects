#include<bits/stdc++.h>
using namespace std;
class Game{
	int num;
	int score;
	int player_number;
	public:
		static float totalpoints;
		static int playercount;
		static float finalscore;
		static float relative_score[100];
		Game(){							//Default Constructor
			cout << "Default Constructor Invoked for player " << ++Game::playercount << endl;
			player_number=Game::playercount;
			score=0;
		}
		
		void num_input(int number){			//number input for persons
			num=number;
			cout << "Player " << player_number << " choice is: " << num << endl;
			Game::totalpoints+=this->num;
		}
		
		int getnum(){return num;}
		int getscore(){return score;}
		int getplayernumber(){return player_number;}
		void changescore(int scor){
			score=scor;
		}
		
		void changeplayernumber(int playernumber){
			player_number=playernumber;
		}
		
		static void calulation(){			//calculates and display finalscore
			Game::finalscore=(Game::totalpoints/Game::playercount)*0.8;
			cout << "Final Score is: " << Game::finalscore << endl;
		}
		
		~Game(){						//Destructor
			cout << "Destructor Invoked for player " << player_number << endl;
		}
};
float Game::totalpoints=0;
int Game::playercount=0;
float Game::finalscore=0;
float Game::relative_score[]={0};

int main()
{
	int n, roundcount=0;
	cout << "Enter the number of players: ";
	cin  >> n;
	Game p[n];
	
	while(Game::playercount!=1){
	roundcount++;
	cout << "\n+++++++++++++++ Round " << roundcount << " Begins +++++++++++++++\n\n";
	srand(time(NULL));
	Game::totalpoints=0;
	for(int i=0;i<Game::playercount;i++){
		p[i].num_input(rand()%101+1);			//passes rand. number to input func.
	}

	Game::calulation();						//Final Score Calculation
	for(int i=0;i<Game::playercount;i++){
			Game::relative_score[i]=abs(Game::finalscore-p[i].getnum());
			cout << "Player " << i+1 <<" finalscore - num is: " << Game::relative_score[i] << endl;
	}
	float min=Game::relative_score[0];
		for(int i=1;i<Game::playercount;i++){			
			if(Game::relative_score[i] < min){
				min=Game::relative_score[i];
			}
		}
		for(int i=0;i<Game::playercount;i++){
			if(min!=Game::relative_score[i]){		//this will asign -1 score...
				 p[i].changescore(p[i].getscore()-1);		//score changing
				if(p[i].getscore()==-10){
					cout << "Player " << p[i].getplayernumber() << " is Eliminated...\n";
					Game::playercount--;
					for(int y=i;y<Game::playercount;y++){		//when plyr is eliminated,later plyr gets shifted to earlier index
						p[y].changescore(p[y+1].getscore());	//score is updated to earlier index/object
						p[y].changeplayernumber(p[y+1].getplayernumber());	//playernumber is updated to earlier index/object
					}
				}
			}
		}
		cout << "\n**************** Round " << roundcount << " Results ****************\n";
		for(int i=0;i<Game::playercount;i++){
			cout << "Player: " << p[i].getplayernumber() << " Score: " << p[i].getscore() << endl;
		}
		system("pause");
}
	cout << "PLAYER " << p[0].getplayernumber() << " IS WINNER !\n\n";

	return 0;
}
