#ifndef PITH
#define PITH

typedef enum PIT_ChannelTypedef_{
  PIT_CH0 = 0b00000001,
  PIT_CH1 = 0b00000010,
  PIT_CH2 = 0b00000100,
  PIT_CH3 = 0b00001000
}PIT_Channel;

typedef enum PIT_InterruptTypedef_{
  PIT_Int_Disabled = 0,
  PIT_Int_Enabled =1
}PIT_Interrupt;

//chan: desired PIT channel (0-1 as enum)
//iWantInterrupt : turn on channel interrupt or not (0 == no interrupt)
//uLBusRate : bus frequency , in Hz
//ulInterval_us : desired interval in us (maximum is bus rate and 2^24 register limit dependent

int PIT_Init(PIT_Channel chan, PIT_Interrupt intState,unsigned long ulInterval_us);
// blockinng sleep for the sppecific number of ms, using the specific channel
// will kill any action on that channel if already in use

int PIT_Sleep(PIT_Channel chan, unsigned long ulBusRate, unsigned int ms);
#endif