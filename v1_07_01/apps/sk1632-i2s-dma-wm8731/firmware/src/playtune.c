#include <xc.h>
#include <sys/attribs.h>
#include "app.h"
#include "system_definitions.h"
#include "envtable.h"
#include "wavetable.h"
#include "songdata.h"
#include "tuningwords.h"
#include "main.h"

// parser courtesy of Len Shustek.
// https://github.com/LenShustek/arduino-playtune
volatile unsigned char cmd, opcode, chan;

short buffer_a[BUFFER_LENGTH];
short buffer_b[BUFFER_LENGTH];
short* buffer_pp;

unsigned char isPlaying = 1;
unsigned char isFillFlag = 0;
unsigned char buffer_position = 0;

// suffix C means "Carrier", suffix M means "Modulator".
unsigned long accum1_c = 0;
unsigned long tuningWord1_c = 0;
unsigned long accum1_m = 0;
unsigned long tuningWord1_m = 0;
long temp1_m = 0;                               // intermediate for FM synth calculation.
unsigned long amplitude1_m = MOD_AMPL;             // modulator amplitude.
long output1 = 0;                              // intermediate for channel 1 output.

unsigned long accum2_c = 0;
unsigned long tuningWord2_c = 0;
unsigned long accum2_m = 0;
unsigned long tuningWord2_m = 0;
long temp2_m = 0;                               // intermediate for FM synth calculation.
unsigned long amplitude2_m = MOD_AMPL;             // modulator amplitude.
long output2 = 0;                              // intermediate for channel 2 output.

unsigned long accum3_c = 0;
unsigned long tuningWord3_c = 0;
unsigned long accum3_m = 0;
unsigned long tuningWord3_m = 0;
long temp3_m = 0;                               // intermediate for FM synth calculation.
unsigned long amplitude3_m = MOD_AMPL;             // modulator amplitude.
long output3 = 0;                              // intermediate for channel 3 output.

unsigned long accum4_c = 0;
unsigned long tuningWord4_c = 0;
unsigned long accum4_m = 0;
unsigned long tuningWord4_m = 0;
long temp4_m = 0;                               // intermediate for FM synth calculation.
unsigned long amplitude4_m = MOD_AMPL;             // modulator amplitude.
long output4 = 0;                              // intermediate for channel 4 output.

unsigned long accum5_c = 0;
unsigned long tuningWord5_c = 0;
unsigned long accum5_m = 0;
unsigned long tuningWord5_m = 0;
long temp5_m = 0;                               // intermediate for FM synth calculation.
unsigned long amplitude5_m = MOD_AMPL;             // modulator amplitude.
long output5 = 0;                              // intermediate for channel 5 output.

unsigned long accum6_c = 0;
unsigned long tuningWord6_c = 0;
unsigned long accum6_m = 0;
unsigned long tuningWord6_m = 0;
long temp6_m = 0;                               // intermediate for FM synth calculation.
unsigned long amplitude6_m = MOD_AMPL;             // modulator amplitude.
long output6 = 0;                              // intermediate for channel 6 output.

unsigned int envelope_count1 = 0;
unsigned int envelope_ptr1  = 0;

unsigned int envelope_count2 = 0;
unsigned int envelope_ptr2  = 0;

unsigned int envelope_count3 = 0;
unsigned int envelope_ptr3  = 0;

unsigned int envelope_count4 = 0;
unsigned int envelope_ptr4  = 0;

unsigned int envelope_count5 = 0;
unsigned int envelope_ptr5  = 0;

unsigned int envelope_count6 = 0;
unsigned int envelope_ptr6  = 0;

unsigned long time_play = 0;  // note duration.
unsigned long time_play_count = 0;
unsigned long songIndex = 0;
unsigned char tone_channel = 0;
unsigned char play_note = 0;

