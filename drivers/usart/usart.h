#ifndef USART_H
#define USART_H

#include <stdint.h>

/**
 * @file pwm.h
 * @brief Generic Pulse Width Modulation (PWM) Driver.
 * 
 * Accurately controls the PWM duty cycle for supported pins.
 * Automatically manages underlying Timers (Timer1, Timer2).
 */

/**
 * @brief Initialize PWM on a specific pin.
 * 
 * Configures the associated timer for the given pin. 
 * Note: Pins sharing a timer must use compatible frequencies if underlying hardware dictates it.
 * 
 * @param port GPIO Port (GPIO_PORTB, GPIO_PORTD usually).
 * @param pin Pin number (0-7).
 * @param frequency_hz Desired PWM frequency in Hz.
 */
#define USART_Init_Default() USART_Init(16000000, 57600)
void USART_Init(unsigned long fosc, unsigned int baud);

/**
 * @brief Set the duty cycle for a specific pin.
 * 
 * @param port GPIO Port.
 * @param pin Pin number.
 * @param duty Duty cycle (0-255). 0 = 0%, 255 = 100%.
 */
void USART_Transmit(unsigned char* data, uint8_t size);

/**
 * @brief Stop PWM on a specific pin.
 * 
 * Disables the PWM output for that pin.
 * 
 * @param port GPIO Port.
 * @param pin Pin number.
 */
void USART_Receive(unsigned char* data, uint8_t size);

#endif // PWM_H
