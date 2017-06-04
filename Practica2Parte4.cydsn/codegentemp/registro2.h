/*******************************************************************************
* File Name: registro2.h  
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

#if !defined(CY_STATUS_REG_registro2_H) /* CY_STATUS_REG_registro2_H */
#define CY_STATUS_REG_registro2_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} registro2_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 registro2_Read(void) ;
void registro2_InterruptEnable(void) ;
void registro2_InterruptDisable(void) ;
void registro2_WriteMask(uint8 mask) ;
uint8 registro2_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define registro2_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define registro2_INPUTS              4


/***************************************
*             Registers
***************************************/

/* Status Register */
#define registro2_Status             (* (reg8 *) registro2_sts_sts_reg__STATUS_REG )
#define registro2_Status_PTR         (  (reg8 *) registro2_sts_sts_reg__STATUS_REG )
#define registro2_Status_Mask        (* (reg8 *) registro2_sts_sts_reg__MASK_REG )
#define registro2_Status_Aux_Ctrl    (* (reg8 *) registro2_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_registro2_H */


/* [] END OF FILE */
