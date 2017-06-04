/*******************************************************************************
* File Name: convertidorAnalogicoDigital_AMux.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_convertidorAnalogicoDigital_AMux_H)
#define CY_AMUX_convertidorAnalogicoDigital_AMux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void convertidorAnalogicoDigital_AMux_Start(void) ;
#define convertidorAnalogicoDigital_AMux_Init() convertidorAnalogicoDigital_AMux_Start()
void convertidorAnalogicoDigital_AMux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void convertidorAnalogicoDigital_AMux_Stop(void); */
/* void convertidorAnalogicoDigital_AMux_Select(uint8 channel); */
/* void convertidorAnalogicoDigital_AMux_Connect(uint8 channel); */
/* void convertidorAnalogicoDigital_AMux_Disconnect(uint8 channel); */
/* void convertidorAnalogicoDigital_AMux_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define convertidorAnalogicoDigital_AMux_CHANNELS  2u
#define convertidorAnalogicoDigital_AMux_MUXTYPE   1
#define convertidorAnalogicoDigital_AMux_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define convertidorAnalogicoDigital_AMux_NULL_CHANNEL 0xFFu
#define convertidorAnalogicoDigital_AMux_MUX_SINGLE   1
#define convertidorAnalogicoDigital_AMux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if convertidorAnalogicoDigital_AMux_MUXTYPE == convertidorAnalogicoDigital_AMux_MUX_SINGLE
# if !convertidorAnalogicoDigital_AMux_ATMOSTONE
#  define convertidorAnalogicoDigital_AMux_Connect(channel) convertidorAnalogicoDigital_AMux_Set(channel)
# endif
# define convertidorAnalogicoDigital_AMux_Disconnect(channel) convertidorAnalogicoDigital_AMux_Unset(channel)
#else
# if !convertidorAnalogicoDigital_AMux_ATMOSTONE
void convertidorAnalogicoDigital_AMux_Connect(uint8 channel) ;
# endif
void convertidorAnalogicoDigital_AMux_Disconnect(uint8 channel) ;
#endif

#if convertidorAnalogicoDigital_AMux_ATMOSTONE
# define convertidorAnalogicoDigital_AMux_Stop() convertidorAnalogicoDigital_AMux_DisconnectAll()
# define convertidorAnalogicoDigital_AMux_Select(channel) convertidorAnalogicoDigital_AMux_FastSelect(channel)
void convertidorAnalogicoDigital_AMux_DisconnectAll(void) ;
#else
# define convertidorAnalogicoDigital_AMux_Stop() convertidorAnalogicoDigital_AMux_Start()
void convertidorAnalogicoDigital_AMux_Select(uint8 channel) ;
# define convertidorAnalogicoDigital_AMux_DisconnectAll() convertidorAnalogicoDigital_AMux_Start()
#endif

#endif /* CY_AMUX_convertidorAnalogicoDigital_AMux_H */


/* [] END OF FILE */
