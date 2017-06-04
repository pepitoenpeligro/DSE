/*******************************************************************************
* File Name: generadorPulsosPWM.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_generadorPulsosPWM_H)
#define CY_PWM_generadorPulsosPWM_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 generadorPulsosPWM_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define generadorPulsosPWM_Resolution                     (8u)
#define generadorPulsosPWM_UsingFixedFunction             (0u)
#define generadorPulsosPWM_DeadBandMode                   (0u)
#define generadorPulsosPWM_KillModeMinTime                (0u)
#define generadorPulsosPWM_KillMode                       (0u)
#define generadorPulsosPWM_PWMMode                        (0u)
#define generadorPulsosPWM_PWMModeIsCenterAligned         (0u)
#define generadorPulsosPWM_DeadBandUsed                   (0u)
#define generadorPulsosPWM_DeadBand2_4                    (0u)

#if !defined(generadorPulsosPWM_PWMUDB_genblk8_stsreg__REMOVED)
    #define generadorPulsosPWM_UseStatus                  (1u)
#else
    #define generadorPulsosPWM_UseStatus                  (0u)
#endif /* !defined(generadorPulsosPWM_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define generadorPulsosPWM_UseControl                 (1u)
#else
    #define generadorPulsosPWM_UseControl                 (0u)
#endif /* !defined(generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define generadorPulsosPWM_UseOneCompareMode              (1u)
#define generadorPulsosPWM_MinimumKillTime                (1u)
#define generadorPulsosPWM_EnableMode                     (0u)

#define generadorPulsosPWM_CompareMode1SW                 (0u)
#define generadorPulsosPWM_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define generadorPulsosPWM__B_PWM__DISABLED 0
#define generadorPulsosPWM__B_PWM__ASYNCHRONOUS 1
#define generadorPulsosPWM__B_PWM__SINGLECYCLE 2
#define generadorPulsosPWM__B_PWM__LATCHED 3
#define generadorPulsosPWM__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define generadorPulsosPWM__B_PWM__DBMDISABLED 0
#define generadorPulsosPWM__B_PWM__DBM_2_4_CLOCKS 1
#define generadorPulsosPWM__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define generadorPulsosPWM__B_PWM__ONE_OUTPUT 0
#define generadorPulsosPWM__B_PWM__TWO_OUTPUTS 1
#define generadorPulsosPWM__B_PWM__DUAL_EDGE 2
#define generadorPulsosPWM__B_PWM__CENTER_ALIGN 3
#define generadorPulsosPWM__B_PWM__DITHER 5
#define generadorPulsosPWM__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define generadorPulsosPWM__B_PWM__LESS_THAN 1
#define generadorPulsosPWM__B_PWM__LESS_THAN_OR_EQUAL 2
#define generadorPulsosPWM__B_PWM__GREATER_THAN 3
#define generadorPulsosPWM__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define generadorPulsosPWM__B_PWM__EQUAL 0
#define generadorPulsosPWM__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!generadorPulsosPWM_UsingFixedFunction)
        uint8 PWMUdb;               /* PWM Current Counter value  */
        #if(!generadorPulsosPWM_PWMModeIsCenterAligned)
            uint8 PWMPeriod;
        #endif /* (!generadorPulsosPWM_PWMModeIsCenterAligned) */
        #if (generadorPulsosPWM_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (generadorPulsosPWM_UseStatus) */

        /* Backup for Deadband parameters */
        #if(generadorPulsosPWM_DeadBandMode == generadorPulsosPWM__B_PWM__DBM_256_CLOCKS || \
            generadorPulsosPWM_DeadBandMode == generadorPulsosPWM__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(generadorPulsosPWM_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (generadorPulsosPWM_KillModeMinTime) */

        /* Backup control register */
        #if(generadorPulsosPWM_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (generadorPulsosPWM_UseControl) */

    #endif /* (!generadorPulsosPWM_UsingFixedFunction) */

}generadorPulsosPWM_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    generadorPulsosPWM_Start(void) ;
void    generadorPulsosPWM_Stop(void) ;

#if (generadorPulsosPWM_UseStatus || generadorPulsosPWM_UsingFixedFunction)
    void  generadorPulsosPWM_SetInterruptMode(uint8 interruptMode) ;
    uint8 generadorPulsosPWM_ReadStatusRegister(void) ;
#endif /* (generadorPulsosPWM_UseStatus || generadorPulsosPWM_UsingFixedFunction) */

