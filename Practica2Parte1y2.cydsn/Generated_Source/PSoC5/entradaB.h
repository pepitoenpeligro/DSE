/*******************************************************************************
* File Name: entradaB.h  
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

#if !defined(CY_PINS_entradaB_H) /* Pins entradaB_H */
#define CY_PINS_entradaB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "entradaB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 entradaB__PORT == 15 && ((entradaB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    entradaB_Write(uint8 value);
void    entradaB_SetDriveMode(uint8 mode);
uint8   entradaB_ReadDataReg(void);
uint8   entradaB_Read(void);
void    entradaB_SetInterruptMode(uint16 position, uint16 mode);
uint8   entradaB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the entradaB_SetDriveMode() function.
     *  @{
     */
        #define entradaB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define entradaB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define entradaB_DM_RES_UP          PIN_DM_RES_UP
        #define entradaB_DM_RES_DWN         PIN_DM_RES_DWN
        #define entradaB_DM_OD_LO           PIN_DM_OD_LO
        #define entradaB_DM_OD_HI           PIN_DM_OD_HI
        #define entradaB_DM_STRONG          PIN_DM_STRONG
        #define entradaB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define entradaB_MASK               entradaB__MASK
#define entradaB_SHIFT              entradaB__SHIFT
#define entradaB_WIDTH              1u

/* Interrupt constants */
#if defined(entradaB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in entradaB_SetInterruptMode() function.
     *  @{
     */
        #define entradaB_INTR_NONE      (uint16)(0x0000u)
        #define entradaB_INTR_RISING    (uint16)(0x0001u)
        #define entradaB_INTR_FALLING   (uint16)(0x0002u)
        #define entradaB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define entradaB_INTR_MASK      (0x01u) 
#endif /* (entradaB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define entradaB_PS                     (* (reg8 *) entradaB__PS)
/* Data Register */
#define entradaB_DR                     (* (reg8 *) entradaB__DR)
/* Port Number */
#define entradaB_PRT_NUM                (* (reg8 *) entradaB__PRT) 
/* Connect to Analog Globals */                                                  
#define entradaB_AG                     (* (reg8 *) entradaB__AG)                       
/* Analog MUX bux enable */
#define entradaB_AMUX                   (* (reg8 *) entradaB__AMUX) 
/* Bidirectional Enable */                                                        
#define entradaB_BIE                    (* (reg8 *) entradaB__BIE)
/* Bit-mask for Aliased Register Access */
#define entradaB_BIT_MASK               (* (reg8 *) entradaB__BIT_MASK)
/* Bypass Enable */
#define entradaB_BYP                    (* (reg8 *) entradaB__BYP)
/* Port wide control signals */                                                   
#define entradaB_CTL                    (* (reg8 *) entradaB__CTL)
/* Drive Modes */
#define entradaB_DM0                    (* (reg8 *) entradaB__DM0) 
#define entradaB_DM1                    (* (reg8 *) entradaB__DM1)
#define entradaB_DM2                    (* (reg8 *) entradaB__DM2) 
/* Input Buffer Disable Override */
#define entradaB_INP_DIS                (* (reg8 *) entradaB__INP_DIS)
/* LCD Common or Segment Drive */
#define entradaB_LCD_COM_SEG            (* (reg8 *) entradaB__LCD_COM_SEG)
/* Enable Segment LCD */
#define entradaB_LCD_EN                 (* (reg8 *) entradaB__LCD_EN)
/* Slew Rate Control */
#define entradaB_SLW                    (* (reg8 *) entradaB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define entradaB_PRTDSI__CAPS_SEL       (* (reg8 *) entradaB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define entradaB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) entradaB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define entradaB_PRTDSI__OE_SEL0        (* (reg8 *) entradaB__PRTDSI__OE_SEL0) 
#define entradaB_PRTDSI__OE_SEL1        (* (reg8 *) entradaB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define entradaB_PRTDSI__OUT_SEL0       (* (reg8 *) entradaB__PRTDSI__OUT_SEL0) 
#define entradaB_PRTDSI__OUT_SEL1       (* (reg8 *) entradaB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define entradaB_PRTDSI__SYNC_OUT       (* (reg8 *) entradaB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(entradaB__SIO_CFG)
    #define entradaB_SIO_HYST_EN        (* (reg8 *) entradaB__SIO_HYST_EN)
    #define entradaB_SIO_REG_HIFREQ     (* (reg8 *) entradaB__SIO_REG_HIFREQ)
    #define entradaB_SIO_CFG            (* (reg8 *) entradaB__SIO_CFG)
    #define entradaB_SIO_DIFF           (* (reg8 *) entradaB__SIO_DIFF)
#endif /* (entradaB__SIO_CFG) */

/* Interrupt Registers */
#if defined(entradaB__INTSTAT)
    #define entradaB_INTSTAT            (* (reg8 *) entradaB__INTSTAT)
    #define entradaB_SNAP               (* (reg8 *) entradaB__SNAP)
    
	#define entradaB_0_INTTYPE_REG 		(* (reg8 *) entradaB__0__INTTYPE)
#endif /* (entradaB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_entradaB_H */


/* [] END OF FILE */
