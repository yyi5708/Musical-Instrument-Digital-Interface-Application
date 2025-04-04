#include "GPIO.h"
#include "stdbool.h"
#include "stm32l4xx.h"
#include "printf.h"

//#include "project_part_2.h"
#include "project_part_3.h"

// Current state of the LED (0 = off, 1 = on, 2 = flashing) shared across modules
extern int led_state;
// Flag indicating if the system is in remote control mode (1 = remote mode active) shared across modules
extern int is_remote_mode;
// Flag indicating if the system is in local control mode (1 = local mode active) shared across modules
extern int is_local_mode;

// Initialize GPIO pins for button interrupts
void GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitStruct.Pin = B1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);
    GPIO_InitStruct.Pin = S1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(S1_GPIO_Port, &GPIO_InitStruct);
    HAL_NVIC_SetPriority(EXTI9_5_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

// Interrupt handler for EXTI lines 10 to 15 (handles B1 button press)
void EXTI15_10_IRQHandler(void) {
    if (__HAL_GPIO_EXTI_GET_IT(B1_Pin) != RESET) {
        if (is_remote_mode) {
            switch_to_local_mode();
        } else {
            switch_to_remote_mode();
        }
        __HAL_GPIO_EXTI_CLEAR_IT(B1_Pin);
    }
}

// Interrupt handler for EXTI lines 9 to 5 (handles S1 button press)
void EXTI9_5_IRQHandler(void) {
    static uint32_t last_press_time = 0;
    static uint8_t press_count = 0;
    uint32_t current_time = HAL_GetTick();
    if (__HAL_GPIO_EXTI_GET_IT(S1_Pin) != RESET && is_local_mode) {
        if (HAL_GPIO_ReadPin(S1_GPIO_Port, S1_Pin) == GPIO_PIN_SET) {
            if (current_time - last_press_time <= 1000) {
                press_count++;
                if (press_count == 4) {
                    next_song();
                    toggle_flash();
                    custom_printf("\r\n\n>> ");
                }
            } else {
                press_count = 1;
            }
            if (press_count == 5) {
                stop_song();
                press_count = 0;
            }
            last_press_time = current_time;
        } else {
            if (press_count == 1 || press_count == 2) {
                if (led_state == 1) {
                    pause_song();
                } else {
                    play_song();
                }
            }
        }
        __HAL_GPIO_EXTI_CLEAR_IT(S1_Pin);
    }
}