volatile long temp_output1;
void channel1_generate() {
      // on dsPIC33F: (output divide by 8)  
      // approximately 120us per operation.   (generate 128 samples of sine wave DDS, 1 channel)
      // approximately 160us per operation.   (128 samples of FM-modulated DDS, 1 channel)
      // approximately 360us per operation.   (128 samples of FM-modulated DDS, 1 channel with decay envelope)
      unsigned int i = 0;
      LATASET = 0x02;
      for(i = 0; i < BUFFER_LENGTH/2; i++) {
            accum1_m += tuningWord1_m;                  // generating modulator for 1st channel.
            temp1_m = (long)wavetable[accum1_m >> 20];
            accum1_c += (unsigned long)(tuningWord1_c) + (long)temp1_m*amplitude1_m; // 2085, beta approx. 1.0

            // Envelope generator channel 1:
            if (envelope_count1 >= ENVELOPE_SPEED) { // decay channel 1
                envelope_count1 = 0;
                if (envelope_ptr1 >= 255)
                    envelope_ptr1 = 255;
                else
                    envelope_ptr1++;
            } else envelope_count1++;
            
            accum2_m += tuningWord2_m;                  // generating modulator for 2nd channel.
            temp2_m = (long)wavetable[accum2_m >> 20];
            accum2_c += (unsigned long)(tuningWord2_c) + (long)temp2_m*amplitude2_m; // 2085, beta approx. 1.0

            // Envelope generator channel 2:
            if (envelope_count2 >= ENVELOPE_SPEED) { // decay channel 2.
                envelope_count2 = 0;
                if (envelope_ptr2 >= 255)
                    envelope_ptr2 = 255;
                else
                    envelope_ptr2++;
            } else envelope_count2++;

            accum3_m += tuningWord3_m;                  // generating modulator for 3rd channel.
            temp3_m = (long)wavetable[accum3_m >> 20];
            accum3_c += (unsigned long)(tuningWord3_c) + (long)temp3_m*amplitude3_m; // 2085, beta approx. 1.0

            // Envelope generator channel 3:
            if (envelope_count3 >= ENVELOPE_SPEED) { // decay channel 3.
                envelope_count3 = 0;
                if (envelope_ptr3 >= 255)
                    envelope_ptr3 = 255;
                else
                    envelope_ptr3++;
            } else envelope_count3++;

            accum4_m += tuningWord4_m;                  // generating modulator for 4th channel.
            temp4_m = (long)wavetable[accum4_m >> 20];
            accum4_c += (unsigned long)(tuningWord4_c) + (long)temp4_m*amplitude4_m; // 2085, beta approx. 1.0

            // Envelope generator channel 4:
            if (envelope_count4 >= ENVELOPE_SPEED) { // decay channel 4.
                envelope_count4 = 0;
                if (envelope_ptr4 >= 255)
                    envelope_ptr4 = 255;
                else
                    envelope_ptr4++;
            } else envelope_count4++;
            
            accum5_m += tuningWord5_m;                  // generating modulator for 5th channel.
            temp5_m = (long)wavetable[accum5_m >> 20];
            accum5_c += (unsigned long)(tuningWord5_c) + (long)temp5_m*amplitude5_m; // 2085, beta approx. 1.0

            // Envelope generator channel 5:
            if (envelope_count5 >= ENVELOPE_SPEED) { // decay channel 5.
                envelope_count5 = 0;
                if (envelope_ptr5 >= 255)
                    envelope_ptr5 = 255;
                else
                    envelope_ptr5++;
            } else envelope_count5++;
            
            accum6_m += tuningWord6_m;                  // generating modulator for 6th channel.
            temp6_m = (long)wavetable[accum6_m >> 20];
            accum6_c += (unsigned long)(tuningWord6_c) + (long)temp6_m*amplitude6_m; // 2085, beta approx. 1.0

            // Envelope generator channel 6:
            if (envelope_count6 >= ENVELOPE_SPEED) { // decay channel 6.
                envelope_count6 = 0;
                if (envelope_ptr6 >= 255)
                    envelope_ptr6 = 255;
                else
                    envelope_ptr6++;
            } else envelope_count6++;

            output1 = (long)((wavetable[(accum1_c) >> 20] >> 8) * envelope[envelope_ptr1]);
            output2 = (long)((wavetable[(accum2_c) >> 20] >> 8) * envelope[envelope_ptr2]);
            output3 = (long)((wavetable[(accum3_c) >> 20] >> 8) * envelope[envelope_ptr3]);
            output4 = (long)((wavetable[(accum4_c) >> 20] >> 8) * envelope[envelope_ptr4]);
            output5 = (long)((wavetable[(accum5_c) >> 20] >> 8) * envelope[envelope_ptr5]);
            output6 = (long)((wavetable[(accum6_c) >> 20] >> 8) * envelope[envelope_ptr6]);
            
            temp_output1 =  (int)((output1 + output2 + output3 + output4 + output5 + output6) / 6) ;
            buffer_pp[2*i]   = temp_output1;    // One channel.
            buffer_pp[2*i+1] = temp_output1;    // the Other channel!
      }
      LATACLR = 0x02;

}

volatile unsigned char isStopNote = 0;
volatile unsigned char isUpdateNote = 0;

