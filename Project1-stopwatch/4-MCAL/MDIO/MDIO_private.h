/*********************************************/
/*   Author  	:		Mahmoud Tanany		 */
/*											 */
/*											 */
				
/*	Supervesion	:		Eng.Mohamed Tarek	*/
/*   					            		 */
/*   							   	         */
/*********************************************/

#ifndef _MDIO_PRIVATE_H_									/* 		File guard for MCAL digital input output private 																*/
#define _MDIO_PRIVATE_H_


typedef struct												/* 		Defining a struct GPIO_TYPE including identification of PIN,DDR, and PORT numbers 								*/
{
	u8 PIN;
	u8 DDR;
	u8 PORT;
}GPIO_type;

#define GPIOD ((volatile GPIO_type *)0x30)					/* 		Defining the address for PIND																					*/
#define GPIOC ((volatile GPIO_type *)0x33)					/* 		Defining the address for PINC																					*/
#define GPIOB ((volatile GPIO_type *)0x36)					/* 		Defining the address for PINB																					*/
#define GPIOA ((volatile GPIO_type *)0x39)					/* 		Defining the address for PINA																					*/


#endif
