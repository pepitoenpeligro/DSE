/*******************************************************************************
* File Name: generadorOnda.h  
* Version 2.0
*
* Description:
*  This file contains the function prototypes and constants used in
*  the 8-bit Waveform DAC (WaveDAC8) Component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_WaveDAC8_generadorOnda_H) 
#define CY_WaveDAC8_generadorOnda_H

#include "cytypes.h"
#include "cyfitter.h"
#include <generadorOnda_Wave1_DMA_dma.h>
#include <generadorOnda_Wave2_DMA_dma.h>
#include <generadorOnda_VDAC8.h>


/***************************************
*  Initial Parameter Constants
***************************************/

#define generadorOnda_WAVE1_TYPE     (0u)     /* Waveform for wave1 */
#define generadorOnda_WAVE2_TYPE     (2u)     /* Waveform for wave2 */
#define generadorOnda_SINE_WAVE      (0u)
#define generadorOnda_SQUARE_WAVE    (1u)
#define generadorOnda_TRIANGLE_WAVE  (2u)
#define generadorOnda_SAWTOOTH_WAVE  (3u)
#define generadorOnda_ARB_DRAW_WAVE  (10u) /* Arbitrary (draw) */
#define generadorOnda_ARB_FILE_WAVE  (11u) /* Arbitrary (from file) */

#define generadorOnda_WAVE1_LENGTH   (4000u)   /* Length for wave1 */
#define generadorOnda_WAVE2_LENGTH   (100u)   /* Length for wave2 */
	
#define generadorOnda_DEFAULT_RANGE    (1u) /* Default DAC range */
#define generadorOnda_DAC_RANGE_1V     (0u)
#define generadorOnda_DAC_RANGE_1V_BUF (16u)
#define generadorOnda_DAC_RANGE_4V     (1u)
#define generadorOnda_DAC_RANGE_4V_BUF (17u)
#define generadorOnda_VOLT_MODE        (0u)
#define generadorOnda_CURRENT_MODE     (1u)
#define generadorOnda_DAC_MODE         (((generadorOnda_DEFAULT_RANGE == generadorOnda_DAC_RANGE_1V) || \
									  (generadorOnda_DEFAULT_RANGE == generadorOnda_DAC_RANGE_4V) || \
							  		  (generadorOnda_DEFAULT_RANGE == generadorOnda_DAC_RANGE_1V_BUF) || \
									  (generadorOnda_DEFAULT_RANGE == generadorOnda_DAC_RANGE_4V_BUF)) ? \
									   generadorOnda_VOLT_MODE : generadorOnda_CURRENT_MODE)

#define generadorOnda_DACMODE generadorOnda_DAC_MODE /* legacy definition for backward compatibility */

#define generadorOnda_DIRECT_MODE (0u)
#define generadorOnda_BUFFER_MODE (1u)
#define generadorOnda_OUT_MODE    (((generadorOnda_DEFAULT_RANGE == generadorOnda_DAC_RANGE_1V_BUF) || \
								 (generadorOnda_DEFAULT_RANGE == generadorOnda_DAC_RANGE_4V_BUF)) ? \
								  generadorOnda_BUFFER_MODE : generadorOnda_DIRECT_MODE)

#if(generadorOnda_OUT_MODE == generadorOnda_BUFFER_MODE)
    #include <generadorOnda_BuffAmp.h>
#endif /* generadorOnda_OUT_MODE == generadorOnda_BUFFER_MODE */

#define generadorOnda_CLOCK_INT      (1u)
#define generadorOnda_CLOCK_EXT      (0u)
#define generadorOnda_CLOCK_SRC      (0u)

#if(generadorOnda_CLOCK_SRC == generadorOnda_CLOCK_INT)  
	#include <generadorOnda_DacClk.h>
	#if defined(generadorOnda_DacClk_PHASE)
		#define generadorOnda_CLK_PHASE_0nS (1u)
	#endif /* defined(generadorOnda_DacClk_PHASE) */
#endif /* generadorOnda_CLOCK_SRC == generadorOnda_CLOCK_INT */

#if (CY_PSOC3)
	#define generadorOnda_HI16FLASHPTR   (0xFFu)
#endif /* CY_PSOC3 */

