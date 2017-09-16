# sk1632-i2s-dma
Cytron SK1632 FM synth music player using UDA1334ATS and a PIC32MX1xx/2xx microcontroller.

In this project, PIC32MX150F128B is used.

Required: MPLAB XC32 1.40 and above, MPLAB Harmony 1.07.01, and MPLAB X IDE 3.55.

Features:

Conversion of MIDI to C array courtesy of Len Shustek: https://github.com/LenShustek/arduino-playtune
6-channel FM synthesis using DDS algorithm.
External audio DAC: NXP UDA1334ATS.
Samples are pushed into the DAC using DMA.
With some modifications, the code can be ported to other 32-bit platforms like Chipkit.

Please extract this to the Harmony apps folder, example: X:\microchip\harmony, where X is your Harmony installation drive.

The pin assignments can be viewed in the "MPLAB Harmony Configurator". [Tools->Embedded->MPLAB Harmony Configurator]

Issues: 
1.) Clicking noises between changing notes.

Todo: 
1.) Suppress the clicking noises between changing notes.
2.) Add an interpolation filter to each sine wave.

There is the WM8731 version of this project. In the project the WM8731 resides on a "Mikroelektronika Audio Codec Board Proto". Please check this repository for the "WM8731" suffix for more information.
