/*******************************************************************************
* File Name: pantalla_LCDPort.h  
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

#if !defined(CY_PINS_pantalla_LCDPort_ALIASES_H) /* Pins pantalla_LCDPort_ALIASES_H */
#define CY_PINS_pantalla_LCDPort_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define pantalla_LCDPort_0			(pantalla_LCDPort__0__PC)
#define pantalla_LCDPort_0_INTR	((uint16)((uint16)0x0001u << pantalla_LCDPort__0__SHIFT))

#define pantalla_LCDPort_1			(pantalla_LCDPort__1__PC)
#define pantalla_LCDPort_1_INTR	((uint16)((uint16)0x0001u << pantalla_LCDPort__1__SHIFT))

#define pantalla_LCDPort_2			(pantalla_LCDPort__2__PC)
#define pantalla_LCDPort_2_INTR	((uint16)((uint16)0x0001u << pantalla_LCDPort__2__SHIFT))

#define pantalla_LCDPort_3			(pantalla_LCDPort__3__PC)
#define pantalla_LCDPort_3_INTR	((uint16)((uint16)0x0001u << pantalla_LCDPort__3__SHIFT))

#define pantalla_LCDPort_4			(pantalla_LCDPort__4__PC)
#define pantalla_LCDPort_4_INTR	((uint16)((uint16)0x0001u << pantalla_LCDPort__4__SHIFT))

#define pantalla_LCDPort_5			(pantalla_LCDPort__5__PC)
#define pantalla_LCDPort_5_INTR	((uint16)((uint16)0x0001u << pantalla_LCDPort__5__SHIFT))

#define pantalla_LCDPort_6			(pantalla_LCDPort__6__PC)
#define pantalla_LCDPort_6_INTR	((uint16)((uint16)0x0001u << pantalla_LCDPort__6__SHIFT))

#define pantalla_LCDPort_INTR_ALL	 ((uint16)(pantalla_LCDPort_0_INTR| pantalla_LCDPort_1_INTR| pantalla_LCDPort_2_INTR| pantalla_LCDPort_3_INTR| pantalla_LCDPort_4_INTR| pantalla_LCDPort_5_INTR| pantalla_LCDPort_6_INTR))

#endif /* End Pins pantalla_LCDPort_ALIASES_H */


/* [] END OF FILE */
