/*******************************************************************************
* File Name: convertidorAnalogicoDigital_PM.c
* Version 3.20
*
* Description:
*  This file provides the power manager source code to the API for the
*  Delta-Sigma ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "convertidorAnalogicoDigital.h"

static convertidorAnalogicoDigital_BACKUP_STRUCT convertidorAnalogicoDigital_backup =
{
    convertidorAnalogicoDigital_DISABLED,
    convertidorAnalogicoDigital_CFG1_DEC_CR
};


/*******************************************************************************
* Function Name: convertidorAnalogicoDigital_SaveConfig
********************************************************************************
*
* Summary:
*  Save the register configuration which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  convertidorAnalogicoDigital_backup:  This global structure variable is used to store
*  configuration registers which are non retention whenever user wants to go
*  sleep mode by calling Sleep() API.
*
*******************************************************************************/
void convertidorAnalogicoDigital_SaveConfig(void) 
{
    convertidorAnalogicoDigital_backup.deccr = convertidorAnalogicoDigital_DEC_CR_REG;
}


/*******************************************************************************
* Function Name: convertidorAnalogicoDigital_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  convertidorAnalogicoDigital_backup:  This global structure variable is used to restore
*  configuration registers which are non retention whenever user wants to switch
*  to active power mode by calling Wakeup() API.
*
*******************************************************************************/
void convertidorAnalogicoDigital_RestoreConfig(void) 
{
    convertidorAnalogicoDigital_DEC_CR_REG = convertidorAnalogicoDigital_backup.deccr;
}


/*******************************************************************************
* Function Name: convertidorAnalogicoDigital_Sleep
********************************************************************************
*
* Summary:
*  Stops the operation of the block and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  convertidorAnalogicoDigital_backup:  The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void convertidorAnalogicoDigital_Sleep(void) 
{
    /* Save ADC enable state */
    if((convertidorAnalogicoDigital_ACT_PWR_DEC_EN == (convertidorAnalogicoDigital_PWRMGR_DEC_REG & convertidorAnalogicoDigital_ACT_PWR_DEC_EN)) &&
       (convertidorAnalogicoDigital_ACT_PWR_DSM_EN == (convertidorAnalogicoDigital_PWRMGR_DSM_REG & convertidorAnalogicoDigital_ACT_PWR_DSM_EN)))
    {
        /* Component is enabled */
        convertidorAnalogicoDigital_backup.enableState = convertidorAnalogicoDigital_ENABLED;
        if((convertidorAnalogicoDigital_DEC_CR_REG & convertidorAnalogicoDigital_DEC_START_CONV) != 0u)
        {   
            /* Conversion is started */
            convertidorAnalogicoDigital_backup.enableState |= convertidorAnalogicoDigital_STARTED;
        }
		
        /* Stop the configuration */
        convertidorAnalogicoDigital_Stop();
    }
    else
    {
        /* Component is disabled */
        convertidorAnalogicoDigital_backup.enableState = convertidorAnalogicoDigital_DISABLED;
    }

    /* Save the user configuration */
    convertidorAnalogicoDigital_SaveConfig();
}


/*******************************************************************************
* Function Name: convertidorAnalogicoDigital_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and enables the power to the block.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  convertidorAnalogicoDigital_backup:  The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void convertidorAnalogicoDigital_Wakeup(void) 
{
    /* Restore the configuration */
    convertidorAnalogicoDigital_RestoreConfig();

    /* Enables the component operation */
    if(convertidorAnalogicoDigital_backup.enableState != convertidorAnalogicoDigital_DISABLED)
    {
        convertidorAnalogicoDigital_Enable();
        if((convertidorAnalogicoDigital_backup.enableState & convertidorAnalogicoDigital_STARTED) != 0u)
        {
            convertidorAnalogicoDigital_StartConvert();
        }
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
