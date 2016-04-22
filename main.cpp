#include <iostream>
#include <ctime>
#include "Darts501.h"
#include <windows.h>


using namespace std;

int main() {
	Darts_501 Joe;	// Declare object 'Joe' from class 'Darts_501'.
	Darts_501 Sid;  // Delcare object 'Sid' from class 'Darts_501'.

	Joe.accuracy = 70; //Set accuracy for each player
	Sid.accuracy = 75;
	
	bool joeTurn;
	bool joeStart = 1;

	int results[14] = { 0 }; //Array of results of matches, one for each possible outcome.

	srand(time(NULL));

	for (int i = 0; i < N; i++) { // Play 10k championships
		Sid.sWon = 0;
		Joe.sWon = 0;

		do
		{ // Play match
			Sid.gWon = 0;
			Joe.gWon = 0;
			do
			{ // Play set
				Joe.score = 501;
				Sid.score = 501;
				if (joeStart == 1) //if joe starts this game
					joeTurn = 1; //make next turn his
				else
					joeTurn = 0; //if not, make next turn sid's
				do
				{ // Play one game
					if (joeTurn == 0)
					{
						Sid.takeTurn();
						joeTurn = 1;
					}
					else
					{
						Joe.takeTurn();
						joeTurn = 0;
					}
				} while ((Sid.score != 0) && (Joe.score != 0)); //until someone wins
				if (joeStart == 1) //if joe started that game
					joeStart = 0; //make sid start next game
				else
					joeStart = 1; //if not, make joe start next game
				if (Sid.score == 0) //add game won to winner
					Sid.gWon++;
				else if (Joe.score == 0)
					Joe.gWon++;
			} while (Sid.gWon != 3 && Joe.gWon != 3);
			if (Sid.gWon == 3) 
				Sid.sWon++;
			else if (Joe.gWon == 3)
				Joe.sWon++;
		} while ((Sid.sWon != 7) && (Joe.sWon != 7));
		if (Sid.sWon == 7)
			results[Joe.sWon]++;
		else if (Joe.sWon == 7)
			results[Sid.sWon + 7]++;
	}

	cout << "Championship Match Result Compilation\nJoe:Sid" << endl << endl;

	cout << "0  :  7  - " << results[0] << endl;
	cout << "1  :  7  - " << results[1] << endl;
	cout << "2  :  7  - " << results[2] << endl;
	cout << "3  :  7  - " << results[3] << endl;
	cout << "4  :  7  - " << results[4] << endl;
	cout << "5  :  7  - " << results[5] << endl;
	cout << "6  :  7  - " << results[6] << endl;
	cout << "7  :  0  - " << results[7] << endl;
	cout << "7  :  1  - " << results[8] << endl;
	cout << "7  :  2  - " << results[9] << endl;
	cout << "7  :  3  - " << results[10] << endl;
	cout << "7  :  4  - " << results[11] << endl;
	cout << "7  :  5  - " << results[12] << endl;
	cout << "7  :  6  - " << results[13] << endl << endl;

	cin.get();

	return 0;
}
