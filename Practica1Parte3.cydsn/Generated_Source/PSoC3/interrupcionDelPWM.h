/*******************************************************************************
* File Name: interrupcionDelPWM.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ISR_interrupcionDelPWM_H)
#define CY_ISR_interrupcionDelPWM_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void interrupcionDelPWM_Start(void) ;
void interrupcionDelPWM_StartEx(cyisraddress address) ;
void interrupcionDelPWM_Stop(void) ;

CY_ISR_PROTO(interrupcionDelPWM_Interrupt);

void interrupcionDelPWM_SetVector(cyisraddress address) ;
cyisraddress interrupcionDelPWM_GetVector(void) ;

void interrupcionDelPWM_SetPriority(uint8 priority) ;
uint8 interrupcionDelPWM_GetPriority(void) ;

void interrupcionDelPWM_Enable(void) ;
uint8 interrupcionDelPWM_GetState(void) ;
void interrupcionDelPWM_Disable(void) ;

void interrupcionDelPWM_SetPending(void) ;
void interrupcionDelPWM_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the interrupcionDelPWM ISR. */
#define interrupcionDelPWM_INTC_VECTOR            ((reg16 *) interrupcionDelPWM__INTC_VECT)

/* Address of the interrupcionDelPWM ISR priority. */
#define interrupcionDelPWM_INTC_PRIOR             ((reg8 *) interrupcionDelPWM__INTC_PRIOR_REG)

/* Priority of the interrupcionDelPWM interrupt. */
#define interrupcionDelPWM_INTC_PRIOR_NUMBER      interrupcionDelPWM__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable interrupcionDelPWM interrupt. */
#define interrupcionDelPWM_INTC_SET_EN            ((reg8 *) interrupcionDelPWM__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the interrupcionDelPWM interrupt. */
#define interrupcionDelPWM_INTC_CLR_EN            ((reg8 *) interrupcionDelPWM__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the interrupcionDelPWM interrupt state to pending. */
#define interrupcionDelPWM_INTC_SET_PD            ((reg8 *) interrupcionDelPWM__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the interrupcionDelPWM interrupt. */
#define interrupcionDelPWM_INTC_CLR_PD            ((reg8 *) interrupcionDelPWM__INTC_CLR_PD_REG)



#endif /* CY_ISR_interrupcionDelPWM_H */


/* [] END OF FILE */
