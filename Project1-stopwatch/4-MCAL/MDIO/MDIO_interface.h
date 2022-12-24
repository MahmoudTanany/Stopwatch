	/*********************************************/
/*   Author  	:		Mahmoud Tanany		 */
/*											 */
/*											 */
				
/*	Supervesion	:		Eng.Mohamed Tarek	*/
/*   					            		 */
/*   							   	         */
/*********************************************/






#ifndef _MDIO_INTERFACE_H_ 									/* 		File guard for MCAL digital input output interface 																*/    
#define _MDIO_INTERFACE_H_

#define MDIO_PORTA 	77 										/* 		Defining MCAL digital input output 	'PORTA' 		 															*/    
#define MDIO_PORTB 	64 										/* 		Defining MCAL digital input output 	'PORTB' 		 															*/ 
#define MDIO_PORTC 	12 										/* 		Defining MCAL digital input output 	'PORTC' 		 															*/ 
#define MDIO_PORTD 	17 										/* 		Defining MCAL digital input output 	'PORTD' 		 															*/  


#define MDIO_HIGH	1 										/* 		Defining MCAL digital input output 	'HIGH' 		 																*/
#define MDIO_LOW	0 										/* 		Defining MCAL digital input output 	'LOW' 		 																*/

#define MDIO_INPUT	0 										/* 		Defining MCAL digital input output As an input for defining the PIN direction '0 for input pin' 		 		*/
#define MDIO_OUTPUT	1 										/* 		Defining MCAL digital input output As an output for defining the PIN direction '1 for output pin' 		 		*/


void MDIO_SetPortDirection(u8 port, u8 direction); 			/* 		A prototype for a function that set the direction of a port addressing the register DDR, this function parameters
																	are PORT number MDIO_PORT.. and the direction even MDIO_INPUT or MDIO_OUTPUT									*/
																	
void MDIO_SetPortValue(u8 port, u8 value); 					/* 		A prototype for a function that set the PORT a value even MDIO_HIGH or MDIO_LOW, this function parameters are 	
																	the PORT number MDIO_PORT.. and the value																		*/
																	
u8 	 MDIO_GetPortValue(u8 port); 							/* 		A prototype for a function that get the port value if the port is input direction even MDIO_HIGH or MDIO_LOW 
																	,This function parameter is the PORT number PORT..																*/

void MDIO_SetPinDirection(u8 port, u8 pin, u8 direction); 	/* 		A prototype for a function that set the direction of a specific PIN in a port,this function parameters are the port
																	number MDIO_PORT.. ,pin number 0,1,2,.. ,and the direction MDIO_INPUT MDIO_OUTPUT								*/
																	
void MDIO_SetPinValue(u8 port, u8 pin, u8 value); 			/* 		A prototype for a function that setting a bit value,this function parameters are PORT number MDIO_PORT..
																	Pin number 0,1,2,.. ,and the value MDIO_HIGH MDIO_LOW															*/
																	
u8   MDIO_GetPinValue(u8 port, u8 pin); 					/* 		A prototype for a function that get the pin value MDIO_HIGH MDIO_LOW in case input direction, this function 	
																	parameters are PORT number MDIO_PORT.., and the pin number 0,1,2..												*/

#endif