// This body of the interrupt has been moved into the main loop due to the excessive overhead!
void __ISR(_TIMER_23_VECTOR, ipl6AUTO) _IntHandlerTimer3(void) {
     // is note duration reached already?
     // yes, then:
     //LATAbits.LATA0 = 1;

     if(time_play_count > time_play) {
        time_play_count = 0;
        isUpdateNote = 1;
        /*
        while(1) {
           cmd = songData1[songIndex];
        
           if(cmd < 0x80) {
              time_play = (songData1[songIndex] << 8) | songData1[songIndex+1];
              songIndex += 2;
              break;
           }
           
           opcode = cmd & 0xf0;
           chan   = cmd & 0x0f;
           
           if(opcode == 0x80) {// stop note here!
               switch(chan) {
                  case 0: accum1_c = 0;
                          accum1_m = 0;
                          envelope_count1 = 0;
                          envelope_ptr1 = 0;
                          tuningWord1_c = 0;  // convert and put next notes!
                          tuningWord1_m = 0;  // same as previous.
                          break;
                  case 1: accum2_c = 0;
                          accum2_m = 0;
                          envelope_count2 = 0;
                          envelope_ptr2 = 0;
                          tuningWord2_c = 0;  // convert and put next notes!
                          tuningWord2_m = 0;  // same as previous.
                          break;
                  case 2: accum3_c = 0;
                          accum3_m = 0;
                          envelope_count3 = 0;
                          envelope_ptr3 = 0;
                          tuningWord3_c = 0;  // convert and put next notes!
                          tuningWord3_m = 0;  // same as previous.
                          break;
                  case 3: accum4_c = 0;
                          accum4_m = 0;
                          envelope_count4 = 0;
                          envelope_ptr4 = 0;
                          tuningWord4_c = 0;  // convert and put next notes!
                          tuningWord4_m = 0;  // same as previous.
                          break;
                  case 4: accum5_c = 0;
                          accum5_m = 0;
                          envelope_count5 = 0;
                          envelope_ptr5 = 0;
                          tuningWord5_c = 0;  // convert and put next notes!
                          tuningWord5_m = 0;  // same as previous.
                          break;
                  case 5: accum6_c = 0;
                          accum6_m = 0;
                          envelope_count6 = 0;
                          envelope_ptr6 = 0;
                          tuningWord6_c = 0;  // convert and put next notes!
                          tuningWord6_m = 0;  // same as previous.
                          break;
                  default: break;
              }
              songIndex += 1;
               
           }
           else if(opcode == 0x90) { // play note here!
               isUpdateNote = 1;
               switch(chan) {
                  case 0: accum1_c = 0;
                          accum1_m = 0;
                          envelope_count1 = 0;
                          envelope_ptr1 = 0;
                          tuningWord1_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;  // convert and put next notes!
                          tuningWord1_m = tuningWords[songData1[songIndex+1]]*MOD_AMPL;  // same as previous.
                          break;
                  case 1:   accum2_c = 0;
                            accum2_m = 0;
                            envelope_count2 = 0;
                            envelope_ptr2 = 0;
                            tuningWord2_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;  // convert and put next notes!
                            tuningWord2_m = tuningWords[songData1[songIndex+1]]*MOD_AMPL;  // same as previous.
                            break;
                  case 2:   accum3_c = 0;
                            accum3_m = 0;
                            envelope_count3 = 0;
                            envelope_ptr3 = 0;
                            tuningWord3_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;  // convert and put next notes!
                            tuningWord3_m = tuningWords[songData1[songIndex+1]]*MOD_AMPL;  // same as previous.
                            break;
                  case 3:   accum4_c = 0;
                            accum4_m = 0;
                            envelope_count4 = 0;
                            envelope_ptr4 = 0;
                            tuningWord4_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;  // convert and put next notes!
                            tuningWord4_m = tuningWords[songData1[songIndex+1]]*MOD_AMPL;  // same as previous.
                            break;
                  case 4:   accum5_c = 0;
                            accum5_m = 0;
                            envelope_count5 = 0;
                            envelope_ptr5 = 0;
                            tuningWord5_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;  // convert and put next notes!
                            tuningWord5_m = tuningWords[songData1[songIndex+1]]*MOD_AMPL;  // same as previous.
                            break;
                  case 5:   accum6_c = 0;
                            accum6_m = 0;
                            envelope_count6 = 0;
                            envelope_ptr6 = 0;
                            tuningWord6_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;  // convert and put next notes!
                            tuningWord6_m = tuningWords[songData1[songIndex+1]]*MOD_AMPL;  // same as previous.
                            break;
                            
                 default:  break;
               }
               songIndex += 2;
              
           }

         else if(opcode == 0xf0) {  // stop playing score!
                isPlaying = 0;
                //DAC1CON.DACEN = 0;
                //DMA0CONbits.CHEN = 0;
                break;
         }
         
         else if(opcode == 0xe0) {  // start playing from beginning!
               songIndex = 0;
               time_play_count = 0;
               time_play = 0;
               break;
         }
        }
         */
     } else time_play_count++;

    IFS0bits.T3IF = 0;
}

