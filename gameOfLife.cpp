#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#define endl "\n"

using namespace std;



#define maxHeight 150

#define maxWidth 150

int board[maxHeight][maxWidth]; //maxwidth, height

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
	cout << endl;
	while (generationCount) {
		int neigh;

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
		generationCount--;
	}
}





void randInput() {

	srand((unsigned int)time(NULL));


	for (int i = 0; i < maxHeight; i++) {

		for (int j = 0; j < maxWidth; j++) {

			board[i][j] = rand() % 2;

		}

	}
	//test
	/*for (int i = 0; i<maxHeight; i++) {
	for (int j = 0; j<maxWidth; j++) {
	cout << board[i][j];
	}
	}*/

	cout << endl;


}//if randomize input if there is no board input set





void print() {

	cout << endl;

	for (int i = 0; i <Height; i++) {

		for (int j = 0; j < Width; j++) {

			cout << board[i][j];

		}cout << endl;

	}

	cout << endl;

}

void getInputTxt(char* src) {
	string in_line;
	ifstream in(src);
	int targetHeigth = 0;
	int count = 0;
	while (getline(in, in_line, ' ')) {

		if (count == 0) {
			//cout<<in_line;
			string s1;
			for (int i = 0; i<in_line.size(); i++) {
				if (in_line[i] != ' ')s1 += in_line[i];
			}
			//cout<<s1<<endl;
			Height = atoi(s1.c_str());

		}
		else if (count == 1) {
			string s2;
			for (int i = 0; i<in_line.size(); i++) {
				if (in_line[i] != ' ')s2 += in_line[i];
			}
			//cout<<s2<<endl;
			Width = atoi(s2.c_str());
		}
		else {
			for (int j = 0; j < Width; j++) {
				board[targetHeigth][j] = in_line[j];
			}
			targetHeigth++;
		}
		count++;
	}
	in.close();
	//	cout << "height" << Height << endl;
	//	cout << "width" << Width << endl;

}

void dumpTxt() {
	string out_line;
	ofstream out("dump.txt");
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			out << board[i][j];
		}out << endl;
	}
	out.close();
}

int main(int argc, char* argv[]) {

	ios::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);//fast io

				   //cout<<argc<<endl;

	char* arg1;
	int arg2;
	if (argc != 1 && argc != 2 && argc != 3) {
		cout << "argc error. usage: ./life || ./life plus.txt ||./life plus.txt generationCount" << endl;
	}
	if (argc >= 2) {
		arg1 = argv[1]; //txt
						//cout << arg1 << endl;
	}
	if (argc >= 3) {
		arg2 = atoi(argv[2]); //generation count
							  //cout << arg2 << endl;
	}

	//arg1 입력이 없다면 랜덤 인풋
	if (argc == 1) {
		randInput();
		makeState(1);
		print();
	}
	else if (argc == 2) {
		// 입력된 파일 읽어오기.
		getInputTxt(arg1);
		makeState(1);
		print();
	}
	else if (argc == 3) {
		// 입력된 파일 읽어오고 해당 generationCount만큼 실행한후 txt파일로 dump(dump.txt)
		getInputTxt(arg1);
		makeState(arg2);
		dumpTxt();
	}
	//arg2 입력이 없다면 


}


