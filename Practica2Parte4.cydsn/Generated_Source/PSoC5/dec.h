/*******************************************************************************
* File Name: dec.h  
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

#if !defined(CY_PINS_dec_H) /* Pins dec_H */
#define CY_PINS_dec_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "dec_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 dec__PORT == 15 && ((dec__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    dec_Write(uint8 value);
void    dec_SetDriveMode(uint8 mode);
uint8   dec_ReadDataReg(void);
uint8   dec_Read(void);
void    dec_SetInterruptMode(uint16 position, uint16 mode);
uint8   dec_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the dec_SetDriveMode() function.
     *  @{
     */
        #define dec_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define dec_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define dec_DM_RES_UP          PIN_DM_RES_UP
        #define dec_DM_RES_DWN         PIN_DM_RES_DWN
        #define dec_DM_OD_LO           PIN_DM_OD_LO
        #define dec_DM_OD_HI           PIN_DM_OD_HI
        #define dec_DM_STRONG          PIN_DM_STRONG
        #define dec_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define dec_MASK               dec__MASK
#define dec_SHIFT              dec__SHIFT
#define dec_WIDTH              1u

/* Interrupt constants */
#if defined(dec__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in dec_SetInterruptMode() function.
     *  @{
     */
        #define dec_INTR_NONE      (uint16)(0x0000u)
        #define dec_INTR_RISING    (uint16)(0x0001u)
        #define dec_INTR_FALLING   (uint16)(0x0002u)
        #define dec_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define dec_INTR_MASK      (0x01u) 
#endif /* (dec__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define dec_PS                     (* (reg8 *) dec__PS)
/* Data Register */
#define dec_DR                     (* (reg8 *) dec__DR)
/* Port Number */
#define dec_PRT_NUM                (* (reg8 *) dec__PRT) 
/* Connect to Analog Globals */                                                  
#define dec_AG                     (* (reg8 *) dec__AG)                       
/* Analog MUX bux enable */
#define dec_AMUX                   (* (reg8 *) dec__AMUX) 
/* Bidirectional Enable */                                                        
#define dec_BIE                    (* (reg8 *) dec__BIE)
/* Bit-mask for Aliased Register Access */
#define dec_BIT_MASK               (* (reg8 *) dec__BIT_MASK)
/* Bypass Enable */
#define dec_BYP                    (* (reg8 *) dec__BYP)
/* Port wide control signals */                                                   
#define dec_CTL                    (* (reg8 *) dec__CTL)
/* Drive Modes */
#define dec_DM0                    (* (reg8 *) dec__DM0) 
#define dec_DM1                    (* (reg8 *) dec__DM1)
#define dec_DM2                    (* (reg8 *) dec__DM2) 
/* Input Buffer Disable Override */
#define dec_INP_DIS                (* (reg8 *) dec__INP_DIS)
/* LCD Common or Segment Drive */
#define dec_LCD_COM_SEG            (* (reg8 *) dec__LCD_COM_SEG)
/* Enable Segment LCD */
#define dec_LCD_EN                 (* (reg8 *) dec__LCD_EN)
/* Slew Rate Control */
#define dec_SLW                    (* (reg8 *) dec__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define dec_PRTDSI__CAPS_SEL       (* (reg8 *) dec__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define dec_PRTDSI__DBL_SYNC_IN    (* (reg8 *) dec__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define dec_PRTDSI__OE_SEL0        (* (reg8 *) dec__PRTDSI__OE_SEL0) 
#define dec_PRTDSI__OE_SEL1        (* (reg8 *) dec__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define dec_PRTDSI__OUT_SEL0       (* (reg8 *) dec__PRTDSI__OUT_SEL0) 
#define dec_PRTDSI__OUT_SEL1       (* (reg8 *) dec__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define dec_PRTDSI__SYNC_OUT       (* (reg8 *) dec__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(dec__SIO_CFG)
    #define dec_SIO_HYST_EN        (* (reg8 *) dec__SIO_HYST_EN)
    #define dec_SIO_REG_HIFREQ     (* (reg8 *) dec__SIO_REG_HIFREQ)
    #define dec_SIO_CFG            (* (reg8 *) dec__SIO_CFG)
    #define dec_SIO_DIFF           (* (reg8 *) dec__SIO_DIFF)
#endif /* (dec__SIO_CFG) */

/* Interrupt Registers */
#if defined(dec__INTSTAT)
    #define dec_INTSTAT            (* (reg8 *) dec__INTSTAT)
    #define dec_SNAP               (* (reg8 *) dec__SNAP)
    
	#define dec_0_INTTYPE_REG 		(* (reg8 *) dec__0__INTTYPE)
#endif /* (dec__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_dec_H */


/* [] END OF FILE */
