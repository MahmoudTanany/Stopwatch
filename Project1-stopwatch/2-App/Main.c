/*********************************************/
/*   Author  	:		Mahmoud Tanany		 */
/*											 */
/*											 */

/*	Supervesion	:		Eng.Mohamed Tarek	*/
/*   					            		 */
/*   							   	         */
/*********************************************/

#include "MDIO_interface.h"
#include "MDIO_private.h"
#include "LSTD_types.h"
#include "INT_interface.h"
#include "LBIT_math.h"
#include "Timer1_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>




u8 tic=0;	// sec1
u8 tic1=0;	// sec2
u8 tic2=0;	//min1
u8 tic3=0;	//min2
u8 tic4=0;	//hour1
u8 tic5=0;	//hour2

int main(void)
{
	MDIO_SetPinDirection(PORTA, 0, MDIO_OUTPUT);
	MDIO_SetPinDirection(PORTA, 1, MDIO_OUTPUT);
	MDIO_SetPinDirection(PORTA, 2, MDIO_OUTPUT);
	MDIO_SetPinDirection(PORTA, 3, MDIO_OUTPUT);
	MDIO_SetPinDirection(PORTA, 4, MDIO_OUTPUT);
	MDIO_SetPinDirection(PORTA, 5, MDIO_OUTPUT);
	DDRC|=0xff;

	MDIO_SetPortValue(PORTC, MDIO_LOW);
	MDIO_SetPortValue(PORTD, MDIO_HIGH);
	MDIO_SetPortValue(PORTA, MDIO_HIGH);

	INT1_Init();
	INT0_Init();
	INT2_Init();
	Timer1_init();



	while(1)
	{

		PORTA=0x20;
		PORTC=tic;
		_delay_us(5);
		PORTA=0x10;
		PORTC=tic1;
		_delay_us(5);
		PORTA=0x08;
		PORTC=tic2;
		_delay_us(5);
		PORTA=0x04;
		PORTC=tic3;
		_delay_us(5);
		PORTA=0x02;
		PORTC=tic4;
		_delay_us(5);
		PORTA=0x01;
		PORTC=tic5;
		_delay_us(5);


	}


}

ISR(TIMER1_COMPA_vect)
{
	tic++;
		TCNT1 = 0;
		if(tic==10){
			tic1++;
			tic=0;
		}
	if(tic1==6){
		tic2++;
		_delay_ms(10);
		tic1=0;
	}
	if(tic2==10){
		tic3++;
		tic2=0;
	}
	if(tic3==6){
		tic4++;
		tic3=0;
	}
	if(tic4==10){
		tic5++;
		tic4=0;
	}
}
ISR(INT0_vect)
{
	tic=0;
		tic1=0;
		tic2=0;
		tic3=0;
		tic4=0;
		tic5=0;
}
ISR(INT1_vect)
{
	CLEAR_BIT(TCCR1B,0);
	CLEAR_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,2);

}
ISR(INT2_vect)
{

	TCCR1B=(1<<CS12)|(1<<CS10);

}
