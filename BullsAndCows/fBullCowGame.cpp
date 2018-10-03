//
//  FBullCowGame.cpp
//  BullsAndCows
//
//  Created by asdf on 10/2/18.
//  Copyright © 2018 asdf. All rights reserved.
//

#include "FBullCowGame.hpp"


bool FBullCowGame::CheckGuessValidity(std::string) { 
    return false;
}


bool FBullCowGame::IsGameWon() { 
    return false;
}


int FBullCowGame::GetCurrentTry() const {
    return MyCurrentTry;
}


void FBullCowGame::Reset() { 
    return;
}


int FBullCowGame::GetMaxTries() const { 
    return MyMaxTries;
}
