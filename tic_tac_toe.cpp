#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

class TicTacToe{
public:
	char board[3][3] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};

	char currentPlayer =  'X';

	void printBoard(){
		for (int i = 0; i < 3; i++){
			cout<<" ";
			for (int j = 0; j < 3; j++){
				cout<<board[i][j];
				if (j < 2) cout<<" | ";
			}
			cout<<endl;
			if (i < 2) cout<<"---+---+---\n";
		}}

	bool makeMove(int row, int col){
		if (board[row][col] != 'X' && board[row][col] != 'O'){
				board[row][col] = currentPlayer;
				return true;
		}
		else cout<<"The cell is already filled\n";
		return false;
	}

	bool gameWin(){
		for (int i = 0; i < 3; ++i){
			if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i])){
				return true;
			}
		}
		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])){
			return true;
		}
		return false;
	}

	bool gameDraw(){ 	
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (board[i][j] != 'X' && board[i][j] != 'O'){
					return false;
				}}}
		return true;
	}

	void switchPlayer() {currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';}

	void clearScreen() {system("clear");}

	void resetBoard(){
		int k = 1;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				board[i][j] = '0' + k++;
			}}}};

int main(){
	while (true){
		TicTacToe game;
		int position, row, col;
		game.clearScreen();

		while(true){
			game.printBoard();
			cout<<"Player "<<game.currentPlayer<<" enter your choice(1-9): \n";

			while(!(cin>>position) && (position < 1 || position > 9) || (position==0)){
				cout<<"Enter a valid position please!\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			row = (position - 1) / 3;
			col = (position - 1) % 3;
	
			if (game.makeMove(row, col)){
				if (game.gameDraw()){
					cout<<"Draw Guyss\n";
					break;
				}
				if (game.gameWin()){
					cout<<"Player "<<game.currentPlayer<<" won!\n";
					break;
				}
			}
			else {
				cout<<"Enter an empty cell pweash\n";
				continue;
			}
			game.switchPlayer();
		}
		cout<<"Wanna Play again(y/n)?\b"<<endl;
		char play_again;
		cin>>play_again;

		if (play_again == 'y') game.resetBoard();
		
		else if (play_again == 'n'){
			cout<<"Alright niggas get going!\n";
			break;
		}
	}
}
