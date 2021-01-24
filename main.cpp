//George Kullen main.cpp
#include "mbed.h"
#include "MMA8452.h"
#include "PinDetect.h"
#include "Speaker.h"
#include "uLCD_4DGL.h"
#include "farkleGame.h"
#include "dice.h"

uLCD_4DGL uLCD(p9, p10, p11); // serial tx, serial rx, reset pin;

Speaker mySpeaker(p26);
Serial pc(USBTX,USBRX);

PinDetect pb1(p21);
PinDetect pb2(p22);
PinDetect pb3(p23);

int main() {
    srand(time(0));
    
    pb1.mode(PullUp);
    pb2.mode(PullUp);
    pb3.mode(PullUp);
    
    MMA8452 acc(p28, p27, 40000); //instantiate an acc object!
    //set parameters -- use these and don't change
    acc.setBitDepth(MMA8452::BIT_DEPTH_12);
    acc.setDynamicRange(MMA8452::DYNAMIC_RANGE_4G);
    acc.setDataRate(MMA8452::RATE_100);
    
    FarkleGame farkle;
    double x = 0, y = 0, z = 0;
    int numDice = 6;
    int rollScore = 0;
    int turnScore = 0;
    //int farkleCount = 0;
    while(1) { //Core game loop
        //Display intro message
        uLCD.cls();
        uLCD.display_control(PORTRAIT);
        uLCD.text_width(2);
        uLCD.text_height(2);
        uLCD.locate(0,1);
        uLCD.printf("Shake\n");
        uLCD.printf("Board\n");
        uLCD.printf("------\n");
        uLCD.printf("To Roll\n");
        uLCD.printf("%d Dice\n", numDice);
        
        while (1) {
            if (pb2 == false) { //Cycle through dice #
                numDice = (numDice+1)%7;
                wait(0.5);
                uLCD.cls();
                uLCD.display_control(PORTRAIT);
                uLCD.text_width(2);
                uLCD.text_height(2);
                uLCD.locate(0,1);
                uLCD.printf("Shake\n");
                uLCD.printf("Board\n");
                uLCD.printf("------\n");
                uLCD.printf("To Roll\n");
                uLCD.printf("%d Dice\n", numDice);
            }
            if(!acc.isXYZReady()) {
                wait(0.01);
            } else {
                acc.readXYZGravity(&x,&y,&z);
                if (x > 0.5 || y > 0.5 || y < -0.5 || x < -0.5) {
                    break;
                }   
            }
        }
        if (x > 0.5 || y > 0.5 || y < -0.5 || x < -0.5) { //Detect Shake (tilt of board)
            uLCD.cls();
            mySpeaker.PlayNote(200.0,0.25,0.1);
            mySpeaker.PlayNote(250.0,0.25,0.1);
            mySpeaker.PlayNote(300.0,0.25,0.1);
            for (int i = 0; i < numDice; i++) { //roll given number of dice
                farkle.diceArray[i].rollDice();
                farkle.diceArray[i].displayDice(i);
                wait(0.1);             
            }
            rollScore = farkle.calcRoll();
            turnScore = rollScore + turnScore;
            if (rollScore == 0 || numDice == 0) { //farkle!
                uLCD.text_width(2);
                uLCD.text_height(2);
                uLCD.locate(0,6);
                uLCD.printf("FARKLE\n");
                turnScore = 0;
            } else { //report score
                uLCD.text_width(1);
                uLCD.text_height(1);
                uLCD.locate(0,11);
                uLCD.printf("Roll Score: %d\n", rollScore);
                uLCD.printf("Turn Score: %d", turnScore);  
            }
            while (1) {
                if (pb1 == false) { //display final turn score
                    uLCD.cls();
                    uLCD.display_control(PORTRAIT);
                    uLCD.text_width(2);
                    uLCD.text_height(2);
                    uLCD.locate(0,1);
                    uLCD.printf("Your\n");
                    uLCD.printf("Turn\n");
                    uLCD.printf("Score\n");
                    uLCD.printf("------\n");
                    uLCD.printf("%d\n", turnScore);
                        
                    //wait for button press again
                    while (1) {
                        if (pb1 == false) {
                            break;
                        }
                    }
                    numDice = 6;
                    rollScore = 0;
                    turnScore = 0;
                    for (int i = 0; i < 6; i++) { //reset dice
                        farkle.diceArray[i].setDice(0);
                    }
                    break;
                } else if (pb3 == false) {
                    numDice = numDice - farkle.getScoringDice();
                    for (int i = 0; i < 6; i++) { //reset dice
                        farkle.diceArray[i].setDice(0);
                    }
                    break;
                }
            }
        }
    }
}