#include "drivers/gpio/gpio.h"
#include "drivers/timer/timer0.h"
#include "bsp/nano.h"
#include "drivers/usart/usart.h"

int main(void) {

    Timer0_Init();

    GPIO_Init(LED_BUILTIN, GPIO_OUTPUT);
    USART_Init_Default();
    uint8_t size;
    char data[10];
    while (1) {
        size = USART_Receive(data,2000);
        if (size > 0)
        {
            USART_Transmit(data, size);
        }
        DelayT0(300);
    }
}  
