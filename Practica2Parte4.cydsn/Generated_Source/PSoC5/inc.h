/*******************************************************************************
* File Name: inc.h  
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

#if !defined(CY_PINS_inc_H) /* Pins inc_H */
#define CY_PINS_inc_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "inc_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 inc__PORT == 15 && ((inc__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    inc_Write(uint8 value);
void    inc_SetDriveMode(uint8 mode);
uint8   inc_ReadDataReg(void);
uint8   inc_Read(void);
void    inc_SetInterruptMode(uint16 position, uint16 mode);
uint8   inc_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the inc_SetDriveMode() function.
     *  @{
     */
        #define inc_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define inc_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define inc_DM_RES_UP          PIN_DM_RES_UP
        #define inc_DM_RES_DWN         PIN_DM_RES_DWN
        #define inc_DM_OD_LO           PIN_DM_OD_LO
        #define inc_DM_OD_HI           PIN_DM_OD_HI
        #define inc_DM_STRONG          PIN_DM_STRONG
        #define inc_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define inc_MASK               inc__MASK
#define inc_SHIFT              inc__SHIFT
#define inc_WIDTH              1u

/* Interrupt constants */
#if defined(inc__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in inc_SetInterruptMode() function.
     *  @{
     */
        #define inc_INTR_NONE      (uint16)(0x0000u)
        #define inc_INTR_RISING    (uint16)(0x0001u)
        #define inc_INTR_FALLING   (uint16)(0x0002u)
        #define inc_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define inc_INTR_MASK      (0x01u) 
#endif /* (inc__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define inc_PS                     (* (reg8 *) inc__PS)
/* Data Register */
#define inc_DR                     (* (reg8 *) inc__DR)
/* Port Number */
#define inc_PRT_NUM                (* (reg8 *) inc__PRT) 
/* Connect to Analog Globals */                                                  
#define inc_AG                     (* (reg8 *) inc__AG)                       
/* Analog MUX bux enable */
#define inc_AMUX                   (* (reg8 *) inc__AMUX) 
/* Bidirectional Enable */                                                        
#define inc_BIE                    (* (reg8 *) inc__BIE)
/* Bit-mask for Aliased Register Access */
#define inc_BIT_MASK               (* (reg8 *) inc__BIT_MASK)
/* Bypass Enable */
#define inc_BYP                    (* (reg8 *) inc__BYP)
/* Port wide control signals */                                                   
#define inc_CTL                    (* (reg8 *) inc__CTL)
/* Drive Modes */
#define inc_DM0                    (* (reg8 *) inc__DM0) 
#define inc_DM1                    (* (reg8 *) inc__DM1)
#define inc_DM2                    (* (reg8 *) inc__DM2) 
/* Input Buffer Disable Override */
#define inc_INP_DIS                (* (reg8 *) inc__INP_DIS)
/* LCD Common or Segment Drive */
#define inc_LCD_COM_SEG            (* (reg8 *) inc__LCD_COM_SEG)
/* Enable Segment LCD */
#define inc_LCD_EN                 (* (reg8 *) inc__LCD_EN)
/* Slew Rate Control */
#define inc_SLW                    (* (reg8 *) inc__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define inc_PRTDSI__CAPS_SEL       (* (reg8 *) inc__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define inc_PRTDSI__DBL_SYNC_IN    (* (reg8 *) inc__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define inc_PRTDSI__OE_SEL0        (* (reg8 *) inc__PRTDSI__OE_SEL0) 
#define inc_PRTDSI__OE_SEL1        (* (reg8 *) inc__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define inc_PRTDSI__OUT_SEL0       (* (reg8 *) inc__PRTDSI__OUT_SEL0) 
#define inc_PRTDSI__OUT_SEL1       (* (reg8 *) inc__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define inc_PRTDSI__SYNC_OUT       (* (reg8 *) inc__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(inc__SIO_CFG)
    #define inc_SIO_HYST_EN        (* (reg8 *) inc__SIO_HYST_EN)
    #define inc_SIO_REG_HIFREQ     (* (reg8 *) inc__SIO_REG_HIFREQ)
    #define inc_SIO_CFG            (* (reg8 *) inc__SIO_CFG)
    #define inc_SIO_DIFF           (* (reg8 *) inc__SIO_DIFF)
#endif /* (inc__SIO_CFG) */

/* Interrupt Registers */
#if defined(inc__INTSTAT)
    #define inc_INTSTAT            (* (reg8 *) inc__INTSTAT)
    #define inc_SNAP               (* (reg8 *) inc__SNAP)
    
	#define inc_0_INTTYPE_REG 		(* (reg8 *) inc__0__INTTYPE)
#endif /* (inc__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_inc_H */


/* [] END OF FILE */
