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
FText GetGuess();
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
    constexpr int32 WORD_LENGTH = 5;
    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the ";
    std::cout << WORD_LENGTH;
    std::cout << " letter word I'm thinking of?\n";
    int32 CurrentTry = BCGame.GetCurrentTry();
    std::cout << "Try " << CurrentTry << std::endl;
    return;
}

void PlayGame() {
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries << std::endl;

    for (int32 i = 1; i <= MaxTries; i++){
        FText Guess = GetGuess();
        std::cout << "Your guess was: " << Guess;
        std::cout << std::endl;
    }
}

FText GetGuess(){
    FText Guess = "";
    getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain(){
    std::cout << "Play again? (y/n)";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
    
}
