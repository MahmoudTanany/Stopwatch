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
#include "LBIT_math.h"
#include "LSTD_types.h"
#include "INT_interface.h"
#include <avr/interrupt.h>
#include<avr/io.h>




void INT0_Init(void)
{
	MDIO_SetPinDirection(PORTD, 2, MDIO_INPUT);  	// Configure INT0/PD2 as input pin
	MDIO_SetPinValue(PORTD,2,MDIO_HIGH);			//enable internal pull up resistore at PD2 pin
	SET_BIT(GICR,6);              					   // Enable external interrupt pin INT0
	SET_BIT(MCUCR,1);
	CLEAR_BIT(MCUCR,0);														// Trigger INT0 with the FALLING edge
	SET_BIT(SREG,7);                   					// Enable interrupts by setting I-bit
}

void INT1_Init(void)
{
	SREG  &= ~(1<<7);
	MDIO_SetPinDirection(PORTD, 3, MDIO_INPUT);  // Configure INT1/PD3 as input pin
	MDIO_SetPinValue(PORTD,3,MDIO_LOW);
	SET_BIT(GICR,7);   // Enable external interrupt pin INT1					
	SET_BIT(MCUCR,3);
	SET_BIT(MCUCR,2);
	SET_BIT(SREG,7);      // Enable interrupts by setting I-bit
}

void INT2_Init(void)
{
	SREG  &= ~(1<<7);
	MDIO_SetPinDirection(PORTB, 2, MDIO_INPUT);
	MDIO_SetPinValue(PORTB,2,MDIO_HIGH);
	SET_BIT(GICR,5);
	CLEAR_BIT(MCUCSR,6);

	SET_BIT(SREG,7);
}
