//George Kullen farkleGame.h
#include "mbed.h"
#include "dice.h"

#ifndef FARKLEGAME_H
#define FARKLEGAME_H

#define NUM_DICE 6
using namespace std;

class FarkleGame
{
     public:
        FarkleGame(); //no arg constructor that initializes diceArray
        int calcRoll(); //calculates score of dicearray
        Dice diceArray[NUM_DICE]; //public array of dice
        int getScoringDice(); //returns # of dice that scored since last call of calcRoll
    private:
        int scoringDice; //stores # of dice that scored since last call of calcRoll
};
#endif
