#include "lcd.h"

void lcd_write_instr(uint8_t data) {
	LCD_PORT &=~(1<<LCD_RS);
	LCD_PORT |= (1<<LCD_E);
	LCD_PORT = ( data & 0xF0 )|( LCD_PORT & 0x0F );
	_delay_ms(1);
	LCD_PORT &= ~(1<<LCD_E);
	_delay_ms(1);
	LCD_PORT |= (1<<LCD_E);
	LCD_PORT = ( data<<4 )|( LCD_PORT & 0x0F );
	_delay_ms(1);
	LCD_PORT &= ~(1<<LCD_E);
	_delay_ms(1);
	
}

void lcd_write_data(uint8_t data) {
	LCD_PORT |= (1<<LCD_RS);
	LCD_PORT |= (1<<LCD_E);
	LCD_PORT = ( data & 0xF0 )|( LCD_PORT & 0x0F );
	_delay_ms(1);
	LCD_PORT &= ~(1<<LCD_E);
	_delay_ms(1);
	LCD_PORT |= (1<<LCD_E);
	LCD_PORT = ( data<<4 )|( LCD_PORT & 0x0F );
	_delay_ms(1);
	LCD_PORT &= ~(1<<LCD_E);
	_delay_ms(1);
	
}
void lcdinit(void) {
	LCD_DDR = 0xFF;
	_delay_ms(45);
	lcd_write_instr(0x33);
	lcd_write_instr(0x32);
	lcd_write_instr(0x28);
	lcd_write_instr(0x08);
	lcd_write_instr(0x01);
	lcd_write_instr(0x06);
	lcd_write_instr(0x0F);
}

void lcd_clear(void) {
	lcd_write_instr(0b0000001);
}

void lcd_set_xy(uint8_t x, uint8_t y) {
	lcd_write_instr(0x80+x+y*0x40);
}

void lcd_write_text_xy(uint8_t x, uint8_t y, char *text) {
	lcd_set_xy(x,y);
	while(*text){
		lcd_write_data(*text);
		text++;
	}	
	
}

int lcd_putc(char c,FILE* unused) {
	lcd_write_data(c);
	return 0;
}

void kursor(int a) {
	if (a==0)
		lcd_write_instr(0b00001100);
	else
		lcd_write_instr(0b00001111);
}
