/*********************************************/
/*   Author  	:		Mahmoud Tanany		 */
/*											 */
/*											 */
				
/*	Supervesion	:		Eng.Mohamed Tarek	*/
/*   					            		 */
/*   							   	         */
/*********************************************/

/* Bit math */ 






#ifndef _LBIT_MATH_H_ 									/* 		File guard for Bit math 																					*/    

#define _LBIT_MATH_H_	

#define SET_BIT(REG, BIT) 		REG |= (1<<BIT)			/* 		Setting 'High' a bit in a register,this function parameters are the register and the bit number needed 		*/ 

#define CLEAR_BIT(REG, BIT)		REG &=~(1<<BIT)			/* 		Clearing 'Low' a bit in a register,this function parameters are the register and the bit number needed 		*/ 

#define TOGGLE_BIT(REG, BIT)	REG ^= (1<<BIT)			/* 		Toggling a bit in a register,this function parameters are the register and the bin number needed		    */ 

#define GET_BIT(REG,BIT)		(REG>>BIT)&1			/* 		This function is to get the value of a needed bit, this function parameters are the register and 
																the bit number needed to be known 																			*/ 

#endif