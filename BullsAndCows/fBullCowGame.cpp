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

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    // if the guess isn't an isogram, return an error
    if (false)
    {
        return EGuessStatus::Not_Isogram;
    }
    // if the guess isn't lowercase
    else if (false)
    {
        return EGuessStatus::Not_Lowercase;
    }
    // if the guess length is wrong
    else if ( Guess.length() != GetHiddenWordLength() )
    {
        return EGuessStatus::Wrong_Length;
    }
    // otherwise return OK
    else
    {
        return EGuessStatus::OK;
    }
};

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

int32 FBullCowGame::GetHiddenWordLength() const
{
    return MyHiddenWord.length();
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
    // increment turn number
    MyCurrentTry++;
    
    // setup a return variable
    FBullCowCount BullCowCount;
    
    // loop through all letters in the guess
    int32 Wordlength = MyHiddenWord.length(); //assuming guess and hidden are the same length
    for (int32 MHWChar = 0; MHWChar < Wordlength; MHWChar++) {
        // compare letters against hidden word
        for (int32 GChar = 0; GChar < Wordlength; GChar++) {
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

