#include "drivers/timer/timer0.h"



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
void USART_Transmit(void* buffer, uint8_t size)
{
    unsigned char* data = (unsigned char*)buffer;
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
int USART_Receive(void* buffer)
{
    unsigned char* data = (unsigned char*)buffer;
    int i = 0;
    uint32_t last_time = Millis();

    // Loop until timeout or buffer is full (save 1 byte for null terminator)
    while ((Millis() - last_time <= 1000) && (i < 50)) {

        // Non-blocking check for data
        if (UCSR0A & (1 << RXC0)) {
            data[i] = UDR0;

            // Reset timer on every successful byte (Optional: Rolling Timeout)
            last_time = Millis();

            if (data[i] == '\n' || data[i] == '\r') {
                break;
            }
            i++;
        }
    }

    data[i] = '\0'; // Always null-terminate
    return i;
}