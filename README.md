# sk1632-i2s-dma
Cytron SK1632 FM synth music player using UDA1334ATS, WM8731 and PCM5102 and a PIC32MX1xx/2xx microcontroller.

In this project, PIC32MX150F128B and PIC32MX250F128B is used.

> **Note: The new update (7/2/2018) only applies on the PCM5102 folder. The other codecs will be updated in the near future.**

> **There is the WM8731 version of this project. In the project the WM8731 resides on a "Mikroelektronika Audio Codec Board Proto".
> Please check this repository for the "WM8731" suffix for more information.**

> **PCM5102 version of this project is here too. In the project the PCM5102 resides on a board, which can be obtained through eBay.
> Please check this repository for the "PCM5102" suffix for more information.**

Required: MPLAB XC32 1.40 and above, MPLAB Harmony 1.07.01, and MPLAB X IDE 3.55.

## Features
- Conversion of MIDI to C array courtesy of Len Shustek: https://github.com/LenShustek/arduino-playtune
- 6-channel FM synthesis using DDS algorithm.
- External audio DAC: NXP UDA1334ATS, Cirrus Logic WM8731 and PCM5102.
- Samples are pushed into the DAC using DMA.
- With some modifications, the code can be ported to other 32-bit platforms like Chipkit.
- One 2nd-order High-pass Butterworth filter to remove 20Hz DC component and below.
- Envelope generator by Bruce Land! Check out his exciting page about some topics of DSP there : https://people.ece.cornell.edu/land/courses/ece4760/PIC32/index_DSP.html

Please extract this to the Harmony apps folder, example: X:\microchip\harmony, where X is your Harmony installation drive.

The pin assignments can be viewed in the "MPLAB Harmony Configurator". [Tools->Embedded->MPLAB Harmony Configurator]

## Issues
1. Clicking noises between changing notes -> Most of the clicking has been removed, but some of them are still present.

## Todo
1. Suppress more of the remaining clicking noises between changing notes.
