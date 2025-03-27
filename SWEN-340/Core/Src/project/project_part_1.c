//#include "project_part_1.h"
//#include "printf.h"
//#include "string.h"
//#include "stdio.h"
//#include "stdlib.h"
//#include "stm32l476xx.h"
//#include "SysClock.h"
//#include "UART.h"
//#include "LED.h"
//
//Song song_list[5];
//int current_song_index = 0;
//int led_state = 0;
//int flash_counter = 0;
//
//void init_all() {
//    System_Clock_Init();
//    LED_Init();
//    UART2_Init();
//    strcpy(song_list[0].title, "Twinkle Twinkle Little Star");
//    strcpy(song_list[0].copyright, "Jim Patterson");
//    song_list[0].tempo = 391625;
//    strcpy(song_list[1].title, "Harry Potter Theme");
//    strcpy(song_list[1].copyright, "N/A");
//    song_list[1].tempo = 310442;
//    strcpy(song_list[2].title, "Twinkle Twinkle Little Star");
//    strcpy(song_list[2].copyright, "Jim Patterson");
//    song_list[2].tempo = 391625;
//    strcpy(song_list[3].title, "Legend of Zelda");
//    strcpy(song_list[3].copyright, "N/A");
//    song_list[3].tempo = 31010390;
//    strcpy(song_list[4].title, "Game of Thrones");
//    strcpy(song_list[4].copyright, "N/A");
//    song_list[4].tempo = 305106213;
//    SysTick_Config(SystemCoreClock / 1000);
//}
//
//void display_help() {
//    custom_printf("\r\n***REMOTE LED CONTROL MENU***\r\n\n");
//    custom_printf("Available User Commands:\r\n\n");
//    custom_printf("NEXT: Show the next song information (LED nothing)\r\n");
//    custom_printf("PLAY: Play the current song (LED on)\r\n");
//    custom_printf("PAUSE: Pause the current song (LED flash)\r\n");
//    custom_printf("STOP: Stop the current song (LED off)\r\n\n");
//}
//
//void display_info(const Song *song) {
//    custom_printf("Song Title: %s\r\n", song->title);
//    custom_printf("Song Copyright: %s\r\n", song->copyright);
//    custom_printf("Song Tempo: %d\r\n\n", song->tempo);
//}
//
//void next_info(const Song *song) {
//    custom_printf("\r\n\nSong Title: %s\r\n", song->title);
//    custom_printf("Song Copyright: %s\r\n", song->copyright);
//    custom_printf("Song Tempo: %d\r\n", song->tempo);
//}
//
//void play_song() {
//    if (led_state != 1) {
//        led_state = 1;
//        LED_On();
//    }
//}
//
//void pause_song() {
//    if (led_state != 2) {
//        led_state = 2;
//        flash_counter = 0;
//    }
//}
//
//void stop_song() {
//    if (led_state != 0) {
//        led_state = 0;
//        LED_Off();
//    }
//}
//
//void next_song() {
//    current_song_index = (current_song_index + 1) % 5;
//    next_info(&song_list[current_song_index]);
//}
//
//void toggle_flash() {
//    if (led_state == 2) {
//        flash_counter++;
//        if (flash_counter >= 10) {
//            LED_Toggle();
//            flash_counter = 0;
//        }
//    }
//}
//
//void SysTick_Handler() {
//    static uint32_t ms_count = 0;
//    ms_count++;
//    if (ms_count >= 1000) {
//        toggle_flash();
//        ms_count = 0;
//    }
//}
//
//void process_command(const char *command) {
//    if (strcmp(command, "NEXT") == 0) {
//        next_song();
//    } else if (strcmp(command, "PLAY") == 0) {
//        play_song();
//    } else if (strcmp(command, "PAUSE") == 0) {
//        pause_song();
//    } else if (strcmp(command, "STOP") == 0) {
//        stop_song();
//    } else {
//        custom_printf("\r\n\nInvalid User Command.\r\n");
//    }
//}
//
//void run_loop() {
//    char command[BUFFER_SIZE];
//    uint8_t index = 0;
//    char ch;
//    display_help();
//    custom_printf("Initial Song:\r\n\n");
//    display_info(&song_list[current_song_index]);
//    custom_printf("Enter User Command: ");
//    while (1) {
//        memset(command, 0, sizeof(command));
//        index = 0;
//        while (1) {
//            ch = USART_Read_Nonblocking(USART2);
//            if (ch != 0) {
//                if (ch == '\b') {
//                    if (index > 0) {
//                        index--;
//                        custom_printf("\b \b");
//                    }
//                } else {
//                    if (ch == '\n' || ch == '\r') {
//                        command[index] = '\0';
//                        break;
//                    }
//                    if (index < sizeof(command) - 1) {
//                        command[index++] = ch;
//                        custom_printf("%c", ch);
//                    }
//                }
//            }
//        }
//        process_command(command);
//        custom_printf("\r\nEnter User Command: ");
//    }
//}
//
//int run_main() {
//    init_all();
//    run_loop();
//    return 0;
//}
