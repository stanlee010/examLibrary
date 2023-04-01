
#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "sw_led.h"
//switch and indicator LED library

//init - must be called to init port PT1AD1

void SWL_Init(void) {
  //turn off LEDs(in case they are on)
  PT1AD1 &= 0x1F;
  
  //set my data direction register for leds out, sws in
  DDR1AD1 =0xE0;
  //enable my buttons for input
  ATD1DIEN1 |= 0x1F;
}
////////////////////////////////////////////////////////////

//LED functions
void SWL_ON(SWL_LEDColour led){
   PT1AD1 |= led;
}

void SWL_OFF(SWL_LEDColour led){
   PT1AD1 &= ~led;
}

void SWL_TOG(SWL_LEDColour led){
   PT1AD1 ^= led;
}  

//////////////////////////////////////////////////////////
//special LED functions (does not apply to CNT courses)
//void SWL_AUX_On (void)
//void SWL_AUX_OFF(void);

/////////////////////////////////////////////////////////
//switch functions

//s a specific being pushed (T/F (1/0))
int SWL_Pushed(SWL_SwitchPos pos) 
{
  if((PT1AD1 & pos) > 0 )
  return 1;
  else 
  return 0;
}

//is any switch being pushed (T/F))
int SWL_Any(void) { 

return SWL_Pushed(SWL_ANY);  }
  
////////////////////////////////////////////
//////////////////////////////////////////

//you wont implement these functions initially 
//after we talk about some switch related issues, you will be implementing 
//these functions - possibly in cmpe2250

//by switch name
//todo : need to implemet debounced switch checking
int SWL_Transition (SWL_SwitchPos pos, DebounceOption deb){
  return 0;}
  
  ///////////////////////////////