//
//  main.cpp
//  BullCowGame
//
//  Created by Stii on 2018/03/29.
//  Copyright © 2018 Stii. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess(int32);
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main(int argc, const char * argv[])
{
    std::cout << BCGame.GetMaxTries();
    bool bPlayAgain = false;
    do {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while (bPlayAgain);
    return 0;
}

void PlayGame() {
    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries << std::endl;
    
    for (int32 i = 1; i <= MaxTries; i++) {
        int32 CurrentTry = BCGame.GetCurrentTry();
        FText Answer = GetGuess(CurrentTry);
        EGuessStatus Status = BCGame.CheckGuessValidity(Answer);
        if (Status == EGuessStatus::OK) {
            FBullCowCount BullCowCount = BCGame.SubmitGuess(Answer);
            std::cout << "Bulls = " << BullCowCount.Bulls << " ";
            std::cout << "Cows = " << BullCowCount.Cows;
        }
        else {
            std::cout << "Error!";
        }
        std::cout << std::endl;
    }
    return;
}

void PrintIntro()
{
    std::cout << "Welcome to Bulls and Cows" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?" << std::endl;
    return;
}

FText GetGuess(int32 TryNumber)
{
    FText Guess = "";
    std::cout << "Try " << TryNumber << ". Take a guess: ";
    getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? [y/n]: ";
    FText Answer = "";
    getline(std::cin, Answer);
    return (Answer[0] == 'y' || Answer[0] == 'Y');
}
