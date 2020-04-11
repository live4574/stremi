#include<iostream>
#define endl "\n"
using namespace std;

#define maxHeight 40
#define maxWidth 80
int board[maxHeight][maxWidth]; //wdth 80 height 40
int board2[maxHeight][maxWidth];
int Height, Width;

void resetBoard(int &target[][]) {
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			target[i][j] = 0;
		}
	}
}

void swap(int &board[][] int& board2[][]) {
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
				if (neigh >=4)board2[i][j] = 0;
			}
			else if (board[i][j] == 0) {
				if (neigh == 3)board2[i][j] = 2;
			}
		}
	}
	swap(board, board2);
	resetBoard(board2);
}


void randInput() {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			board[i][j] = rand() % 10;
		}
	}
}//if randomize input if there is no board input set


void print(int board[][]) {
	cout << endl;
	for (int i = 0; i <Height ;i++) {
		for (int j = 0; j < Width; j++) {
			cout << board[i][j]<<endl;
		}
	}
	cout << endl;
}

int main(char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);//fast io

	char* arg1 = argv[1]; //txt
	int arg2 = atoi(argv[2]); //generation count

	cout << arg1<<endl; //test arg1
	cout << arg2<<endl; //test arg2

	//arg1 입력이 없다면 랜덤 인풋
	//arg2 입력이 없다면 
}

