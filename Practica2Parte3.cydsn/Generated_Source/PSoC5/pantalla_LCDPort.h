/*******************************************************************************
* File Name: pantalla_LCDPort.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_pantalla_LCDPort_H) /* Pins pantalla_LCDPort_H */
#define CY_PINS_pantalla_LCDPort_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pantalla_LCDPort_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pantalla_LCDPort__PORT == 15 && ((pantalla_LCDPort__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pantalla_LCDPort_Write(uint8 value);
void    pantalla_LCDPort_SetDriveMode(uint8 mode);
uint8   pantalla_LCDPort_ReadDataReg(void);
uint8   pantalla_LCDPort_Read(void);
void    pantalla_LCDPort_SetInterruptMode(uint16 position, uint16 mode);
uint8   pantalla_LCDPort_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pantalla_LCDPort_SetDriveMode() function.
     *  @{
     */
        #define pantalla_LCDPort_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pantalla_LCDPort_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pantalla_LCDPort_DM_RES_UP          PIN_DM_RES_UP
        #define pantalla_LCDPort_DM_RES_DWN         PIN_DM_RES_DWN
        #define pantalla_LCDPort_DM_OD_LO           PIN_DM_OD_LO
        #define pantalla_LCDPort_DM_OD_HI           PIN_DM_OD_HI
        #define pantalla_LCDPort_DM_STRONG          PIN_DM_STRONG
        #define pantalla_LCDPort_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pantalla_LCDPort_MASK               pantalla_LCDPort__MASK
#define pantalla_LCDPort_SHIFT              pantalla_LCDPort__SHIFT
#define pantalla_LCDPort_WIDTH              7u

/* Interrupt constants */
#if defined(pantalla_LCDPort__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pantalla_LCDPort_SetInterruptMode() function.
     *  @{
     */
        #define pantalla_LCDPort_INTR_NONE      (uint16)(0x0000u)
        #define pantalla_LCDPort_INTR_RISING    (uint16)(0x0001u)
        #define pantalla_LCDPort_INTR_FALLING   (uint16)(0x0002u)
        #define pantalla_LCDPort_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pantalla_LCDPort_INTR_MASK      (0x01u) 
#endif /* (pantalla_LCDPort__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pantalla_LCDPort_PS                     (* (reg8 *) pantalla_LCDPort__PS)
/* Data Register */
#define pantalla_LCDPort_DR                     (* (reg8 *) pantalla_LCDPort__DR)
/* Port Number */
#define pantalla_LCDPort_PRT_NUM                (* (reg8 *) pantalla_LCDPort__PRT) 
/* Connect to Analog Globals */                                                  
#define pantalla_LCDPort_AG                     (* (reg8 *) pantalla_LCDPort__AG)                       
/* Analog MUX bux enable */
#define pantalla_LCDPort_AMUX                   (* (reg8 *) pantalla_LCDPort__AMUX) 
/* Bidirectional Enable */                                                        
#define pantalla_LCDPort_BIE                    (* (reg8 *) pantalla_LCDPort__BIE)
/* Bit-mask for Aliased Register Access */
#define pantalla_LCDPort_BIT_MASK               (* (reg8 *) pantalla_LCDPort__BIT_MASK)
/* Bypass Enable */
#define pantalla_LCDPort_BYP                    (* (reg8 *) pantalla_LCDPort__BYP)
/* Port wide control signals */                                                   
#define pantalla_LCDPort_CTL                    (* (reg8 *) pantalla_LCDPort__CTL)
/* Drive Modes */
#define pantalla_LCDPort_DM0                    (* (reg8 *) pantalla_LCDPort__DM0) 
#define pantalla_LCDPort_DM1                    (* (reg8 *) pantalla_LCDPort__DM1)
#define pantalla_LCDPort_DM2                    (* (reg8 *) pantalla_LCDPort__DM2) 
/* Input Buffer Disable Override */
#define pantalla_LCDPort_INP_DIS                (* (reg8 *) pantalla_LCDPort__INP_DIS)
/* LCD Common or Segment Drive */
#define pantalla_LCDPort_LCD_COM_SEG            (* (reg8 *) pantalla_LCDPort__LCD_COM_SEG)
/* Enable Segment LCD */
#define pantalla_LCDPort_LCD_EN                 (* (reg8 *) pantalla_LCDPort__LCD_EN)
/* Slew Rate Control */
#define pantalla_LCDPort_SLW                    (* (reg8 *) pantalla_LCDPort__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pantalla_LCDPort_PRTDSI__CAPS_SEL       (* (reg8 *) pantalla_LCDPort__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pantalla_LCDPort_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pantalla_LCDPort__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pantalla_LCDPort_PRTDSI__OE_SEL0        (* (reg8 *) pantalla_LCDPort__PRTDSI__OE_SEL0) 
#define pantalla_LCDPort_PRTDSI__OE_SEL1        (* (reg8 *) pantalla_LCDPort__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pantalla_LCDPort_PRTDSI__OUT_SEL0       (* (reg8 *) pantalla_LCDPort__PRTDSI__OUT_SEL0) 
#define pantalla_LCDPort_PRTDSI__OUT_SEL1       (* (reg8 *) pantalla_LCDPort__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pantalla_LCDPort_PRTDSI__SYNC_OUT       (* (reg8 *) pantalla_LCDPort__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pantalla_LCDPort__SIO_CFG)
    #define pantalla_LCDPort_SIO_HYST_EN        (* (reg8 *) pantalla_LCDPort__SIO_HYST_EN)
    #define pantalla_LCDPort_SIO_REG_HIFREQ     (* (reg8 *) pantalla_LCDPort__SIO_REG_HIFREQ)
    #define pantalla_LCDPort_SIO_CFG            (* (reg8 *) pantalla_LCDPort__SIO_CFG)
    #define pantalla_LCDPort_SIO_DIFF           (* (reg8 *) pantalla_LCDPort__SIO_DIFF)
#endif /* (pantalla_LCDPort__SIO_CFG) */

/* Interrupt Registers */
#if defined(pantalla_LCDPort__INTSTAT)
    #define pantalla_LCDPort_INTSTAT            (* (reg8 *) pantalla_LCDPort__INTSTAT)
    #define pantalla_LCDPort_SNAP               (* (reg8 *) pantalla_LCDPort__SNAP)
    
	#define pantalla_LCDPort_0_INTTYPE_REG 		(* (reg8 *) pantalla_LCDPort__0__INTTYPE)
	#define pantalla_LCDPort_1_INTTYPE_REG 		(* (reg8 *) pantalla_LCDPort__1__INTTYPE)
	#define pantalla_LCDPort_2_INTTYPE_REG 		(* (reg8 *) pantalla_LCDPort__2__INTTYPE)
	#define pantalla_LCDPort_3_INTTYPE_REG 		(* (reg8 *) pantalla_LCDPort__3__INTTYPE)
	#define pantalla_LCDPort_4_INTTYPE_REG 		(* (reg8 *) pantalla_LCDPort__4__INTTYPE)
	#define pantalla_LCDPort_5_INTTYPE_REG 		(* (reg8 *) pantalla_LCDPort__5__INTTYPE)
	#define pantalla_LCDPort_6_INTTYPE_REG 		(* (reg8 *) pantalla_LCDPort__6__INTTYPE)
#endif /* (pantalla_LCDPort__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pantalla_LCDPort_H */


/* [] END OF FILE */
