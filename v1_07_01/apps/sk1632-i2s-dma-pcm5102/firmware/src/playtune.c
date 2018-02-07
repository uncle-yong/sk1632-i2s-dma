#include <xc.h>
#include <sys/attribs.h>
#include "app.h"
#include "system_definitions.h"
#include "envtable.h"
#include "wavetable.h"
#include "songdata.h"
#include "tuningwords.h"
#include "main.h"
#include "playtune.h"



// Filter order:
#define N 2

// parser courtesy of Len Shustek.
// https://github.com/LenShustek/arduino-playtune
unsigned char cmd, opcode, chan;
inline void updateNote();

short buffer_a[BUFFER_LENGTH];
short buffer_b[BUFFER_LENGTH];
short* buffer_pp;

unsigned char isPlaying = 1;
unsigned char isFillFlag = 0;
unsigned char buffer_position = 0;

#ifdef DEBUG_FILT
// Test sine wave variables and structures:
//--------------------------------------------
// Tuning word for 440hz @ 32kHz, 32bit = 59055800
// Tuning word for 10hz  @ 32khz, 32bit = 1342177
struct channel test_ch = { 0, 59055800 };
//--------------------------------------------
#endif

unsigned long time_play = 0;  // note duration.
unsigned long time_play_count = 0;
unsigned long songIndex = 0;
unsigned char tone_channel = 0;
unsigned char play_note = 0;

long temp_output1;

// Frame-based filtering: Real-Time Digital Signal Processing from MATLAB® to C with the TMS320C6x DSPs, Second Edition (Thad B. Welch, Cameron H.G. Wright, Michael G. Morrow)
  
// Variables for the high-pass filter:
short working_buffer[256+N];
fix16 output_buffer_fix16[256+N];
fix16 prev_output_value_fix16[N];    // previous output values (fix16) 
short prev_input_value[N];           // previous input values (short 16-bit)

//Fixed point coefficients for 20hz cutoff 1st order high pass Butterworth filter:
//fix16 coeff_b_fp[N+1] = { 65405, -65405 };
//fix16 coeff_a_fp[N+1] = { 65536, -65280 };

//Fixed point coefficients for 30hz cutoff 1st order high pass Butterworth filter:
//fix16 coeff_b_fp[N+1] = { float2fix16(0.9971), float2fix16(-0.9971) };
//fix16 coeff_a_fp[N+1] = { float2fix16(1.0000), float2fix16(-0.9941) };

//Fixed point coefficients for 20hz cutoff 2nd order high pass Butterworth filter:
fix16 coeff_b_fp[N+1] = { float2fix16(0.9973), float2fix16(-1.9945), float2fix16(0.9972) };
fix16 coeff_a_fp[N+1] = { float2fix16(1.0000), float2fix16(-1.9944), float2fix16(0.9945) };

inline void butterworth(short* inputData, fix16* outputData_fix16) {
    unsigned short i = 0;
    unsigned short j = 0;
    unsigned short k = 0;
    
    for (i = N ; i < (BUFFER_LENGTH/2) + N; i++) {
        // First order:
        //outputData_fix16[i] = multfix16(-1 * coeff_a_fp[1], outputData_fix16[i - 1]) + multfix16(coeff_b_fp[0], short2fix16(inputData[i])) + multfix16(coeff_b_fp[0], short2fix16(inputData[i]));
        
        // Second order:
        // Direct Form I algorithm:
        // Source : Matlab and Octave.
         outputData_fix16[i]  = -1*multfix16(coeff_a_fp[1], outputData_fix16[i-1]) - multfix16(coeff_a_fp[2], outputData_fix16[i-2]) + multfix16(coeff_b_fp[0], short2fix16(inputData[i])) + multfix16(coeff_b_fp[1], short2fix16(inputData[i-1])) + multfix16(coeff_b_fp[2], short2fix16(inputData[i-2])); 
    }

    for (i = BUFFER_LENGTH/2, j = 0; i < (BUFFER_LENGTH/2 + N); i++, j++) {
        outputData_fix16[j] = outputData_fix16[i];
        inputData[j] = inputData[i];        
    }

    
   
};