#define generadorOnda_Wave1_DMA_BYTES_PER_BURST      (1u)
#define generadorOnda_Wave1_DMA_REQUEST_PER_BURST    (1u)
#define generadorOnda_Wave2_DMA_BYTES_PER_BURST      (1u)
#define generadorOnda_Wave2_DMA_REQUEST_PER_BURST    (1u)


/***************************************
*   Data Struct Definition
***************************************/

/* Low power Mode API Support */
typedef struct
{
	uint8   enableState;
}generadorOnda_BACKUP_STRUCT;


/***************************************
*        Function Prototypes 
***************************************/

void generadorOnda_Start(void)             ;
void generadorOnda_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)
                                        ;
void generadorOnda_Init(void)              ;
void generadorOnda_Enable(void)            ;
void generadorOnda_Stop(void)              ;

void generadorOnda_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;
void generadorOnda_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;

void generadorOnda_Sleep(void)             ;
void generadorOnda_Wakeup(void)            ;

#define generadorOnda_SetSpeed(speed)      generadorOnda_VDAC8_SetSpeed(speed)
#define generadorOnda_SetRange(range)      generadorOnda_VDAC8_SetRange(range)
#define generadorOnda_SetValue(value)      generadorOnda_VDAC8_SetValue(value)
#define generadorOnda_DacTrim(void)        generadorOnda_VDAC8_DacTrim()
#define generadorOnda_SaveConfig(void)     generadorOnda_VDAC8_SaveConfig()
#define generadorOnda_RestoreConfig(void)  generadorOnda_VDAC8_RestoreConfig()


/***************************************
*    Variable with external linkage 
***************************************/

extern uint8 generadorOnda_initVar;

extern const uint8 CYCODE generadorOnda_wave1[generadorOnda_WAVE1_LENGTH];
extern const uint8 CYCODE generadorOnda_wave2[generadorOnda_WAVE2_LENGTH];


/***************************************
*            API Constants
***************************************/

/* SetRange constants */
#if(generadorOnda_DAC_MODE == generadorOnda_VOLT_MODE)
    #define generadorOnda_RANGE_1V       (0x00u)
    #define generadorOnda_RANGE_4V       (0x04u)
#else /* current mode */
    #define generadorOnda_RANGE_32uA     (0x00u)
    #define generadorOnda_RANGE_255uA    (0x04u)
    #define generadorOnda_RANGE_2mA      (0x08u)
    #define generadorOnda_RANGE_2048uA   generadorOnda_RANGE_2mA
#endif /* generadorOnda_DAC_MODE == generadorOnda_VOLT_MODE */

/* Power setting for SetSpeed API */
#define generadorOnda_LOWSPEED       (0x00u)
#define generadorOnda_HIGHSPEED      (0x02u)


/***************************************
*              Registers        
***************************************/

#define generadorOnda_DAC8__D generadorOnda_VDAC8_viDAC8__D


/***************************************
*         Register Constants       
***************************************/

/* CR0 vDac Control Register 0 definitions */

/* Bit Field  DAC_HS_MODE */
#define generadorOnda_HS_MASK        (0x02u)
#define generadorOnda_HS_LOWPOWER    (0x00u)
#define generadorOnda_HS_HIGHSPEED   (0x02u)

/* Bit Field  DAC_MODE */
#define generadorOnda_MODE_MASK      (0x10u)
#define generadorOnda_MODE_V         (0x00u)
#define generadorOnda_MODE_I         (0x10u)

/* Bit Field  DAC_RANGE */
#define generadorOnda_RANGE_MASK     (0x0Cu)
#define generadorOnda_RANGE_0        (0x00u)
#define generadorOnda_RANGE_1        (0x04u)
#define generadorOnda_RANGE_2        (0x08u)
#define generadorOnda_RANGE_3        (0x0Cu)
#define generadorOnda_IDIR_MASK      (0x04u)

#define generadorOnda_DAC_RANGE      ((uint8)(1u << 2u) & generadorOnda_RANGE_MASK)
#define generadorOnda_DAC_POL        ((uint8)(1u >> 1u) & generadorOnda_IDIR_MASK)


#endif /* CY_WaveDAC8_generadorOnda_H  */

/* [] END OF FILE */
