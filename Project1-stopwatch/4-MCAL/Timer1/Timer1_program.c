	/*********************************************/
/*   Author  	:		Mahmoud Tanany		 */
/*											 */
/*											 */
				
/*	Supervesion	:		Eng.Mohamed Tarek	*/
/*   					            		 */
/*   							   	         */
/*********************************************/

#include <avr/io.h>
#include "LBIT_math.h"
#include "Timer1_interface.h"




void Timer1_init(void)
{

SET_BIT(TCCR1A,3);
SET_BIT(TCCR1B,3);
TCNT1=0;
OCR1A=976;
SET_BIT(TIMSK,4);

CLEAR_BIT(TCCR1A, 0);
CLEAR_BIT(TCCR1A,1);




//SELECTING THE PRESCALER


SET_BIT(TCCR1B,0);
SET_BIT(TCCR1B,2);

}
