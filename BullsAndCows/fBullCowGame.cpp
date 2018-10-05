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

FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
    // increment turn number
    MyCurrentTry++;
    
    // setup a return variable
    FBullCowCount BullCowCount;
    
    // loop through all letters in the guess
    int32 HiddenWordLength = MyHiddenWord.length();
    for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
        // compare letters against hidden word
        for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
        // if they match then
            if ( Guess[GChar] == MyHiddenWord[MHWChar] ) {
                if ( MHWChar == GChar ) {
                    BullCowCount.Bulls++;
                } else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    return BullCowCount;
}

