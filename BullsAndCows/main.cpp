//
//  main.cpp
//  BullsAndCows
//
//  Created by asdf on 10/2/18.
//  Copyright © 2018 asdf. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
string GetGuess();

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
    cout << "Welcome to Bulls and Cows\n";
    cout << "Can you guess the ";
    cout << WORD_LENGTH;
    cout << " letter word I'm thinking of?\n";
    return;
}

void PlayGame() {
    constexpr int NUMBER_OF_TURNS = 5;
    for (int i = 1; i <= NUMBER_OF_TURNS; i++){
        string Guess = GetGuess();
        cout << "Your guess was: " << Guess;
        cout << endl;
    }
}

string GetGuess(){
    string Guess = "";
    getline(cin, Guess);
    return Guess;
}

bool AskToPlayAgain(){
    cout << "Play again? (y/n)";
    string Response = "";
    getline(cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
    
}
