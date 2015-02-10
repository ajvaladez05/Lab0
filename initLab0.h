/* 
 * File:   initLab0.h
 * Author: Anthony
 *
 * Created on February 5, 2015, 2:23 PM
 */

#ifndef INITLAB0_H
#define	INITLAB0_H

#define LED4 LATBbits.LATB15
#define LED5 LATBbits.LATB14
#define LED6 LATBbits.LATB13
#define LED7 LATBbits.LATB12

#define OFF 1;
#define ON 0;

void initLEDS();
void initSwitch1();
void initTimer1();


#endif	/* INITLAB0_H */

