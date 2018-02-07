#ifndef PLAYTUNE_H
#define PLAYTUNE_H

#include "main.h"

// Source: https://people.ece.cornell.edu/land/courses/ece4760/PIC32/index_DSP.html
typedef signed int fix16 ;
#define multfix16(a,b) ((fix16)(((( signed long long)(a))*(( signed long long)(b)))>>16)) //multiply two fixed 16:16
#define float2fix16(a) ((fix16)((a)*65536.0)) // 2^16
#define fix2float16(a) ((float)(a)/65536.0)
#define divfix16(a,b) ((fix16)((((signed long long)(a)<<16)/(b)))) 
#define sqrtfix16(a) (float2fix16(sqrt(fix2float16(a)))) 
#define short2fix16(a) ((fix16)(a << 16))
#define onefix16 0x00010000

unsigned int dk_interval = 0;

struct decay {
    
    // Decay envelopes: (courtesy of Bruce Land)
    fix16 dk_state;
    fix16 attack_state;
    fix16 env;
    fix16 dk;
    fix16 attack;
    
    
    unsigned int dk_interval;
};

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
    
    struct decay dk_main_env;
    struct decay dk_damp_note_off;    
    fix16 temp1_d; // fixed point intermediate from multiplying the waveform with the envelope.
    
    // Note state:
    unsigned char note_state;       // note state = 1 -> stop note.
                                    // note state = 0 -> start note.
    
};

struct channel ch[NUM_OF_CHANNELS]; 




#endif