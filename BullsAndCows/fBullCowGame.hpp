//
//  FBullCowGame.hpp
//  BullsAndCows
//
//  Created by asdf on 10/2/18.
//  Copyright © 2018 asdf. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp
#endif /* FBullCowGame_hpp */
#include <stdio.h>
#include <string>

using FString = std::string;
using int32 = int;

// two integers intialised to 0
struct BullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};


class FBullCowGame
{
public:
    FBullCowGame(); // Constructor
    
    void Reset(); // TODO make a more rich return statement
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    bool CheckGuessValidity(FString);
    
    //counts bulls & cows, and increases try # assuming valid guess
    BullCowCount SubmitGuess(FString);


private:
//    see constructor
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool IsIsogram(FString);

};
