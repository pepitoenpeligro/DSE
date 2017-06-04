/*******************************************************************************
* File Name: generadorPulsosPWM_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "generadorPulsosPWM.h"

static generadorPulsosPWM_backupStruct generadorPulsosPWM_backup;


/*******************************************************************************
* Function Name: generadorPulsosPWM_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  generadorPulsosPWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void generadorPulsosPWM_SaveConfig(void) 
{

    #if(!generadorPulsosPWM_UsingFixedFunction)
        #if(!generadorPulsosPWM_PWMModeIsCenterAligned)
            generadorPulsosPWM_backup.PWMPeriod = generadorPulsosPWM_ReadPeriod();
        #endif /* (!generadorPulsosPWM_PWMModeIsCenterAligned) */
        generadorPulsosPWM_backup.PWMUdb = generadorPulsosPWM_ReadCounter();
        #if (generadorPulsosPWM_UseStatus)
            generadorPulsosPWM_backup.InterruptMaskValue = generadorPulsosPWM_STATUS_MASK;
        #endif /* (generadorPulsosPWM_UseStatus) */

        #if(generadorPulsosPWM_DeadBandMode == generadorPulsosPWM__B_PWM__DBM_256_CLOCKS || \
            generadorPulsosPWM_DeadBandMode == generadorPulsosPWM__B_PWM__DBM_2_4_CLOCKS)
            generadorPulsosPWM_backup.PWMdeadBandValue = generadorPulsosPWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(generadorPulsosPWM_KillModeMinTime)
             generadorPulsosPWM_backup.PWMKillCounterPeriod = generadorPulsosPWM_ReadKillTime();
        #endif /* (generadorPulsosPWM_KillModeMinTime) */

        #if(generadorPulsosPWM_UseControl)
            generadorPulsosPWM_backup.PWMControlRegister = generadorPulsosPWM_ReadControlRegister();
        #endif /* (generadorPulsosPWM_UseControl) */
    #endif  /* (!generadorPulsosPWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: generadorPulsosPWM_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  generadorPulsosPWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void generadorPulsosPWM_RestoreConfig(void) 
{
        #if(!generadorPulsosPWM_UsingFixedFunction)
            #if(!generadorPulsosPWM_PWMModeIsCenterAligned)
                generadorPulsosPWM_WritePeriod(generadorPulsosPWM_backup.PWMPeriod);
            #endif /* (!generadorPulsosPWM_PWMModeIsCenterAligned) */

            generadorPulsosPWM_WriteCounter(generadorPulsosPWM_backup.PWMUdb);

            #if (generadorPulsosPWM_UseStatus)
                generadorPulsosPWM_STATUS_MASK = generadorPulsosPWM_backup.InterruptMaskValue;
            #endif /* (generadorPulsosPWM_UseStatus) */

            #if(generadorPulsosPWM_DeadBandMode == generadorPulsosPWM__B_PWM__DBM_256_CLOCKS || \
                generadorPulsosPWM_DeadBandMode == generadorPulsosPWM__B_PWM__DBM_2_4_CLOCKS)
                generadorPulsosPWM_WriteDeadTime(generadorPulsosPWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(generadorPulsosPWM_KillModeMinTime)
                generadorPulsosPWM_WriteKillTime(generadorPulsosPWM_backup.PWMKillCounterPeriod);
            #endif /* (generadorPulsosPWM_KillModeMinTime) */

            #if(generadorPulsosPWM_UseControl)
                generadorPulsosPWM_WriteControlRegister(generadorPulsosPWM_backup.PWMControlRegister);
            #endif /* (generadorPulsosPWM_UseControl) */
        #endif  /* (!generadorPulsosPWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: generadorPulsosPWM_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  generadorPulsosPWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void generadorPulsosPWM_Sleep(void) 
{
    #if(generadorPulsosPWM_UseControl)
        if(generadorPulsosPWM_CTRL_ENABLE == (generadorPulsosPWM_CONTROL & generadorPulsosPWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            generadorPulsosPWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            generadorPulsosPWM_backup.PWMEnableState = 0u;
        }
    #endif /* (generadorPulsosPWM_UseControl) */

    /* Stop component */
    generadorPulsosPWM_Stop();

    /* Save registers configuration */
    generadorPulsosPWM_SaveConfig();
}


/*******************************************************************************
* Function Name: generadorPulsosPWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  generadorPulsosPWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void generadorPulsosPWM_Wakeup(void) 
{
     /* Restore registers values */
    generadorPulsosPWM_RestoreConfig();

    if(generadorPulsosPWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        generadorPulsosPWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
