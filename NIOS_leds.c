/*
 * NIOS_leds.c
 *
 *  Created on: 30 Mar 2021
 *      Author: Theocharis Theocharidis
 */

#include "io.h"
#include "alt_types.h"
#include "system.h"

//main function - 7 SEGMENT DISPLAY
int main(){
  int sw2; 
  int sw1; 

  static alt_u8 leds = 0x01;    
  long i, itr;                  

  while(1){

	sw2 = IORD(SW_IN_BASE, 0) & 0x00000003; 
	sw1 = IORD(SW_IN_BASE, 0) & 0x00000001; 
    if (sw2==0x01)// ZITOUMENO 1
     {
        if (leds==0x01)
          {
			  leds= 0x20;
			  IOWR(LED_OUT_BASE, 0, ~leds); // Writing the inverse value (complement) of the LED variable on the relevant PIO device 
		  }
		  else
		  {
			  leds = leds >> 1; //Right shift of the value of the leds to turn 6 leds in reverse 
			  IOWR(LED_OUT_BASE, 0, ~leds); // Writing the inverse value (complement) of the LED variable on the relevant PIO device 
		  }
	  }
	else
	 {
		 if (leds==0x20)
		 {
			 leds= 0x01;
			 IOWR(LED_OUT_BASE, 0, ~leds); // Writing the value of the LED variable on the relevant PIO device 
		 }
		 else
		 {
			 leds = leds << 1; //Left shift of the value of the leds to turn 6 leds in reverse 
		 	 IOWR(LED_OUT_BASE, 0, ~leds); // Writing the value of the LED variable on the relevant PIO device 
		 }
	  }
    if (sw1==0x01) //  dummy loop for delay
    {
    	itr = 200000;
    	for (i=0; i<itr; i++) ; // Application of faster dummy loop for delay
    }
    else
    {
    	itr = 100000;
    	for (i=0; i<itr; i++); // Application of slower dummy loop for delay
    }
  }
}
