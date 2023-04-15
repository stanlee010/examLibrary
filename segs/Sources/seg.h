
#ifndef _SEGSH_
       
 
 //for functions that want to add/kill the decimal port
 typedef enum  Segs_DPOption {
  Segs_DP_OFF, Segs_DP_ON
 } Segs_DPOption;
 
 //for functions that specify the upper or lower full display
 typedef enum Segs_LineOption{
  Segs_LineTop, Segs_LineBottom 
 } Segs_Line_Option;
 
 //setup ports to speak with 7-segs
 void Segs_Init (Void)
 
 //control segs manually
 void Segs_Custom(unsigned char Addr, unsigned char Value);
 
 //show HEX decoding (changes all display to HEX, w/wo dp)
 void Segs_Normal (unsigned char Addr, unsigned char Value, Segs_DPOption dp);
 
 //deprecated after term 1202
 //go code B (changes all display to code b)
 //void segs_CodeB (unsigned char addr, unsigned char value);
 
 //show a 16-bit value on the upper or lower display
 void Segs_16H (unsigned int Value, Segs_LineOption Line);
 
 //show a decimal value on the first or second line of the 7-segs
 void Segs_16D (unsigned int Value, Segs_LineOption Line);
 
 //show the 8-bit value starting on the digit as addr (0-6)
 void Segs_8H (unsigned char Addr, unsigned char Value);
 
 //clear the display 
 void Segs_Clear(void);
 
 //say Err on the appropraite line 
 void Segs_SayErr (Segs_LineOption Line);
 
 //deprecated after term 1202
 //say 'help' as best the 7-segs can show
 //void segs_SayHelp (void)
 
 #endif
