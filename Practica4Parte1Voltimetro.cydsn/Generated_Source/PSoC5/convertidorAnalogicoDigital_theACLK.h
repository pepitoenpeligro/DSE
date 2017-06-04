/*******************************************************************************
* File Name: convertidorAnalogicoDigital_theACLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_convertidorAnalogicoDigital_theACLK_H)
#define CY_CLOCK_convertidorAnalogicoDigital_theACLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void convertidorAnalogicoDigital_theACLK_Start(void) ;
void convertidorAnalogicoDigital_theACLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void convertidorAnalogicoDigital_theACLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void convertidorAnalogicoDigital_theACLK_StandbyPower(uint8 state) ;
void convertidorAnalogicoDigital_theACLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 convertidorAnalogicoDigital_theACLK_GetDividerRegister(void) ;
void convertidorAnalogicoDigital_theACLK_SetModeRegister(uint8 modeBitMask) ;
void convertidorAnalogicoDigital_theACLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 convertidorAnalogicoDigital_theACLK_GetModeRegister(void) ;
void convertidorAnalogicoDigital_theACLK_SetSourceRegister(uint8 clkSource) ;
uint8 convertidorAnalogicoDigital_theACLK_GetSourceRegister(void) ;
#if defined(convertidorAnalogicoDigital_theACLK__CFG3)
void convertidorAnalogicoDigital_theACLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 convertidorAnalogicoDigital_theACLK_GetPhaseRegister(void) ;
#endif /* defined(convertidorAnalogicoDigital_theACLK__CFG3) */

#define convertidorAnalogicoDigital_theACLK_Enable()                       convertidorAnalogicoDigital_theACLK_Start()
#define convertidorAnalogicoDigital_theACLK_Disable()                      convertidorAnalogicoDigital_theACLK_Stop()
#define convertidorAnalogicoDigital_theACLK_SetDivider(clkDivider)         convertidorAnalogicoDigital_theACLK_SetDividerRegister(clkDivider, 1u)
#define convertidorAnalogicoDigital_theACLK_SetDividerValue(clkDivider)    convertidorAnalogicoDigital_theACLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define convertidorAnalogicoDigital_theACLK_SetMode(clkMode)               convertidorAnalogicoDigital_theACLK_SetModeRegister(clkMode)
#define convertidorAnalogicoDigital_theACLK_SetSource(clkSource)           convertidorAnalogicoDigital_theACLK_SetSourceRegister(clkSource)
#if defined(convertidorAnalogicoDigital_theACLK__CFG3)
#define convertidorAnalogicoDigital_theACLK_SetPhase(clkPhase)             convertidorAnalogicoDigital_theACLK_SetPhaseRegister(clkPhase)
#define convertidorAnalogicoDigital_theACLK_SetPhaseValue(clkPhase)        convertidorAnalogicoDigital_theACLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(convertidorAnalogicoDigital_theACLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define convertidorAnalogicoDigital_theACLK_CLKEN              (* (reg8 *) convertidorAnalogicoDigital_theACLK__PM_ACT_CFG)
#define convertidorAnalogicoDigital_theACLK_CLKEN_PTR          ((reg8 *) convertidorAnalogicoDigital_theACLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define convertidorAnalogicoDigital_theACLK_CLKSTBY            (* (reg8 *) convertidorAnalogicoDigital_theACLK__PM_STBY_CFG)
#define convertidorAnalogicoDigital_theACLK_CLKSTBY_PTR        ((reg8 *) convertidorAnalogicoDigital_theACLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define convertidorAnalogicoDigital_theACLK_DIV_LSB            (* (reg8 *) convertidorAnalogicoDigital_theACLK__CFG0)
#define convertidorAnalogicoDigital_theACLK_DIV_LSB_PTR        ((reg8 *) convertidorAnalogicoDigital_theACLK__CFG0)
#define convertidorAnalogicoDigital_theACLK_DIV_PTR            ((reg16 *) convertidorAnalogicoDigital_theACLK__CFG0)

/* Clock MSB divider configuration register. */
#define convertidorAnalogicoDigital_theACLK_DIV_MSB            (* (reg8 *) convertidorAnalogicoDigital_theACLK__CFG1)
#define convertidorAnalogicoDigital_theACLK_DIV_MSB_PTR        ((reg8 *) convertidorAnalogicoDigital_theACLK__CFG1)

/* Mode and source configuration register */
#define convertidorAnalogicoDigital_theACLK_MOD_SRC            (* (reg8 *) convertidorAnalogicoDigital_theACLK__CFG2)
#define convertidorAnalogicoDigital_theACLK_MOD_SRC_PTR        ((reg8 *) convertidorAnalogicoDigital_theACLK__CFG2)

#if defined(convertidorAnalogicoDigital_theACLK__CFG3)
/* Analog clock phase configuration register */
#define convertidorAnalogicoDigital_theACLK_PHASE              (* (reg8 *) convertidorAnalogicoDigital_theACLK__CFG3)
#define convertidorAnalogicoDigital_theACLK_PHASE_PTR          ((reg8 *) convertidorAnalogicoDigital_theACLK__CFG3)
#endif /* defined(convertidorAnalogicoDigital_theACLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define convertidorAnalogicoDigital_theACLK_CLKEN_MASK         convertidorAnalogicoDigital_theACLK__PM_ACT_MSK
#define convertidorAnalogicoDigital_theACLK_CLKSTBY_MASK       convertidorAnalogicoDigital_theACLK__PM_STBY_MSK

/* CFG2 field masks */
#define convertidorAnalogicoDigital_theACLK_SRC_SEL_MSK        convertidorAnalogicoDigital_theACLK__CFG2_SRC_SEL_MASK
#define convertidorAnalogicoDigital_theACLK_MODE_MASK          (~(convertidorAnalogicoDigital_theACLK_SRC_SEL_MSK))

#if defined(convertidorAnalogicoDigital_theACLK__CFG3)
/* CFG3 phase mask */
#define convertidorAnalogicoDigital_theACLK_PHASE_MASK         convertidorAnalogicoDigital_theACLK__CFG3_PHASE_DLY_MASK
#endif /* defined(convertidorAnalogicoDigital_theACLK__CFG3) */

#endif /* CY_CLOCK_convertidorAnalogicoDigital_theACLK_H */


/* [] END OF FILE */
