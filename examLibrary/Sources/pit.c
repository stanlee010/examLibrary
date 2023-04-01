#include <hidef.h>      /* common defines and macros */
#include "derivative.h"
#include "pit.h"

int PIT_Init(PIT_Channel chan,PIT_Interrupt intState, unsigned long ulBusRate, unsigned long ulInterval_us) {
  
  //need some storage
  unsigned long prescale =1; //initiall of 1 because prescale and tickCounnt should never be
  unsigned long tickCount = 0;
  
  //TODO: Allow use of microtimer i  ass well
  //for now, always use microtimer 0;
  PITMUX &= ~chan;
  
  //Microtimer 1 would look like
  //PITMUX |= 1 << PIT_Channel;
  
  //How many ticks do i need? (e.g 5000 us is 100000 ticks)
  tickCount = (ulBusRate * ulInterval_us);
  
  //Do i need to prescale?
  if (tickCount > 65536ul) {
    //i want my ticks to be <max , but as large as possible.
    //TODO : modify this to be actually choose a prescale that is a factor of tickCount
    prescale = (tickCount / 65536ul) + 1;
    tickCount /= prescale;
  }
  
  // input my value. -1 because the timer values are offset by 1 (to alllow 1-256 instead of ......
  switch(chan) {
  case PIT_CH0:
    PITMTLD0 = prescale -1;
    PITLD0 = tickCount -1;
    break;
  case PIT_CH1:
    PITMTLD0 = prescale -1;
    PITLD1 = tickCount -1;
    break;
  case PIT_CH2:
    PITMTLD0 = prescale -1;
    PITLD2 = tickCount -1;
    break;
  case PIT_CH3:
    PITMTLD0 = prescale -1;
    PITLD0 = tickCount -1; 
    break;
  }
  
  //now set up interrupts
  if(intState)
  PITINTE |- chan;
  else 
  PITINTE &= ~chan;
  
  //Enable the channel 
  PITCE |= chan;
  
  //finally, Ennable the PIT module
  PITCFLMT |= PITCFLMT_PITE_MASK | PITCFLMT_PITFRZ_MASK;
  
  //force load it (in case the timer is already running)
  PITFLT = chan;
  
  //clear any current flag 
  PITTF = chan;
  return 0;
}
//Blocking 
int PIT_Sleep(PIT_Channel chan, unsigned long ulBusRate, unsigned int ms) {
  
  //set up the timer to go off when i am done waiting
  PIT_Init(chan , 0 , ulBusRate, ms*1000);
  while(!(PITTF & chan ));  // wait until the flag appears
  PITTF = chan;     // clear flag by writing 1
  }
  
