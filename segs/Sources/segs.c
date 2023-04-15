#include <hidef.h>
#include "derivative.h"
#include "seg.h"


//pulse Port A LSB low then high to low latch new value
#define Segs_WLATCH PORTA &= (~0x01); PORTA |= 0x01;

//set the mode bit low
#define Segs_ML PORTA &= (~0x02);

//set the mode line low
#deine Segs_MH PORTA |= 0x02;

//setup ports to speak with 7-segs
void Segs_Init(void) {
  //standard GPIO setup (no inputs in this case)
  //set control pins high to keep device from loadinng 
  PORTA |= 0x03; //0b00000011
  
  //set direction of two lsb bits on PORT A outut
  DDRA |= 0x03;
  
  //set all bits on port B to output
  DDRB |= 0xff;
  
  //after initialization, turn all segs off (if we dont do this, previous atched data will stay on the display until we replace it.)
  //TODO
  
}

//control segs manually
void Segs_custom (unsigned char Addr, unsigned char Value){

}

//show HEX decoding (changes all of the display to HEX, w/wo dp)
void Segs_Normal (unsigned char ADDR, unsigned char Value, Segs_DPOption dp){
  
  //this will display a particular value, 0 to F in hhex , on the specified digit (0 is top left , 7 is bottom right)
  //i am going to use the ADDR byte, which should already contain the three but
  
  Addr &= 0x07; // 0b00000111. clear all bits but the existinng 0-7 address
  
  //add the rest of the command 
  Addr |= 0b01011000;
  
  //do we want the decimal pont?
  
  if(dp) Value &= (~0x80);
  else Value |= 0x80; //ob10000000 - turn dp bit off by setting a 1
  
  
  //send the command to the driver
  PORTB = Addr;
  Segs_MH // This is a comman
  Segs_WLATCH  // strobe R/W to load commad
  
  
  //send the data (number between 0 and F)
  PORTB = value;
  Segs_ML // This is a data
  Segs_WLATCH //loaad data
}

//show a 16-bit value on the upper or lower display

void Segs_16H (unsigned int Value, Segs_LineOption Line) {
  
  
}

//show a decimal value on the first or second line of the 7 segs
void Segs_16D (unsigned int Value, Segs_LineOption Line){
  
}
//show the 8-bit value on the first or second line of the 7 segs
void Segs_8H (unsigned char Addr, unsigned char Value){
  
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  