// UpdateNote - updates the note when it is finished playing. The function
//              parses the array which is generated by Len Shustek's Miditones. 
void updateNote() {
    while(1) {
           cmd = songData1[songIndex];
        
           if(cmd < 0x80) {
              time_play = ( (songData1[songIndex] << 8) | songData1[songIndex+1] ) * TEMPO_MULT / TEMPO_DIV;
              songIndex += 2;
              break;
           }
           
           opcode = cmd & 0xf0;
           chan   = cmd & 0x0f;
           
           if(opcode == 0x80) {// stop note here!
               switch(chan) {
                  case 0: accum1_c = 0;
                          accum1_m = 0;
                          envelope_count1 = 0;
                          envelope_ptr1 = 0;
                          tuningWord1_c = 0;  // convert and put next notes!
                          tuningWord1_m = 0;  // same as previous.
                          break;
                  case 1: accum2_c = 0;
                          accum2_m = 0;
                          envelope_count2 = 0;
                          envelope_ptr2 = 0;
                          tuningWord2_c = 0;  // convert and put next notes!
                          tuningWord2_m = 0;  // same as previous.
                          break;
                  case 2: accum3_c = 0;
                          accum3_m = 0;
                          envelope_count3 = 0;
                          envelope_ptr3 = 0;
                          tuningWord3_c = 0;  // convert and put next notes!
                          tuningWord3_m = 0;  // same as previous.
                          break;
                  case 3: accum4_c = 0;
                          accum4_m = 0;
                          envelope_count4 = 0;
                          envelope_ptr4 = 0;
                          tuningWord4_c = 0;  // convert and put next notes!
                          tuningWord4_m = 0;  // same as previous.
                          break;
                  case 4: accum5_c = 0;
                          accum5_m = 0;
                          envelope_count5 = 0;
                          envelope_ptr5 = 0;
                          tuningWord5_c = 0;  // convert and put next notes!
                          tuningWord5_m = 0;  // same as previous.
                          break;
                  case 5: accum6_c = 0;
                          accum6_m = 0;
                          envelope_count6 = 0;
                          envelope_ptr6 = 0;
                          tuningWord6_c = 0;  // convert and put next notes!
                          tuningWord6_m = 0;  // same as previous.
                          break;
                  default: break;
              }
              songIndex += 1;
               
           }
           else if(opcode == 0x90) { // play note here!
               isUpdateNote = 1;
               switch(chan) {
                  case 0: accum1_c = 0;
                          accum1_m = 0;
                          envelope_count1 = 0;
                          envelope_ptr1 = 0;
                          tuningWord1_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;                               // convert and put next notes!
                          tuningWord1_m = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL*MOD_F_MULT/MOD_F_DIV;  // same as previous.
                          break;
                  case 1:   accum2_c = 0;
                            accum2_m = 0;
                            envelope_count2 = 0;
                            envelope_ptr2 = 0;
                            tuningWord2_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;                              // convert and put next notes!
                            tuningWord2_m = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL*MOD_F_MULT/MOD_F_DIV;  // same as previous.
                            break;
                  case 2:   accum3_c = 0;
                            accum3_m = 0;
                            envelope_count3 = 0;
                            envelope_ptr3 = 0;
                            tuningWord3_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;                             // convert and put next notes!
                            tuningWord3_m = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL*MOD_F_MULT/MOD_F_DIV;  // same as previous.
                            break;
                  case 3:   accum4_c = 0;
                            accum4_m = 0;
                            envelope_count4 = 0;
                            envelope_ptr4 = 0;
                            tuningWord4_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;                             // convert and put next notes!
                            tuningWord4_m = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL*MOD_F_MULT/MOD_F_DIV;  // same as previous.
                            break;
                  case 4:   accum5_c = 0;
                            accum5_m = 0;
                            envelope_count5 = 0;
                            envelope_ptr5 = 0;
                            tuningWord5_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;                             // convert and put next notes!
                            tuningWord5_m = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL*MOD_F_MULT/MOD_F_DIV;  // same as previous.
                            break;
                  case 5:   accum6_c = 0;
                            accum6_m = 0;
                            envelope_count6 = 0;
                            envelope_ptr6 = 0;
                            tuningWord6_c = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL;                              // convert and put next notes!
                            tuningWord6_m = tuningWords[songData1[songIndex+1]]*CARRIER_AMPL*MOD_F_MULT/MOD_F_DIV;  // same as previous.
                            break;
                            
                 default:  break;
               }
               songIndex += 2;
              
           }

         else if(opcode == 0xf0) {  // stop playing score!
                isPlaying = 0;
                //DAC1CON.DACEN = 0;
                //DMA0CONbits.CHEN = 0;
                break;
         }
         
         else if(opcode == 0xe0) {  // start playing from beginning!
               songIndex = 0;
               time_play_count = 0;
               time_play = 0;
               break;
         }
       }

}

