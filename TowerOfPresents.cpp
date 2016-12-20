#include<iostream>

using namespace std;

int numberMoves=0;
//does the typical move for the "Tower of Hanoi"-problem, its recursive
void move(int present, char a, char c, char b){
	if (present>0){   
		move(present-1,a,b,c);
		numberMoves ++;
		cout<<"Moving present from pile "<<a<<" to pile "<<c<<"."<<endl;
		move(present-1, b,c,a);
	}
}

int main(){
	int numberPresents=0;
	//declaration and initialisation of the three piles
	char a = 'A';
	char b = 'B';
	char c = 'C';
	//reads the number of presents
	cout<<"Number of Presents: "<<endl;
	cin>>numberPresents;
	//moves the presents
	move(numberPresents,a,c,b);
	//writes the number of moves
	cout<<"Number of Moves: "<<numberMoves<<endl;
}

//A tower of seven presents needs 127 moves!
