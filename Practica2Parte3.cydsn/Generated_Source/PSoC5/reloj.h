/*******************************************************************************
* File Name: reloj.h
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

#if !defined(CY_CLOCK_reloj_H)
#define CY_CLOCK_reloj_H

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

void reloj_Start(void) ;
void reloj_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void reloj_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void reloj_StandbyPower(uint8 state) ;
void reloj_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 reloj_GetDividerRegister(void) ;
void reloj_SetModeRegister(uint8 modeBitMask) ;
void reloj_ClearModeRegister(uint8 modeBitMask) ;
uint8 reloj_GetModeRegister(void) ;
void reloj_SetSourceRegister(uint8 clkSource) ;
uint8 reloj_GetSourceRegister(void) ;
#if defined(reloj__CFG3)
void reloj_SetPhaseRegister(uint8 clkPhase) ;
uint8 reloj_GetPhaseRegister(void) ;
#endif /* defined(reloj__CFG3) */

#define reloj_Enable()                       reloj_Start()
#define reloj_Disable()                      reloj_Stop()
#define reloj_SetDivider(clkDivider)         reloj_SetDividerRegister(clkDivider, 1u)
#define reloj_SetDividerValue(clkDivider)    reloj_SetDividerRegister((clkDivider) - 1u, 1u)
#define reloj_SetMode(clkMode)               reloj_SetModeRegister(clkMode)
#define reloj_SetSource(clkSource)           reloj_SetSourceRegister(clkSource)
#if defined(reloj__CFG3)
#define reloj_SetPhase(clkPhase)             reloj_SetPhaseRegister(clkPhase)
#define reloj_SetPhaseValue(clkPhase)        reloj_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(reloj__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define reloj_CLKEN              (* (reg8 *) reloj__PM_ACT_CFG)
#define reloj_CLKEN_PTR          ((reg8 *) reloj__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define reloj_CLKSTBY            (* (reg8 *) reloj__PM_STBY_CFG)
#define reloj_CLKSTBY_PTR        ((reg8 *) reloj__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define reloj_DIV_LSB            (* (reg8 *) reloj__CFG0)
#define reloj_DIV_LSB_PTR        ((reg8 *) reloj__CFG0)
#define reloj_DIV_PTR            ((reg16 *) reloj__CFG0)

/* Clock MSB divider configuration register. */
#define reloj_DIV_MSB            (* (reg8 *) reloj__CFG1)
#define reloj_DIV_MSB_PTR        ((reg8 *) reloj__CFG1)

/* Mode and source configuration register */
#define reloj_MOD_SRC            (* (reg8 *) reloj__CFG2)
#define reloj_MOD_SRC_PTR        ((reg8 *) reloj__CFG2)

#if defined(reloj__CFG3)
/* Analog clock phase configuration register */
#define reloj_PHASE              (* (reg8 *) reloj__CFG3)
#define reloj_PHASE_PTR          ((reg8 *) reloj__CFG3)
#endif /* defined(reloj__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define reloj_CLKEN_MASK         reloj__PM_ACT_MSK
#define reloj_CLKSTBY_MASK       reloj__PM_STBY_MSK

/* CFG2 field masks */
#define reloj_SRC_SEL_MSK        reloj__CFG2_SRC_SEL_MASK
#define reloj_MODE_MASK          (~(reloj_SRC_SEL_MSK))

#if defined(reloj__CFG3)
/* CFG3 phase mask */
#define reloj_PHASE_MASK         reloj__CFG3_PHASE_DLY_MASK
#endif /* defined(reloj__CFG3) */

#endif /* CY_CLOCK_reloj_H */


/* [] END OF FILE */
