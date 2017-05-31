/*******************************************************************************
* File Name: ledHardwarePWM.h  
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

#if !defined(CY_PINS_ledHardwarePWM_H) /* Pins ledHardwarePWM_H */
#define CY_PINS_ledHardwarePWM_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ledHardwarePWM_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ledHardwarePWM__PORT == 15 && ((ledHardwarePWM__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ledHardwarePWM_Write(uint8 value);
void    ledHardwarePWM_SetDriveMode(uint8 mode);
uint8   ledHardwarePWM_ReadDataReg(void);
uint8   ledHardwarePWM_Read(void);
void    ledHardwarePWM_SetInterruptMode(uint16 position, uint16 mode);
uint8   ledHardwarePWM_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ledHardwarePWM_SetDriveMode() function.
     *  @{
     */
        #define ledHardwarePWM_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ledHardwarePWM_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ledHardwarePWM_DM_RES_UP          PIN_DM_RES_UP
        #define ledHardwarePWM_DM_RES_DWN         PIN_DM_RES_DWN
        #define ledHardwarePWM_DM_OD_LO           PIN_DM_OD_LO
        #define ledHardwarePWM_DM_OD_HI           PIN_DM_OD_HI
        #define ledHardwarePWM_DM_STRONG          PIN_DM_STRONG
        #define ledHardwarePWM_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ledHardwarePWM_MASK               ledHardwarePWM__MASK
#define ledHardwarePWM_SHIFT              ledHardwarePWM__SHIFT
#define ledHardwarePWM_WIDTH              1u

/* Interrupt constants */
#if defined(ledHardwarePWM__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ledHardwarePWM_SetInterruptMode() function.
     *  @{
     */
        #define ledHardwarePWM_INTR_NONE      (uint16)(0x0000u)
        #define ledHardwarePWM_INTR_RISING    (uint16)(0x0001u)
        #define ledHardwarePWM_INTR_FALLING   (uint16)(0x0002u)
        #define ledHardwarePWM_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ledHardwarePWM_INTR_MASK      (0x01u) 
#endif /* (ledHardwarePWM__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ledHardwarePWM_PS                     (* (reg8 *) ledHardwarePWM__PS)
/* Data Register */
#define ledHardwarePWM_DR                     (* (reg8 *) ledHardwarePWM__DR)
/* Port Number */
#define ledHardwarePWM_PRT_NUM                (* (reg8 *) ledHardwarePWM__PRT) 
/* Connect to Analog Globals */                                                  
#define ledHardwarePWM_AG                     (* (reg8 *) ledHardwarePWM__AG)                       
/* Analog MUX bux enable */
#define ledHardwarePWM_AMUX                   (* (reg8 *) ledHardwarePWM__AMUX) 
/* Bidirectional Enable */                                                        
#define ledHardwarePWM_BIE                    (* (reg8 *) ledHardwarePWM__BIE)
/* Bit-mask for Aliased Register Access */
#define ledHardwarePWM_BIT_MASK               (* (reg8 *) ledHardwarePWM__BIT_MASK)
/* Bypass Enable */
#define ledHardwarePWM_BYP                    (* (reg8 *) ledHardwarePWM__BYP)
/* Port wide control signals */                                                   
#define ledHardwarePWM_CTL                    (* (reg8 *) ledHardwarePWM__CTL)
/* Drive Modes */
#define ledHardwarePWM_DM0                    (* (reg8 *) ledHardwarePWM__DM0) 
#define ledHardwarePWM_DM1                    (* (reg8 *) ledHardwarePWM__DM1)
#define ledHardwarePWM_DM2                    (* (reg8 *) ledHardwarePWM__DM2) 
/* Input Buffer Disable Override */
#define ledHardwarePWM_INP_DIS                (* (reg8 *) ledHardwarePWM__INP_DIS)
/* LCD Common or Segment Drive */
#define ledHardwarePWM_LCD_COM_SEG            (* (reg8 *) ledHardwarePWM__LCD_COM_SEG)
/* Enable Segment LCD */
#define ledHardwarePWM_LCD_EN                 (* (reg8 *) ledHardwarePWM__LCD_EN)
/* Slew Rate Control */
#define ledHardwarePWM_SLW                    (* (reg8 *) ledHardwarePWM__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ledHardwarePWM_PRTDSI__CAPS_SEL       (* (reg8 *) ledHardwarePWM__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ledHardwarePWM_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ledHardwarePWM__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ledHardwarePWM_PRTDSI__OE_SEL0        (* (reg8 *) ledHardwarePWM__PRTDSI__OE_SEL0) 
#define ledHardwarePWM_PRTDSI__OE_SEL1        (* (reg8 *) ledHardwarePWM__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ledHardwarePWM_PRTDSI__OUT_SEL0       (* (reg8 *) ledHardwarePWM__PRTDSI__OUT_SEL0) 
#define ledHardwarePWM_PRTDSI__OUT_SEL1       (* (reg8 *) ledHardwarePWM__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ledHardwarePWM_PRTDSI__SYNC_OUT       (* (reg8 *) ledHardwarePWM__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ledHardwarePWM__SIO_CFG)
    #define ledHardwarePWM_SIO_HYST_EN        (* (reg8 *) ledHardwarePWM__SIO_HYST_EN)
    #define ledHardwarePWM_SIO_REG_HIFREQ     (* (reg8 *) ledHardwarePWM__SIO_REG_HIFREQ)
    #define ledHardwarePWM_SIO_CFG            (* (reg8 *) ledHardwarePWM__SIO_CFG)
    #define ledHardwarePWM_SIO_DIFF           (* (reg8 *) ledHardwarePWM__SIO_DIFF)
#endif /* (ledHardwarePWM__SIO_CFG) */

/* Interrupt Registers */
#if defined(ledHardwarePWM__INTSTAT)
    #define ledHardwarePWM_INTSTAT            (* (reg8 *) ledHardwarePWM__INTSTAT)
    #define ledHardwarePWM_SNAP               (* (reg8 *) ledHardwarePWM__SNAP)
    
	#define ledHardwarePWM_0_INTTYPE_REG 		(* (reg8 *) ledHardwarePWM__0__INTTYPE)
#endif /* (ledHardwarePWM__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ledHardwarePWM_H */


/* [] END OF FILE */
