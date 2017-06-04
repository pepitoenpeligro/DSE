/*******************************************************************************
* File Name: cross.h  
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

#if !defined(CY_PINS_cross_H) /* Pins cross_H */
#define CY_PINS_cross_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "cross_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 cross__PORT == 15 && ((cross__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    cross_Write(uint8 value);
void    cross_SetDriveMode(uint8 mode);
uint8   cross_ReadDataReg(void);
uint8   cross_Read(void);
void    cross_SetInterruptMode(uint16 position, uint16 mode);
uint8   cross_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the cross_SetDriveMode() function.
     *  @{
     */
        #define cross_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define cross_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define cross_DM_RES_UP          PIN_DM_RES_UP
        #define cross_DM_RES_DWN         PIN_DM_RES_DWN
        #define cross_DM_OD_LO           PIN_DM_OD_LO
        #define cross_DM_OD_HI           PIN_DM_OD_HI
        #define cross_DM_STRONG          PIN_DM_STRONG
        #define cross_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define cross_MASK               cross__MASK
#define cross_SHIFT              cross__SHIFT
#define cross_WIDTH              1u

/* Interrupt constants */
#if defined(cross__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in cross_SetInterruptMode() function.
     *  @{
     */
        #define cross_INTR_NONE      (uint16)(0x0000u)
        #define cross_INTR_RISING    (uint16)(0x0001u)
        #define cross_INTR_FALLING   (uint16)(0x0002u)
        #define cross_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define cross_INTR_MASK      (0x01u) 
#endif /* (cross__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define cross_PS                     (* (reg8 *) cross__PS)
/* Data Register */
#define cross_DR                     (* (reg8 *) cross__DR)
/* Port Number */
#define cross_PRT_NUM                (* (reg8 *) cross__PRT) 
/* Connect to Analog Globals */                                                  
#define cross_AG                     (* (reg8 *) cross__AG)                       
/* Analog MUX bux enable */
#define cross_AMUX                   (* (reg8 *) cross__AMUX) 
/* Bidirectional Enable */                                                        
#define cross_BIE                    (* (reg8 *) cross__BIE)
/* Bit-mask for Aliased Register Access */
#define cross_BIT_MASK               (* (reg8 *) cross__BIT_MASK)
/* Bypass Enable */
#define cross_BYP                    (* (reg8 *) cross__BYP)
/* Port wide control signals */                                                   
#define cross_CTL                    (* (reg8 *) cross__CTL)
/* Drive Modes */
#define cross_DM0                    (* (reg8 *) cross__DM0) 
#define cross_DM1                    (* (reg8 *) cross__DM1)
#define cross_DM2                    (* (reg8 *) cross__DM2) 
/* Input Buffer Disable Override */
#define cross_INP_DIS                (* (reg8 *) cross__INP_DIS)
/* LCD Common or Segment Drive */
#define cross_LCD_COM_SEG            (* (reg8 *) cross__LCD_COM_SEG)
/* Enable Segment LCD */
#define cross_LCD_EN                 (* (reg8 *) cross__LCD_EN)
/* Slew Rate Control */
#define cross_SLW                    (* (reg8 *) cross__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define cross_PRTDSI__CAPS_SEL       (* (reg8 *) cross__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define cross_PRTDSI__DBL_SYNC_IN    (* (reg8 *) cross__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define cross_PRTDSI__OE_SEL0        (* (reg8 *) cross__PRTDSI__OE_SEL0) 
#define cross_PRTDSI__OE_SEL1        (* (reg8 *) cross__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define cross_PRTDSI__OUT_SEL0       (* (reg8 *) cross__PRTDSI__OUT_SEL0) 
#define cross_PRTDSI__OUT_SEL1       (* (reg8 *) cross__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define cross_PRTDSI__SYNC_OUT       (* (reg8 *) cross__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(cross__SIO_CFG)
    #define cross_SIO_HYST_EN        (* (reg8 *) cross__SIO_HYST_EN)
    #define cross_SIO_REG_HIFREQ     (* (reg8 *) cross__SIO_REG_HIFREQ)
    #define cross_SIO_CFG            (* (reg8 *) cross__SIO_CFG)
    #define cross_SIO_DIFF           (* (reg8 *) cross__SIO_DIFF)
#endif /* (cross__SIO_CFG) */

/* Interrupt Registers */
#if defined(cross__INTSTAT)
    #define cross_INTSTAT            (* (reg8 *) cross__INTSTAT)
    #define cross_SNAP               (* (reg8 *) cross__SNAP)
    
	#define cross_0_INTTYPE_REG 		(* (reg8 *) cross__0__INTTYPE)
#endif /* (cross__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_cross_H */


/* [] END OF FILE */
