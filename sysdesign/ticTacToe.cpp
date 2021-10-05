#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > board;
vector<int> rowX, rowO, colX, colO, digX, digO;
int n;

void printBoard() {
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++)
			cout << board[i][j];
		cout << '\n';
	}
	return;
}

int checkWin() {
	for(int i = 0 ; i < n ; i++)
		if((rowX[i] == n || colX[i] == n) || (rowO[i] == n || colO[i] == n))
			return 1;
	if((digX[0] == n || digX[1] == n) || (digO[0] == n || digO[1] == n))
		return 1;
	return -1;
}

bool updateBoard(int x, int y, int player) {
	if(board[x][y] == '.') {
		if(!player) {
			board[x][y] = 'x';
			if(x == y)
				digX[0]++;
			if(x == n-y-1)
				digX[1]++;
			rowX[x]++;
			colX[y]++;
		}
		else {
			board[x][y] = 'o';
			if(x == y)
				digO[0]++;
			if(x == n-y-1)
				digO[1]++;
			rowO[x]++;
			colO[y]++;
		}
		return true;
	}
	return false;
}

int move(int player) {
	if(checkWin() != -1) {
		cout << "Player " << player + 1 << " won!\n";
		return 0;
	}
	return 1;
}

int main() {
	cin >> n;
	board.resize(n);
	rowX.resize(n), rowO.resize(n), colX.resize(n), colO.resize(n), digX.resize(2), digO.resize(2);
	for(int i = 0 ; i < n ; i++) {
		board[i].resize(n);
		for(int j = 0 ; j < n ; j++)
			board[i][j] = '.';
	}
	int cnt = 0;
	int player = 0;
	while(cnt < n*n) {
		int check = move(player);
		if(!check)
			break;
		player ^= check;
		cnt++;
		printBoard();
	}
	printBoard();
	return 0;
}
