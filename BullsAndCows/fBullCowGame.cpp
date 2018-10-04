//
//  FBullCowGame.cpp
//  BullsAndCows
//
//  Created by asdf on 10/2/18.
//  Copyright © 2018 asdf. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() {
    Reset();
}

bool FBullCowGame::CheckGuessValidity(FString) { 
    return false;
}

int32 FBullCowGame::GetCurrentTry() const {
    return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const{
    return false;
}


int32 FBullCowGame::GetMaxTries() const { 
    return MyMaxTries;
}

void FBullCowGame::Reset() {
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    return;
}

BullCowCount FBullCowGame::SubmitGuess(FString) {
    // increment turn number
    MyCurrentTry++;
    // setup a return variable
    BullCowCount BullCowCount;
    // loop through all letters in the guess
        // compare letters against hidden word
    return BullCowCount;
}

