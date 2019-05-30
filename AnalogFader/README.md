# Control RGB color using an analog input signal

## Purpose

Determine what values driving an RGB LED produce a smooth transition from green -> yellow -> red.

## Hardware

* Arduino UNO
* Volume fader or similar (10K used for this)
* RGB LED
* 3x series resistors for the LED. 200 minimum or up to about 1K.

Connect the middle leg of the volume fader to A0 with outer legs connected to ground and 5V to provide a 0-5V analog input.
Connect the longest leg of the RGB LED to ground. When the ground is toward the left, the remaining pins are red, green and blue left to right respectively. Connect the LED inputs to the digital outputs indicated in the code.
 
## Branches

### indicator

Vary the color from red to green at 3.33 to 4.5 V (10V to 13.5 V at the battery.)

## TODO

* Average several input readings for better noise rejection.
* Develop scaled analog input with protection.
* Develop VR to power board from ~12V auto power.