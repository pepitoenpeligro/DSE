/*******************************************************************************
* File Name: convertidorAnalogicoDigital_Ext_CP_Clk.h
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

#if !defined(CY_CLOCK_convertidorAnalogicoDigital_Ext_CP_Clk_H)
#define CY_CLOCK_convertidorAnalogicoDigital_Ext_CP_Clk_H

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

void convertidorAnalogicoDigital_Ext_CP_Clk_Start(void) ;
void convertidorAnalogicoDigital_Ext_CP_Clk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void convertidorAnalogicoDigital_Ext_CP_Clk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void convertidorAnalogicoDigital_Ext_CP_Clk_StandbyPower(uint8 state) ;
void convertidorAnalogicoDigital_Ext_CP_Clk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 convertidorAnalogicoDigital_Ext_CP_Clk_GetDividerRegister(void) ;
void convertidorAnalogicoDigital_Ext_CP_Clk_SetModeRegister(uint8 modeBitMask) ;
void convertidorAnalogicoDigital_Ext_CP_Clk_ClearModeRegister(uint8 modeBitMask) ;
uint8 convertidorAnalogicoDigital_Ext_CP_Clk_GetModeRegister(void) ;
void convertidorAnalogicoDigital_Ext_CP_Clk_SetSourceRegister(uint8 clkSource) ;
uint8 convertidorAnalogicoDigital_Ext_CP_Clk_GetSourceRegister(void) ;
#if defined(convertidorAnalogicoDigital_Ext_CP_Clk__CFG3)
void convertidorAnalogicoDigital_Ext_CP_Clk_SetPhaseRegister(uint8 clkPhase) ;
uint8 convertidorAnalogicoDigital_Ext_CP_Clk_GetPhaseRegister(void) ;
#endif /* defined(convertidorAnalogicoDigital_Ext_CP_Clk__CFG3) */

#define convertidorAnalogicoDigital_Ext_CP_Clk_Enable()                       convertidorAnalogicoDigital_Ext_CP_Clk_Start()
#define convertidorAnalogicoDigital_Ext_CP_Clk_Disable()                      convertidorAnalogicoDigital_Ext_CP_Clk_Stop()
#define convertidorAnalogicoDigital_Ext_CP_Clk_SetDivider(clkDivider)         convertidorAnalogicoDigital_Ext_CP_Clk_SetDividerRegister(clkDivider, 1u)
#define convertidorAnalogicoDigital_Ext_CP_Clk_SetDividerValue(clkDivider)    convertidorAnalogicoDigital_Ext_CP_Clk_SetDividerRegister((clkDivider) - 1u, 1u)
#define convertidorAnalogicoDigital_Ext_CP_Clk_SetMode(clkMode)               convertidorAnalogicoDigital_Ext_CP_Clk_SetModeRegister(clkMode)
#define convertidorAnalogicoDigital_Ext_CP_Clk_SetSource(clkSource)           convertidorAnalogicoDigital_Ext_CP_Clk_SetSourceRegister(clkSource)
#if defined(convertidorAnalogicoDigital_Ext_CP_Clk__CFG3)
#define convertidorAnalogicoDigital_Ext_CP_Clk_SetPhase(clkPhase)             convertidorAnalogicoDigital_Ext_CP_Clk_SetPhaseRegister(clkPhase)
#define convertidorAnalogicoDigital_Ext_CP_Clk_SetPhaseValue(clkPhase)        convertidorAnalogicoDigital_Ext_CP_Clk_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(convertidorAnalogicoDigital_Ext_CP_Clk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define convertidorAnalogicoDigital_Ext_CP_Clk_CLKEN              (* (reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__PM_ACT_CFG)
#define convertidorAnalogicoDigital_Ext_CP_Clk_CLKEN_PTR          ((reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define convertidorAnalogicoDigital_Ext_CP_Clk_CLKSTBY            (* (reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__PM_STBY_CFG)
#define convertidorAnalogicoDigital_Ext_CP_Clk_CLKSTBY_PTR        ((reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define convertidorAnalogicoDigital_Ext_CP_Clk_DIV_LSB            (* (reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__CFG0)
#define convertidorAnalogicoDigital_Ext_CP_Clk_DIV_LSB_PTR        ((reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__CFG0)
#define convertidorAnalogicoDigital_Ext_CP_Clk_DIV_PTR            ((reg16 *) convertidorAnalogicoDigital_Ext_CP_Clk__CFG0)

/* Clock MSB divider configuration register. */
#define convertidorAnalogicoDigital_Ext_CP_Clk_DIV_MSB            (* (reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__CFG1)
#define convertidorAnalogicoDigital_Ext_CP_Clk_DIV_MSB_PTR        ((reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__CFG1)

/* Mode and source configuration register */
#define convertidorAnalogicoDigital_Ext_CP_Clk_MOD_SRC            (* (reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__CFG2)
#define convertidorAnalogicoDigital_Ext_CP_Clk_MOD_SRC_PTR        ((reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__CFG2)

#if defined(convertidorAnalogicoDigital_Ext_CP_Clk__CFG3)
/* Analog clock phase configuration register */
#define convertidorAnalogicoDigital_Ext_CP_Clk_PHASE              (* (reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__CFG3)
#define convertidorAnalogicoDigital_Ext_CP_Clk_PHASE_PTR          ((reg8 *) convertidorAnalogicoDigital_Ext_CP_Clk__CFG3)
#endif /* defined(convertidorAnalogicoDigital_Ext_CP_Clk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define convertidorAnalogicoDigital_Ext_CP_Clk_CLKEN_MASK         convertidorAnalogicoDigital_Ext_CP_Clk__PM_ACT_MSK
#define convertidorAnalogicoDigital_Ext_CP_Clk_CLKSTBY_MASK       convertidorAnalogicoDigital_Ext_CP_Clk__PM_STBY_MSK

/* CFG2 field masks */
#define convertidorAnalogicoDigital_Ext_CP_Clk_SRC_SEL_MSK        convertidorAnalogicoDigital_Ext_CP_Clk__CFG2_SRC_SEL_MASK
#define convertidorAnalogicoDigital_Ext_CP_Clk_MODE_MASK          (~(convertidorAnalogicoDigital_Ext_CP_Clk_SRC_SEL_MSK))

#if defined(convertidorAnalogicoDigital_Ext_CP_Clk__CFG3)
/* CFG3 phase mask */
#define convertidorAnalogicoDigital_Ext_CP_Clk_PHASE_MASK         convertidorAnalogicoDigital_Ext_CP_Clk__CFG3_PHASE_DLY_MASK
#endif /* defined(convertidorAnalogicoDigital_Ext_CP_Clk__CFG3) */

#endif /* CY_CLOCK_convertidorAnalogicoDigital_Ext_CP_Clk_H */


/* [] END OF FILE */
