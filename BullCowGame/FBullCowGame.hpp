//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Stii on 2018/03/29.
//  Copyright © 2018 Stii. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus
{
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame
{
public:
    FBullCowGame();
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;
    
    FBullCowCount SubmitGuess(FString);
    
    void Reset();
    
private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};

#endif /* FBullCowGame_hpp */
