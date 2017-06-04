/*******************************************************************************
* File Name: Pantalla_PM.c
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

#include "Pantalla.h"


static Pantalla_BACKUP_STRUCT Pantalla_backup;


/*******************************************************************************
* Function Name: Pantalla_SaveConfig
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
void Pantalla_SaveConfig(void) 
{
}


/*******************************************************************************
* Function Name: Pantalla_RestoreConfig
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
void Pantalla_RestoreConfig(void) 
{
}


/*******************************************************************************
* Function Name: Pantalla_Sleep
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
void Pantalla_Sleep(void) 
{
    Pantalla_backup.enableState = Pantalla_enableState;
    Pantalla_SaveConfig();
    Pantalla_Stop();
}


/*******************************************************************************
* Function Name: Pantalla_Wakeup
********************************************************************************
*
* Summary:
*  Wakes the component from sleep mode. Configures DMA and enables the component
*  for normal operation.
*
* Parameters:
*  Pantalla_enableState - Global variable.
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
void Pantalla_Wakeup(void) 
{
    Pantalla_RestoreConfig();

    if(Pantalla_backup.enableState == 1u)
    {
        Pantalla_Enable();
    }
}


/* [] END OF FILE */
