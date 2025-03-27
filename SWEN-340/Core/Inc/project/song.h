#ifndef INC_SONG_H_
#define INC_SONG_H_

#include "stdint.h"

// Defines a structure to store song data
typedef struct {
	unsigned char* p_song;
	unsigned int size;
} song;

// Function prototype to retrieve a song based on an index
song get_song(uint8_t);

#endif /* INC_SONG_H_ */
