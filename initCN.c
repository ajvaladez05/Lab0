
#include "p24fj64ga002.h"
#include "initCN.h"

void initCNForSwitch1(){
    //Using the switch on the board
    TRISBbits.TRISB5 = 1;
    IFS1bits.CNIF = 0;
    IEC1bits.CNIE = 1;
    CNEN2bits.CN27IE = 1;
}