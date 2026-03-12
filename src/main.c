#include "drivers/gpio/gpio.h"
#include "drivers/interrupt/external_interrupt.h"
#include "bsp/nano.h"
#include "utils/delay.h"
#include <avr/io.h>
int main()
{


    // Disable USART0 - releases PD0 and PD1 back to GPIO control
    UCSR0B = 0;
    GPIO_Init(LED_BUILTIN, GPIO_OUTPUT);
    GPIO_Init(D0, GPIO_OUTPUT);
    GPIO_Init(D1, GPIO_OUTPUT);
    volatile int i = 0;
    while (1) {
        for (i = 0; i < 8; i++) {
            GPIO_Write(D0, (i & 1));
            GPIO_Write(D1, ((i >> 1) & 1));
            GPIO_Write(LED_BUILTIN, ((i >> 2) & 1));
            Delay(1000);

        }
    }
}