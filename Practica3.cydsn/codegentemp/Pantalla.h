/*******************************************************************************
* File Name: Pantalla.h
* Version 2.20
*
* Description:
*  This header file contains registers and constants associated with the
*  Character LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CHARLCD_Pantalla_H)
#define CY_CHARLCD_Pantalla_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Pantalla_CONVERSION_ROUTINES     (1u)
#define Pantalla_CUSTOM_CHAR_SET         (0u)

/* Custom character set types */
#define Pantalla_NONE                     (0u)    /* No Custom Fonts      */
#define Pantalla_HORIZONTAL_BG            (1u)    /* Horizontal Bar Graph */
#define Pantalla_VERTICAL_BG              (2u)    /* Vertical Bar Graph   */
#define Pantalla_USER_DEFINED             (3u)    /* User Defined Fonts   */


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} Pantalla_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void Pantalla_Init(void) ;
void Pantalla_Enable(void) ;
void Pantalla_Start(void) ;
void Pantalla_Stop(void) ;
void Pantalla_WriteControl(uint8 cByte) ;
void Pantalla_WriteData(uint8 dByte) ;
void Pantalla_PrintString(char8 const string[]) ;
void Pantalla_Position(uint8 row, uint8 column) ;
void Pantalla_PutChar(char8 character) ;
void Pantalla_IsReady(void) ;
void Pantalla_SaveConfig(void) ;
void Pantalla_RestoreConfig(void) ;
void Pantalla_Sleep(void) ;
void Pantalla_Wakeup(void) ;

#if((Pantalla_CUSTOM_CHAR_SET == Pantalla_VERTICAL_BG) || \
                (Pantalla_CUSTOM_CHAR_SET == Pantalla_HORIZONTAL_BG))

    void  Pantalla_LoadCustomFonts(uint8 const customData[])
                        ;

    void  Pantalla_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                         ;

    void Pantalla_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                        ;

#endif /* ((Pantalla_CUSTOM_CHAR_SET == Pantalla_VERTICAL_BG) */

#if(Pantalla_CUSTOM_CHAR_SET == Pantalla_USER_DEFINED)

    void Pantalla_LoadCustomFonts(uint8 const customData[])
                            ;

#endif /* ((Pantalla_CUSTOM_CHAR_SET == Pantalla_USER_DEFINED) */

#if(Pantalla_CONVERSION_ROUTINES == 1u)

    /* ASCII Conversion Routines */
    void Pantalla_PrintInt8(uint8 value) ;
    void Pantalla_PrintInt16(uint16 value) ;
    void Pantalla_PrintInt32(uint32 value) ;
    void Pantalla_PrintNumber(uint16 value) ; 
    void Pantalla_PrintU32Number(uint32 value) ;
    
#endif /* Pantalla_CONVERSION_ROUTINES == 1u */

/* Clear Macro */
#define Pantalla_ClearDisplay() Pantalla_WriteControl(Pantalla_CLEAR_DISPLAY)

/* Off Macro */
#define Pantalla_DisplayOff() Pantalla_WriteControl(Pantalla_DISPLAY_CURSOR_OFF)

/* On Macro */
#define Pantalla_DisplayOn() Pantalla_WriteControl(Pantalla_DISPLAY_ON_CURSOR_OFF)

#define Pantalla_PrintNumber(value) Pantalla_PrintU32Number((uint16) (value))


/***************************************
*           Global Variables
***************************************/

extern uint8 Pantalla_initVar;
extern uint8 Pantalla_enableState;
extern uint8 const CYCODE Pantalla_customFonts[64u];


/***************************************
*           API Constants
***************************************/

/* Full Byte Commands Sent as Two Nibbles */
#define Pantalla_DISPLAY_8_BIT_INIT       (0x03u)
#define Pantalla_DISPLAY_4_BIT_INIT       (0x02u)
#define Pantalla_DISPLAY_CURSOR_OFF       (0x08u)
#define Pantalla_CLEAR_DISPLAY            (0x01u)
#define Pantalla_CURSOR_AUTO_INCR_ON      (0x06u)
#define Pantalla_DISPLAY_CURSOR_ON        (0x0Eu)
#define Pantalla_DISPLAY_2_LINES_5x10     (0x2Cu)
#define Pantalla_DISPLAY_ON_CURSOR_OFF    (0x0Cu)