volatile fix16 temp_a = 0;
void channel1_generate() {
      // on dsPIC33F: (output divide by 8)  
      // approximately 120us per operation.   (generate 128 samples of sine wave DDS, 1 channel)
      // approximately 160us per operation.   (128 samples of FM-modulated DDS, 1 channel)
      // approximately 360us per operation.   (128 samples of FM-modulated DDS, 1 channel with decay envelope)
      unsigned int i = 0;
      unsigned int j = 0;
         
      //LATASET = 0x02;
           
      for(i = N; i < BUFFER_LENGTH/2 + N; i++) {
          
         for (j = 0; j < NUM_OF_CHANNELS; j++) {
            ch[j].accum_m += ch[j].tuningWord_m;
            ch[j].temp1_m = (long) wavetable[ch[j].accum_m >> 20];
            ch[j].accum_c += (unsigned long) (ch[j].tuningWord_c) + (long) ch[j].temp1_m * ch[j].amplitude_m; // 2085, beta approx. 1.0

            // Envelope generator:
            // When the note isn't stopped, play the envelope.
            if (ch[j].note_state == 0x01) {
                if ((ch[j].dk_damp_note_off.dk_interval++ & 0x7f) == 0) {
                    //LATAbits.LATA1 = 1;
                    ch[j].dk_damp_note_off.dk_state = multfix16(ch[j].dk_damp_note_off.dk_state, ch[j].dk_damp_note_off.dk);
                    ch[j].dk_damp_note_off.attack_state = multfix16(ch[j].dk_damp_note_off.attack_state, ch[j].dk_damp_note_off.attack);
                    ch[j].dk_damp_note_off.env = multfix16(onefix16 - ch[j].dk_damp_note_off.attack_state, ch[j].dk_damp_note_off.dk_state);
                    //LATAbits.LATA1 = 0;
                }
                temp_a = short2fix16(wavetable[ch[j].accum_c >> 20]);
                ch[j].temp1_d = multfix16(temp_a, ch[j].dk_damp_note_off.env);
                ch[j].output = (long) (ch[j].temp1_d >> 16) >> 3;

            } else if (ch[j].note_state == 0x00) {
                if ((ch[j].dk_main_env.dk_interval++ & 0x7f) == 0) {
                    ch[j].dk_main_env.dk_state = multfix16(ch[j].dk_main_env.dk_state, ch[j].dk_main_env.dk);
                    ch[j].dk_main_env.attack_state = multfix16(ch[j].dk_main_env.attack_state, ch[j].dk_main_env.attack);
                    ch[j].dk_main_env.env = multfix16(onefix16 - ch[j].dk_main_env.attack_state, ch[j].dk_main_env.dk_state);
                }
                ch[j].temp1_d = multfix16(short2fix16(wavetable[ch[j].accum_c >> 20]), ch[j].dk_main_env.env);
                ch[j].output = (long) (ch[j].temp1_d >> 16) >> 3;
            }


        }
          
        temp_output1 = (int)(ch[0].output + ch[1].output + ch[2].output + ch[3].output + ch[4].output + ch[5].output) ;
        
#ifdef FILT_DEBUG
        // Test channel here:
        //------------------------------------------------------------
        test_ch.accum_c += test_ch.tuningWord_c;
        test_ch.output  = (long)wavetable[(test_ch.accum_c) >> 20];
        //------------------------------------------------------------
#endif
        

        //buffer_pp[2*i]   = (short)temp_output1;    // One channel.
        //buffer_pp[2*i+1] = (short)temp_output1;    // the Other channel!
        working_buffer[i] = (short)temp_output1;
#ifdef FILT_DEBUG
        working_buffer[i] = (short)test_ch.output >> 1;
#endif
        
      }   
      
      butterworth(working_buffer, output_buffer_fix16);
      
      for(i = 0; i < BUFFER_LENGTH/2; i++) {
        
           //buffer_pp[2*i]   = (short)(working_buffer[i+N]);    // One channel. (working_buffer + order_number)
           //buffer_pp[2*i+1] = (short)(working_buffer[i+N]);    // the Other channel!
              
           buffer_pp[2*i]   = (short)(output_buffer_fix16[i+N] >> 16) * VOLUME_PERCENT / VOLUME_PERCENT_DIV;    // One channel.
           buffer_pp[2*i+1] = (short)(output_buffer_fix16[i+N] >> 16) * VOLUME_PERCENT / VOLUME_PERCENT_DIV;    // the Other channel!         
          
      }
      
      //LATACLR = 0x02;

}

