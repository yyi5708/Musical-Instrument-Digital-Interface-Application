#ifndef INC_PROJECT_PROJECT_PART_3_H_
#define INC_PROJECT_PROJECT_PART_3_H_

// Defines a structure to store song information
typedef struct {
    char title[50];
    char copyright[50];
    int tempo;
} Song;

// Current state of the LED (on, off, flashing)
extern int led_state;
// Flag indicating if the system is in remote mode
extern int is_remote_mode;
// Flag indicating if the system is in local mode
extern int is_local_mode;

// Initialize all system components
void init_all();

// Switch to remote control mode
void switch_to_remote_mode();

// Switch to local control mode
void switch_to_local_mode();

// Display available commands for remote mode
void display_help();

// Display the help menu for the help command
void next_help();

// Display information about a song
void display_info(const Song *song);

// Play the current song
void play_song();

// Pause the current song
void pause_song();

// Stop the current song
void stop_song();

// Move to the next song in the playlist
void next_song();

// Toggle LED flashing effect (for pause state)
void toggle_flash();

// SysTick interrupt handler for timing events
void SysTick_Handler();

// Process commands entered by the user
void process_command(const char *command);

// Main program loop to handle commands
void run_loop();

// Main function to initialize and run the loop
int run_main();

#endif /* INC_PROJECT_PROJECT_PART_3_H_ */
