//
//  main.cpp
//  BullsAndCows
//
//  Created by asdf on 10/2/18.
//  Copyright © 2018 asdf. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
std::string GetGuess();
FBullCowGame BCGame; //instantiate game

int main(int argc, const char * argv[]) {
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
    constexpr int WORD_LENGTH = 5;
    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the ";
    std::cout << WORD_LENGTH;
    std::cout << " letter word I'm thinking of?\n";
    int CurrentTry = BCGame.GetCurrentTry();
    std::cout << "Try " << CurrentTry << std::endl;
    return;
}

void PlayGame() {
    int MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries << std::endl;

    for (int i = 1; i <= MaxTries; i++){
        std::string Guess = GetGuess();
        std::cout << "Your guess was: " << Guess;
        std::cout << std::endl;
    }
}

std::string GetGuess(){
    std::string Guess = "";
    getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain(){
    std::cout << "Play again? (y/n)";
    std::string Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
    
}
