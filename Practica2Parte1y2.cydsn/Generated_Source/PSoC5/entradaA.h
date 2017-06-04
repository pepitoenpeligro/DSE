/*******************************************************************************
* File Name: entradaA.h  
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

#if !defined(CY_PINS_entradaA_H) /* Pins entradaA_H */
#define CY_PINS_entradaA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "entradaA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 entradaA__PORT == 15 && ((entradaA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    entradaA_Write(uint8 value);
void    entradaA_SetDriveMode(uint8 mode);
uint8   entradaA_ReadDataReg(void);
uint8   entradaA_Read(void);
void    entradaA_SetInterruptMode(uint16 position, uint16 mode);
uint8   entradaA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the entradaA_SetDriveMode() function.
     *  @{
     */
        #define entradaA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define entradaA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define entradaA_DM_RES_UP          PIN_DM_RES_UP
        #define entradaA_DM_RES_DWN         PIN_DM_RES_DWN
        #define entradaA_DM_OD_LO           PIN_DM_OD_LO
        #define entradaA_DM_OD_HI           PIN_DM_OD_HI
        #define entradaA_DM_STRONG          PIN_DM_STRONG
        #define entradaA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define entradaA_MASK               entradaA__MASK
#define entradaA_SHIFT              entradaA__SHIFT
#define entradaA_WIDTH              1u

/* Interrupt constants */
#if defined(entradaA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in entradaA_SetInterruptMode() function.
     *  @{
     */
        #define entradaA_INTR_NONE      (uint16)(0x0000u)
        #define entradaA_INTR_RISING    (uint16)(0x0001u)
        #define entradaA_INTR_FALLING   (uint16)(0x0002u)
        #define entradaA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define entradaA_INTR_MASK      (0x01u) 
#endif /* (entradaA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define entradaA_PS                     (* (reg8 *) entradaA__PS)
/* Data Register */
#define entradaA_DR                     (* (reg8 *) entradaA__DR)
/* Port Number */
#define entradaA_PRT_NUM                (* (reg8 *) entradaA__PRT) 
/* Connect to Analog Globals */                                                  
#define entradaA_AG                     (* (reg8 *) entradaA__AG)                       
/* Analog MUX bux enable */
#define entradaA_AMUX                   (* (reg8 *) entradaA__AMUX) 
/* Bidirectional Enable */                                                        
#define entradaA_BIE                    (* (reg8 *) entradaA__BIE)
/* Bit-mask for Aliased Register Access */
#define entradaA_BIT_MASK               (* (reg8 *) entradaA__BIT_MASK)
/* Bypass Enable */
#define entradaA_BYP                    (* (reg8 *) entradaA__BYP)
/* Port wide control signals */                                                   
#define entradaA_CTL                    (* (reg8 *) entradaA__CTL)
/* Drive Modes */
#define entradaA_DM0                    (* (reg8 *) entradaA__DM0) 
#define entradaA_DM1                    (* (reg8 *) entradaA__DM1)
#define entradaA_DM2                    (* (reg8 *) entradaA__DM2) 
/* Input Buffer Disable Override */
#define entradaA_INP_DIS                (* (reg8 *) entradaA__INP_DIS)
/* LCD Common or Segment Drive */
#define entradaA_LCD_COM_SEG            (* (reg8 *) entradaA__LCD_COM_SEG)
/* Enable Segment LCD */
#define entradaA_LCD_EN                 (* (reg8 *) entradaA__LCD_EN)
/* Slew Rate Control */
#define entradaA_SLW                    (* (reg8 *) entradaA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define entradaA_PRTDSI__CAPS_SEL       (* (reg8 *) entradaA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define entradaA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) entradaA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define entradaA_PRTDSI__OE_SEL0        (* (reg8 *) entradaA__PRTDSI__OE_SEL0) 
#define entradaA_PRTDSI__OE_SEL1        (* (reg8 *) entradaA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define entradaA_PRTDSI__OUT_SEL0       (* (reg8 *) entradaA__PRTDSI__OUT_SEL0) 
#define entradaA_PRTDSI__OUT_SEL1       (* (reg8 *) entradaA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define entradaA_PRTDSI__SYNC_OUT       (* (reg8 *) entradaA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(entradaA__SIO_CFG)
    #define entradaA_SIO_HYST_EN        (* (reg8 *) entradaA__SIO_HYST_EN)
    #define entradaA_SIO_REG_HIFREQ     (* (reg8 *) entradaA__SIO_REG_HIFREQ)
    #define entradaA_SIO_CFG            (* (reg8 *) entradaA__SIO_CFG)
    #define entradaA_SIO_DIFF           (* (reg8 *) entradaA__SIO_DIFF)
#endif /* (entradaA__SIO_CFG) */

/* Interrupt Registers */
#if defined(entradaA__INTSTAT)
    #define entradaA_INTSTAT            (* (reg8 *) entradaA__INTSTAT)
    #define entradaA_SNAP               (* (reg8 *) entradaA__SNAP)
    
	#define entradaA_0_INTTYPE_REG 		(* (reg8 *) entradaA__0__INTTYPE)
#endif /* (entradaA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_entradaA_H */


/* [] END OF FILE */
