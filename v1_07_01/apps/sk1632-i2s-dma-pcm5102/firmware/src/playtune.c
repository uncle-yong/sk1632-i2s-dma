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

struct channel {
    
    // FM modulators:
    unsigned long accum_c;
    unsigned long tuningWord_c;
    unsigned long accum_m;
    unsigned long tuningWord_m;
    unsigned long amplitude_m;
    long temp1_m;
    long output;
    
    // Envelope:
    unsigned long envelope_count;
    unsigned long envelope_ptr;
    
};

struct channel ch[NUM_OF_CHANNELS]; 

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
      unsigned int j = 0;
      
      LATASET = 0x02;
           
      for(i = 0; i < BUFFER_LENGTH/2; i++) {
          
         for (j = 0; j < NUM_OF_CHANNELS; j++) {
            ch[j].accum_m += ch[j].tuningWord_m;
            ch[j].temp1_m = (long) wavetable[ch[j].accum_m >> 20];
            ch[j].accum_c += (unsigned long) (ch[j].tuningWord_c) + (long) ch[j].temp1_m * ch[j].amplitude_m; // 2085, beta approx. 1.0

            // Envelope generator:
            if (ch[j].envelope_count >= ENVELOPE_SPEED) { // decay channel
                ch[j].envelope_count = 0;
                if (ch[j].envelope_ptr >= ENVELOPE_SIZE)
                    ch[j].envelope_ptr = ENVELOPE_SIZE;
                else
                    ch[j].envelope_ptr++;
            } else ch[j].envelope_count++;
            
            ch[j].output = ( (long)(wavetable[(ch[j].accum_c) >> 20] * (envelope[ch[j].envelope_ptr])) ) >> 16;
            
       }
          
        temp_output1 = (int)(ch[0].output + ch[1].output + ch[2].output + ch[3].output + ch[4].output + ch[5].output) ;
        
        buffer_pp[2*i]   = (short)temp_output1;    // One channel.
        buffer_pp[2*i+1] = (short)temp_output1;    // the Other channel!
          
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
//               switch(chan) {
//                  case 0: ch[0].accum_c = 0;
//                          ch[0].accum_m = 0;
//                          ch[0].envelope_count = 0;
//                          ch[0].envelope_ptr = 0;
//                          ch[0].tuningWord_c = 0;  // convert and put next notes!
//                          ch[0].tuningWord_m = 0;  // same as previous.
//                          break;
//                  case 1: ch[1].accum_c = 0;
//                          ch[1].accum_m = 0;
//                          ch[1].envelope_count = 0;
//                          ch[1].envelope_ptr = 0;
//                          ch[1].tuningWord_c = 0;  // convert and put next notes!
//                          ch[1].tuningWord_m = 0;  // same as previous.
//                          break;
//                  case 2: ch[2].accum_c = 0;
//                          ch[2].accum_m = 0;
//                          ch[2].envelope_count = 0;
//                          ch[2].envelope_ptr = 0;
//                          ch[2].tuningWord_c = 0;  // convert and put next notes!
//                          ch[2].tuningWord_m = 0;  // same as previous.
//                          break;
//                  case 3: ch[3].accum_c = 0;
//                          ch[3].accum_m = 0;
//                          ch[3].envelope_count = 0;
//                          ch[3].envelope_ptr = 0;
//                          ch[3].tuningWord_c = 0;  // convert and put next notes!
//                          ch[3].tuningWord_m = 0;  // same as previous.
//                          break;
//                  case 4: ch[4].accum_c = 0;
//                          ch[4].accum_m = 0;
//                          ch[4].envelope_count = 0;
//                          ch[4].envelope_ptr = 0;
//                          ch[4].tuningWord_c = 0;  // convert and put next notes!
//                          ch[4].tuningWord_m = 0;  // same as previous.
//                          break;
//                  case 5: ch[5].accum_c = 0;
//                          ch[5].accum_m = 0;
//                          ch[5].envelope_count = 0;
//                          ch[5].envelope_ptr = 0;
//                          ch[5].tuningWord_c = 0;  // convert and put next notes!
//                          ch[5].tuningWord_m = 0;  // same as previous.
//                          break;
//                  default: break;
//              }
              
               ch[chan].accum_c = 0;
               ch[chan].accum_m = 0;
               ch[chan].envelope_count = 0;
               ch[chan].envelope_ptr = 0;
               ch[chan].tuningWord_c = 0;  // convert and put next notes!
               ch[chan].tuningWord_m = 0;  // same as previous.
               
              songIndex += 1;
               
            } else if (opcode == 0x90) { // play note here!
                isUpdateNote = 1;
//                switch (chan) {
//                    case 0: ch[0].accum_c = 0;
//                        ch[0].accum_m = 0;
//                        ch[0].envelope_count = 0;
//                        ch[0].envelope_ptr = 0;
//                        ch[0].tuningWord_c = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL; // convert and put next notes!
//                        ch[0].tuningWord_m = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL * MOD_F_MULT / MOD_F_DIV; // same as previous.
//                        break;
//                    case 1: ch[1].accum_c = 0;
//                        ch[1].accum_m = 0;
//                        ch[1].envelope_count = 0;
//                        ch[1].envelope_ptr = 0;
//                        ch[1].tuningWord_c = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL; // convert and put next notes!
//                        ch[1].tuningWord_m = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL * MOD_F_MULT / MOD_F_DIV; // same as previous.
//                        break;
//                    case 2: ch[2].accum_c = 0;
//                        ch[2].accum_m = 0;
//                        ch[2].envelope_count = 0;
//                        ch[2].envelope_ptr = 0;
//                        ch[2].tuningWord_c = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL; // convert and put next notes!
//                        ch[2].tuningWord_m = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL * MOD_F_MULT / MOD_F_DIV; // same as previous.
//                        break;
//                    case 3: ch[3].accum_c = 0;
//                        ch[3].accum_m = 0;
//                        ch[3].envelope_count = 0;
//                        ch[3].envelope_ptr = 0;
//                        ch[3].tuningWord_c = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL; // convert and put next notes!
//                        ch[3].tuningWord_m = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL * MOD_F_MULT / MOD_F_DIV; // same as previous.
//                        break;
//                    case 4: ch[4].accum_c = 0;
//                        ch[4].accum_m = 0;
//                        ch[4].envelope_count = 0;
//                        ch[4].envelope_ptr = 0;
//                        ch[4].tuningWord_c = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL; // convert and put next notes!
//                        ch[4].tuningWord_m = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL * MOD_F_MULT / MOD_F_DIV; // same as previous.
//                        break;
//                    case 5: ch[5].accum_c = 0;
//                        ch[5].accum_m = 0;
//                        ch[5].envelope_count = 0;
//                        ch[5].envelope_ptr = 0;
//                        ch[5].tuningWord_c = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL; // convert and put next notes!
//                        ch[5].tuningWord_m = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL * MOD_F_MULT / MOD_F_DIV; // same as previous.
//                        break;
//
//                    default: break;
//                }
                
                ch[chan].accum_c = 0;
                ch[chan].accum_m = 0;
                ch[chan].envelope_count = 0;
                ch[chan].envelope_ptr = 0;
                ch[chan].tuningWord_c = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL; // convert and put next notes!
                ch[chan].tuningWord_m = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL * MOD_F_MULT / MOD_F_DIV; // same as previous.
                ch[chan].amplitude_m = MOD_AMPL;
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

