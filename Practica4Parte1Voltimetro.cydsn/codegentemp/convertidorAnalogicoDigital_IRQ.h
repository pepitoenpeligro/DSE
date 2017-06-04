/*******************************************************************************
* File Name: convertidorAnalogicoDigital_IRQ.h
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
#if !defined(CY_ISR_convertidorAnalogicoDigital_IRQ_H)
#define CY_ISR_convertidorAnalogicoDigital_IRQ_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void convertidorAnalogicoDigital_IRQ_Start(void);
void convertidorAnalogicoDigital_IRQ_StartEx(cyisraddress address);
void convertidorAnalogicoDigital_IRQ_Stop(void);

CY_ISR_PROTO(convertidorAnalogicoDigital_IRQ_Interrupt);

void convertidorAnalogicoDigital_IRQ_SetVector(cyisraddress address);
cyisraddress convertidorAnalogicoDigital_IRQ_GetVector(void);

void convertidorAnalogicoDigital_IRQ_SetPriority(uint8 priority);
uint8 convertidorAnalogicoDigital_IRQ_GetPriority(void);

void convertidorAnalogicoDigital_IRQ_Enable(void);
uint8 convertidorAnalogicoDigital_IRQ_GetState(void);
void convertidorAnalogicoDigital_IRQ_Disable(void);

void convertidorAnalogicoDigital_IRQ_SetPending(void);
void convertidorAnalogicoDigital_IRQ_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the convertidorAnalogicoDigital_IRQ ISR. */
#define convertidorAnalogicoDigital_IRQ_INTC_VECTOR            ((reg32 *) convertidorAnalogicoDigital_IRQ__INTC_VECT)

/* Address of the convertidorAnalogicoDigital_IRQ ISR priority. */
#define convertidorAnalogicoDigital_IRQ_INTC_PRIOR             ((reg8 *) convertidorAnalogicoDigital_IRQ__INTC_PRIOR_REG)

/* Priority of the convertidorAnalogicoDigital_IRQ interrupt. */
#define convertidorAnalogicoDigital_IRQ_INTC_PRIOR_NUMBER      convertidorAnalogicoDigital_IRQ__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable convertidorAnalogicoDigital_IRQ interrupt. */
#define convertidorAnalogicoDigital_IRQ_INTC_SET_EN            ((reg32 *) convertidorAnalogicoDigital_IRQ__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the convertidorAnalogicoDigital_IRQ interrupt. */
#define convertidorAnalogicoDigital_IRQ_INTC_CLR_EN            ((reg32 *) convertidorAnalogicoDigital_IRQ__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the convertidorAnalogicoDigital_IRQ interrupt state to pending. */
#define convertidorAnalogicoDigital_IRQ_INTC_SET_PD            ((reg32 *) convertidorAnalogicoDigital_IRQ__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the convertidorAnalogicoDigital_IRQ interrupt. */
#define convertidorAnalogicoDigital_IRQ_INTC_CLR_PD            ((reg32 *) convertidorAnalogicoDigital_IRQ__INTC_CLR_PD_REG)


#endif /* CY_ISR_convertidorAnalogicoDigital_IRQ_H */


/* [] END OF FILE */
