/*******************************************************************************
* File Name: pantalla_PM.c
* Version 2.20
*
* Description:
*  This file provides the API source code for the Static Segment LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "pantalla.h"


static pantalla_BACKUP_STRUCT pantalla_backup;


/*******************************************************************************
* Function Name: pantalla_SaveConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void pantalla_SaveConfig(void) 
{
}


/*******************************************************************************
* Function Name: pantalla_RestoreConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void pantalla_RestoreConfig(void) 
{
}


/*******************************************************************************
* Function Name: pantalla_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void pantalla_Sleep(void) 
{
    pantalla_backup.enableState = pantalla_enableState;
    pantalla_SaveConfig();
    pantalla_Stop();
}


/*******************************************************************************
* Function Name: pantalla_Wakeup
********************************************************************************
*
* Summary:
*  Wakes the component from sleep mode. Configures DMA and enables the component
*  for normal operation.
*
* Parameters:
*  pantalla_enableState - Global variable.
*
* Return:
*  Status one of standard status for PSoC3 Component
*       CYRET_SUCCESS - Function completed successfully.
*       CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                      a channel already in use.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void pantalla_Wakeup(void) 
{
    pantalla_RestoreConfig();

    if(pantalla_backup.enableState == 1u)
    {
        pantalla_Enable();
    }
}


/* [] END OF FILE */
