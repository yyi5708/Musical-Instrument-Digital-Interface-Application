#include "tone.h"

//CPU speed set to 80 MHz
#define CPU_SPEED (80000000.0)

//Maximum number of simultaneous tones is 1
#define MAX_TONES (1)

static float notes[] = {
/* Octave -1 */			   8.18,    8.66,    9.18,    9.73,   10.30,   10.92,   11.56,   12.25,   12.98,   13.75,   14.57,   13.44,
/* Octave  0 */           16.35,   17.32,   18.35,   19.45,   20.60,   21.83,   23.12,   24.50,   25.96,   27.50,   29.14,   30.87,
/* Octave  1 */  	      32.70,   34.65,   36.71,   38.89,   41.20,   43.65,   46.25,   49.00,   51.91,   55.00,   58.27,   61.74,
/* Octave  2 */			  65.41,   69.30,   73.42,   77.78,   82.41,   87.31,   92.50,   98.00,  103.83,  110.00,  116.54,  123.47,
/* Octave  3 */			 130.81,  138.59,  146.83,  155.56,  164.81,  174.61,  185.00,  196.00,  207.65,  220.00,  233.08,  246.94,
/* Octave  4 */			 261.63,  277.18,  293.66,  311.13,  329.63,  349.23,  369.99,  392.00,  415.30,  440.00,  466.16,  493.88,
/* Octave  5 */          523.25,  554.37,  587.33,  622.25,  659.25,  698.46,  739.99,  783.99,  830.61,  880.00,  932.33,  987.77,
/* Octave  6 */         1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53,
/* Octave  7 */         2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07,
/* Octave  8 */         4186.01, 4434.92, 4698.63, 4978.03, 5274.04, 5587.65, 5919.91, 6271.93, 6644.88, 7040.00, 7458.62, 7902.13,
/* Octave  9 */         8372.02, 8869.84, 9397.26, 9956.06,10548.08,11175.30,11839.82,12543.86};

// Structure to hold information about a tone, including its duration in ticks and power level
typedef struct {
	uint32_t duration;
	uint16_t power;
} tone_info;

// Initialize a counter for tone playback
static uint32_t counter = 0;

// Array to store tone information for the maximum number of tones
static tone_info tones[MAX_TONES] = {{0,0}};

// Function to get the tick speed based on system configuration
uint32_t get_tick_speed();

// Function to convert frequency in hertz to MIDI ticks
uint32_t hertz_to_midi_ticks(float hertz) {
	float ticks_per_second = CPU_SPEED / (SysTick->LOAD + 1);
	if (hertz == 0)
		return 0;
	float duration = 1 / hertz;
	return (uint32_t) (duration * ticks_per_second);
}

// Function to get the current counter value
uint32_t get_counter() {
	return counter;
}

// Function to reset the counter to zero
void reset_counter() {
	counter = 0;
}

// Function to add a tone to the array with specified note and velocity
uint8_t add_tone(uint8_t note, uint8_t velocity) {
	tones [0] = (tone_info){hertz_to_midi_ticks(notes [note]), velocity};
	return 0;
}

// Function to remove a tone from the array based on the specified note
uint8_t remove_tone(uint8_t note) {
	tones [0].duration = hertz_to_midi_ticks(notes [note]);
	tones [0].power = 0;
	return 0;
}

// Function to play the tones
void play_tones() {
    if (tones[0].power > 0) {
        DAC_Set_Value(tones[0].power);
        HAL_Delay(tones[0].duration);
        DAC_Set_Value(0);
    }
}
