//
//  Darts501.h
//  Darts501
//
//  Created by Paul Dreczkowski on 22/04/2016.
//  Copyright © 2016 Paul Dreczkowski. All rights reserved.
//

#ifndef _DARTS_501_CLASS_H											// Using a header file in order to speed up compile time, 
#define _DARTS_501_CLASS_H

enum state { fast, slow, earlyfinish, focus, out };					// Using enums to make FSM's to make life easier
extern const int N;

class Darts_501{													//Darts_501 class with it's attributes
public:
    
    int accuracy;
    int score;
    state state_of_player;
    int darts;
    int bull(int p);
    int throw_single(int single);
    int throw_double(int d);
    int throw_treble(int d, int p);
    void takeTurn();
    int gameWon;
    int setWon;
};

#endif															//End of header file
