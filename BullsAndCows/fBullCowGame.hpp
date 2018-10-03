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
#include <string>

#endif /* FBullCowGame_hpp */

class FBullCowGame {
public:
    void Reset(); // TODO make a more rich return statement
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon();
    bool CheckGuessValidity(std::string);


private:
    int MyCurrentTry = 1;
    int MyMaxTries = 5;
    bool IsIsogram(std::string);

};
