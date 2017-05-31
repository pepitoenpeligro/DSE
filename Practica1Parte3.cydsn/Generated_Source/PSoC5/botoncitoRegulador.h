/*******************************************************************************
* File Name: botoncitoRegulador.h  
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

#if !defined(CY_PINS_botoncitoRegulador_H) /* Pins botoncitoRegulador_H */
#define CY_PINS_botoncitoRegulador_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "botoncitoRegulador_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 botoncitoRegulador__PORT == 15 && ((botoncitoRegulador__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    botoncitoRegulador_Write(uint8 value);
void    botoncitoRegulador_SetDriveMode(uint8 mode);
uint8   botoncitoRegulador_ReadDataReg(void);
uint8   botoncitoRegulador_Read(void);
void    botoncitoRegulador_SetInterruptMode(uint16 position, uint16 mode);
uint8   botoncitoRegulador_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the botoncitoRegulador_SetDriveMode() function.
     *  @{
     */
        #define botoncitoRegulador_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define botoncitoRegulador_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define botoncitoRegulador_DM_RES_UP          PIN_DM_RES_UP
        #define botoncitoRegulador_DM_RES_DWN         PIN_DM_RES_DWN
        #define botoncitoRegulador_DM_OD_LO           PIN_DM_OD_LO
        #define botoncitoRegulador_DM_OD_HI           PIN_DM_OD_HI
        #define botoncitoRegulador_DM_STRONG          PIN_DM_STRONG
        #define botoncitoRegulador_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define botoncitoRegulador_MASK               botoncitoRegulador__MASK
#define botoncitoRegulador_SHIFT              botoncitoRegulador__SHIFT
#define botoncitoRegulador_WIDTH              1u

/* Interrupt constants */
#if defined(botoncitoRegulador__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in botoncitoRegulador_SetInterruptMode() function.
     *  @{
     */
        #define botoncitoRegulador_INTR_NONE      (uint16)(0x0000u)
        #define botoncitoRegulador_INTR_RISING    (uint16)(0x0001u)
        #define botoncitoRegulador_INTR_FALLING   (uint16)(0x0002u)
        #define botoncitoRegulador_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define botoncitoRegulador_INTR_MASK      (0x01u) 
#endif /* (botoncitoRegulador__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define botoncitoRegulador_PS                     (* (reg8 *) botoncitoRegulador__PS)
/* Data Register */
#define botoncitoRegulador_DR                     (* (reg8 *) botoncitoRegulador__DR)
/* Port Number */
#define botoncitoRegulador_PRT_NUM                (* (reg8 *) botoncitoRegulador__PRT) 
/* Connect to Analog Globals */                                                  
#define botoncitoRegulador_AG                     (* (reg8 *) botoncitoRegulador__AG)                       
/* Analog MUX bux enable */
#define botoncitoRegulador_AMUX                   (* (reg8 *) botoncitoRegulador__AMUX) 
/* Bidirectional Enable */                                                        
#define botoncitoRegulador_BIE                    (* (reg8 *) botoncitoRegulador__BIE)
/* Bit-mask for Aliased Register Access */
#define botoncitoRegulador_BIT_MASK               (* (reg8 *) botoncitoRegulador__BIT_MASK)
/* Bypass Enable */
#define botoncitoRegulador_BYP                    (* (reg8 *) botoncitoRegulador__BYP)
/* Port wide control signals */                                                   
#define botoncitoRegulador_CTL                    (* (reg8 *) botoncitoRegulador__CTL)
/* Drive Modes */
#define botoncitoRegulador_DM0                    (* (reg8 *) botoncitoRegulador__DM0) 
#define botoncitoRegulador_DM1                    (* (reg8 *) botoncitoRegulador__DM1)
#define botoncitoRegulador_DM2                    (* (reg8 *) botoncitoRegulador__DM2) 
/* Input Buffer Disable Override */
#define botoncitoRegulador_INP_DIS                (* (reg8 *) botoncitoRegulador__INP_DIS)
/* LCD Common or Segment Drive */
#define botoncitoRegulador_LCD_COM_SEG            (* (reg8 *) botoncitoRegulador__LCD_COM_SEG)
/* Enable Segment LCD */
#define botoncitoRegulador_LCD_EN                 (* (reg8 *) botoncitoRegulador__LCD_EN)
/* Slew Rate Control */
#define botoncitoRegulador_SLW                    (* (reg8 *) botoncitoRegulador__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define botoncitoRegulador_PRTDSI__CAPS_SEL       (* (reg8 *) botoncitoRegulador__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define botoncitoRegulador_PRTDSI__DBL_SYNC_IN    (* (reg8 *) botoncitoRegulador__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define botoncitoRegulador_PRTDSI__OE_SEL0        (* (reg8 *) botoncitoRegulador__PRTDSI__OE_SEL0) 
#define botoncitoRegulador_PRTDSI__OE_SEL1        (* (reg8 *) botoncitoRegulador__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define botoncitoRegulador_PRTDSI__OUT_SEL0       (* (reg8 *) botoncitoRegulador__PRTDSI__OUT_SEL0) 
#define botoncitoRegulador_PRTDSI__OUT_SEL1       (* (reg8 *) botoncitoRegulador__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define botoncitoRegulador_PRTDSI__SYNC_OUT       (* (reg8 *) botoncitoRegulador__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(botoncitoRegulador__SIO_CFG)
    #define botoncitoRegulador_SIO_HYST_EN        (* (reg8 *) botoncitoRegulador__SIO_HYST_EN)
    #define botoncitoRegulador_SIO_REG_HIFREQ     (* (reg8 *) botoncitoRegulador__SIO_REG_HIFREQ)
    #define botoncitoRegulador_SIO_CFG            (* (reg8 *) botoncitoRegulador__SIO_CFG)
    #define botoncitoRegulador_SIO_DIFF           (* (reg8 *) botoncitoRegulador__SIO_DIFF)
#endif /* (botoncitoRegulador__SIO_CFG) */

/* Interrupt Registers */
#if defined(botoncitoRegulador__INTSTAT)
    #define botoncitoRegulador_INTSTAT            (* (reg8 *) botoncitoRegulador__INTSTAT)
    #define botoncitoRegulador_SNAP               (* (reg8 *) botoncitoRegulador__SNAP)
    
	#define botoncitoRegulador_0_INTTYPE_REG 		(* (reg8 *) botoncitoRegulador__0__INTTYPE)
#endif /* (botoncitoRegulador__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_botoncitoRegulador_H */


/* [] END OF FILE */
