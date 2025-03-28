#ifndef INC_TONE_H_
#define INC_TONE_H_

#include "dac.h"

// Function prototype for the SysTick interrupt handler
void SysTick_Handler();

// Function prototypes for managing tone playback
uint32_t get_counter();
void reset_counter();

// Function prototype for converting frequency to MIDI ticks
uint32_t hertz_to_midi_ticks (float hertz);

// Function prototypes for adding and removing tones
uint8_t add_tone(uint8_t note, uint8_t velocity);
uint8_t remove_tone(uint8_t note);

// Function prototype to play the added tones
void play_tones();

#endif /* INC_TONE_H_ */