#define generadorPulsosPWM_GetInterruptSource() generadorPulsosPWM_ReadStatusRegister()

#if (generadorPulsosPWM_UseControl)
    uint8 generadorPulsosPWM_ReadControlRegister(void) ;
    void  generadorPulsosPWM_WriteControlRegister(uint8 control)
          ;
#endif /* (generadorPulsosPWM_UseControl) */

#if (generadorPulsosPWM_UseOneCompareMode)
   #if (generadorPulsosPWM_CompareMode1SW)
       void    generadorPulsosPWM_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (generadorPulsosPWM_CompareMode1SW) */
#else
    #if (generadorPulsosPWM_CompareMode1SW)
        void    generadorPulsosPWM_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (generadorPulsosPWM_CompareMode1SW) */
    #if (generadorPulsosPWM_CompareMode2SW)
        void    generadorPulsosPWM_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (generadorPulsosPWM_CompareMode2SW) */
#endif /* (generadorPulsosPWM_UseOneCompareMode) */

#if (!generadorPulsosPWM_UsingFixedFunction)
    uint8   generadorPulsosPWM_ReadCounter(void) ;
    uint8 generadorPulsosPWM_ReadCapture(void) ;

    #if (generadorPulsosPWM_UseStatus)
            void generadorPulsosPWM_ClearFIFO(void) ;
    #endif /* (generadorPulsosPWM_UseStatus) */

    void    generadorPulsosPWM_WriteCounter(uint8 counter)
            ;
#endif /* (!generadorPulsosPWM_UsingFixedFunction) */

void    generadorPulsosPWM_WritePeriod(uint8 period)
        ;
uint8 generadorPulsosPWM_ReadPeriod(void) ;

#if (generadorPulsosPWM_UseOneCompareMode)
    void    generadorPulsosPWM_WriteCompare(uint8 compare)
            ;
    uint8 generadorPulsosPWM_ReadCompare(void) ;
#else
    void    generadorPulsosPWM_WriteCompare1(uint8 compare)
            ;
    uint8 generadorPulsosPWM_ReadCompare1(void) ;
    void    generadorPulsosPWM_WriteCompare2(uint8 compare)
            ;
    uint8 generadorPulsosPWM_ReadCompare2(void) ;
#endif /* (generadorPulsosPWM_UseOneCompareMode) */


#if (generadorPulsosPWM_DeadBandUsed)
    void    generadorPulsosPWM_WriteDeadTime(uint8 deadtime) ;
    uint8   generadorPulsosPWM_ReadDeadTime(void) ;
#endif /* (generadorPulsosPWM_DeadBandUsed) */

#if ( generadorPulsosPWM_KillModeMinTime)
    void generadorPulsosPWM_WriteKillTime(uint8 killtime) ;
    uint8 generadorPulsosPWM_ReadKillTime(void) ;
#endif /* ( generadorPulsosPWM_KillModeMinTime) */

void generadorPulsosPWM_Init(void) ;
void generadorPulsosPWM_Enable(void) ;
void generadorPulsosPWM_Sleep(void) ;
void generadorPulsosPWM_Wakeup(void) ;
void generadorPulsosPWM_SaveConfig(void) ;
void generadorPulsosPWM_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define generadorPulsosPWM_INIT_PERIOD_VALUE          (99u)
#define generadorPulsosPWM_INIT_COMPARE_VALUE1        (50u)
#define generadorPulsosPWM_INIT_COMPARE_VALUE2        (63u)
#define generadorPulsosPWM_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(1u <<   \
                                                    generadorPulsosPWM_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    generadorPulsosPWM_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    generadorPulsosPWM_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    generadorPulsosPWM_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define generadorPulsosPWM_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  generadorPulsosPWM_CTRL_CMPMODE2_SHIFT)