volatile unsigned char isStopNote = 0;
volatile unsigned char isUpdateNote = 0;

// This body of the interrupt has been moved into the main loop due to the excessive overhead!
void __ISR(_TIMER_23_VECTOR, ipl6AUTO) _IntHandlerTimer3(void) {
     // is note duration reached already?
     // yes, then:
     if(time_play_count > time_play) {
        time_play_count = 0;
        isUpdateNote = 1;
        //updateNote();
     } else time_play_count++;

    IFS0bits.T3IF = 0;
}

// UpdateNote - updates the note when it is finished playing. The function
//              parses the array which is generated by Len Shustek's Miditones. 
inline void updateNote() {
    
    cmd = songData1[songIndex];
    opcode = cmd & 0xf0;
    chan = cmd & 0x0f;
    asm("nop");
    
    if (opcode == 0x90) {
        while (opcode == 0x90) {
            // Play a note here! Reset accumulators and set tuning words from the next note!
            // Also reset decay and attack states!
            ch[chan].accum_c = 0;
            ch[chan].accum_m = 0;
            ch[chan].envelope_count = 0;
            ch[chan].envelope_ptr = 0;
            ch[chan].tuningWord_c = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL; // convert and put next notes!
            ch[chan].tuningWord_m = tuningWords[songData1[songIndex + 1]] * CARRIER_AMPL * MOD_F_MULT / MOD_F_DIV; // same as previous.
            ch[chan].amplitude_m = MOD_AMPL;
            ch[chan].note_state = 0;
            
            ch[chan].dk_main_env.dk_state = onefix16;
            ch[chan].dk_main_env.attack_state = onefix16;
            ch[chan].dk_main_env.env = 0;
            
            ch[chan].dk_damp_note_off.dk_state = onefix16;
            ch[chan].dk_damp_note_off.attack_state = onefix16;
            ch[chan].dk_damp_note_off.env = 0;
            
            songIndex += 2;
            cmd = songData1[songIndex];
            opcode = cmd & 0xf0;
            chan = cmd & 0x0f;

            asm("nop");

        }
    } else if (opcode == 0x80) {

        while (opcode == 0x80) {
            // Stop note: the note is dampened immediately in order to prevent the click
            // once the next note is played. Not all the clicks in the sound can be removed: this is currently
            // being investigated.

            ch[chan].envelope_count = 0;
            ch[chan].envelope_ptr = 0;
            ch[chan].note_state = 1;
            
            // Take the last note decay state and put it here so that the envelope
            // doesn't reset back to the start!
            ch[chan].dk_damp_note_off.dk_state = ch[chan].dk_main_env.dk_state;
            
            ch[chan].dk_damp_note_off.attack_state = 0;
            
            ch[chan].dk_damp_note_off.dk_interval = 0;
            
            songIndex += 1;
            cmd = songData1[songIndex];
            opcode = cmd & 0xf0;
            chan = cmd & 0x0f;

            asm("nop");

        }
    } else if (opcode == 0xf0) { // stop playing score!
        isPlaying = 0;
        //DAC1CON.DACEN = 0;
        //DMA0CONbits.CHEN = 0;
        return;
    }
    else if (opcode == 0xe0) { // start playing from beginning!
        songIndex = 0;
        time_play_count = 0;
        time_play = 0;
        return;
    }

    
    cmd = songData1[songIndex];
    opcode = cmd & 0xf0;
        
    if ((opcode & 0x80) == 0) {
        time_play = ((songData1[songIndex] << 8) | songData1[songIndex + 1]) * TEMPO_MULT / TEMPO_DIV;
        songIndex += 2;
        //return;
    } 

}



