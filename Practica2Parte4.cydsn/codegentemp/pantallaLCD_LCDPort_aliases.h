/*******************************************************************************
* File Name: pantallaLCD_LCDPort.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_pantallaLCD_LCDPort_ALIASES_H) /* Pins pantallaLCD_LCDPort_ALIASES_H */
#define CY_PINS_pantallaLCD_LCDPort_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define pantallaLCD_LCDPort_0			(pantallaLCD_LCDPort__0__PC)
#define pantallaLCD_LCDPort_0_INTR	((uint16)((uint16)0x0001u << pantallaLCD_LCDPort__0__SHIFT))

#define pantallaLCD_LCDPort_1			(pantallaLCD_LCDPort__1__PC)
#define pantallaLCD_LCDPort_1_INTR	((uint16)((uint16)0x0001u << pantallaLCD_LCDPort__1__SHIFT))

#define pantallaLCD_LCDPort_2			(pantallaLCD_LCDPort__2__PC)
#define pantallaLCD_LCDPort_2_INTR	((uint16)((uint16)0x0001u << pantallaLCD_LCDPort__2__SHIFT))

#define pantallaLCD_LCDPort_3			(pantallaLCD_LCDPort__3__PC)
#define pantallaLCD_LCDPort_3_INTR	((uint16)((uint16)0x0001u << pantallaLCD_LCDPort__3__SHIFT))

#define pantallaLCD_LCDPort_4			(pantallaLCD_LCDPort__4__PC)
#define pantallaLCD_LCDPort_4_INTR	((uint16)((uint16)0x0001u << pantallaLCD_LCDPort__4__SHIFT))

#define pantallaLCD_LCDPort_5			(pantallaLCD_LCDPort__5__PC)
#define pantallaLCD_LCDPort_5_INTR	((uint16)((uint16)0x0001u << pantallaLCD_LCDPort__5__SHIFT))

#define pantallaLCD_LCDPort_6			(pantallaLCD_LCDPort__6__PC)
#define pantallaLCD_LCDPort_6_INTR	((uint16)((uint16)0x0001u << pantallaLCD_LCDPort__6__SHIFT))

#define pantallaLCD_LCDPort_INTR_ALL	 ((uint16)(pantallaLCD_LCDPort_0_INTR| pantallaLCD_LCDPort_1_INTR| pantallaLCD_LCDPort_2_INTR| pantallaLCD_LCDPort_3_INTR| pantallaLCD_LCDPort_4_INTR| pantallaLCD_LCDPort_5_INTR| pantallaLCD_LCDPort_6_INTR))

#endif /* End Pins pantallaLCD_LCDPort_ALIASES_H */


/* [] END OF FILE */
