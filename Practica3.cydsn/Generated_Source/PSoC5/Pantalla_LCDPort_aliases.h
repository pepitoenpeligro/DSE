/*******************************************************************************
* File Name: Pantalla_LCDPort.h  
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

#if !defined(CY_PINS_Pantalla_LCDPort_ALIASES_H) /* Pins Pantalla_LCDPort_ALIASES_H */
#define CY_PINS_Pantalla_LCDPort_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Pantalla_LCDPort_0			(Pantalla_LCDPort__0__PC)
#define Pantalla_LCDPort_0_INTR	((uint16)((uint16)0x0001u << Pantalla_LCDPort__0__SHIFT))

#define Pantalla_LCDPort_1			(Pantalla_LCDPort__1__PC)
#define Pantalla_LCDPort_1_INTR	((uint16)((uint16)0x0001u << Pantalla_LCDPort__1__SHIFT))

#define Pantalla_LCDPort_2			(Pantalla_LCDPort__2__PC)
#define Pantalla_LCDPort_2_INTR	((uint16)((uint16)0x0001u << Pantalla_LCDPort__2__SHIFT))

#define Pantalla_LCDPort_3			(Pantalla_LCDPort__3__PC)
#define Pantalla_LCDPort_3_INTR	((uint16)((uint16)0x0001u << Pantalla_LCDPort__3__SHIFT))

#define Pantalla_LCDPort_4			(Pantalla_LCDPort__4__PC)
#define Pantalla_LCDPort_4_INTR	((uint16)((uint16)0x0001u << Pantalla_LCDPort__4__SHIFT))

#define Pantalla_LCDPort_5			(Pantalla_LCDPort__5__PC)
#define Pantalla_LCDPort_5_INTR	((uint16)((uint16)0x0001u << Pantalla_LCDPort__5__SHIFT))

#define Pantalla_LCDPort_6			(Pantalla_LCDPort__6__PC)
#define Pantalla_LCDPort_6_INTR	((uint16)((uint16)0x0001u << Pantalla_LCDPort__6__SHIFT))

#define Pantalla_LCDPort_INTR_ALL	 ((uint16)(Pantalla_LCDPort_0_INTR| Pantalla_LCDPort_1_INTR| Pantalla_LCDPort_2_INTR| Pantalla_LCDPort_3_INTR| Pantalla_LCDPort_4_INTR| Pantalla_LCDPort_5_INTR| Pantalla_LCDPort_6_INTR))

#endif /* End Pins Pantalla_LCDPort_ALIASES_H */


/* [] END OF FILE */
