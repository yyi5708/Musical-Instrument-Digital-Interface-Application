#include "project_part_3.h"
#include "printf.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "stm32l476xx.h"
#include "stm32l4xx.h"
#include "SysClock.h"
#include "UART.h"
#include "LED.h"
#include "GPIO.h"

// Array to store the list of songs (max 5 songs)
Song song_list[5];
// Index to keep track of the current song being played (initialized to -1, indicating no song is selected)
int current_song_index = -1;
// Variable to store the current LED state (0 = off, 1 = on, 2 = flashing)
int led_state = 0;
// Counter to keep track of the number of flashes for LED (used when LED is in flashing state)
int flash_counter = 0;
// Flag indicating if the system is in remote control mode (1 = remote mode active)
int is_remote_mode = 1;
// Flag indicating if the system is in local control mode (1 = local mode active)
int is_local_mode = 0;

// Initializes the system components and song list
void init_all() {
    System_Clock_Init();
    LED_Init();
    UART2_Init();
    GPIO_Init();
    strcpy(song_list[0].title, "Twinkle Twinkle Little Star");
    strcpy(song_list[0].copyright, "Jim Patterson");
    song_list[0].tempo = 391625;
    strcpy(song_list[1].title, "Harry Potter Theme");
    strcpy(song_list[1].copyright, "N/A");
    song_list[1].tempo = 310442;
    strcpy(song_list[2].title, "Twinkle Twinkle Little Star");
    strcpy(song_list[2].copyright, "Jim Patterson");
    song_list[2].tempo = 391625;
    strcpy(song_list[3].title, "Legend of Zelda");
    strcpy(song_list[3].copyright, "N/A");
    song_list[3].tempo = 31010390;
    strcpy(song_list[4].title, "Game of Thrones");
    strcpy(song_list[4].copyright, "N/A");
    song_list[4].tempo = 305106213;
    SysTick_Config(SystemCoreClock / 1000);
    custom_printf("\r\n***REMOTE MODE ACTIVE***\r\n");
}

// Switches to remote mode and stops the song
void switch_to_remote_mode() {
    is_remote_mode = 1;
    is_local_mode = 0;
    custom_printf("\r\n\n***REMOTE MODE ACTIVE***\r\n");
    custom_printf("\r\n>> ");
    stop_song();
}

// Switches to local mode and stops the song
void switch_to_local_mode() {
    is_remote_mode = 0;
    is_local_mode = 1;
    custom_printf("\r\n\n***MANUAL OVERRIDE MODE ACTIVE***\r\n");
    custom_printf("\r\n>> ");
    stop_song();
}

// Displays the help menu for remote mode
void display_help() {
    custom_printf("\r\n***REMOTE LED CONTROL MENU***\r\n\n");
    custom_printf("Available User Commands:\r\n\n");
    custom_printf("HELP: Show the available user commands\r\n");
    custom_printf("NEXT: Show the next song information (LED nothing)\r\n");
    custom_printf("PLAY: Play the current song (LED on)\r\n");
    custom_printf("PAUSE: Pause the current song (LED flash)\r\n");
    custom_printf("STOP: Stop the current song (LED off)\r\n\n");
}

// Displays the help menu when the HELP command is called
void next_help() {
    custom_printf("\r\n\n***REMOTE LED CONTROL MENU***\r\n\n");
    custom_printf("Available User Commands:\r\n\n");
    custom_printf("HELP: Show available commands (LED nothing)\r\n");
    custom_printf("NEXT: Show the next song information (LED nothing)\r\n");
    custom_printf("PLAY: Play the current song (LED on)\r\n");
    custom_printf("PAUSE: Pause the current song (LED flash)\r\n");
    custom_printf("STOP: Stop the current song (LED off)\r\n");
}

// Displays the song information
void display_info(const Song *song) {
    custom_printf("\r\n\nSong Title: %s\r\n", song->title);
    custom_printf("Song Copyright: %s\r\n", song->copyright);
    custom_printf("Song Tempo: %d\r", song->tempo);
}

// Plays the current song by turning the LED on
void play_song() {
    if (led_state != 1) {
        led_state = 1;
        LED_On();
    }
}

// Pauses the current song by changing the LED state
void pause_song() {
    if (led_state != 2) {
        led_state = 2;
        flash_counter = 0;
    }
}

// Stops the current song by turning the LED off
void stop_song() {
    if (led_state != 0) {
        led_state = 0;
        LED_Off();
    }
}

// Advances to the next song and displays its information
void next_song() {
    current_song_index = (current_song_index + 1) % 5;
    display_info(&song_list[current_song_index]);
}

// Toggles the LED flashing for pause state
void toggle_flash() {
    if (led_state == 2) {
        flash_counter++;
        if (flash_counter >= 10) {
            LED_Toggle();
            flash_counter = 0;
        }
    }
}

// SysTick interrupt handler for managing timing
void SysTick_Handler() {
    static uint32_t ms_count = 0;
    ms_count++;
    if (ms_count >= 1000) {
        toggle_flash();
        ms_count = 0;
    }
}

// Processes user commands based on the current mode
void process_command(const char *command) {
    if (is_remote_mode) {
        if (strcmp(command, "HELP") == 0) {
            next_help();
        } else if (strcmp(command, "NEXT") == 0) {
            next_song();
        } else if (strcmp(command, "PLAY") == 0) {
            play_song();
        } else if (strcmp(command, "PAUSE") == 0) {
            pause_song();
        } else if (strcmp(command, "STOP") == 0) {
            stop_song();
        } else {
            custom_printf("\r\n\nInvalid User Command\r");
        }
    } else {
        custom_printf("\r\n\nTerminal Input Disabled\r");
    }
}

// Main loop for processing commands
void run_loop() {
    char command[BUFFER_SIZE];
    uint8_t index = 0;
    char ch;
    display_help();
    custom_printf(">> ");
    while (1) {
        memset(command, 0, sizeof(command));
        index = 0;
        while (1) {
            ch = USART_Read_Nonblocking(USART2);
            if (ch != 0) {
                if (ch == '\b') {
                    if (index > 0) {
                        index--;
                        custom_printf("\b \b");
                    }
                } else {
                    if (ch == '\n' || ch == '\r') {
                        command[index] = '\0';
                        break;
                    }
                    if (index < sizeof(command) - 1) {
                        command[index++] = ch;
                        custom_printf("%c", ch);
                    }
                }
            }
        }
        process_command(command);
        custom_printf("\r\n\n>> ");
    }
}

// Main function for the program
int run_main() {
    init_all();
    run_loop();
    return 0;
}
