#include "drivers/gpio/gpio.h"
#include "drivers/timer/timer0.h"
#include "bsp/nano.h"

int main(void) {
    // Initialize Timer for Millis()
    Timer0_Init();
    // Initialize LED pin
    GPIO_Init(LED_BUILTIN, GPIO_OUTPUT);

    while (1) {
        
        if (Millis() % 1000 == 0) {
            GPIO_Toggle(LED_BUILTIN);
        }
    }
}