#define generadorPulsosPWM_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  generadorPulsosPWM_CTRL_CMPMODE1_SHIFT)
#define generadorPulsosPWM_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (generadorPulsosPWM_UsingFixedFunction)
   #define generadorPulsosPWM_PERIOD_LSB              (*(reg16 *) generadorPulsosPWM_PWMHW__PER0)
   #define generadorPulsosPWM_PERIOD_LSB_PTR          ( (reg16 *) generadorPulsosPWM_PWMHW__PER0)
   #define generadorPulsosPWM_COMPARE1_LSB            (*(reg16 *) generadorPulsosPWM_PWMHW__CNT_CMP0)
   #define generadorPulsosPWM_COMPARE1_LSB_PTR        ( (reg16 *) generadorPulsosPWM_PWMHW__CNT_CMP0)
   #define generadorPulsosPWM_COMPARE2_LSB            (0x00u)
   #define generadorPulsosPWM_COMPARE2_LSB_PTR        (0x00u)
   #define generadorPulsosPWM_COUNTER_LSB             (*(reg16 *) generadorPulsosPWM_PWMHW__CNT_CMP0)
   #define generadorPulsosPWM_COUNTER_LSB_PTR         ( (reg16 *) generadorPulsosPWM_PWMHW__CNT_CMP0)
   #define generadorPulsosPWM_CAPTURE_LSB             (*(reg16 *) generadorPulsosPWM_PWMHW__CAP0)
   #define generadorPulsosPWM_CAPTURE_LSB_PTR         ( (reg16 *) generadorPulsosPWM_PWMHW__CAP0)
   #define generadorPulsosPWM_RT1                     (*(reg8 *)  generadorPulsosPWM_PWMHW__RT1)
   #define generadorPulsosPWM_RT1_PTR                 ( (reg8 *)  generadorPulsosPWM_PWMHW__RT1)

#else
   #if (generadorPulsosPWM_Resolution == 8u) /* 8bit - PWM */

       #if(generadorPulsosPWM_PWMModeIsCenterAligned)
           #define generadorPulsosPWM_PERIOD_LSB      (*(reg8 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D1_REG)
           #define generadorPulsosPWM_PERIOD_LSB_PTR  ((reg8 *)   generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #else
           #define generadorPulsosPWM_PERIOD_LSB      (*(reg8 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__F0_REG)
           #define generadorPulsosPWM_PERIOD_LSB_PTR  ((reg8 *)   generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__F0_REG)
       #endif /* (generadorPulsosPWM_PWMModeIsCenterAligned) */

       #define generadorPulsosPWM_COMPARE1_LSB        (*(reg8 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D0_REG)
       #define generadorPulsosPWM_COMPARE1_LSB_PTR    ((reg8 *)   generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D0_REG)
       #define generadorPulsosPWM_COMPARE2_LSB        (*(reg8 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #define generadorPulsosPWM_COMPARE2_LSB_PTR    ((reg8 *)   generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #define generadorPulsosPWM_COUNTERCAP_LSB      (*(reg8 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A1_REG)
       #define generadorPulsosPWM_COUNTERCAP_LSB_PTR  ((reg8 *)   generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A1_REG)
       #define generadorPulsosPWM_COUNTER_LSB         (*(reg8 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A0_REG)
       #define generadorPulsosPWM_COUNTER_LSB_PTR     ((reg8 *)   generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A0_REG)
       #define generadorPulsosPWM_CAPTURE_LSB         (*(reg8 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__F1_REG)
       #define generadorPulsosPWM_CAPTURE_LSB_PTR     ((reg8 *)   generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(generadorPulsosPWM_PWMModeIsCenterAligned)
               #define generadorPulsosPWM_PERIOD_LSB      (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D1_REG)
               #define generadorPulsosPWM_PERIOD_LSB_PTR  ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #else
               #define generadorPulsosPWM_PERIOD_LSB      (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__F0_REG)
               #define generadorPulsosPWM_PERIOD_LSB_PTR  ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__F0_REG)
            #endif /* (generadorPulsosPWM_PWMModeIsCenterAligned) */

            #define generadorPulsosPWM_COMPARE1_LSB       (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D0_REG)
            #define generadorPulsosPWM_COMPARE1_LSB_PTR   ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D0_REG)
            #define generadorPulsosPWM_COMPARE2_LSB       (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #define generadorPulsosPWM_COMPARE2_LSB_PTR   ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #define generadorPulsosPWM_COUNTERCAP_LSB     (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define generadorPulsosPWM_COUNTERCAP_LSB_PTR ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define generadorPulsosPWM_COUNTER_LSB        (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define generadorPulsosPWM_COUNTER_LSB_PTR    ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define generadorPulsosPWM_CAPTURE_LSB        (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__F1_REG)
            #define generadorPulsosPWM_CAPTURE_LSB_PTR    ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__F1_REG)
        #else
            #if(generadorPulsosPWM_PWMModeIsCenterAligned)
               #define generadorPulsosPWM_PERIOD_LSB      (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
               #define generadorPulsosPWM_PERIOD_LSB_PTR  ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #else
               #define generadorPulsosPWM_PERIOD_LSB      (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
               #define generadorPulsosPWM_PERIOD_LSB_PTR  ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
            #endif /* (generadorPulsosPWM_PWMModeIsCenterAligned) */

            #define generadorPulsosPWM_COMPARE1_LSB       (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define generadorPulsosPWM_COMPARE1_LSB_PTR   ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define generadorPulsosPWM_COMPARE2_LSB       (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define generadorPulsosPWM_COMPARE2_LSB_PTR   ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define generadorPulsosPWM_COUNTERCAP_LSB     (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define generadorPulsosPWM_COUNTERCAP_LSB_PTR ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define generadorPulsosPWM_COUNTER_LSB        (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define generadorPulsosPWM_COUNTER_LSB_PTR    ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define generadorPulsosPWM_CAPTURE_LSB        (*(reg16 *) generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
            #define generadorPulsosPWM_CAPTURE_LSB_PTR    ((reg16 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define generadorPulsosPWM_AUX_CONTROLDP1          (*(reg8 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)
       #define generadorPulsosPWM_AUX_CONTROLDP1_PTR      ((reg8 *)   generadorPulsosPWM_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (generadorPulsosPWM_Resolution == 8) */

   #define generadorPulsosPWM_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A1_REG)
   #define generadorPulsosPWM_AUX_CONTROLDP0          (*(reg8 *)  generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)
   #define generadorPulsosPWM_AUX_CONTROLDP0_PTR      ((reg8 *)   generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (generadorPulsosPWM_UsingFixedFunction) */

