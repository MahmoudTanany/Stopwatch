/*********************************************/
/*   Author  	:		Mahmoud Tanany		 */
/*											 */
/*											 */
				
/*	Supervesion	:		Eng.Mohamed Tarek	*/
/*   					            		 */
/*   							   	         */
/*********************************************/

#include "LBIT_math.h"									/* 		Including the library files 																						*/
#include "LSTD_types.h"

#include "MDIO_private.h"								/* 		Including the MCAL digital input output files																		*/
#include "MDIO_interface.h"


void MDIO_SetPortDirection(u8 port,u8 direction)); 		/* 		Function that set the direction of a port addressing the register DDR, this function parameters
																	are PORT number MDIO_PORT.. and the direction even MDIO_INPUT or MDIO_OUTPUT									*/
{
	switch(port)										/* 		Switch case for selecting the port needed to set the direction of it												*/	
	{
		case MDIO_PORTA:
		{
			GPIOA -> DDR = direction;
			break;
		}
		case MDIO_PORTB:
		{
			GPIOB -> DDR = direction;
			break;
		}
		case MDIO_PORTC:
		{
			GPIOC -> DDR = direction;
			break;
		}
		case MDIO_PORTD:
		{
			GPIOD -> DDR = direction;
			break;
		}
		default:
		{
			//Report an Error
			break;
		}
	}
}
void MDIO_SetPortValue(u8 port, u8 value)			/* 		Function that set the PORT a value even MDIO_HIGH or MDIO_LOW, this function parameters are 	
																	the PORT number MDIO_PORT.. and the value																		*/
{
	switch(port)									/* 		Switch case for selecting the port needed to set the direction of it													*/
	{
		case MDIO_PORTA:
		{
			GPIOA -> PORT = value;
			break;
		}
		case MDIO_PORTB:
		{
			GPIOB -> PORT = value;
			break;
		}
		case MDIO_PORTC:
		{
			GPIOC -> PORT = value;
			break;
		}
		case MDIO_PORTD:
		{
			GPIOD -> PORT = value;
			break;
		}
		default:
		{
			//Report an Error
			break;
		}
	}
}
u8  MDIO_GetPortValue(u8 port) 							/* 		 Function that get the port value if the port is input direction even MDIO_HIGH or MDIO_LOW 
																	,This function parameter is the PORT number PORT..																*/
{
	u8 value;											/* 		Defining a value as an unsigned character 																			*/
	
	switch(port)										/* 		Switch case for selecting the port needed to set the direction of it												*/
	{
		case MDIO_PORTA:
		{
			value = GPIOA -> PIN;
			break;
		}
		case MDIO_PORTB:
		{
			value = GPIOB -> PIN;
			break;
		}
		case MDIO_PORTC:
		{
			value = GPIOC -> PIN;
			break;
		}
		case MDIO_PORTD:
		{
			value = GPIOD -> PIN;
			break;
		}
		default:
		{
			//Report and Error
			break;
		}
	}
	return value;
}

