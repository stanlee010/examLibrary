#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

unsigned int i;

//initialize
unsigned long sci0_Init(unsigned long ulBaudRate, int iRDRF_Interrupt){
  SCI0CR1 = 0b00000000;
  SCI0CR2 = 0b00101100;
  SCI0BD = ulBaudRate/16 / iRDRF_Interrupt;
}

//read a byte with blocking
unsigned char sci0_bread(void){
  while (!(SCI0SR1 & SCI0SR1_RDRF_MASK)){
    return SCI0DRL;
  }
}
//read a byte without blocking
unsigned char sci0_rxByte(unsigned char * pData){
 if(SCI0SR1 & SCI0SR1_RDRF_MASK){
  
  *pData = SCI0DRL;
  return 1;
 }else {
  return 0;
 }
}

//send a byte 
void sci0_txtByte(unsigned char data){
  
  while(!(SCI0SR1 & SCI0SR1_TDRE_MASK));
  SCI0DRL = data;
}
  
//send a string
void sci0_txStr (char const * straddr){
  i = 0 ;
  while (straddr[i] != 0){
    
    while((SCI0SR1 & SCI0SR1_TDRE_MASK)){
      SCI0DRL = straddr[i++];
      
    }
  }
}
int sc0_rxStr (char * const pTarget,int BufferSize){
  char* pTargetP = pTarget;
  int totalLength = BufferSize;
    while(--BufferSize){
      //receive a character
      *pTargetP = sci0_bread();
      
      //
      if(*pTargetP == 13){
        *pTargetP = 0;
        sci0_txtStr(pTargetP);
        return totalLength - BufferSize;
      }
      *pTargetP;
    }
    *pTargetP = 0;

}
