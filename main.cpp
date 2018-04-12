#include<iostream>
#include<string>

char board[6][7];

bool win_checkV(char p1, char p2) {
	char point;
	for (int j = 0; j <= 6; j++) {                                                              // Check if anyone has won vertically 
		int counter = 1;
		for (int i = 5; i >=3; i--) {
			point = board[i][j];
			if (board[i][j] == board[i - 1][j] && point != 'x') {
				counter++;
				if (counter == 4) {
					if (point == p1) {
						std::cout << "Player 1 won (vertically)" << std::endl;
						return true;
					}
					else {
						std::cout << "Player 2 won  (vertically)" << std::endl;
						return true;
					}
				}
			}
			else
				counter = 1;
		}
	}
	return false;
}

bool win_checkH(char p1, char p2) {
	char point;
	for (int i = 5; i >= 0; i--) {                                                               // Check horizontally if anyone has won
		int counter = 1;
		for (int j = 0; j <= 5; j++) {
			point = board[i][j];
			if (board[i][j] == board[i][j + 1] && point != 'x') {
				counter++;
				if (counter == 4) {
					if (point == p1) {
						std::cout << "Player 1 won (horizontally)" << std::endl;
						return true;
					}
					else {
						std::cout << "Player 2 won (horizontally)" << std::endl;
						return true;
					}
				}
			}
			else
				counter = 1;
		}
	}
	return false;
}

bool win_checkD(char p1, char p2) {
	char point;
	int counter = 1;
	for (int i = 6; i >= 3; i--) {         //move up the table
		for (int j = 0; j <= i; j++) {     //move right of the table
			int k = i;
			point = board[i][j];
			if (board[k][j] == board[k-1][j + 1] && point != 'x') {
				counter++;
				if (counter == 4) {
					if (point == p1) {
						std::cout << "Player 1 won" << std::endl;
						return true;
					}
					else {
						std::cout << "Player 2 won" << std::endl;
						return true;
					}
				}
			}
			else
				counter = 1;
			k--;
		}
	}
}

void printboard(){
	for (int ver = 0; ver <= 5; ver++) {                      // Printing out the board
		for (int hor = 0; hor <= 6; hor++) {
			std::cout << board[ver][hor];
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "1 2 3 4 5 6 7" << std::endl;
}

void player(char choice1 , char choice2) {
	bool boardfull = false;
	
	while (boardfull == false) {
		int row = 6;
		int choice;
		bool valid = false;
		std::cin >> choice;
			while (valid == false ) {
				if (row >= 0 && board[row][choice - 1] == 'x') {              // Fill the board with X's
					board[row][choice - 1] = choice1;
					valid = boardfull = true; 
				}
				else if (board[row][choice - 1] != 'x' && row >= 0) {
					row--;
				}
				else if (row < 0) {
					std::cout << "choose another row, row full" << std::endl;
					valid = true;
				}
			}
		}
	}

int main() {
	char p1;
	char p2;
	bool notsame = false;
	bool notx = false;
	bool boardfull = false;
	bool notx2 = false;

	while (notx == false) {
		std::cout << "player 1 choose symbol (please don't pick 'x' )" << std::endl;
		std::cin >> p1;
		if (p1 != 'x') {
			notx = true;
		}
	}
	while (notx2 == false && notsame == false) {
		std::cout << "player 2 choose symbol (please don't pick 'x' )" << std::endl;
		std::cin >> p2;
		if (p2 == p1) {
			std::cout << "player 2's symbol taken" << std::endl;
		}
		if (p2 == 'x') {
			std::cout << "don't pick x" << std::endl;
		}
		else if (p2 != 'x' && p2 != p1) {
			notx2 = true;
			notsame = true;
		}
	}
		for (int ver = 0; ver <= 6; ver++) {
			for (int hor = 0; hor <= 5; hor++) {
				board[hor][ver] = 'x';
			}
		}

		for (int i = 0; i <= 8; i++) {
			printboard();
			std::cout << "Player 1 chose a collem" << std::endl;
			player(p1, p2);
			printboard();
			win_checkH(p1, p2);
			win_checkV(p1, p2);
			win_checkD(p1, p2);
			std::cout << "Player 2 chose a collem" << std::endl;
			player(p2, p1);
			printboard();
			win_checkH(p1, p2);
			win_checkV(p1, p2);
			win_checkD(p1, p2);
		}

			system("pause");
			return 0;
	}