void MDIO_SetPinDirection(u8 port, u8 pin, u8 direction) /* 	Function that set the direction of a specific PIN in a port,this function parameters are the port
																	number MDIO_PORT.. ,pin number 0,1,2,.. ,and the direction MDIO_INPUT MDIO_OUTPUT								*/
{
	if(pin>=0 && pin<=7) 								 /* 	If condition that make sure that the number of the pin entered is valid 											*/
	{
		switch(port)									 /* 	Switch case for selecting the port needed to set the direction of it												*/
		{
			case MDIO_PORTA:
			{
				if(MDIO_OUTPUT == direction)			 /* 	If condition for specify if the pin is MDIO_OUTPUT or MDIO_INPUT 													*/
				{
					SET_BIT(GPIOA -> DDR, pin);			 /* 	Setting 'High' a bit in a register,this function parameters are the register and the bit number needed the parameters
																	are the register name which is DDR and the pin number															*/ 
						
				}
				else if(MDIO_INPUT == direction)
				{
					CLEAR_BIT(GPIOA -> DDR, pin);
				}
				else
				{
					//report error
				}
				break;
			}	
		
			case MDIO_PORTB:
			{
				if(MDIO_OUTPUT == direction)
				{
					SET_BIT(GPIOB ->DDR, pin);
						
				}
				
				else if(MDIO_INPUT == direction)
				{
					CLEAR_BIT(GPIOB -> DDR, pin);
				}	
				else
				{
					//report error
				}
				break;
			}
			case MDIO_PORTC:
			{
				if(MDIO_OUTPUT == direction)
				{
					SET_BIT(GPIOC ->DDR, pin);
						
				}
				
				else if (MDIO_INPUT == direction)
				{
					
					CLEAR_BIT(GPIOC -> DDR, pin);
				}
				else
				{
					//report error
				}
				break;
			}
			
			case MDIO_PORTD:
			{
				if(MDIO_OUTPUT == direction)
				{
					SET_BIT(GPIOD ->DDR, pin);
						
				}
				
				else if (MDIO_INPUT == direction)
				{
					CLEAR_BIT(GPIOD -> DDR, pin);
				}
				else
				{
					//report error
				}
				break;
			}
			default:
			{
					//Report an Error
				break;
			}
		}
	}
	else
	{
		//Report an Error
	}	
}
void MDIO_SetPinValue(u8 port, u8 pin, u8 value) 		/* 		Function that setting a bit value,this function parameters are PORT number MDIO_PORT..
																	Pin number 0,1,2,.. ,and the value MDIO_HIGH MDIO_LOW															*/
{
	if(pin>=0 && pin<=7) 								/* 	If condition that make sure that the number of the pin entered is valid 												*/
	{
		switch(port)									/* 	Switch case for selecting the port needed to set the direction of it													*/
		{
			case MDIO_PORTA:
			{
				if(value == MDIO_HIGH)			 		/* 	If condition for specify if the pin is MDIO_HIGH or MDIO_LOW 															*/
				{
					SET_BIT(GPIOA -> PORT, pin);
						
				}
				else if(value == MDIO_LOW)
				{
					CLEAR_BIT(GPIOA -> PORT, pin);
				}
				else
				{
					//report error
				}
				break;
			}	
		
			case MDIO_PORTB:
			{
				if(value == MDIO_HIGH)
				{
					SET_BIT(GPIOB ->PORT, pin);
						
				}
				
				else if(value == MDIO_LOW)
				{
					CLEAR_BIT(GPIOB -> PORT, pin);
				}	
				else
				{
					//report error
				}
				break;
			}
			case MDIO_PORTC:
			{
				if(value == MDIO_HIGH)
				{
					SET_BIT(GPIOC ->PORT, pin);
						
				}
				
				else if (value == MDIO_LOW)
				{
					
					CLEAR_BIT(GPIOC -> PORT, pin);
				}
				else
				{
					//report error
				}
				break;
			}
			
			case MDIO_PORTD:
			{
				if(value == MDIO_HIGH)
				{
					SET_BIT(GPIOD ->PORT, pin);
						
				}
				
				else if (value == MDIO_LOW)
				{
					CLEAR_BIT(GPIOD -> PORT, pin);
				}
				else
				{
					//report error
				}
				break;
			}
			default:
			{
					//Report an Error
				break;
			}
		}
	}
	else
	{
		//Report an Error
	}
}
u8   MDIO_GetPinValue(u8 port, u8 pin)
{
	u8 value;
	
	if(pin >= 0 && pin <=7)
	{
		switch (port)
		{
			case MDIO_PORTA:
			{
				if(1 == (GET_BIT((GPIOA -> PIN),pin)))
				{
					value = MDIO_HIGH;
				}
				else if(0 == (GET_BIT((GPIOA -> PIN),pin)))
				{
					value = MDIO_LOW;
				}
				else
				{
					//report error
				}
				break;
			}
			case MDIO_PORTB:
			{
				if(1 ==(GET_BIT((GPIOB -> PIN),pin)))
				{
					value = MDIO_HIGH;
				}
				else if(0 ==(GET_BIT((GPIOB -> PIN),pin)))
				{
					value = MDIO_LOW;
				}
				else
				{
					//reprt error
				}
			break;
			}
			case MDIO_PORTC:
			{
				if(1 ==(GET_BIT((GPIOC -> PIN),pin)))
				{
					value = MDIO_HIGH;
				}
				else if(0 ==(GET_BIT((GPIOC -> PIN),pin)))
				{
					value = MDIO_LOW;
				}
				else
				{
					//reprt error
				}
			break;
			}
			case MDIO_PORTD:
			{
				if(1 ==(GET_BIT((GPIOD -> PIN),pin)))
				{
					value = MDIO_HIGH;
				}
				else if(0 == (GET_BIT((GPIOD -> PIN),pin)))
				{
					value = MDIO_LOW;
				}
				else
				{
					//reprt error
				}
			break;
			}
			
		}
	}
	else
	{
		//report error
	}
	
	return value;
}
