/* 
 * File:   Lab0.c
 * Author: Anthony
 *
 * Created on February 5, 2015, 1:39 PM
 */
#include "p24fj64ga002.h"
#include "initLEDS.h"
#include "initCN.h"
#include "initTimer.h"
#include <stdio.h>
#include <stdlib.h>

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_ON & ICS_PGx1 &
           FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
           IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )


/*
 * 
 */
typedef enum stateTypeEnum{
    led4, led5, led6, led7
}stateType;

volatile stateType currState;
int main(void) {
   
    initLEDS(); //initialize LEDS to off
    initCNForSwitch1(); //set input for sw1
    currState = led4; //starting position of LED
     


    while(1){
        
       switch(currState){
             case led4:
                 turnOnLED(4);
                 break;
             case led5: 
                 turnOnLED(5);
                 break;
             case led6:
                 turnOnLED(6);
                 break;
             case led7:
                 turnOnLED(7);
                 break;
         }
         

    }
    return 0;
}

void _ISR _CNInterrupt(void){
    IFS1bits.CNIF = 0;
    if(PORTBbits.RB5 == PRESSED){
     
    if(currState == led4) currState = led5;
    else if(currState == led5) currState = led6;
    else if(currState == led6) currState = led7;
    else if(currState == led7) currState = led4;
    }
}

void _ISR _T3Interrupt(void){
    IFS0bits.T3IF = 0;
    if(currState == led4) currState = led7;
    else if(currState == led5) currState = led4;
    else if(currState == led6) currState = led5;
    else if(currState == led7) currState = led6;
}