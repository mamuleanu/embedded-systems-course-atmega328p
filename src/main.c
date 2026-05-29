#include "drivers/gpio/gpio.h"
#include "drivers/timer/timer0.h"
#include "drivers/pwm/pwm.h"
#include "bsp/nano.h"
#include "utils/delay.h"
#define MASINA_ROSU   D3
#define MASINA_GALBEN D4
#define MASINA_VERDE  D5
#define PIETON_ROSU   D6
#define PIETON_VERDE  D7
#define BUTON         D8
#define BUZZER_SEMNAL D9
#define BUZZER_ACTIV  D10
#define NOTA_DO       261
#define NOTA_RE       294
#define NOTA_MI       329
int main(void) {
    Timer0_Init();
    GPIO_Init(MASINA_ROSU, GPIO_OUTPUT);
    GPIO_Init(MASINA_GALBEN, GPIO_OUTPUT);
    GPIO_Init(MASINA_VERDE, GPIO_OUTPUT);
    GPIO_Init(PIETON_ROSU, GPIO_OUTPUT);
    GPIO_Init(PIETON_VERDE, GPIO_OUTPUT);
    GPIO_Init(BUZZER_ACTIV, GPIO_OUTPUT);
    GPIO_Init(BUTON, GPIO_INPUT);
    PWM_Init(BUZZER_SEMNAL, NOTA_DO);
    PWM_SetDutyCycle(BUZZER_SEMNAL, 0);
    GPIO_Write(MASINA_VERDE, GPIO_HIGH);
    GPIO_Write(MASINA_GALBEN, GPIO_LOW);
    GPIO_Write(MASINA_ROSU, GPIO_LOW);
    GPIO_Write(PIETON_VERDE, GPIO_LOW);
    GPIO_Write(PIETON_ROSU, GPIO_HIGH);
    GPIO_Write(BUZZER_ACTIV, GPIO_LOW);
    while (1) {
        if (GPIO_Read(BUTON) == GPIO_HIGH) {
            Delay(50);
            if (GPIO_Read(BUTON) == GPIO_HIGH) {
                GPIO_Write(MASINA_VERDE, GPIO_HIGH);
                GPIO_Write(MASINA_GALBEN, GPIO_LOW);
                GPIO_Write(MASINA_ROSU, GPIO_LOW);
                GPIO_Write(PIETON_VERDE, GPIO_LOW);
                GPIO_Write(PIETON_ROSU, GPIO_HIGH);
                Delay(5000);
                GPIO_Write(MASINA_VERDE, GPIO_LOW);
                GPIO_Write(MASINA_GALBEN, GPIO_HIGH);
                GPIO_Write(MASINA_ROSU, GPIO_LOW);
                GPIO_Write(PIETON_VERDE, GPIO_LOW);
                GPIO_Write(PIETON_ROSU, GPIO_HIGH);
                Delay(5000);
                GPIO_Write(MASINA_VERDE, GPIO_LOW);
                GPIO_Write(MASINA_GALBEN, GPIO_LOW);
                GPIO_Write(MASINA_ROSU, GPIO_HIGH);
                GPIO_Write(PIETON_ROSU, GPIO_LOW);
                GPIO_Write(PIETON_VERDE, GPIO_HIGH);
                GPIO_Write(BUZZER_ACTIV, GPIO_HIGH);
                for (int i = 0; i < 3; i++) {
                    PWM_Init(BUZZER_SEMNAL, NOTA_DO);
                    PWM_SetDutyCycle(BUZZER_SEMNAL, 50);
                    Delay(500);
                    PWM_Init(BUZZER_SEMNAL, NOTA_RE);
                    PWM_SetDutyCycle(BUZZER_SEMNAL, 50);
                    Delay(500);
                    PWM_Init(BUZZER_SEMNAL, NOTA_MI);
                    PWM_SetDutyCycle(BUZZER_SEMNAL, 50);
                    Delay(500);
                    PWM_SetDutyCycle(BUZZER_SEMNAL, 0);
                    Delay(1500);
                }
                GPIO_Write(BUZZER_ACTIV, GPIO_LOW);
                PWM_SetDutyCycle(BUZZER_SEMNAL, 0);
                GPIO_Write(MASINA_VERDE, GPIO_HIGH);
                GPIO_Write(MASINA_GALBEN, GPIO_LOW);
                GPIO_Write(MASINA_ROSU, GPIO_LOW);
                GPIO_Write(PIETON_VERDE, GPIO_LOW);
                GPIO_Write(PIETON_ROSU, GPIO_HIGH);
            }
        }
    }
}
