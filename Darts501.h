#ifndef _DARTS_501_CLASS_H
#define _DARTS_501_CLASS_H

enum state { fast, slow, earlyfinish, focus, out };
extern const int N;

class Darts_501{
public:

	int accuracy;
	int score;
	state curr_state;
	int darts;
	int bull(int p);
	int throw_single(int single);
	int throw_double(int d);
	int throw_treble(int d, int p);
	void takeTurn();
	int gWon;
	int sWon;
};

#endif