#if(generadorPulsosPWM_KillModeMinTime )
    #define generadorPulsosPWM_KILLMODEMINTIME        (*(reg8 *)  generadorPulsosPWM_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define generadorPulsosPWM_KILLMODEMINTIME_PTR    ((reg8 *)   generadorPulsosPWM_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (generadorPulsosPWM_KillModeMinTime ) */

#if(generadorPulsosPWM_DeadBandMode == generadorPulsosPWM__B_PWM__DBM_256_CLOCKS)
    #define generadorPulsosPWM_DEADBAND_COUNT         (*(reg8 *)  generadorPulsosPWM_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define generadorPulsosPWM_DEADBAND_COUNT_PTR     ((reg8 *)   generadorPulsosPWM_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define generadorPulsosPWM_DEADBAND_LSB_PTR       ((reg8 *)   generadorPulsosPWM_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define generadorPulsosPWM_DEADBAND_LSB           (*(reg8 *)  generadorPulsosPWM_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(generadorPulsosPWM_DeadBandMode == generadorPulsosPWM__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (generadorPulsosPWM_UsingFixedFunction)
        #define generadorPulsosPWM_DEADBAND_COUNT         (*(reg8 *)  generadorPulsosPWM_PWMHW__CFG0)
        #define generadorPulsosPWM_DEADBAND_COUNT_PTR     ((reg8 *)   generadorPulsosPWM_PWMHW__CFG0)
        #define generadorPulsosPWM_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << generadorPulsosPWM_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define generadorPulsosPWM_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define generadorPulsosPWM_DEADBAND_COUNT         (*(reg8 *)  generadorPulsosPWM_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define generadorPulsosPWM_DEADBAND_COUNT_PTR     ((reg8 *)   generadorPulsosPWM_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define generadorPulsosPWM_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << generadorPulsosPWM_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define generadorPulsosPWM_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (generadorPulsosPWM_UsingFixedFunction) */
#endif /* (generadorPulsosPWM_DeadBandMode == generadorPulsosPWM__B_PWM__DBM_256_CLOCKS) */



