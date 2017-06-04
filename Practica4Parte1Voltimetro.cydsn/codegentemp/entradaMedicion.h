/*******************************************************************************
* File Name: entradaMedicion.h  
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

#if !defined(CY_PINS_entradaMedicion_H) /* Pins entradaMedicion_H */
#define CY_PINS_entradaMedicion_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "entradaMedicion_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 entradaMedicion__PORT == 15 && ((entradaMedicion__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    entradaMedicion_Write(uint8 value);
void    entradaMedicion_SetDriveMode(uint8 mode);
uint8   entradaMedicion_ReadDataReg(void);
uint8   entradaMedicion_Read(void);
void    entradaMedicion_SetInterruptMode(uint16 position, uint16 mode);
uint8   entradaMedicion_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the entradaMedicion_SetDriveMode() function.
     *  @{
     */
        #define entradaMedicion_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define entradaMedicion_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define entradaMedicion_DM_RES_UP          PIN_DM_RES_UP
        #define entradaMedicion_DM_RES_DWN         PIN_DM_RES_DWN
        #define entradaMedicion_DM_OD_LO           PIN_DM_OD_LO
        #define entradaMedicion_DM_OD_HI           PIN_DM_OD_HI
        #define entradaMedicion_DM_STRONG          PIN_DM_STRONG
        #define entradaMedicion_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define entradaMedicion_MASK               entradaMedicion__MASK
#define entradaMedicion_SHIFT              entradaMedicion__SHIFT
#define entradaMedicion_WIDTH              1u

/* Interrupt constants */
#if defined(entradaMedicion__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in entradaMedicion_SetInterruptMode() function.
     *  @{
     */
        #define entradaMedicion_INTR_NONE      (uint16)(0x0000u)
        #define entradaMedicion_INTR_RISING    (uint16)(0x0001u)
        #define entradaMedicion_INTR_FALLING   (uint16)(0x0002u)
        #define entradaMedicion_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define entradaMedicion_INTR_MASK      (0x01u) 
#endif /* (entradaMedicion__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define entradaMedicion_PS                     (* (reg8 *) entradaMedicion__PS)
/* Data Register */
#define entradaMedicion_DR                     (* (reg8 *) entradaMedicion__DR)
/* Port Number */
#define entradaMedicion_PRT_NUM                (* (reg8 *) entradaMedicion__PRT) 
/* Connect to Analog Globals */                                                  
#define entradaMedicion_AG                     (* (reg8 *) entradaMedicion__AG)                       
/* Analog MUX bux enable */
#define entradaMedicion_AMUX                   (* (reg8 *) entradaMedicion__AMUX) 
/* Bidirectional Enable */                                                        
#define entradaMedicion_BIE                    (* (reg8 *) entradaMedicion__BIE)
/* Bit-mask for Aliased Register Access */
#define entradaMedicion_BIT_MASK               (* (reg8 *) entradaMedicion__BIT_MASK)
/* Bypass Enable */
#define entradaMedicion_BYP                    (* (reg8 *) entradaMedicion__BYP)
/* Port wide control signals */                                                   
#define entradaMedicion_CTL                    (* (reg8 *) entradaMedicion__CTL)
/* Drive Modes */
#define entradaMedicion_DM0                    (* (reg8 *) entradaMedicion__DM0) 
#define entradaMedicion_DM1                    (* (reg8 *) entradaMedicion__DM1)
#define entradaMedicion_DM2                    (* (reg8 *) entradaMedicion__DM2) 
/* Input Buffer Disable Override */
#define entradaMedicion_INP_DIS                (* (reg8 *) entradaMedicion__INP_DIS)
/* LCD Common or Segment Drive */
#define entradaMedicion_LCD_COM_SEG            (* (reg8 *) entradaMedicion__LCD_COM_SEG)
/* Enable Segment LCD */
#define entradaMedicion_LCD_EN                 (* (reg8 *) entradaMedicion__LCD_EN)
/* Slew Rate Control */
#define entradaMedicion_SLW                    (* (reg8 *) entradaMedicion__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define entradaMedicion_PRTDSI__CAPS_SEL       (* (reg8 *) entradaMedicion__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define entradaMedicion_PRTDSI__DBL_SYNC_IN    (* (reg8 *) entradaMedicion__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define entradaMedicion_PRTDSI__OE_SEL0        (* (reg8 *) entradaMedicion__PRTDSI__OE_SEL0) 
#define entradaMedicion_PRTDSI__OE_SEL1        (* (reg8 *) entradaMedicion__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define entradaMedicion_PRTDSI__OUT_SEL0       (* (reg8 *) entradaMedicion__PRTDSI__OUT_SEL0) 
#define entradaMedicion_PRTDSI__OUT_SEL1       (* (reg8 *) entradaMedicion__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define entradaMedicion_PRTDSI__SYNC_OUT       (* (reg8 *) entradaMedicion__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(entradaMedicion__SIO_CFG)
    #define entradaMedicion_SIO_HYST_EN        (* (reg8 *) entradaMedicion__SIO_HYST_EN)
    #define entradaMedicion_SIO_REG_HIFREQ     (* (reg8 *) entradaMedicion__SIO_REG_HIFREQ)
    #define entradaMedicion_SIO_CFG            (* (reg8 *) entradaMedicion__SIO_CFG)
    #define entradaMedicion_SIO_DIFF           (* (reg8 *) entradaMedicion__SIO_DIFF)
#endif /* (entradaMedicion__SIO_CFG) */

/* Interrupt Registers */
#if defined(entradaMedicion__INTSTAT)
    #define entradaMedicion_INTSTAT            (* (reg8 *) entradaMedicion__INTSTAT)
    #define entradaMedicion_SNAP               (* (reg8 *) entradaMedicion__SNAP)
    
	#define entradaMedicion_0_INTTYPE_REG 		(* (reg8 *) entradaMedicion__0__INTTYPE)
#endif /* (entradaMedicion__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_entradaMedicion_H */


/* [] END OF FILE */
