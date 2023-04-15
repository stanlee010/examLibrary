#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "sw_led.h"
#include "sci.h"
#include "pit.h"
#include "seg.h"



//Define the test you want to do 
#define SEGTEST

void delay (void);
void ledFlicker(void);

void main (void){
 char c = 0;
 char buffer[256] ={0};
 int i = 0; //scratch data
 int digit = 0;
 int val = 0;
 
 
 	EnableInterrupts;

//intit LEDs and switches

 SWL_Init();







































/*
//define the tests you want to do
#define PITTEST

void delay(void);   //function to bbusy-wait for testing
void ledFlicker(void);//fucntion to just run the lights with delay


void main(void) {
 char c = 0;
 char buffer[256] ={0};
 int i = 0; //scratch data
 
 	EnableInterrupts;

//intit LEDs and switches
SWL_Init();

//flicker slow
ledFlicker();

//set the clockspeed to 20MHz
PLL_To20MHz();

//flicker faster (one hopes)
ledFlicker();


  for(;;)
   {          //loops forever
  #ifdef BUTTONTEST
  //button test code
  if(SWL_Pushed(SWL_LEFT))
  SWL_ON(SWL_REED);
  else 
  SWL_OFF(SWL_RED);
  
  if (SWL_Pushed(SWL_CTR))
  SWL_ON(SWL_YELLOW);
  else 
  SWL_OFF(SWL_YELLOW);
  if(SWL_Pushed(SWL_RIGHT))
  SWL_ON(SWL_GREEN)
  else
  SWL_OFF(SWL_GREEN)  ;
     #endif
     #ifdef SCITEST
     SCI_Init(BDFromLong(9600));
     SCI_TxByte('T');
     SCI_TxByte('e');
     SCI_TxByte('s');
     SCI_TxByte('t');
     SCI_TxByte('\r');
     
     do{
      
      c = SCI_RxByteB();
      SCI_SCI_TxString("You typed a ");
      SCI_TxByte(c);
      SCI_TxByte('r');
      )while (c != 'q');
      
      SCI_TxString("Enter a string: ");
      SCI_RxSreing(buffer,256);
      SCI_TxString("You typed: ");
      SCI_TxString(buffer);
      SCI_TxStrinng("\r\r");
      SCI-TxString("Now you can use r,y,g keys to control light....");
      while(1) {
        
        if(SCI_RxByte(&c))// to pass by address, must send address, not value
        switch (c) {
          case 'r':
          SWL_TOG(SWL_RED);
          break;
           case 'y':
          SWL_TOG(SWL_YELLOW);
          break;
           case 'g':
          SWL_TOG(SWL_GREEN);
          break;
        }
      }
  #endif
  #ifdef PITTEST
  while(1) {
    PIT_Sleep(PIT_CH0,20,10);
    SWL_TOG(SWL_RED);
  }
  
  #endif  
  } 
}
//please  make sure that you never leave main

void delay(void){
  
  long cntr = 25000;
  while (cntr--)
  ;
}
void ledFlicker(void)  {
  
  //led test code
}
 */