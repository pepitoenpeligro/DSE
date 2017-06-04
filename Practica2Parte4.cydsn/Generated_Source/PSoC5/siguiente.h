/*******************************************************************************
* File Name: siguiente.h  
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

#if !defined(CY_PINS_siguiente_H) /* Pins siguiente_H */
#define CY_PINS_siguiente_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "siguiente_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 siguiente__PORT == 15 && ((siguiente__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    siguiente_Write(uint8 value);
void    siguiente_SetDriveMode(uint8 mode);
uint8   siguiente_ReadDataReg(void);
uint8   siguiente_Read(void);
void    siguiente_SetInterruptMode(uint16 position, uint16 mode);
uint8   siguiente_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the siguiente_SetDriveMode() function.
     *  @{
     */
        #define siguiente_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define siguiente_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define siguiente_DM_RES_UP          PIN_DM_RES_UP
        #define siguiente_DM_RES_DWN         PIN_DM_RES_DWN
        #define siguiente_DM_OD_LO           PIN_DM_OD_LO
        #define siguiente_DM_OD_HI           PIN_DM_OD_HI
        #define siguiente_DM_STRONG          PIN_DM_STRONG
        #define siguiente_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define siguiente_MASK               siguiente__MASK
#define siguiente_SHIFT              siguiente__SHIFT
#define siguiente_WIDTH              1u

/* Interrupt constants */
#if defined(siguiente__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in siguiente_SetInterruptMode() function.
     *  @{
     */
        #define siguiente_INTR_NONE      (uint16)(0x0000u)
        #define siguiente_INTR_RISING    (uint16)(0x0001u)
        #define siguiente_INTR_FALLING   (uint16)(0x0002u)
        #define siguiente_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define siguiente_INTR_MASK      (0x01u) 
#endif /* (siguiente__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define siguiente_PS                     (* (reg8 *) siguiente__PS)
/* Data Register */
#define siguiente_DR                     (* (reg8 *) siguiente__DR)
/* Port Number */
#define siguiente_PRT_NUM                (* (reg8 *) siguiente__PRT) 
/* Connect to Analog Globals */                                                  
#define siguiente_AG                     (* (reg8 *) siguiente__AG)                       
/* Analog MUX bux enable */
#define siguiente_AMUX                   (* (reg8 *) siguiente__AMUX) 
/* Bidirectional Enable */                                                        
#define siguiente_BIE                    (* (reg8 *) siguiente__BIE)
/* Bit-mask for Aliased Register Access */
#define siguiente_BIT_MASK               (* (reg8 *) siguiente__BIT_MASK)
/* Bypass Enable */
#define siguiente_BYP                    (* (reg8 *) siguiente__BYP)
/* Port wide control signals */                                                   
#define siguiente_CTL                    (* (reg8 *) siguiente__CTL)
/* Drive Modes */
#define siguiente_DM0                    (* (reg8 *) siguiente__DM0) 
#define siguiente_DM1                    (* (reg8 *) siguiente__DM1)
#define siguiente_DM2                    (* (reg8 *) siguiente__DM2) 
/* Input Buffer Disable Override */
#define siguiente_INP_DIS                (* (reg8 *) siguiente__INP_DIS)
/* LCD Common or Segment Drive */
#define siguiente_LCD_COM_SEG            (* (reg8 *) siguiente__LCD_COM_SEG)
/* Enable Segment LCD */
#define siguiente_LCD_EN                 (* (reg8 *) siguiente__LCD_EN)
/* Slew Rate Control */
#define siguiente_SLW                    (* (reg8 *) siguiente__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define siguiente_PRTDSI__CAPS_SEL       (* (reg8 *) siguiente__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define siguiente_PRTDSI__DBL_SYNC_IN    (* (reg8 *) siguiente__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define siguiente_PRTDSI__OE_SEL0        (* (reg8 *) siguiente__PRTDSI__OE_SEL0) 
#define siguiente_PRTDSI__OE_SEL1        (* (reg8 *) siguiente__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define siguiente_PRTDSI__OUT_SEL0       (* (reg8 *) siguiente__PRTDSI__OUT_SEL0) 
#define siguiente_PRTDSI__OUT_SEL1       (* (reg8 *) siguiente__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define siguiente_PRTDSI__SYNC_OUT       (* (reg8 *) siguiente__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(siguiente__SIO_CFG)
    #define siguiente_SIO_HYST_EN        (* (reg8 *) siguiente__SIO_HYST_EN)
    #define siguiente_SIO_REG_HIFREQ     (* (reg8 *) siguiente__SIO_REG_HIFREQ)
    #define siguiente_SIO_CFG            (* (reg8 *) siguiente__SIO_CFG)
    #define siguiente_SIO_DIFF           (* (reg8 *) siguiente__SIO_DIFF)
#endif /* (siguiente__SIO_CFG) */

/* Interrupt Registers */
#if defined(siguiente__INTSTAT)
    #define siguiente_INTSTAT            (* (reg8 *) siguiente__INTSTAT)
    #define siguiente_SNAP               (* (reg8 *) siguiente__SNAP)
    
	#define siguiente_0_INTTYPE_REG 		(* (reg8 *) siguiente__0__INTTYPE)
#endif /* (siguiente__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_siguiente_H */


/* [] END OF FILE */
