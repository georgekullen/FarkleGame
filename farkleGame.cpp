//George Kullen farkleGame.cpp
#include "farkleGame.h"

using namespace std;

FarkleGame::FarkleGame() {
    for (int i = 0; i < 6; i++) {
        diceArray[i].setDice(0);
    }
}

int FarkleGame::calcRoll() {
    int histogramArray[7] = {-1, 0, 0, 0, 0, 0, 0};
    scoringDice = 0;
    for (int i = 0; i < 6; i++) { //creates histogram
        switch(diceArray[i].getDice()) {
            case 1:
                histogramArray[1]++;
                break;
            case 2:
                histogramArray[2]++;
                break;
            case 3:
                histogramArray[3]++;
                break;
            case 4:
                histogramArray[4]++;
                break;
            case 5:
                histogramArray[5]++;
                break;
            case 6:
                histogramArray[6]++;
                break;
            default:
                break;
        }
    }
    int score = 0;
    for (int i = 1; i < 7; i++) { //6 of a kind
        if (histogramArray[i] == 6) {
            score = 3000;
            scoringDice = 6;
            return score;
        }
    }
    for (int i = 1; i < 7; i++) { // 5 of a kind
        if (histogramArray[i] == 5) {
            score = 2000;
            scoringDice = 5;
            return score;
        }
    }
    for (int i = 1; i < 7; i++) { //4 of a kind
        if (histogramArray[i] == 4) {
            score = 1000;
            scoringDice = 4;
            return score;
        }
    }
    for (int i = 1; i < 7; i++) {
        if (histogramArray[i] == 3) {
            for (int j = 1; j < 7; j++) {
                if (histogramArray[j] == 3 && i != j) { //2 Triplets
                    score = 2500;
                    scoringDice = 6;
                    return score;
                }
            }
            switch(i) { //scores 3 of kinds
            case 1:
                score = 1000;
                scoringDice = 3;
                return score;
            case 2:
                score = 200;
                scoringDice = 3;
                return score;
            case 3:
                score = 300;
                scoringDice = 3;
                return score;
            case 4:
                score = 400;
                scoringDice = 3;
                return score;
            case 5:
                score = 500;
                scoringDice = 3;
                return score;
            case 6:
                score = 600;
                scoringDice = 3;
                return score;
            default:
                break;
            }
        }   
    }
    for (int i = 1; i < 7; i++) { 
        if (histogramArray[i] == 2) {
            for (int j = 1; j < 7; j++) {
                if (histogramArray[j] == 2 && j != i) {
                    for (int k = 1; k < 7; k++) { //3 pair
                        if (histogramArray[k] == 2 && k != j && k != i) {
                            score = 1500;
                            scoringDice = 6;
                            return score;
                        }
                    }
                }
            }
        }
    }
    if (histogramArray[1] == 1 && histogramArray[2] == 1 && histogramArray[3] == 1 && histogramArray[4] == 1 && histogramArray[5] == 1 && histogramArray[6] == 1) { //scores straight
        score = 1500;  
        scoringDice = 6;
        return score; 
    }
    if (histogramArray[1] == 1 || histogramArray[1] == 2) { //checks for 1
        score = 100;
        scoringDice = 1;
        return score;
    }
    if (histogramArray[5] == 1 || histogramArray[5] == 2) { //checks for 5
        score = 50;
        scoringDice = 1;
        return score;
    }
    scoringDice = 0;
    return score;
}

int FarkleGame::getScoringDice() {
    return scoringDice;   
}