// Connect 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
#include <iostream>
#include <windows.h>   // WinApi header
#include <bitset>
#include <math.h>
#include <random>
#include <time.h>


using namespace std;




// C++ program to convert decimal
// number to ternary number

#include <cstdio>


// Function to convert a decimal
// number to a ternary number


// Function to convert the decimal to ternary


int log_a_to_base_b(int a, int b)
{
	return log2(a) / log2(b);
}

int main()
{

	srand(time(NULL));

	const int l = 19;
	const int w = 19;
	string list[l][w] = {};

	int placex = 0;
	int placey = 0;
	bool player = true;
	string token= "[X]";
	string token2 = "[O]";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);









	// Header
	SetConsoleTextAttribute(hConsole, 7);
	//cout << "   ";
	for (int i = 1; i < w + 1; i++) {

		int number = i;

		if (number == 10) {

			//cout << to_string(number) << " ";
		}

		if (number > 10) {

			//cout << " " << to_string(number) << " ";
		}

		if (number < 10) {

			//cout << " " << to_string(number) << "  ";
		}



	}
	//cout << endl;




	// Creating the board
	for (int i = 0; i < l; i++) {

		for (int j = 0; j < w; j++) {
			SetConsoleTextAttribute(hConsole, 8);
			list[i][j] = "[ ]";
		}
	}



	double pointsp1[l][w] = {};
	double taken = 0;
	double localpointsp1 = 0;

	double pointsp2[l][w] = {};
	double localpointsp2 = 0;
	int a2placex = 0;
	int a2placey = 0;



	int coeffp1[81] = {};
	string lettersp1[4][81] = {};
	int bit3p1[4][81];
	int used[81] = {};

	int coeffp2[81] = {};
	string lettersp2[4][81] = {};
	int bit3p2[4][81];

	








	// Printing 

	for (int i = 0; i < l; i++) {

		if (i > 8) {
			SetConsoleTextAttribute(hConsole, 7);
			cout << i + 1 << " ";
		}
		else {
			SetConsoleTextAttribute(hConsole, 7);
			cout << " " << i + 1 << " ";
		}

		for (int j = 0; j < w; j++) {
			SetConsoleTextAttribute(hConsole, 8);
			cout << list[i][j] << " ";
		}
		cout << endl;
		cout << endl;
	}


	// Creating coefficents
	for (int i = 0; i < 81; i++) {
		coeffp1[i] = 5;
		coeffp2[i] = (rand() % 10) + 1;



		if (lettersp1[0][i] == "[ ]" and lettersp1[1][i] == "[ ]" and lettersp1[2][i] == "[ ]" and lettersp1[3][i] == "[ ]") {
			coeffp1[i] = 0;

		}
		if (lettersp2[0][i] == "[ ]" and lettersp2[1][i] == "[ ]" and lettersp2[2][i] == "[ ]" and lettersp2[3][i] == "[ ]") {
			coeffp2[i] = 0;

		}
		//cout << coeffp1[i] << endl;
	}





	int wins = 0;
	while (wins < 100) {


		// Header
		SetConsoleTextAttribute(hConsole, 7);
		//cout << "   ";
		for (int i = 1; i < w + 1; i++) {

			int number = i;

			if (number == 10) {

				//cout << to_string(number) << " ";
			}

			if (number > 10) {

				//cout << " " << to_string(number) << " ";
			}

			if (number < 10) {

				//cout << " " << to_string(number) << "  ";
			}



		}
		//cout << endl;




		// Creating the board
		for (int i = 0; i < l; i++) {

			for (int j = 0; j < w; j++) {
				SetConsoleTextAttribute(hConsole, 8);
				list[i][j] = "[ ]";
			}
		}












		// Printing 

		for (int i = 0; i < l; i++) {

			if (i > 8) {
				SetConsoleTextAttribute(hConsole, 7);
				//cout << i + 1 << " ";
			}
			else {
				SetConsoleTextAttribute(hConsole, 7);
				//cout << " " << i + 1 << " ";
			}

			for (int j = 0; j < w; j++) {
				SetConsoleTextAttribute(hConsole, 8);
				//cout << list[i][j] << " ";
			}
			//cout << endl;
			//cout << endl;
		}


		// AI formula /////////////////////////////////////////////////////
		

		int y = 0;

		for (int i = 0; i < 81; i++) {
			int n = i;

			bit3p1[3][i] = n % 3;
			n /= 3;
			bit3p1[2][i] = n % 3;
			n /= 3;
			bit3p1[1][i] = n % 3;
			n /= 3;
			bit3p1[0][i] = n % 3;
			
			int b = i;
			bit3p2[3][i] = b % 3;
			b /= 3;
			bit3p2[2][i] = b % 3;
			b /= 3;
			bit3p2[1][i] = b % 3;
			b /= 3;
			bit3p2[0][i] = b % 3;
		}

		// c = char
		for (int i = 0; i < 81; i++) {
			for (int c = 0; c < 4; c++) {
				if (bit3p1[c][i] == 0) {
					lettersp1[c][i] = "[ ]";
				}
				if (bit3p1[c][i] == 1) {
					lettersp1[c][i] = token;
				}
				if (bit3p1[c][i] == 2) {
					lettersp1[c][i] = token2;
				}
			}
		}

		// Switching players
		if (player == true) {
			token = "[X]";
			token2 = "[O]";
		}
		else {
			token = "[O]";
			token2 = "[X]";
		}

		
		// c = char
		for (int i = 0; i < 81; i++) {
			for (int c = 0; c < 4; c++) {
				if (bit3p2[c][i] == 0) {
					lettersp2[c][i] = "[ ]";
				}
				if (bit3p2[c][i] == 1) {
					lettersp2[c][i] = token;
				}
				if (bit3p2[c][i] == 2) {
					lettersp2[c][i] = token2;
				}
			}
		}


		




		
			






































		bool end = false;
		while (end == false) {
			bool check = true;




			// Switching players
			if (player == true) {
				token = "[X]";
				token2 = "[O]";
			}
			else {
				token = "[O]";
				token2 = "[X]";
			}



			for (int i = 0; i < l; i++) {

				for (int j = 0; j < w; j++) {
					if (list[i][j] == "[X]" or list[i][j] == "[O]") {
						taken = 0;

					}
					else {
						taken = 1;
					}

					int lenl = j;
					int lenr = w - j;
					int lenu = i;
					int lend = l - i;


					int lenul = min(lenl, lenu);
					int lenur = min(lenr, lenu);
					int lendl = min(lenl, lend);
					int lendr = min(lenr, lend);
					localpointsp2 = 0;

					//cout << "lenr: " << lenr << endl;


					if (i == l / 2 and j == w / 2) {
						localpointsp2 += 0.01;
					}


					// Scan 4 Same 4/////////////////////////////////////////////////////////////////////////////////////////////////////////////

					// Scan 4 right
					for (int n = 0; n < 81; n++) {
						if (lenr > 4) {
							if (list[i][j + 1] == lettersp2[0][n] and list[i][j + 2] == lettersp2[1][n] and list[i][j + 3] == lettersp2[2][n] and list[i][j + 4] == lettersp2[3][n]) {
								localpointsp2 += coeffp2[n];
							}
						}

						// Scan 4 left
						if (lenl > 4) {
							if (list[i][j - 1] == lettersp2[0][n] and list[i][j - 2] == lettersp2[1][n] and list[i][j - 3] == lettersp2[2][n] and list[i][j - 4] == lettersp2[3][n]) {
								localpointsp2 += coeffp2[n];
							}
						}

						// Scan 4 up
						if (lenu > 4) {
							if (list[i - 1][j] == lettersp2[0][n] and list[i - 2][j] == lettersp2[1][n] and list[i - 3][j] == lettersp2[2][n] and list[i - 4][j] == lettersp2[3][n]) {
								localpointsp2 += coeffp2[n];
							}
						}

						// Scan 4down
						if (lend > 4) {
							if (list[i + 1][j] == lettersp2[0][n] and list[i + 2][j] == lettersp2[1][n] and list[i + 3][j] == lettersp2[2][n] and list[i + 4][j] == lettersp2[3][n]) {
								localpointsp2 += coeffp2[n];
							}
						}

						// Scan 4 up right
						if (lenur > 4) {
							if (list[i - 1][j + 1] == lettersp2[0][n] and list[i - 2][j + 2] == lettersp2[1][n] and list[i - 3][j + 3] == lettersp2[2][n] and list[i - 4][j + 4] == lettersp2[3][n]) {
								localpointsp2 += coeffp2[n];
							}
						}

						// Scan 4 up left
						if (lenul > 4) {
							if (list[i - 1][j - 1] == lettersp2[0][n] and list[i - 2][j - 2] == lettersp2[1][n] and list[i - 3][j - 3] == lettersp2[2][n] and list[i - 4][j - 4] == lettersp2[3][n]) {
								localpointsp2 += coeffp2[n];
							}
						}

						// Scan 4 down left
						if (lendl > 4) {
							if (list[i + 1][j - 1] == lettersp2[0][n] and list[i + 2][j - 2] == lettersp2[1][n] and list[i + 3][j - 3] == lettersp2[2][n] and list[i + 4][j - 4] == lettersp2[3][n]) {
								localpointsp2 += coeffp2[n];
							}
						}

						// Scan 4 down right
						if (lendr > 4) {
							if (list[i + 1][j + 1] == lettersp2[0][n] and list[i + 2][j + 2] == lettersp2[1][n] and list[i + 3][j + 3] == lettersp2[2][n] and list[i + 4][j + 4] == lettersp2[3][n]) {
								localpointsp2 += coeffp2[n];
							}
						}

					}

					pointsp2[i][j] = localpointsp2 * taken;
				}
			}


			int a2placex = 0;
			int a2placey = 0;
			double highest = 0;
			for (int i = 0; i < l; i++) {

				for (int j = 0; j < w; j++) {
					if (pointsp2[i][j] >= highest) {
						a2placey = i;
						a2placex = j;
						highest = pointsp2[i][j];
						//cout << pointsp2[i][j] << endl;
					}

				}
			}

			list[a2placey][a2placex] = token;
			if (player == true) {
				player = false;
			}
			else {
				player = true;
			}




			if (player == true) {
				token = "[X]";
				token2 = "[O]";
			}
			else {
				token = "[O]";
				token2 = "[X]";
			}

			











			// J is X, I is Y

			// J+ is right, I+ is down


			



			for (int i = 0; i < l; i++) {

				for (int j = 0; j < w; j++) {
					if (list[i][j] == "[X]" or list[i][j] == "[O]") {
						taken = 0;

					}
					else {
						taken = 1;
					}

					int lenl = j;
					int lenr = w - j;
					int lenu = i;
					int lend = l - i;


					int lenul = min(lenl, lenu);
					int lenur = min(lenr, lenu);
					int lendl = min(lenl, lend);
					int lendr = min(lenr, lend);
					localpointsp1 = 0;

					//cout << "lenr: " << lenr << endl;


					if (i == l / 2 and j == w / 2) {
						localpointsp1 += 0.01;
					}


					// Scan 4 Same 4/////////////////////////////////////////////////////////////////////////////////////////////////////////////

					// Scan 4 right
					for (int n = 0; n < 81; n++) {
						if (lenr > 4) {
							if (list[i][j + 1] == lettersp1[0][n] and list[i][j + 2] == lettersp1[1][n] and list[i][j + 3] == lettersp1[2][n] and list[i][j + 4] == lettersp1[3][n]) {
								localpointsp1 += coeffp1[n];
							}
						}

						// Scan 4 left
						if (lenl > 4) {
							if (list[i][j - 1] == lettersp1[0][n] and list[i][j - 2] == lettersp1[1][n] and list[i][j - 3] == lettersp1[2][n] and list[i][j - 4] == lettersp1[3][n]) {
								localpointsp1 += coeffp1[n];
							}
						}

						// Scan 4 up
						if (lenu > 4) {
							if (list[i - 1][j] == lettersp1[0][n] and list[i - 2][j] == lettersp1[1][n] and list[i - 3][j] == lettersp1[2][n] and list[i - 4][j] == lettersp1[3][n]) {
								localpointsp1 += coeffp1[n];
							}
						}

						// Scan 4down
						if (lend > 4) {
							if (list[i + 1][j] == lettersp1[0][n] and list[i + 2][j] == lettersp1[1][n] and list[i + 3][j] == lettersp1[2][n] and list[i + 4][j] == lettersp1[3][n]) {
								localpointsp1 += coeffp1[n];
							}
						}

						// Scan 4 up right
						if (lenur > 4) {
							if (list[i - 1][j + 1] == lettersp1[0][n] and list[i - 2][j + 2] == lettersp1[1][n] and list[i - 3][j + 3] == lettersp1[2][n] and list[i - 4][j + 4] == lettersp1[3][n]) {
								localpointsp1 += coeffp1[n];
							}
						}

						// Scan 4 up left
						if (lenul > 4) {
							if (list[i - 1][j - 1] == lettersp1[0][n] and list[i - 2][j - 2] == lettersp1[1][n] and list[i - 3][j - 3] == lettersp1[2][n] and list[i - 4][j - 4] == lettersp1[3][n]) {
								localpointsp1 += coeffp1[n];
							}
						}

						// Scan 4 down left
						if (lendl > 4) {
							if (list[i + 1][j - 1] == lettersp1[0][n] and list[i + 2][j - 2] == lettersp1[1][n] and list[i + 3][j - 3] == lettersp1[2][n] and list[i + 4][j - 4] == lettersp1[3][n]) {
								localpointsp1 += coeffp1[n];
							}
						}

						// Scan 4 down right
						if (lendr > 4) {
							if (list[i + 1][j + 1] == lettersp1[0][n] and list[i + 2][j + 2] == lettersp1[1][n] and list[i + 3][j + 3] == lettersp1[2][n] and list[i + 4][j + 4] == lettersp1[3][n]) {
								localpointsp1 += coeffp1[n];
							}
						}

					}

					pointsp1[i][j] = localpointsp1 * taken;
				}
			}


			int aplacex = 0;
			int aplacey = 0;
			highest = 0;
			for (int i = 0; i < l; i++) {

				for (int j = 0; j < w; j++) {
					if (pointsp1[i][j] >= highest) {
						aplacey = i;
						aplacex = j;
						highest = pointsp1[i][j];
						//cout << pointsp1[i][j] << endl;
					}

				}
			}
			
			list[aplacey][aplacex] = token;
			if (player == true) {
				player = false;
			}
			else {
				player = true;
			}


			

			if (player == true) {
				token = "[X]";
				token2 = "[O]";
			}
			else {
				token = "[O]";
				token2 = "[X]";
			}


			// Printing again

			for (int i = 0; i < l; i++) {
				if (i > 8) {
					SetConsoleTextAttribute(hConsole, 7);
					//cout << i + 1 << " ";
				}
				else {
					SetConsoleTextAttribute(hConsole, 7);
					//cout << " " << i + 1 << " ";
				}

				for (int j = 0; j < w; j++) {
					//cout << " " << pointsp1[i][j] << "  ";
				}
				//cout << endl;
				//cout << endl;
			}

			// Printing again

			for (int i = 0; i < l; i++) {
				if (i > 8) {
					SetConsoleTextAttribute(hConsole, 7);
					//cout << i + 1 << " ";
				}
				else {
					SetConsoleTextAttribute(hConsole, 7);
					//cout << " " << i + 1 << " ";
				}

				for (int j = 0; j < w; j++) {
					//out << " " << pointsp2[i][j] << "  ";
				}
				//cout << endl;
				//cout << endl;
			}




			// Header
			SetConsoleTextAttribute(hConsole, 7);
			//cout << "   ";
			for (int i = 1; i < w + 1; i++) {

				int number = i;

				if (number == 10) {

					//cout << to_string(number) << " ";
				}

				if (number > 10) {

					//cout << " " << to_string(number) << " ";
				}

				if (number < 10) {

					//cout << " " << to_string(number) << "  ";
				}



			}
			//cout << endl;










			// Printing the board
			for (int i = 0; i < l; i++) {
				if (i > 8) {
					SetConsoleTextAttribute(hConsole, 7);
					//cout << i + 1 << " ";
				}
				else {
					SetConsoleTextAttribute(hConsole, 7);
					//cout << " " << i + 1 << " ";
				}

				for (int j = 0; j < w; j++) {
					if (list[i][j] == "[X]") {
						SetConsoleTextAttribute(hConsole, 14);
						//cout << list[i][j] << " ";
					}
					if (list[i][j] == "[O]") {
						SetConsoleTextAttribute(hConsole, 11);
						//cout << list[i][j] << " ";
					}
					if (list[i][j] == "[ ]") {
						SetConsoleTextAttribute(hConsole, 8);
						//cout << list[i][j] << " ";
					}
				}
				//cout << endl;
				//cout << endl;
			}



			// Sideways win

			for (int i = 0; i < l; i++) {

				for (int j = 0; j < w - 4; j++) {
					if (list[i][j] == "[X]" and list[i][j + 1] == "[X]" and list[i][j + 2] == "[X]" and list[i][j + 3] == "[X]" and list[i][j + 4] == "[X]") {
						end = true;
						//cout << "X win!" << "sideways starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins = 0;
						
					}
					if (list[i][j] == "[O]" and list[i][j + 1] == "[O]" and list[i][j + 2] == "[O]" and list[i][j + 3] == "[O]" and list[i][j + 4] == "[O]") {
						end = true;
						//cout << "O win!" << "sideways starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins += 1;
					}
				}
			}

			//Vert win list[y][x]
			for (int j = 0; j < w; j++) {

				for (int i = 0; i < l - 4; i++) {
					if (list[i][j] == "[X]" and list[i + 1][j] == "[X]" and list[i + 2][j] == "[X]" and list[i + 3][j] == "[X]" and list[i + 4][j] == "[X]") {
						end = true;
						//cout << "X win!" << "verticle starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins = 0;
					}
					if (list[i][j] == "[O]" and list[i + 1][j] == "[O]" and list[i + 2][j] == "[O]" and list[i + 3][j] == "[O]" and list[i + 4][j] == "[O]") {
						end = true;
						//cout << "O win!" << "verticle starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins += 1;
					}
				}
			}

			// down right win list[y][x] = list[i][j]
			for (int j = 0; j < w - 4; j++) {

				for (int i = 0; i < l - 4; i++) {
					if (list[i][j] == "[X]" and list[i + 1][j + 1] == "[X]" and list[i + 2][j + 2] == "[X]" and list[i + 3][j + 3] == "[X]" and list[i + 4][j + 4] == "[X]") {
						end = true;
						//cout << "X win!" << "down right starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins = 0;
					}
					if (list[i][j] == "[O]" and list[i + 1][j + 1] == "[O]" and list[i + 2][j + 2] == "[O]" and list[i + 3][j + 3] == "[O]" and list[i + 4][j + 4] == "[O]") {
						end = true;
						//cout << "O win!" << "down right starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins += 1;
					}
				}
			}


			// down left win list[y][x] = list[i][j]
			for (int j = 4; j < w; j++) {

				for (int i = 0; i < l - 4; i++) {
					if (list[i][j] == "[X]" and list[i + 1][j - 1] == "[X]" and list[i + 2][j - 2] == "[X]" and list[i + 3][j - 3] == "[X]" and list[i + 4][j - 4] == "[X]") {
						end = true;
						//cout << "X win!" << "down left starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins = 0;
					}
					if (list[i][j] == "[O]" and list[i + 1][j - 1] == "[O]" and list[i + 2][j - 2] == "[O]" and list[i + 3][j - 3] == "[O]" and list[i - 4][j - 4] == "[O]") {
						end = true;
						//cout << "O win!" << "down left starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins += 1;
					}
				}
			}

			// up left win list[y][x] = list[i][j]
			for (int j = 4; j < w; j++) {

				for (int i = 4; i < l; i++) {
					if (list[i][j] == "[X]" and list[i - 1][j - 1] == "[X]" and list[i - 2][j - 2] == "[X]" and list[i - 3][j - 3] == "[X]" and list[i - 4][j - 4] == "[X]") {
						end = true;
						//cout << "X win!" << "up left starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins = 0;
					}
					if (list[i][j] == "[O]" and list[i - 1][j - 1] == "[O]" and list[i - 2][j - 2] == "[O]" and list[i - 3][j - 3] == "[O]" and list[i - 4][j - 4] == "[O]") {
						end = true;
						//cout << "O win!" << "up left starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins += 1;
					}
				}
			}

			// up right win list[y][x] = list[i][j]
			for (int j = 0; j < w - 4; j++) {

				for (int i = 4; i < l; i++) {
					if (list[i][j] == "[X]" and list[i - 1][j + 1] == "[X]" and list[i - 2][j + 2] == "[X]" and list[i - 3][j + 3] == "[X]" and list[i - 4][j + 4] == "[X]") {
						end = true;
						//cout << "X win!" << "up right starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins = 0;
					}
					if (list[i][j] == "[O]" and list[i - 1][j + 1] == "[O]" and list[i - 2][j + 2] == "[O]" and list[i - 3][j + 3] == "[O]" and list[i - 4][j + 4] == "[O]") {
						end = true;
						//cout << "O win!" << "up right starting at X: " << j + 1 << " and Y:" << i + 1 << endl;
						wins += 1;
					}
				}
			}
		}
		srand(time(NULL));

		if (wins == 0) {
			for (int i = 0; i < 81; i++) {
				if (coeffp1[i] > coeffp2[i]) {
					coeffp1[i] -= 1;
				}
				if (coeffp1[i] < coeffp2[i]) {
					coeffp1[i] += 1;
				}
				

				coeffp2[i] = (rand() % 10) + 1;
				if (lettersp1[0][i] == "[ ]" and lettersp1[1][i] == "[ ]" and lettersp1[2][i] == "[ ]" and lettersp1[3][i] == "[ ]") {
					coeffp1[i] = 0;
					
				}
				if (lettersp2[0][i] == "[ ]" and lettersp2[1][i] == "[ ]" and lettersp2[2][i] == "[ ]" and lettersp2[3][i] == "[ ]") {
					coeffp2[i] = 0;

				}
				
			}
			//cout << "GOT BEAT" << endl;
		}

		if (wins > 0) {
			for (int i = 0; i < 81; i++) {
				coeffp2[i] = (rand() % 10) + 1;



				if (lettersp1[0][i] == "[ ]" and lettersp1[1][i] == "[ ]" and lettersp1[2][i] == "[ ]" and lettersp1[3][i] == "[ ]") {
					coeffp1[i] = 0;

				}
				if (lettersp2[0][i] == "[ ]" and lettersp2[1][i] == "[ ]" and lettersp2[2][i] == "[ ]" and lettersp2[3][i] == "[ ]") {
					coeffp2[i] = 0;

				}
				//cout << coeffp1[i] << endl;
			}
		}
		//cout << " PLayer 2:" << endl;
		for (int i = 0; i < 81; i++) {
			//cout << coeffp2[i] << endl;
		}
		cout << wins << endl;

	}
	cout << " PLayer 1:" << endl;
	for (int i = 0; i < 81; i++) {
		cout << coeffp1[i] << endl;
	}

	


}


