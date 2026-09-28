# Summary
 A program for switching a LED on/off and changing the blinking frequency using rotary encoder

 # Requirements
 - Rot_Sw, the push button on the rotary encoder shaft is the on/off button. When button is pressed
the state of LEDs is toggled. Program must require that button presses that are closer than 250 ms
are ignored.
- Rotary encoder is used to control blinking frequency of the LED. Turning the knob clockwise
increases frequency and turning counterclockwise reduces frequency. If the LED is in OFF state
turning the knob has no effect. Minimum frequency is 2 Hz and maximum frequency is 200 Hz.
When frequency is changed it must be printed
- When LED state is toggled to ON the program must use the frequency at which it was switched off.

# FreeRTOS kernel mechanism
- Queue

# Hardware
The program was implemented on Raspberry Pi Pico W
