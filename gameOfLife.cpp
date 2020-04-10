#include<iostream>
#define endl "\n"
using namespace std;

#define maxHeight 40
#define maxWidth 80
int board[maxHeight][maxWidth]; //wdth 80 height 40
int board[maxHeight][maxWidth];
int Height, Width;

void makeState(int generationCount) {
		
}

void print(int board[][]) {
	cout << endl;
	for (int i = 0; i <Height ;i++) {
		for (int j = 0; j < Width; j++) {
			cout << board[i][j]endl;
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