//George Kullen dice.h
#include "mbed.h"

#ifndef DICE_H
#define DICE_H

using namespace std;

class Dice
{
    public:
        Dice();
        void rollDice(); //roll a die
        void displayDice(int); //display a die with position
        void setDice(int); //set a die to a value (for debugging mostly)
        int getDice(); //get value of a die
    private:
        int number; //value of die
};
#endif