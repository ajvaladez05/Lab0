#include "p24fj64ga002.h"
#include "initLEDS.h"

void initLEDS(){
    /*Using the helper function from GitHub*/

    TRISB &= 0x0FFF;
    LATB |= 0xF000;
}

    void turnOnLED(int led){
    /*
        if (led == 4){
            LATBbits.LATB15 = ON;
            LATBbits.LATB14 = OFF;
            LATBbits.LATB13 = OFF;
            LATBbits.LATB12 = OFF;
        }
        else if(led == 5){
            LATBbits.LATB15 = OFF;
            LATBbits.LATB14 = ON;
            LATBbits.LATB13 = OFF;
            LATBbits.LATB12 = OFF;
        }
        else if(led == 6){
            LATBbits.LATB15 = OFF;
            LATBbits.LATB14 = OFF;
            LATBbits.LATB13 = ON;
            LATBbits.LATB12 = OFF;
        }
        else if(led == 7){
            LATBbits.LATB15 = OFF;
            LATBbits.LATB14 = OFF;
            LATBbits.LATB13 = OFF;
            LATBbits.LATB12 = ON;
        }
      */

        /*Using the helpef function from GitHub*/
        
        LATB |= 0xF000;
        LATB ^= (0x1 <<(19 - led));
        

}