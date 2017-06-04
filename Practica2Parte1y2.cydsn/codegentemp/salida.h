/*******************************************************************************
* File Name: salida.h  
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

#if !defined(CY_PINS_salida_H) /* Pins salida_H */
#define CY_PINS_salida_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "salida_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 salida__PORT == 15 && ((salida__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    salida_Write(uint8 value);
void    salida_SetDriveMode(uint8 mode);
uint8   salida_ReadDataReg(void);
uint8   salida_Read(void);
void    salida_SetInterruptMode(uint16 position, uint16 mode);
uint8   salida_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the salida_SetDriveMode() function.
     *  @{
     */
        #define salida_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define salida_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define salida_DM_RES_UP          PIN_DM_RES_UP
        #define salida_DM_RES_DWN         PIN_DM_RES_DWN
        #define salida_DM_OD_LO           PIN_DM_OD_LO
        #define salida_DM_OD_HI           PIN_DM_OD_HI
        #define salida_DM_STRONG          PIN_DM_STRONG
        #define salida_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define salida_MASK               salida__MASK
#define salida_SHIFT              salida__SHIFT
#define salida_WIDTH              1u

/* Interrupt constants */
#if defined(salida__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in salida_SetInterruptMode() function.
     *  @{
     */
        #define salida_INTR_NONE      (uint16)(0x0000u)
        #define salida_INTR_RISING    (uint16)(0x0001u)
        #define salida_INTR_FALLING   (uint16)(0x0002u)
        #define salida_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define salida_INTR_MASK      (0x01u) 
#endif /* (salida__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define salida_PS                     (* (reg8 *) salida__PS)
/* Data Register */
#define salida_DR                     (* (reg8 *) salida__DR)
/* Port Number */
#define salida_PRT_NUM                (* (reg8 *) salida__PRT) 
/* Connect to Analog Globals */                                                  
#define salida_AG                     (* (reg8 *) salida__AG)                       
/* Analog MUX bux enable */
#define salida_AMUX                   (* (reg8 *) salida__AMUX) 
/* Bidirectional Enable */                                                        
#define salida_BIE                    (* (reg8 *) salida__BIE)
/* Bit-mask for Aliased Register Access */
#define salida_BIT_MASK               (* (reg8 *) salida__BIT_MASK)
/* Bypass Enable */
#define salida_BYP                    (* (reg8 *) salida__BYP)
/* Port wide control signals */                                                   
#define salida_CTL                    (* (reg8 *) salida__CTL)
/* Drive Modes */
#define salida_DM0                    (* (reg8 *) salida__DM0) 
#define salida_DM1                    (* (reg8 *) salida__DM1)
#define salida_DM2                    (* (reg8 *) salida__DM2) 
/* Input Buffer Disable Override */
#define salida_INP_DIS                (* (reg8 *) salida__INP_DIS)
/* LCD Common or Segment Drive */
#define salida_LCD_COM_SEG            (* (reg8 *) salida__LCD_COM_SEG)
/* Enable Segment LCD */
#define salida_LCD_EN                 (* (reg8 *) salida__LCD_EN)
/* Slew Rate Control */
#define salida_SLW                    (* (reg8 *) salida__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define salida_PRTDSI__CAPS_SEL       (* (reg8 *) salida__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define salida_PRTDSI__DBL_SYNC_IN    (* (reg8 *) salida__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define salida_PRTDSI__OE_SEL0        (* (reg8 *) salida__PRTDSI__OE_SEL0) 
#define salida_PRTDSI__OE_SEL1        (* (reg8 *) salida__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define salida_PRTDSI__OUT_SEL0       (* (reg8 *) salida__PRTDSI__OUT_SEL0) 
#define salida_PRTDSI__OUT_SEL1       (* (reg8 *) salida__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define salida_PRTDSI__SYNC_OUT       (* (reg8 *) salida__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(salida__SIO_CFG)
    #define salida_SIO_HYST_EN        (* (reg8 *) salida__SIO_HYST_EN)
    #define salida_SIO_REG_HIFREQ     (* (reg8 *) salida__SIO_REG_HIFREQ)
    #define salida_SIO_CFG            (* (reg8 *) salida__SIO_CFG)
    #define salida_SIO_DIFF           (* (reg8 *) salida__SIO_DIFF)
#endif /* (salida__SIO_CFG) */

/* Interrupt Registers */
#if defined(salida__INTSTAT)
    #define salida_INTSTAT            (* (reg8 *) salida__INTSTAT)
    #define salida_SNAP               (* (reg8 *) salida__SNAP)
    
	#define salida_0_INTTYPE_REG 		(* (reg8 *) salida__0__INTTYPE)
#endif /* (salida__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_salida_H */


/* [] END OF FILE */