#define Pantalla_RESET_CURSOR_POSITION    (0x03u)
#define Pantalla_CURSOR_WINK              (0x0Du)
#define Pantalla_CURSOR_BLINK             (0x0Fu)
#define Pantalla_CURSOR_SH_LEFT           (0x10u)
#define Pantalla_CURSOR_SH_RIGHT          (0x14u)
#define Pantalla_DISPLAY_SCRL_LEFT        (0x18u)
#define Pantalla_DISPLAY_SCRL_RIGHT       (0x1Eu)
#define Pantalla_CURSOR_HOME              (0x02u)
#define Pantalla_CURSOR_LEFT              (0x04u)
#define Pantalla_CURSOR_RIGHT             (0x06u)

/* Point to Character Generator Ram 0 */
#define Pantalla_CGRAM_0                  (0x40u)

/* Point to Display Data Ram 0 */
#define Pantalla_DDRAM_0                  (0x80u)

/* LCD Characteristics */
#define Pantalla_CHARACTER_WIDTH          (0x05u)
#define Pantalla_CHARACTER_HEIGHT         (0x08u)

#if(Pantalla_CONVERSION_ROUTINES == 1u)
    #define Pantalla_NUMBER_OF_REMAINDERS_U32 (0x0Au)
    #define Pantalla_TEN                      (0x0Au)
    #define Pantalla_8_BIT_SHIFT              (8u)
    #define Pantalla_32_BIT_SHIFT             (32u)
    #define Pantalla_ZERO_CHAR_ASCII          (48u)
#endif /* Pantalla_CONVERSION_ROUTINES == 1u */

/* Nibble Offset and Mask */
#define Pantalla_NIBBLE_SHIFT             (0x04u)
#define Pantalla_NIBBLE_MASK              (0x0Fu)

/* LCD Module Address Constants */
#define Pantalla_ROW_0_START              (0x80u)
#define Pantalla_ROW_1_START              (0xC0u)
#define Pantalla_ROW_2_START              (0x94u)
#define Pantalla_ROW_3_START              (0xD4u)

/* Custom Character References */
#define Pantalla_CUSTOM_0                 (0x00u)
#define Pantalla_CUSTOM_1                 (0x01u)
#define Pantalla_CUSTOM_2                 (0x02u)
#define Pantalla_CUSTOM_3                 (0x03u)
#define Pantalla_CUSTOM_4                 (0x04u)
#define Pantalla_CUSTOM_5                 (0x05u)
#define Pantalla_CUSTOM_6                 (0x06u)
#define Pantalla_CUSTOM_7                 (0x07u)

/* Other constants */
#define Pantalla_BYTE_UPPER_NIBBLE_SHIFT  (0x04u)
#define Pantalla_BYTE_LOWER_NIBBLE_MASK   (0x0Fu)
#define Pantalla_U16_UPPER_BYTE_SHIFT     (0x08u)
#define Pantalla_U16_LOWER_BYTE_MASK      (0xFFu)
#define Pantalla_CUSTOM_CHAR_SET_LEN      (0x40u)

#define Pantalla_LONGEST_CMD_US           (0x651u)
#define Pantalla_WAIT_CYCLE               (0x10u)
#define Pantalla_READY_DELAY              ((Pantalla_LONGEST_CMD_US * 4u)/(Pantalla_WAIT_CYCLE))


/***************************************
*             Registers
***************************************/

/* Device specific registers */
#if (CY_PSOC4)

    #define Pantalla_PORT_DR_REG           (*(reg32 *) Pantalla_LCDPort__DR)  /* Data Output Register */
    #define Pantalla_PORT_DR_PTR           ( (reg32 *) Pantalla_LCDPort__DR)
    #define Pantalla_PORT_PS_REG           (*(reg32 *) Pantalla_LCDPort__PS)  /* Pin State Register */
    #define Pantalla_PORT_PS_PTR           ( (reg32 *) Pantalla_LCDPort__PS)
    
    #define Pantalla_PORT_PC_REG           (*(reg32 *) Pantalla_LCDPort__PC)
    #define Pantalla_PORT_PC_PTR           (*(reg32 *) Pantalla_LCDPort__PC)
    
#else

    #define Pantalla_PORT_DR_REG           (*(reg8 *) Pantalla_LCDPort__DR)  /* Data Output Register */
    #define Pantalla_PORT_DR_PTR           ( (reg8 *) Pantalla_LCDPort__DR)
    #define Pantalla_PORT_PS_REG           (*(reg8 *) Pantalla_LCDPort__PS)  /* Pin State Register */
    #define Pantalla_PORT_PS_PTR           ( (reg8 *) Pantalla_LCDPort__PS)

    #define Pantalla_PORT_DM0_REG          (*(reg8 *) Pantalla_LCDPort__DM0) /* Port Drive Mode 0 */
    #define Pantalla_PORT_DM0_PTR          ( (reg8 *) Pantalla_LCDPort__DM0)
    #define Pantalla_PORT_DM1_REG          (*(reg8 *) Pantalla_LCDPort__DM1) /* Port Drive Mode 1 */
    #define Pantalla_PORT_DM1_PTR          ( (reg8 *) Pantalla_LCDPort__DM1)
    #define Pantalla_PORT_DM2_REG          (*(reg8 *) Pantalla_LCDPort__DM2) /* Port Drive Mode 2 */
    #define Pantalla_PORT_DM2_PTR          ( (reg8 *) Pantalla_LCDPort__DM2)

