#include<iostream>
#include<stdlib.h>
#define endl "\n"

using namespace std;



#define maxHeight 40

#define maxWidth 80

int board[maxHeight][maxWidth]; //wdth 80 height 40

int board2[maxHeight][maxWidth];

int Height, Width;



void resetBoard() {

	for (int i = 0; i < Height; i++) {

		for (int j = 0; j < Width; j++) {

			board2[i][j] = 0;

		}

	}

}



void swap(int board[][maxWidth], int board2[][maxWidth]) {

	for (int i = 0; i < Height; i++) {

		for (int j = 0; j < Width; j++) {

			int temp = board[i][j];

			board[i][j] = board2[i][j];

			board2[i][j] = temp;

		}

	}

}//board board2 swap



void makeState(int generationCount) {

	int neigh;

	cout << endl;

	for (int i = 0; i < maxHeight; i++) {

		for (int j = 0; j < maxWidth; j++) {

			neigh = 0;

			if (board[i][j - 1] == 1)neigh++;

			if (board[i - 1][j] == 1)neigh++;

			if (board[i - 1][j - 1] == 1)neigh++;

			if (board[i + 1][j] == 1)neigh++;

			if (board[i][j + 1] == 1)neigh++;

			if (board[i + 1][j + 1] == 1)neigh++;

			if (board[i - 1][j + 1] == 1)neigh++;

			if (board[i + 1][j - 1] == 1)neigh++;



			if (board[i][j] == 1) {

				if (neigh < 2)board2[i][j] = 0;

				if (neigh >= 4)board2[i][j] = 0;

			}

			else if (board[i][j] == 0) {

				if (neigh == 3)board2[i][j] = 2;

			}

		}

	}

	swap(board, board2);

	resetBoard();

}





void randInput() {

	srand((unsigned int)time(NULL));

	for (int i = 0; i < Height; i++) {

		for (int j = 0; j < Width; j++) {

			board[i][j] = rand() % 10;

		}

	}

}//if randomize input if there is no board input set





void print(int board[][maxWidth]) {

	cout << endl;

	for (int i = 0; i <Height; i++) {

		for (int j = 0; j < Width; j++) {

			cout << board[i][j] << endl;

		}

	}

	cout << endl;

}



int main(int argc, char* argv[]) {

	ios::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);//fast io

	//cout<<argc<<endl;

	if (argc != 1 && argc != 2 && argc != 3) {
		cout << "argc error. usage: ./life || ./life plus.txt ||./life plus.txt generationCount" << endl;
	}
	if (argc >= 2) {
		char* arg1 = argv[1]; //txt
		cout << arg1 << endl;
	}
	if (argc >= 3) {
		int arg2 = atoi(argv[2]); //generation count
		cout << arg2 << endl;
	}

	//arg1 입력이 없다면 랜덤 인풋
	if (argc == 1) {

	}
	else if (argc == 2) {

	}
	else if (argc == 3) {

	}
	//arg2 입력이 없다면 
	

}


