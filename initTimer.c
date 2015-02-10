
#include "p24fj64ga002.h"
#include "initTimer.h"
#include "initCN.h"

#define FCY 14745600.0
#define PRESCALAR 64


void initTimer(int delay){
   while(PORTBbits.RB5 == PRESSED){
    long int prVal;
    prVal = (FCY * delay )/PRESCALAR -1; //Calculate the needed PRval for the desired time delay
    PR3 = (prVal >> 16); //Taking the 16 LSB
    PR2 = (prVal << 16) >> 16; //Taking the 16 MSB
    T2CONbits.T32 = 1;
    T2CONbits.TCKPS = 0b10;
    IEC0bits.T3IE = 1;
    IFS0bits.T3IF = 0;
    T2CONbits.TON = 1;
   }

}