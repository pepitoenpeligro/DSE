/*******************************************************************************
* File Name: registro.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_registro_H) /* CY_CONTROL_REG_registro_H */
#define CY_CONTROL_REG_registro_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} registro_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    registro_Write(uint8 control) ;
uint8   registro_Read(void) ;

void registro_SaveConfig(void) ;
void registro_RestoreConfig(void) ;
void registro_Sleep(void) ; 
void registro_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define registro_Control        (* (reg8 *) registro_Sync_ctrl_reg__CONTROL_REG )
#define registro_Control_PTR    (  (reg8 *) registro_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_registro_H */


/* [] END OF FILE */
