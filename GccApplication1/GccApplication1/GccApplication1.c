/*
 * GccApplication1.c
 *
 * Created: 12/14/2017 12:20:05 PM
 *  Author: Student
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"
void cycle_1() {
	int c;
	char b[2];
	for(int i =20;i>0;i--) {
		LCDGotoXY(0,0);
		sprintf(b,"%d",i);
		LCDstring(b,2);
		_delay_ms(500);
		PORTD|=((1<<0) | (1 << 7));
		PORTC|=((1<<2)|(1<<3));
		if(i<=10) {
			PORTD|=((1<<6)|(1<<2));
			PORTC |=((1<<1)|(1<<5));
			PORTD&= ~((1<<0) | (1 << 7));
			PORTC&= ~((1<<2)|(1<<3));
		}
	}
}
void cycle_2() {
	char b[2];
	for(int i =20;i>0;i--) {
		LCDGotoXY(0,0);
		sprintf(b,"%d",i);
		LCDstring(b,2);
		_delay_ms(500);
		PORTD|=((1<<2)|(1<<5));
		PORTC|=((1<<0)|(1<<5));
		if(i<=10) {
			PORTD|=((1<<1)|(1<<7));
			PORTC |=((1<<2)|(1<<4));
			PORTD &= ~((1<<2)|(1<<5));
			PORTC &= ~((1<<0)|(1<<5));
		}
	}
}
void cycle_3() {
	char b[2];
	for(int i =20;i>0;i--) {
		LCDGotoXY(0,0);
		sprintf(b,"%d",i);
		LCDstring(b,2);
		_delay_ms(500);
		PORTD|=((1<<0)|(1<<6));
		PORTC|=((1<<1)|(1<<3));
		if(i<=10) {
			PORTD|=((1<<2)|(1<<5));
			PORTC |=((1<<0)|(1<<5));
					PORTD&=~((1<<0)|(1<<6));
					PORTC&=~((1<<1)|(1<<3));
		}
	}
}
int main(void){
	int a[2];
	char b[2];
	DDRD |=((1<<0)|(1<<1)|(1<<2)|(1<<5)|(1<<6)|(1<<7));
	DDRC |=((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5));
	LCDinit();
	while(1) {
			cycle_1();
			PORTD&=~((1<<6)|(1<<2));
			PORTC &=~((1<<1)|(1<<5));
			cycle_2();
			PORTD&=~((1<<1)|(1<<7));
			PORTC &=~((1<<2)|(1<<4));
			cycle_3();
			PORTD&=~((1<<2)|(1<<5));
			PORTC &=~((1<<0)|(1<<5));
	}
	}			