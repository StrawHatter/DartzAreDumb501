//
//  main.cpp
//  Darts501
//
//  Created by Paul Dreczkowski on 22/04/2016.
//  Copyright © 2016 Paul Dreczkowski. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "Darts501.h"
#include <windows.h>


using namespace std;

int main() {
    Darts_501 Joe;                                                                                  // Objects "Joe" and "Sid" from class 'Darts_501'
    Darts_501 Sid;
    
    Joe.accuracy = 70;                                                                              //Set accuracy for each player
    Sid.accuracy = 75;
    
    bool joeTurn;
    bool joeStart = 1;
    
    int results[14] = { 0 };                                                                        //Array of results of matches, one for each outcome
    
    srand(time(NULL));
    
    for (int i = 0; i < N; i++) {                                                                   // Play 10,000 sets
        Sid.setWon = 0;
        Joe.setWon = 0;
        
        do
        {                                                                                           // Play match
            Sid.gameWon = 0;
            Joe.gameWon = 0;
            do
            {                                                                                       // Play set
                Joe.score = 501;
                Sid.score = 501;
                if (joeStart == 1)                                                                  //If Joe starts the game off, the next turn is his. If he didn't start it, Sid's turn is next
                    joeTurn = 1;
                else
                    joeTurn = 0;
                do
                {                                                                                   // Play one game
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
                } while ((Sid.score != 0) && (Joe.score != 0));                                     //Loop until someone wins
                if (joeStart == 1)                                                                  //If Joe started the game off, Sid's turn is next
                    joeStart = 0;
                else
                    joeStart = 1;                                                                   //If he didn't, Joe's turn is next
                if (Sid.score == 0)                                                                 //Whoever won a game, get's it added to a counter system
                    Sid.gameWon++;
                else if (Joe.score == 0)
                    Joe.gameWon++;
            } while (Sid.gameWon != 3 && Joe.gameWon != 3);
            if (Sid.gameWon == 3)
                Sid.setWon++;
            else if (Joe.gameWon == 3)
                Joe.setWon++;
        } while ((Sid.setWon != 7) && (Joe.setWon != 7));
        if (Sid.setWon == 7)
            results[Joe.setWon]++;
        else if (Joe.setWon == 7)
            results[Sid.setWon + 7]++;
    }
    
    cout << "Joe:Sid    Frequency" << endl;
    cout << "0  :  7  - %" << (float(results[0])/N)*100 << endl;                                      //Outputting things with frequencies. Added in floats to get nice looking percents
    cout << "1  :  7  - %" << (float(results[1])/N)*100 << endl;
    cout << "2  :  7  - %" << (float(results[2])/N)*100 << endl;
    cout << "3  :  7  - %" << (float(results[3])/N)*100 << endl;
    cout << "4  :  7  - %" << (float(results[4])/N)*100 << endl;
    cout << "5  :  7  - %" << (float(results[5])/N)*100 << endl;
    cout << "6  :  7  - %" << (float(results[6])/N)*100 << endl;
    cout << "7  :  0  - %" << (float(results[7])/N)*100 << endl;
    cout << "7  :  1  - %" << (float(results[8])/N)*100 << endl;
    cout << "7  :  2  - %" << (float(results[9])/N)*100 << endl;
    cout << "7  :  3  - %" << (float(results[10])/N)*100 << endl;
    cout << "7  :  4  - %" << (float(results[11])/N)*100 << endl;
    cout << "7  :  5  - %" << (float(results[12])/N)*100 << endl;
    cout << "7  :  6  - %" << (float(results[13])/N)*100 << endl;
    
    //cin.get(); merely  keeps the console open for saving screenshot purposes
    
    return 0;
}