#if (generadorPulsosPWM_UsingFixedFunction)
    #define generadorPulsosPWM_STATUS                 (*(reg8 *) generadorPulsosPWM_PWMHW__SR0)
    #define generadorPulsosPWM_STATUS_PTR             ((reg8 *) generadorPulsosPWM_PWMHW__SR0)
    #define generadorPulsosPWM_STATUS_MASK            (*(reg8 *) generadorPulsosPWM_PWMHW__SR0)
    #define generadorPulsosPWM_STATUS_MASK_PTR        ((reg8 *) generadorPulsosPWM_PWMHW__SR0)
    #define generadorPulsosPWM_CONTROL                (*(reg8 *) generadorPulsosPWM_PWMHW__CFG0)
    #define generadorPulsosPWM_CONTROL_PTR            ((reg8 *) generadorPulsosPWM_PWMHW__CFG0)
    #define generadorPulsosPWM_CONTROL2               (*(reg8 *) generadorPulsosPWM_PWMHW__CFG1)
    #define generadorPulsosPWM_CONTROL3               (*(reg8 *) generadorPulsosPWM_PWMHW__CFG2)
    #define generadorPulsosPWM_GLOBAL_ENABLE          (*(reg8 *) generadorPulsosPWM_PWMHW__PM_ACT_CFG)
    #define generadorPulsosPWM_GLOBAL_ENABLE_PTR      ( (reg8 *) generadorPulsosPWM_PWMHW__PM_ACT_CFG)
    #define generadorPulsosPWM_GLOBAL_STBY_ENABLE     (*(reg8 *) generadorPulsosPWM_PWMHW__PM_STBY_CFG)
    #define generadorPulsosPWM_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) generadorPulsosPWM_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define generadorPulsosPWM_BLOCK_EN_MASK          (generadorPulsosPWM_PWMHW__PM_ACT_MSK)
    #define generadorPulsosPWM_BLOCK_STBY_EN_MASK     (generadorPulsosPWM_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define generadorPulsosPWM_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define generadorPulsosPWM_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define generadorPulsosPWM_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define generadorPulsosPWM_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define generadorPulsosPWM_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define generadorPulsosPWM_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define generadorPulsosPWM_CTRL_ENABLE            (uint8)((uint8)0x01u << generadorPulsosPWM_CTRL_ENABLE_SHIFT)
    #define generadorPulsosPWM_CTRL_RESET             (uint8)((uint8)0x01u << generadorPulsosPWM_CTRL_RESET_SHIFT)
    #define generadorPulsosPWM_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << generadorPulsosPWM_CTRL_CMPMODE2_SHIFT)
    #define generadorPulsosPWM_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << generadorPulsosPWM_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define generadorPulsosPWM_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define generadorPulsosPWM_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << generadorPulsosPWM_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define generadorPulsosPWM_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define generadorPulsosPWM_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define generadorPulsosPWM_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define generadorPulsosPWM_STATUS_TC_INT_EN_MASK_SHIFT            (generadorPulsosPWM_STATUS_TC_SHIFT - 4u)
    #define generadorPulsosPWM_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define generadorPulsosPWM_STATUS_CMP1_INT_EN_MASK_SHIFT          (generadorPulsosPWM_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define generadorPulsosPWM_STATUS_TC              (uint8)((uint8)0x01u << generadorPulsosPWM_STATUS_TC_SHIFT)
    #define generadorPulsosPWM_STATUS_CMP1            (uint8)((uint8)0x01u << generadorPulsosPWM_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define generadorPulsosPWM_STATUS_TC_INT_EN_MASK              (uint8)((uint8)generadorPulsosPWM_STATUS_TC >> 4u)
    #define generadorPulsosPWM_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)generadorPulsosPWM_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define generadorPulsosPWM_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define generadorPulsosPWM_RT1_MASK              (uint8)((uint8)0x03u << generadorPulsosPWM_RT1_SHIFT)
    #define generadorPulsosPWM_SYNC                  (uint8)((uint8)0x03u << generadorPulsosPWM_RT1_SHIFT)
    #define generadorPulsosPWM_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define generadorPulsosPWM_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << generadorPulsosPWM_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define generadorPulsosPWM_SYNCDSI_EN            (uint8)((uint8)0x0Fu << generadorPulsosPWM_SYNCDSI_SHIFT)


