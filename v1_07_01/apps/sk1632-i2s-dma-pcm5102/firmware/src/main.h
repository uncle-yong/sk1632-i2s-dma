#ifndef MAIN_H
#define MAIN_H

#define BUFFER_LENGTH       512             // Buffer length = 2 * working buffers. This is for the audio DAC where there are left + right channels.

#define ENVELOPE_DECLICK    1               // Not used anymore! Replaced by Bruce Land's envelope generator!
#define ENVELOPE_SPEED      20              //
#define ENVELOPE_SIZE       4096-1          //


#define CARRIER_AMPL        3               // shift carrier to the desired number of octaves.
#define MOD_F_MULT          7
#define MOD_F_DIV           2
// C:M - 3:3.5 -> sounds like xylophone?

#define MOD_AMPL            4096      

#define TEMPO_MULT          100  
#define TEMPO_DIV           100

#define VOLUME_PERCENT      15
#define VOLUME_PERCENT_DIV  100

enum { NUM_OF_CHANNELS = 6 };






#endif