#endif /* CY_PSOC4 */


/***************************************
*       Register Constants
***************************************/

/* SHIFT must be 1 or 0 */
#if (0 == Pantalla_LCDPort__SHIFT)
    #define Pantalla_PORT_SHIFT               (0x00u)
#else
    #define Pantalla_PORT_SHIFT               (0x01u)
#endif /* (0 == Pantalla_LCDPort__SHIFT) */

#define Pantalla_PORT_MASK                ((uint8) (Pantalla_LCDPort__MASK))

#if (CY_PSOC4)

    #define Pantalla_DM_PIN_STEP              (3u)
    /* Hi-Z Digital is defined by the value of "001b" and this should be set for
    * four data pins, in this way we get - 0x00000249. A similar Strong drive
    * is defined with "110b" so we get 0x00000DB6.
    */
    #define Pantalla_HIGH_Z_DATA_DM           ((0x00000249ul) << (Pantalla_PORT_SHIFT *\
                                                                          Pantalla_DM_PIN_STEP))
    #define Pantalla_STRONG_DATA_DM           ((0x00000DB6ul) << (Pantalla_PORT_SHIFT *\
                                                                          Pantalla_DM_PIN_STEP))
    #define Pantalla_DATA_PINS_MASK           (0x00000FFFul)
    #define Pantalla_DM_DATA_MASK             ((uint32) (Pantalla_DATA_PINS_MASK << \
                                                      (Pantalla_PORT_SHIFT * Pantalla_DM_PIN_STEP)))

#else

    /* Drive Mode register values for High Z */
    #define Pantalla_HIGH_Z_DM0               (0xFFu)
    #define Pantalla_HIGH_Z_DM1               (0x00u)
    #define Pantalla_HIGH_Z_DM2               (0x00u)

    /* Drive Mode register values for High Z Analog */
    #define Pantalla_HIGH_Z_A_DM0             (0x00u)
    #define Pantalla_HIGH_Z_A_DM1             (0x00u)
    #define Pantalla_HIGH_Z_A_DM2             (0x00u)

    /* Drive Mode register values for Strong */
    #define Pantalla_STRONG_DM0               (0x00u)
    #define Pantalla_STRONG_DM1               (0xFFu)
    #define Pantalla_STRONG_DM2               (0xFFu)

#endif /* CY_PSOC4 */

/* Pin Masks */
#define Pantalla_RS                     ((uint8) \
                                                (((uint8) 0x20u) << Pantalla_LCDPort__SHIFT))
#define Pantalla_RW                     ((uint8) \
                                                (((uint8) 0x40u) << Pantalla_LCDPort__SHIFT))
#define Pantalla_E                      ((uint8) \
                                                (((uint8) 0x10u) << Pantalla_LCDPort__SHIFT))
#define Pantalla_READY_BIT              ((uint8) \
                                                (((uint8) 0x08u) << Pantalla_LCDPort__SHIFT))
#define Pantalla_DATA_MASK              ((uint8) \
                                                (((uint8) 0x0Fu) << Pantalla_LCDPort__SHIFT))

/* These names are obsolete and will be removed in future revisions */
#define Pantalla_PORT_DR                  Pantalla_PORT_DR_REG
#define Pantalla_PORT_PS                  Pantalla_PORT_PS_REG
#define Pantalla_PORT_DM0                 Pantalla_PORT_DM0_REG
#define Pantalla_PORT_DM1                 Pantalla_PORT_DM1_REG
#define Pantalla_PORT_DM2                 Pantalla_PORT_DM2_REG


/***************************************
*       Obsolete function names
***************************************/
#if(Pantalla_CONVERSION_ROUTINES == 1u)
    /* This function names are obsolete and will be removed in future 
    * revisions of the component.
    */
    #define Pantalla_PrintDecUint16(x)   Pantalla_PrintNumber(x)  
    #define Pantalla_PrintHexUint8(x)    Pantalla_PrintInt8(x)
    #define Pantalla_PrintHexUint16(x)   Pantalla_PrintInt16(x)        

#endif /* Pantalla_CONVERSION_ROUTINES == 1u */

#endif /* CY_CHARLCD_Pantalla_H */


/* [] END OF FILE */
