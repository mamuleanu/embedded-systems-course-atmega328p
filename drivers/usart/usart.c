#include "drivers/timer/timer1.h"
#include "drivers/timer/timer2.h"



/**
 * @brief Initialize USART transmision
 * 
 * 
 * @param fosc Frequency of osscilator (16mhz default)
 * @param baud Baud rate (57600 default)
 */

void USART_Init(unsigned long fosc, unsigned int baud)
{
    unsigned long ubrr = (fosc / (16UL * baud)) - 1;

    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)(ubrr);

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    // 8 data bits, 1 stop bit, no parity
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}
/**
 * @brief Sends a char pointer trough USART.
 * 
 * 
 * @param data - char pointer
 */
void USART_Transmit(unsigned char* data, uint8_t size)
{
    for (int i = 0; i < size; i++) {
        /* Wait for empty transmit buffer */
        while (!(UCSR0A & (1 << UDRE0)))
            ;
        /* Put data into buffer, sends the data */
        UDR0 = data[i];
    }
}

/**
 * @brief Puts USART data to the data pointer.
 * 
 * @param 
 * @param 
 */
void USART_Receive(unsigned char* data, uint8_t size)
{
    for (int i = 0; i < size; i++) {
        /* Wait for data to be received */
        while (!(UCSR0A & (1 << RXC0)))
            ;
        /* Get and return received data from buffer */
        data[i] = UDR0;
    }
}
