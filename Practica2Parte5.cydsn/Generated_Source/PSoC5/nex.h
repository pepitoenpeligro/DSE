/*******************************************************************************
* File Name: nex.h  
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

#if !defined(CY_PINS_nex_H) /* Pins nex_H */
#define CY_PINS_nex_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "nex_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 nex__PORT == 15 && ((nex__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    nex_Write(uint8 value);
void    nex_SetDriveMode(uint8 mode);
uint8   nex_ReadDataReg(void);
uint8   nex_Read(void);
void    nex_SetInterruptMode(uint16 position, uint16 mode);
uint8   nex_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the nex_SetDriveMode() function.
     *  @{
     */
        #define nex_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define nex_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define nex_DM_RES_UP          PIN_DM_RES_UP
        #define nex_DM_RES_DWN         PIN_DM_RES_DWN
        #define nex_DM_OD_LO           PIN_DM_OD_LO
        #define nex_DM_OD_HI           PIN_DM_OD_HI
        #define nex_DM_STRONG          PIN_DM_STRONG
        #define nex_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define nex_MASK               nex__MASK
#define nex_SHIFT              nex__SHIFT
#define nex_WIDTH              1u

/* Interrupt constants */
#if defined(nex__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in nex_SetInterruptMode() function.
     *  @{
     */
        #define nex_INTR_NONE      (uint16)(0x0000u)
        #define nex_INTR_RISING    (uint16)(0x0001u)
        #define nex_INTR_FALLING   (uint16)(0x0002u)
        #define nex_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define nex_INTR_MASK      (0x01u) 
#endif /* (nex__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define nex_PS                     (* (reg8 *) nex__PS)
/* Data Register */
#define nex_DR                     (* (reg8 *) nex__DR)
/* Port Number */
#define nex_PRT_NUM                (* (reg8 *) nex__PRT) 
/* Connect to Analog Globals */                                                  
#define nex_AG                     (* (reg8 *) nex__AG)                       
/* Analog MUX bux enable */
#define nex_AMUX                   (* (reg8 *) nex__AMUX) 
/* Bidirectional Enable */                                                        
#define nex_BIE                    (* (reg8 *) nex__BIE)
/* Bit-mask for Aliased Register Access */
#define nex_BIT_MASK               (* (reg8 *) nex__BIT_MASK)
/* Bypass Enable */
#define nex_BYP                    (* (reg8 *) nex__BYP)
/* Port wide control signals */                                                   
#define nex_CTL                    (* (reg8 *) nex__CTL)
/* Drive Modes */
#define nex_DM0                    (* (reg8 *) nex__DM0) 
#define nex_DM1                    (* (reg8 *) nex__DM1)
#define nex_DM2                    (* (reg8 *) nex__DM2) 
/* Input Buffer Disable Override */
#define nex_INP_DIS                (* (reg8 *) nex__INP_DIS)
/* LCD Common or Segment Drive */
#define nex_LCD_COM_SEG            (* (reg8 *) nex__LCD_COM_SEG)
/* Enable Segment LCD */
#define nex_LCD_EN                 (* (reg8 *) nex__LCD_EN)
/* Slew Rate Control */
#define nex_SLW                    (* (reg8 *) nex__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define nex_PRTDSI__CAPS_SEL       (* (reg8 *) nex__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define nex_PRTDSI__DBL_SYNC_IN    (* (reg8 *) nex__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define nex_PRTDSI__OE_SEL0        (* (reg8 *) nex__PRTDSI__OE_SEL0) 
#define nex_PRTDSI__OE_SEL1        (* (reg8 *) nex__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define nex_PRTDSI__OUT_SEL0       (* (reg8 *) nex__PRTDSI__OUT_SEL0) 
#define nex_PRTDSI__OUT_SEL1       (* (reg8 *) nex__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define nex_PRTDSI__SYNC_OUT       (* (reg8 *) nex__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(nex__SIO_CFG)
    #define nex_SIO_HYST_EN        (* (reg8 *) nex__SIO_HYST_EN)
    #define nex_SIO_REG_HIFREQ     (* (reg8 *) nex__SIO_REG_HIFREQ)
    #define nex_SIO_CFG            (* (reg8 *) nex__SIO_CFG)
    #define nex_SIO_DIFF           (* (reg8 *) nex__SIO_DIFF)
#endif /* (nex__SIO_CFG) */

/* Interrupt Registers */
#if defined(nex__INTSTAT)
    #define nex_INTSTAT            (* (reg8 *) nex__INTSTAT)
    #define nex_SNAP               (* (reg8 *) nex__SNAP)
    
	#define nex_0_INTTYPE_REG 		(* (reg8 *) nex__0__INTTYPE)
#endif /* (nex__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_nex_H */


/* [] END OF FILE */
