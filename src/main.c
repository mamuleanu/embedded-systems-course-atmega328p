#include "drivers/gpio/gpio.h"
#include "drivers/timer/timer0.h"
#include "bsp/nano.h"

int main(void) {
    
    Timer0_Init();

    
    GPIO_Init(LED_BUILTIN, GPIO_OUTPUT);
<<<<<<< HEAD

    uint32_t last_time = 0;

=======
    int state = 0;
>>>>>>> d704f37 (changed baudrate,com port and solved main toggle problems)
    while (1) {
            
        if (Millis() - last_time >= 1000) {
            last_time = Millis();
            GPIO_Toggle(LED_BUILTIN);
            for (int i = 0; i < 40; i++) {}
        }
    }
}