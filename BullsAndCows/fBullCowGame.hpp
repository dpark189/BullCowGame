//
//  FBullCowGame.hpp
//  BullsAndCows
//
//  Created by asdf on 10/2/18.
//  Copyright © 2018 asdf. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>

#endif /* FBullCowGame_hpp */

class FBullCowGame {
public:
    void Reset(); // TODO make a more rich return statement
    int GetMaxTries();
    int GetCurrentTry();
    bool IsGameWon();
    bool CheckGuessValidity(string);


private:
    int MyCurrentTry;
    int MyMaxTries;
    bool IsIsogram(string);

};
