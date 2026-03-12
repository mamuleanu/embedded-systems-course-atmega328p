#include "drivers/gpio/gpio.h"
#include "drivers/interrupt/external_interrupt.h"
#include "bsp/nano.h"
#include "drivers/usart/usart.h"
#include "drivers/timer/timer0.h"
#include <avr/io.h>

int main()
{
    Timer0_Init();
    USART_Init_Default();
    uint8_t message[20];
    uint8_t size;
    while (1) {
        size = USART_Receive(message);
        if (size > 0) {
            USART_Transmit(message, size);
        }
    }
}