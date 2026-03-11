#include "drivers/gpio/gpio.h"
#include "drivers/timer/timer0.h"
#include "bsp/nano.h"
#include "drivers/usart/usart.h"

int main(void) {

    Timer0_Init();


    GPIO_Init(LED_BUILTIN, GPIO_OUTPUT);
    GPIO_Init(D8, GPIO_OUTPUT);
    GPIO_Init(D7, GPIO_OUTPUT);
    GPIO_Init(D6, GPIO_OUTPUT);
    GPIO_Init(D9, GPIO_OUTPUT);
    USART_Init_Default();
    uint32_t last_time = 0;
    uint8_t counter = 0;
    uint8_t copy = 0;
    char* mesaj = "salut";
    uint32_t wait = 300;
    while (1) {

        USART_Transmit(mesaj, sizeof(mesaj));
        DelayT0(300);
    }
}  
