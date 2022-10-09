#ifndef _i1wire_h
#define _i1wire_h
#include <avr/io.h>
#include <util/delay.h>


#define OW_low OW_DIR |= 1 << OW_PIN
#define OW_high OW_DIR &= ~( 1 << OW_PIN )
#define OW_check ( OW_IN & ( 1 << OW_PIN ) )

uint8_t OW_reset(void);
void OW_send(uint8_t byte);
uint8_t OW_recv(void);
void OWWriteBit(uint8_t bit);
uint8_t OWReadBit(void);

#define OW_PIN PB3
#define OW_DIR DDRB
#define OW_OUT PORTB
#define OW_IN PINB

#endif
