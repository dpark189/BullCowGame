//
//  main.cpp
//  BullsAndCows
//
//  Created by asdf on 10/2/18.
//  Copyright © 2018 asdf. All rights reserved.
//
/* This is the console executable, that makes use of the BullCow Class
 this acts as a view in a mvc pattern, and is responsible for all user interaction for game logic see the FBullCowGame class.
 */
#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FText GetValidGuess();
FBullCowGame BCGame; //instantiate game

int main(int32 argc, const char * argv[]) {
    // insert code here...
    bool bWantsToPlayAgain = false;
    do {
        PrintIntro();
        PlayGame();
        bWantsToPlayAgain = AskToPlayAgain();
    } while (bWantsToPlayAgain);
    return 0;
}

void PrintIntro(){
    std::cout << "\n\nWelcome to Bulls and Cows\n";
    std::cout << "Can you guess the ";
    std::cout << BCGame.GetHiddenWordLength();
    std::cout << " letter word I'm thinking of?\n";
    int32 CurrentTry = BCGame.GetCurrentTry();
    std::cout << "Try " << CurrentTry << std::endl;
    return;
}

void PlayGame() {
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries << std::endl;
    // loop for the number of turns asking for guesses
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
        FText Guess = GetValidGuess();
        
        // submit valid guess to the game and receive counts
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
        std::cout << "Your guess was: " << Guess;
        std::cout << std::endl;
    }
}

// loop until player gives valid guess
FText GetValidGuess()
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    do {
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << ". Enter your guess: ";
        
        getline(std::cin, Guess);
        
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " length word.\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter only lowercase letters";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter a word with no repeating letters";
                break;
            default:
                break;
        }
    } while (Status != EGuessStatus::OK); // keep looping until no errors

    return Guess;
}

bool AskToPlayAgain(){
    std::cout << "Play again? (y/n)";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
    
}
