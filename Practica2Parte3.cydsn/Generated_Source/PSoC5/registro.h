/*******************************************************************************
* File Name: registro.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_registro_H) /* CY_STATUS_REG_registro_H */
#define CY_STATUS_REG_registro_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} registro_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 registro_Read(void) ;
void registro_InterruptEnable(void) ;
void registro_InterruptDisable(void) ;
void registro_WriteMask(uint8 mask) ;
uint8 registro_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define registro_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define registro_INPUTS              8


/***************************************
*             Registers
***************************************/

/* Status Register */
#define registro_Status             (* (reg8 *) registro_sts_sts_reg__STATUS_REG )
#define registro_Status_PTR         (  (reg8 *) registro_sts_sts_reg__STATUS_REG )
#define registro_Status_Mask        (* (reg8 *) registro_sts_sts_reg__MASK_REG )
#define registro_Status_Aux_Ctrl    (* (reg8 *) registro_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_registro_H */


/* [] END OF FILE */