#else
    #define generadorPulsosPWM_STATUS                (*(reg8 *)   generadorPulsosPWM_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define generadorPulsosPWM_STATUS_PTR            ((reg8 *)    generadorPulsosPWM_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define generadorPulsosPWM_STATUS_MASK           (*(reg8 *)   generadorPulsosPWM_PWMUDB_genblk8_stsreg__MASK_REG)
    #define generadorPulsosPWM_STATUS_MASK_PTR       ((reg8 *)    generadorPulsosPWM_PWMUDB_genblk8_stsreg__MASK_REG)
    #define generadorPulsosPWM_STATUS_AUX_CTRL       (*(reg8 *)   generadorPulsosPWM_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define generadorPulsosPWM_CONTROL               (*(reg8 *)   generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define generadorPulsosPWM_CONTROL_PTR           ((reg8 *)    generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define generadorPulsosPWM_CTRL_ENABLE_SHIFT      (0x07u)
    #define generadorPulsosPWM_CTRL_RESET_SHIFT       (0x06u)
    #define generadorPulsosPWM_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define generadorPulsosPWM_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define generadorPulsosPWM_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define generadorPulsosPWM_CTRL_ENABLE            (uint8)((uint8)0x01u << generadorPulsosPWM_CTRL_ENABLE_SHIFT)
    #define generadorPulsosPWM_CTRL_RESET             (uint8)((uint8)0x01u << generadorPulsosPWM_CTRL_RESET_SHIFT)
    #define generadorPulsosPWM_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << generadorPulsosPWM_CTRL_CMPMODE2_SHIFT)
    #define generadorPulsosPWM_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << generadorPulsosPWM_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define generadorPulsosPWM_STATUS_KILL_SHIFT          (0x05u)
    #define generadorPulsosPWM_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define generadorPulsosPWM_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define generadorPulsosPWM_STATUS_TC_SHIFT            (0x02u)
    #define generadorPulsosPWM_STATUS_CMP2_SHIFT          (0x01u)
    #define generadorPulsosPWM_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define generadorPulsosPWM_STATUS_KILL_INT_EN_MASK_SHIFT          (generadorPulsosPWM_STATUS_KILL_SHIFT)
    #define generadorPulsosPWM_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (generadorPulsosPWM_STATUS_FIFONEMPTY_SHIFT)
    #define generadorPulsosPWM_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (generadorPulsosPWM_STATUS_FIFOFULL_SHIFT)
    #define generadorPulsosPWM_STATUS_TC_INT_EN_MASK_SHIFT            (generadorPulsosPWM_STATUS_TC_SHIFT)
    #define generadorPulsosPWM_STATUS_CMP2_INT_EN_MASK_SHIFT          (generadorPulsosPWM_STATUS_CMP2_SHIFT)
    #define generadorPulsosPWM_STATUS_CMP1_INT_EN_MASK_SHIFT          (generadorPulsosPWM_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define generadorPulsosPWM_STATUS_KILL            (uint8)((uint8)0x00u << generadorPulsosPWM_STATUS_KILL_SHIFT )
    #define generadorPulsosPWM_STATUS_FIFOFULL        (uint8)((uint8)0x01u << generadorPulsosPWM_STATUS_FIFOFULL_SHIFT)
    #define generadorPulsosPWM_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << generadorPulsosPWM_STATUS_FIFONEMPTY_SHIFT)
    #define generadorPulsosPWM_STATUS_TC              (uint8)((uint8)0x01u << generadorPulsosPWM_STATUS_TC_SHIFT)
    #define generadorPulsosPWM_STATUS_CMP2            (uint8)((uint8)0x01u << generadorPulsosPWM_STATUS_CMP2_SHIFT)
    #define generadorPulsosPWM_STATUS_CMP1            (uint8)((uint8)0x01u << generadorPulsosPWM_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define generadorPulsosPWM_STATUS_KILL_INT_EN_MASK            (generadorPulsosPWM_STATUS_KILL)
    #define generadorPulsosPWM_STATUS_FIFOFULL_INT_EN_MASK        (generadorPulsosPWM_STATUS_FIFOFULL)
    #define generadorPulsosPWM_STATUS_FIFONEMPTY_INT_EN_MASK      (generadorPulsosPWM_STATUS_FIFONEMPTY)
    #define generadorPulsosPWM_STATUS_TC_INT_EN_MASK              (generadorPulsosPWM_STATUS_TC)
    #define generadorPulsosPWM_STATUS_CMP2_INT_EN_MASK            (generadorPulsosPWM_STATUS_CMP2)
    #define generadorPulsosPWM_STATUS_CMP1_INT_EN_MASK            (generadorPulsosPWM_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define generadorPulsosPWM_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define generadorPulsosPWM_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define generadorPulsosPWM_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define generadorPulsosPWM_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define generadorPulsosPWM_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* generadorPulsosPWM_UsingFixedFunction */

#endif  /* CY_PWM_generadorPulsosPWM_H */


/* [] END OF FILE */
