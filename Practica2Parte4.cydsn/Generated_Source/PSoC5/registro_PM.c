/*******************************************************************************
* File Name: registro_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "registro.h"

/* Check for removal by optimization */
#if !defined(registro_Sync_ctrl_reg__REMOVED)

static registro_BACKUP_STRUCT  registro_backup = {0u};

    
/*******************************************************************************
* Function Name: registro_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void registro_SaveConfig(void) 
{
    registro_backup.controlState = registro_Control;
}


/*******************************************************************************
* Function Name: registro_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void registro_RestoreConfig(void) 
{
     registro_Control = registro_backup.controlState;
}


/*******************************************************************************
* Function Name: registro_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void registro_Sleep(void) 
{
    registro_SaveConfig();
}


/*******************************************************************************
* Function Name: registro_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void registro_Wakeup(void)  
{
    registro_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
