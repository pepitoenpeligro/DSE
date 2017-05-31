/*******************************************************************************
* File Name: ledSoftwareInterrupcionPWM.h  
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

#if !defined(CY_PINS_ledSoftwareInterrupcionPWM_H) /* Pins ledSoftwareInterrupcionPWM_H */
#define CY_PINS_ledSoftwareInterrupcionPWM_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ledSoftwareInterrupcionPWM_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ledSoftwareInterrupcionPWM_Write(uint8 value) ;
void    ledSoftwareInterrupcionPWM_SetDriveMode(uint8 mode) ;
uint8   ledSoftwareInterrupcionPWM_ReadDataReg(void) ;
uint8   ledSoftwareInterrupcionPWM_Read(void) ;
void    ledSoftwareInterrupcionPWM_SetInterruptMode(uint16 position, uint16 mode) ;
uint8   ledSoftwareInterrupcionPWM_ClearInterrupt(void) ;
/** @} general */

/***************************************
*           API Constants        
***************************************/

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ledSoftwareInterrupcionPWM_SetDriveMode() function.
     *  @{
     */
        /* Drive Modes */
        #define ledSoftwareInterrupcionPWM_DM_ALG_HIZ         PIN_DM_ALG_HIZ   /**< \brief High Impedance Analog   */
        #define ledSoftwareInterrupcionPWM_DM_DIG_HIZ         PIN_DM_DIG_HIZ   /**< \brief High Impedance Digital  */
        #define ledSoftwareInterrupcionPWM_DM_RES_UP          PIN_DM_RES_UP    /**< \brief Resistive Pull Up       */
        #define ledSoftwareInterrupcionPWM_DM_RES_DWN         PIN_DM_RES_DWN   /**< \brief Resistive Pull Down     */
        #define ledSoftwareInterrupcionPWM_DM_OD_LO           PIN_DM_OD_LO     /**< \brief Open Drain, Drives Low  */
        #define ledSoftwareInterrupcionPWM_DM_OD_HI           PIN_DM_OD_HI     /**< \brief Open Drain, Drives High */
        #define ledSoftwareInterrupcionPWM_DM_STRONG          PIN_DM_STRONG    /**< \brief Strong Drive            */
        #define ledSoftwareInterrupcionPWM_DM_RES_UPDWN       PIN_DM_RES_UPDWN /**< \brief Resistive Pull Up/Down  */
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ledSoftwareInterrupcionPWM_MASK               ledSoftwareInterrupcionPWM__MASK
#define ledSoftwareInterrupcionPWM_SHIFT              ledSoftwareInterrupcionPWM__SHIFT
#define ledSoftwareInterrupcionPWM_WIDTH              1u

/* Interrupt constants */
#if defined(ledSoftwareInterrupcionPWM__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ledSoftwareInterrupcionPWM_SetInterruptMode() function.
     *  @{
     */
        #define ledSoftwareInterrupcionPWM_INTR_NONE      (uint16)(0x0000u)   /**< \brief Disabled             */
        #define ledSoftwareInterrupcionPWM_INTR_RISING    (uint16)(0x0001u)   /**< \brief Rising edge trigger  */
        #define ledSoftwareInterrupcionPWM_INTR_FALLING   (uint16)(0x0002u)   /**< \brief Falling edge trigger */
        #define ledSoftwareInterrupcionPWM_INTR_BOTH      (uint16)(0x0003u)   /**< \brief Both edge trigger    */
        /** @} intrMode */
/** @} group_constants */

    #define ledSoftwareInterrupcionPWM_INTR_MASK      (0x01u)
#endif /* (ledSoftwareInterrupcionPWM__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ledSoftwareInterrupcionPWM_PS                     (* (reg8 *) ledSoftwareInterrupcionPWM__PS)
/* Data Register */
#define ledSoftwareInterrupcionPWM_DR                     (* (reg8 *) ledSoftwareInterrupcionPWM__DR)
/* Port Number */
#define ledSoftwareInterrupcionPWM_PRT_NUM                (* (reg8 *) ledSoftwareInterrupcionPWM__PRT) 
/* Connect to Analog Globals */                                                  
#define ledSoftwareInterrupcionPWM_AG                     (* (reg8 *) ledSoftwareInterrupcionPWM__AG)                       
/* Analog MUX bux enable */
#define ledSoftwareInterrupcionPWM_AMUX                   (* (reg8 *) ledSoftwareInterrupcionPWM__AMUX) 
/* Bidirectional Enable */                                                        
#define ledSoftwareInterrupcionPWM_BIE                    (* (reg8 *) ledSoftwareInterrupcionPWM__BIE)
/* Bit-mask for Aliased Register Access */
#define ledSoftwareInterrupcionPWM_BIT_MASK               (* (reg8 *) ledSoftwareInterrupcionPWM__BIT_MASK)
/* Bypass Enable */
#define ledSoftwareInterrupcionPWM_BYP                    (* (reg8 *) ledSoftwareInterrupcionPWM__BYP)
/* Port wide control signals */                                                   
#define ledSoftwareInterrupcionPWM_CTL                    (* (reg8 *) ledSoftwareInterrupcionPWM__CTL)
/* Drive Modes */
#define ledSoftwareInterrupcionPWM_DM0                    (* (reg8 *) ledSoftwareInterrupcionPWM__DM0) 
#define ledSoftwareInterrupcionPWM_DM1                    (* (reg8 *) ledSoftwareInterrupcionPWM__DM1)
#define ledSoftwareInterrupcionPWM_DM2                    (* (reg8 *) ledSoftwareInterrupcionPWM__DM2) 
/* Input Buffer Disable Override */
#define ledSoftwareInterrupcionPWM_INP_DIS                (* (reg8 *) ledSoftwareInterrupcionPWM__INP_DIS)
/* LCD Common or Segment Drive */
#define ledSoftwareInterrupcionPWM_LCD_COM_SEG            (* (reg8 *) ledSoftwareInterrupcionPWM__LCD_COM_SEG)
/* Enable Segment LCD */
#define ledSoftwareInterrupcionPWM_LCD_EN                 (* (reg8 *) ledSoftwareInterrupcionPWM__LCD_EN)
/* Slew Rate Control */
#define ledSoftwareInterrupcionPWM_SLW                    (* (reg8 *) ledSoftwareInterrupcionPWM__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ledSoftwareInterrupcionPWM_PRTDSI__CAPS_SEL       (* (reg8 *) ledSoftwareInterrupcionPWM__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ledSoftwareInterrupcionPWM_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ledSoftwareInterrupcionPWM__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ledSoftwareInterrupcionPWM_PRTDSI__OE_SEL0        (* (reg8 *) ledSoftwareInterrupcionPWM__PRTDSI__OE_SEL0) 
#define ledSoftwareInterrupcionPWM_PRTDSI__OE_SEL1        (* (reg8 *) ledSoftwareInterrupcionPWM__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ledSoftwareInterrupcionPWM_PRTDSI__OUT_SEL0       (* (reg8 *) ledSoftwareInterrupcionPWM__PRTDSI__OUT_SEL0) 
#define ledSoftwareInterrupcionPWM_PRTDSI__OUT_SEL1       (* (reg8 *) ledSoftwareInterrupcionPWM__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ledSoftwareInterrupcionPWM_PRTDSI__SYNC_OUT       (* (reg8 *) ledSoftwareInterrupcionPWM__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ledSoftwareInterrupcionPWM__SIO_CFG)
    #define ledSoftwareInterrupcionPWM_SIO_HYST_EN        (* (reg8 *) ledSoftwareInterrupcionPWM__SIO_HYST_EN)
    #define ledSoftwareInterrupcionPWM_SIO_REG_HIFREQ     (* (reg8 *) ledSoftwareInterrupcionPWM__SIO_REG_HIFREQ)
    #define ledSoftwareInterrupcionPWM_SIO_CFG            (* (reg8 *) ledSoftwareInterrupcionPWM__SIO_CFG)
    #define ledSoftwareInterrupcionPWM_SIO_DIFF           (* (reg8 *) ledSoftwareInterrupcionPWM__SIO_DIFF)
#endif /* (ledSoftwareInterrupcionPWM__SIO_CFG) */

/* Interrupt Registers */
#if defined(ledSoftwareInterrupcionPWM__INTSTAT)
    #define ledSoftwareInterrupcionPWM_INTSTAT             (* (reg8 *) ledSoftwareInterrupcionPWM__INTSTAT)
    #define ledSoftwareInterrupcionPWM_SNAP                (* (reg8 *) ledSoftwareInterrupcionPWM__SNAP)
    
	#define ledSoftwareInterrupcionPWM_0_INTTYPE_REG 		(* (reg8 *) ledSoftwareInterrupcionPWM__0__INTTYPE)
#endif /* (ledSoftwareInterrupcionPWM__INTSTAT) */

#endif /* End Pins ledSoftwareInterrupcionPWM_H */


/* [] END OF FILE */
