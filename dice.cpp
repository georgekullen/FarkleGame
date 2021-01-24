//George Kullen dice.cpp
#include "dice.h"
#include "uLCD_4DGL.h"

extern uLCD_4DGL uLCD;

Dice::Dice(){ //gives dice value of 0 when created
    number = 0;
}

void Dice::rollDice() { //rolls a die
    number = rand() % 6 + 1;
}

void Dice::displayDice(int position) {
    int radius = 3;
    int x = 0;
    int y = 0;
    //determines offset off of position input
    if (position == 0) {
        uLCD.rectangle(0, 0, 41, 41, GREEN);
        x = 0;
        y = 0;
    } else if (position == 1) {
        uLCD.rectangle(42, 0, 83, 41, GREEN);
        x = 42;
        y = 0;
    } else if (position == 2) {
        uLCD.rectangle(84, 0, 125, 41, GREEN);
        x = 84;
        y = 0;
    } else if (position == 3) {
        uLCD.rectangle(0, 42, 41, 83, GREEN);
        x = 0;
        y = 42;
    } else if (position == 4) {
        uLCD.rectangle(42, 42, 83, 83, GREEN);
        x = 42;
        y = 42;
    } else if (position == 5) {
        uLCD.rectangle(84, 42, 125, 83, GREEN);
        x = 84;
        y = 42;
    }
    if (number == 1) {
        uLCD.filled_circle(x + 21, y + 21, radius, GREEN);
        return;
    }
    if (number == 2) {
        uLCD.filled_circle(x + 12, y + 12, radius, GREEN);
        uLCD.filled_circle(x + 30, y + 30, radius, GREEN);
        return;
    }
    if (number == 3) {
        uLCD.filled_circle(x + 21, y + 21, radius, GREEN);
        uLCD.filled_circle(x + 12, y + 12, radius, GREEN);
        uLCD.filled_circle(x + 30, y + 30, radius, GREEN);
        return;
    }
    if (number == 4) {
        uLCD.filled_circle(x + 12, y + 12, radius, GREEN);
        uLCD.filled_circle(x + 30, y + 30, radius, GREEN);
        uLCD.filled_circle(x + 12, y + 30, radius, GREEN);
        uLCD.filled_circle(x + 30, y + 12, radius, GREEN);
        return;
    }
    if (number == 5) {
        uLCD.filled_circle(x + 12, y + 12, radius, GREEN);
        uLCD.filled_circle(x + 30, y + 30, radius, GREEN);
        uLCD.filled_circle(x + 12, y + 30, radius, GREEN);
        uLCD.filled_circle(x + 30, y + 12, radius, GREEN);
        uLCD.filled_circle(x + 21, y + 21, radius, GREEN);
        return;
    }
    if (number == 6) {
        uLCD.filled_circle(x + 12, y + 12, radius, GREEN);
        uLCD.filled_circle(x + 30, y + 30, radius, GREEN);
        uLCD.filled_circle(x + 12, y + 30, radius, GREEN);
        uLCD.filled_circle(x + 30, y + 12, radius, GREEN);
        uLCD.filled_circle(x + 12, y + 21, radius, GREEN);
        uLCD.filled_circle(x + 30, y + 21, radius, GREEN);
        return;
    }
}

void Dice::setDice(int n) {
    number = n;
}
        
int Dice::getDice() {
    return number;   
}