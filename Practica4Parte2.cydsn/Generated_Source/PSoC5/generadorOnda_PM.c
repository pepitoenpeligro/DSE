/*******************************************************************************
* File Name: generadorOnda_PM.c  
* Version 2.0
*
* Description:
*  This file provides the power manager source code to the API for 
*  the WaveDAC8 component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "generadorOnda.h"

static generadorOnda_BACKUP_STRUCT  generadorOnda_backup;


/*******************************************************************************
* Function Name: generadorOnda_Sleep
********************************************************************************
*
* Summary:
*  Stops the component and saves its configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  generadorOnda_backup:  The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void generadorOnda_Sleep(void) 
{
	/* Save DAC8's enable state */

	generadorOnda_backup.enableState = (generadorOnda_VDAC8_ACT_PWR_EN == 
		(generadorOnda_VDAC8_PWRMGR_REG & generadorOnda_VDAC8_ACT_PWR_EN)) ? 1u : 0u ;
	
	generadorOnda_Stop();
	generadorOnda_SaveConfig();
}


/*******************************************************************************
* Function Name: generadorOnda_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component configuration. Should be called
*  just after awaking from sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  void
*
* Global variables:
*  generadorOnda_backup:  The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void generadorOnda_Wakeup(void) 
{
	generadorOnda_RestoreConfig();

	if(generadorOnda_backup.enableState == 1u)
	{
		generadorOnda_Enable();
	}
}


/* [] END OF FILE */
