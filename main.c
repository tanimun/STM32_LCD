//Enable GPIOA and GPIOB clock---- RCC APB2ENR Pin2 and Pin3
//Configure GPIOB To 7 as output and GPIOA5 and 7 as OUTPUT


#include "stm32f10x.h"                  // Device header

#define RS 0x0020;
#define EN 0X0080;

void LCD_command(unsigned char command);
void LCD_data (char data);
void delayMs(int delay);

int main(void)
{
	// INITIALIZE GPIO PORT 
	// Initialize te clock for the GPIOA and GPIOB
	RCC->APB2ENR|= 0x0C;
	
	//Configure GPIOB0 To 7 as output
	GPIOB ->CRL = 0x33333333;
	
	//Configure GPIOA5 AND 7 as output
	GPIOA ->CRL = 0x30300000;
	
	// ****** Initialize LCD *********
	
	LCD_command(0x38); 
	delayMs(10);
	LCD_command(0x38);
	delayMs(1);
	LCD_command(0x38);
	delayMs(1);
	LCD_command(0x0E);
	delayMs(1);
	LCD_command(0x01);
	delayMs(1);
	LCD_command(0x06);
	delayMs(1);
	LCD_command(0x80);
	delayMs(1);
	LCD_data('A');
	LCD_data('P');
	LCD_data('U');
	LCD_data('B');
	LCD_data('A');
	LCD_data('I');
	while(1)
	{
	
	}
	
}

void LCD_command (unsigned char command)
{
	
	GPIOA->ODR &= ~RS;
	GPIOB->ODR = command;
	GPIOA->ODR |= EN;
	delayMs(1);
	GPIOA->ODR &=~EN;
	delayMs(1);
}

void LCD_data(char data)
{
	GPIOA->ODR |= RS;
	GPIOB->ODR = data;
	GPIOA->ODR |= EN;
	delayMs(1);
	GPIOA->ODR &=~EN;
	delayMs(1);
	
}

void delayMs(int delay)
{

	for(; delay>0; delay--)
	{
		for(int i = 0; i<5000; i++)
		{}
	}

}

