#include <iostream>
#include "Darts501.h"
#include <windows.h>
using namespace std;

const int N = 10000;

int Darts_501::bull(int p) {
	
	//  Throw for the bull with accuracy p%  (20<p<85)
	
	int r = rand()%100;
	
	if(r<(p-20))
		return 50;
	else if(r<85)	
		return 25;	
	else
		return 1+rand()%20;
}


int Darts_501::throw_single(int d) {

	//  return result of throwing for single d with accuracy 88% (or 80% for the outer)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
	{ 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };
	int r = rand() % 100;

	if (d == 25){		// outer  80%
		if (r<80)
			return 25;
		else if (r<90)
			return 50;
		else
			return 1 + rand() % 20;
	}
	else			// 1 to 20 single
		if (r<88)
			return d;
		else if (r<92)
			return bd[0][d];
		else if (r<96)
			return bd[1][d];
		else if (r<98)
			return 3 * d;
		else
			return 2 * d;
}

int Darts_501::throw_double(int d) {

	//  return result of throwing for double d with accuracy 80%

	// Board neighbours ignoring slot zero
	int bd[2][21] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
	{ 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };
	int r = rand() % 100;
	if (r<80)
		return 2 * d;
	else if (r<85)
		return 0;
	else if (r<90)
		return d;
	else if (r<93)
		return 2 * bd[0][d];
	else if (r<96)
		return 2 * bd[1][d];
	else if (r<98)
		return bd[0][d];
	else
		return bd[1][d];
}

int Darts_501::throw_treble(int d, int p) {

	//  return result of throwing for treble d with accuracy p%  (o<90)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
	{ 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };

	int r = rand() % 100;

	if (r<p)
		return 3 * d;
	else if (r<90)
		return d;
	else if (r<93)
		return 3 * bd[0][d];
	else if (r<96)
		return 3 * bd[1][d];
	else if (r<98)
		return bd[0][d];
	else
		return bd[1][d];
}

void Darts_501::takeTurn() {
	darts = 0;
	int temp = score;
	bool thrown = 0;

	do {
		if (score > 109)
			curr_state = fast;
		else if (score > 50)
			curr_state = slow;
		else if (score == 50)
			curr_state = earlyfinish;
		else if (score > 40)
			curr_state = focus;
		else
			curr_state = out;

		switch (curr_state) {
		case fast:	score -= throw_treble(20, accuracy);
			break;

		case slow:
			for (int i = 0; i <= 20; i++)
			{
				if (score - 50 == i)
				{
					score -= throw_single(i);
					i = 21; //break for loop
					thrown = 1; //indicate dart thrown
				}
				else if (score - 50 == (2 * i))
				{
					score -= throw_double(i);
					i = 21; //break for loop
					thrown = 1; //indicate dart thrown
				}
				else if (score - 50 == (3 * i))
				{
					score -= throw_treble(i, accuracy);
					i = 21; //break for loop
					thrown = 1; //indicate dart thrown
				}
			}
			if (thrown == 0)
				score -= throw_treble(20, accuracy);
			break;
		
		case earlyfinish:	
			score -= bull(accuracy);
			break;

		case focus:	
			score -= throw_single(score - 40);
			break;

		case out:
			if (score % 2 == 1)
				score -= throw_single(1);
			else
				score -= throw_double(score / 2);

		}
		darts++;
	} while ((score > 1) && (darts < 3));
	if (score == 1 || score < 0)
		score = temp;
}
