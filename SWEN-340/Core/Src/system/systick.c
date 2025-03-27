#include "systick.h"
#include "activity_7.h"

// Function to initialize the SysTick timer
void init_systick() {
    struct systick* sys = (struct systick*) 0xE000E010;
    sys->CSR = 0;
    sys->RVR = 7999999;
    sys->CSR |= (1 << 2);
    sys->CSR |= (1 << 0);
}

// Function to create a delay using the SysTick timer
void delay_systick() {
    struct systick* sys = (struct systick*) 0xE000E010;
    for (int i = 0; i < 10; i++)
    {
        while (!(sys->CSR & (1 << 16))) {
        }
    }
}
