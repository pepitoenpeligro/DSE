/*******************************************************************************
* File Name: pantallaLCD_PM.c
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

#include "pantallaLCD.h"


static pantallaLCD_BACKUP_STRUCT pantallaLCD_backup;


/*******************************************************************************
* Function Name: pantallaLCD_SaveConfig
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
void pantallaLCD_SaveConfig(void) 
{
}


/*******************************************************************************
* Function Name: pantallaLCD_RestoreConfig
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
void pantallaLCD_RestoreConfig(void) 
{
}


/*******************************************************************************
* Function Name: pantallaLCD_Sleep
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
void pantallaLCD_Sleep(void) 
{
    pantallaLCD_backup.enableState = pantallaLCD_enableState;
    pantallaLCD_SaveConfig();
    pantallaLCD_Stop();
}


/*******************************************************************************
* Function Name: pantallaLCD_Wakeup
********************************************************************************
*
* Summary:
*  Wakes the component from sleep mode. Configures DMA and enables the component
*  for normal operation.
*
* Parameters:
*  pantallaLCD_enableState - Global variable.
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
void pantallaLCD_Wakeup(void) 
{
    pantallaLCD_RestoreConfig();

    if(pantallaLCD_backup.enableState == 1u)
    {
        pantallaLCD_Enable();
    }
}


/* [] END OF FILE */
