#include "LED.h"

//Define the pin number for the LED (PA7)
#define LED_PIN 7

// Initialize the LED
void LED_Init(void) {
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~(3U<<(2*LED_PIN));
	GPIOA->MODER |= 1U<<(2*LED_PIN);
	GPIOA->OSPEEDR &= ~(3U<<(2*LED_PIN));
	GPIOA->OSPEEDR |= 3U<<(2*LED_PIN);
	GPIOA->OTYPER &= ~(1U<<LED_PIN);
	GPIOA->PUPDR &= ~(3U<<(2*LED_PIN));
}

// Turn the LED on
void LED_On(void) {
	GPIOA->ODR |= (1UL<<LED_PIN);
}

// Turn the LED off
void LED_Off(void) {
	GPIOA->ODR &= ~(1UL<<LED_PIN);
}

// Toggle the LED state
void LED_Toggle(void) {
	GPIOA->ODR ^= (1UL<<LED_PIN);
}
