//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Stii on 2018/03/29.
//  Copyright © 2018 Stii. All rights reserved.
//
#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame()
{
    Reset();
}

void FBullCowGame::Reset()
{
    MyCurrentTry = 1;
    MyMaxTries = 8;
    MyHiddenWord = "planet";
    return;
}

int32 FBullCowGame::GetMaxTries() const
{
    return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
    return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
    return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (false) {
        return EGuessStatus::Not_Isogram;
    }
    else if (Guess.length() != GetHiddenWordLength()) {
        return EGuessStatus::Wrong_Length;
    }
    else if (false) {
        return EGuessStatus::Not_Lowercase;
    }
    else {
        return EGuessStatus::OK;
    }
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 HiddenWordLength = MyHiddenWord.length();
    for (int32 HWChar = 0; HWChar < HiddenWordLength; HWChar++) {
        for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
            if (Guess[GChar] == MyHiddenWord[HWChar]) {
                if (HWChar == GChar) {
                    BullCowCount.Bulls++;
                } else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    return BullCowCount;
}

int32 FBullCowGame::GetHiddenWordLength() const { 
    return MyHiddenWord.length();
}


