/*******************************************************************************
* File Name: pantallaLCD.h
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

#if !defined(CY_CHARLCD_pantallaLCD_H)
#define CY_CHARLCD_pantallaLCD_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define pantallaLCD_CONVERSION_ROUTINES     (1u)
#define pantallaLCD_CUSTOM_CHAR_SET         (0u)

/* Custom character set types */
#define pantallaLCD_NONE                     (0u)    /* No Custom Fonts      */
#define pantallaLCD_HORIZONTAL_BG            (1u)    /* Horizontal Bar Graph */
#define pantallaLCD_VERTICAL_BG              (2u)    /* Vertical Bar Graph   */
#define pantallaLCD_USER_DEFINED             (3u)    /* User Defined Fonts   */


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} pantallaLCD_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void pantallaLCD_Init(void) ;
void pantallaLCD_Enable(void) ;
void pantallaLCD_Start(void) ;
void pantallaLCD_Stop(void) ;
void pantallaLCD_WriteControl(uint8 cByte) ;
void pantallaLCD_WriteData(uint8 dByte) ;
void pantallaLCD_PrintString(char8 const string[]) ;
void pantallaLCD_Position(uint8 row, uint8 column) ;
void pantallaLCD_PutChar(char8 character) ;
void pantallaLCD_IsReady(void) ;
void pantallaLCD_SaveConfig(void) ;
void pantallaLCD_RestoreConfig(void) ;
void pantallaLCD_Sleep(void) ;
void pantallaLCD_Wakeup(void) ;

#if((pantallaLCD_CUSTOM_CHAR_SET == pantallaLCD_VERTICAL_BG) || \
                (pantallaLCD_CUSTOM_CHAR_SET == pantallaLCD_HORIZONTAL_BG))

    void  pantallaLCD_LoadCustomFonts(uint8 const customData[])
                        ;

    void  pantallaLCD_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                         ;

    void pantallaLCD_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                        ;

#endif /* ((pantallaLCD_CUSTOM_CHAR_SET == pantallaLCD_VERTICAL_BG) */

#if(pantallaLCD_CUSTOM_CHAR_SET == pantallaLCD_USER_DEFINED)

    void pantallaLCD_LoadCustomFonts(uint8 const customData[])
                            ;

#endif /* ((pantallaLCD_CUSTOM_CHAR_SET == pantallaLCD_USER_DEFINED) */

#if(pantallaLCD_CONVERSION_ROUTINES == 1u)

    /* ASCII Conversion Routines */
    void pantallaLCD_PrintInt8(uint8 value) ;
    void pantallaLCD_PrintInt16(uint16 value) ;
    void pantallaLCD_PrintInt32(uint32 value) ;
    void pantallaLCD_PrintNumber(uint16 value) ; 
    void pantallaLCD_PrintU32Number(uint32 value) ;
    
#endif /* pantallaLCD_CONVERSION_ROUTINES == 1u */

/* Clear Macro */
#define pantallaLCD_ClearDisplay() pantallaLCD_WriteControl(pantallaLCD_CLEAR_DISPLAY)

/* Off Macro */
#define pantallaLCD_DisplayOff() pantallaLCD_WriteControl(pantallaLCD_DISPLAY_CURSOR_OFF)

/* On Macro */
#define pantallaLCD_DisplayOn() pantallaLCD_WriteControl(pantallaLCD_DISPLAY_ON_CURSOR_OFF)

#define pantallaLCD_PrintNumber(value) pantallaLCD_PrintU32Number((uint16) (value))


/***************************************
*           Global Variables
***************************************/

extern uint8 pantallaLCD_initVar;
extern uint8 pantallaLCD_enableState;
extern uint8 const CYCODE pantallaLCD_customFonts[64u];


/***************************************
*           API Constants
***************************************/

/* Full Byte Commands Sent as Two Nibbles */
#define pantallaLCD_DISPLAY_8_BIT_INIT       (0x03u)
#define pantallaLCD_DISPLAY_4_BIT_INIT       (0x02u)
#define pantallaLCD_DISPLAY_CURSOR_OFF       (0x08u)
#define pantallaLCD_CLEAR_DISPLAY            (0x01u)
#define pantallaLCD_CURSOR_AUTO_INCR_ON      (0x06u)
#define pantallaLCD_DISPLAY_CURSOR_ON        (0x0Eu)
#define pantallaLCD_DISPLAY_2_LINES_5x10     (0x2Cu)
#define pantallaLCD_DISPLAY_ON_CURSOR_OFF    (0x0Cu)

#define pantallaLCD_RESET_CURSOR_POSITION    (0x03u)
#define pantallaLCD_CURSOR_WINK              (0x0Du)
#define pantallaLCD_CURSOR_BLINK             (0x0Fu)
#define pantallaLCD_CURSOR_SH_LEFT           (0x10u)
#define pantallaLCD_CURSOR_SH_RIGHT          (0x14u)
#define pantallaLCD_DISPLAY_SCRL_LEFT        (0x18u)
#define pantallaLCD_DISPLAY_SCRL_RIGHT       (0x1Eu)
#define pantallaLCD_CURSOR_HOME              (0x02u)
#define pantallaLCD_CURSOR_LEFT              (0x04u)
#define pantallaLCD_CURSOR_RIGHT             (0x06u)

/* Point to Character Generator Ram 0 */
#define pantallaLCD_CGRAM_0                  (0x40u)

/* Point to Display Data Ram 0 */
#define pantallaLCD_DDRAM_0                  (0x80u)

/* LCD Characteristics */
#define pantallaLCD_CHARACTER_WIDTH          (0x05u)
#define pantallaLCD_CHARACTER_HEIGHT         (0x08u)

#if(pantallaLCD_CONVERSION_ROUTINES == 1u)
    #define pantallaLCD_NUMBER_OF_REMAINDERS_U32 (0x0Au)
    #define pantallaLCD_TEN                      (0x0Au)
    #define pantallaLCD_8_BIT_SHIFT              (8u)
    #define pantallaLCD_32_BIT_SHIFT             (32u)
    #define pantallaLCD_ZERO_CHAR_ASCII          (48u)
#endif /* pantallaLCD_CONVERSION_ROUTINES == 1u */

/* Nibble Offset and Mask */
#define pantallaLCD_NIBBLE_SHIFT             (0x04u)
#define pantallaLCD_NIBBLE_MASK              (0x0Fu)

/* LCD Module Address Constants */
#define pantallaLCD_ROW_0_START              (0x80u)
#define pantallaLCD_ROW_1_START              (0xC0u)
#define pantallaLCD_ROW_2_START              (0x94u)
#define pantallaLCD_ROW_3_START              (0xD4u)

/* Custom Character References */
#define pantallaLCD_CUSTOM_0                 (0x00u)
#define pantallaLCD_CUSTOM_1                 (0x01u)
#define pantallaLCD_CUSTOM_2                 (0x02u)
#define pantallaLCD_CUSTOM_3                 (0x03u)
#define pantallaLCD_CUSTOM_4                 (0x04u)
#define pantallaLCD_CUSTOM_5                 (0x05u)
#define pantallaLCD_CUSTOM_6                 (0x06u)
#define pantallaLCD_CUSTOM_7                 (0x07u)

/* Other constants */
#define pantallaLCD_BYTE_UPPER_NIBBLE_SHIFT  (0x04u)
#define pantallaLCD_BYTE_LOWER_NIBBLE_MASK   (0x0Fu)
#define pantallaLCD_U16_UPPER_BYTE_SHIFT     (0x08u)
#define pantallaLCD_U16_LOWER_BYTE_MASK      (0xFFu)
#define pantallaLCD_CUSTOM_CHAR_SET_LEN      (0x40u)

#define pantallaLCD_LONGEST_CMD_US           (0x651u)
#define pantallaLCD_WAIT_CYCLE               (0x10u)
#define pantallaLCD_READY_DELAY              ((pantallaLCD_LONGEST_CMD_US * 4u)/(pantallaLCD_WAIT_CYCLE))


/***************************************
*             Registers
***************************************/

/* Device specific registers */
#if (CY_PSOC4)

    #define pantallaLCD_PORT_DR_REG           (*(reg32 *) pantallaLCD_LCDPort__DR)  /* Data Output Register */
    #define pantallaLCD_PORT_DR_PTR           ( (reg32 *) pantallaLCD_LCDPort__DR)
    #define pantallaLCD_PORT_PS_REG           (*(reg32 *) pantallaLCD_LCDPort__PS)  /* Pin State Register */
    #define pantallaLCD_PORT_PS_PTR           ( (reg32 *) pantallaLCD_LCDPort__PS)
    
    #define pantallaLCD_PORT_PC_REG           (*(reg32 *) pantallaLCD_LCDPort__PC)
    #define pantallaLCD_PORT_PC_PTR           (*(reg32 *) pantallaLCD_LCDPort__PC)
    
#else

    #define pantallaLCD_PORT_DR_REG           (*(reg8 *) pantallaLCD_LCDPort__DR)  /* Data Output Register */
    #define pantallaLCD_PORT_DR_PTR           ( (reg8 *) pantallaLCD_LCDPort__DR)
    #define pantallaLCD_PORT_PS_REG           (*(reg8 *) pantallaLCD_LCDPort__PS)  /* Pin State Register */
    #define pantallaLCD_PORT_PS_PTR           ( (reg8 *) pantallaLCD_LCDPort__PS)

    #define pantallaLCD_PORT_DM0_REG          (*(reg8 *) pantallaLCD_LCDPort__DM0) /* Port Drive Mode 0 */
    #define pantallaLCD_PORT_DM0_PTR          ( (reg8 *) pantallaLCD_LCDPort__DM0)
    #define pantallaLCD_PORT_DM1_REG          (*(reg8 *) pantallaLCD_LCDPort__DM1) /* Port Drive Mode 1 */
    #define pantallaLCD_PORT_DM1_PTR          ( (reg8 *) pantallaLCD_LCDPort__DM1)
    #define pantallaLCD_PORT_DM2_REG          (*(reg8 *) pantallaLCD_LCDPort__DM2) /* Port Drive Mode 2 */
    #define pantallaLCD_PORT_DM2_PTR          ( (reg8 *) pantallaLCD_LCDPort__DM2)

#endif /* CY_PSOC4 */


/***************************************
*       Register Constants
***************************************/

/* SHIFT must be 1 or 0 */
#if (0 == pantallaLCD_LCDPort__SHIFT)
    #define pantallaLCD_PORT_SHIFT               (0x00u)
#else
    #define pantallaLCD_PORT_SHIFT               (0x01u)
#endif /* (0 == pantallaLCD_LCDPort__SHIFT) */

#define pantallaLCD_PORT_MASK                ((uint8) (pantallaLCD_LCDPort__MASK))

#if (CY_PSOC4)

    #define pantallaLCD_DM_PIN_STEP              (3u)
    /* Hi-Z Digital is defined by the value of "001b" and this should be set for
    * four data pins, in this way we get - 0x00000249. A similar Strong drive
    * is defined with "110b" so we get 0x00000DB6.
    */
    #define pantallaLCD_HIGH_Z_DATA_DM           ((0x00000249ul) << (pantallaLCD_PORT_SHIFT *\
                                                                          pantallaLCD_DM_PIN_STEP))
    #define pantallaLCD_STRONG_DATA_DM           ((0x00000DB6ul) << (pantallaLCD_PORT_SHIFT *\
                                                                          pantallaLCD_DM_PIN_STEP))
    #define pantallaLCD_DATA_PINS_MASK           (0x00000FFFul)
    #define pantallaLCD_DM_DATA_MASK             ((uint32) (pantallaLCD_DATA_PINS_MASK << \
                                                      (pantallaLCD_PORT_SHIFT * pantallaLCD_DM_PIN_STEP)))

#else

    /* Drive Mode register values for High Z */
    #define pantallaLCD_HIGH_Z_DM0               (0xFFu)
    #define pantallaLCD_HIGH_Z_DM1               (0x00u)
    #define pantallaLCD_HIGH_Z_DM2               (0x00u)

    /* Drive Mode register values for High Z Analog */
    #define pantallaLCD_HIGH_Z_A_DM0             (0x00u)
    #define pantallaLCD_HIGH_Z_A_DM1             (0x00u)
    #define pantallaLCD_HIGH_Z_A_DM2             (0x00u)

    /* Drive Mode register values for Strong */
    #define pantallaLCD_STRONG_DM0               (0x00u)
    #define pantallaLCD_STRONG_DM1               (0xFFu)
    #define pantallaLCD_STRONG_DM2               (0xFFu)

#endif /* CY_PSOC4 */

/* Pin Masks */
#define pantallaLCD_RS                     ((uint8) \
                                                (((uint8) 0x20u) << pantallaLCD_LCDPort__SHIFT))
#define pantallaLCD_RW                     ((uint8) \
                                                (((uint8) 0x40u) << pantallaLCD_LCDPort__SHIFT))
#define pantallaLCD_E                      ((uint8) \
                                                (((uint8) 0x10u) << pantallaLCD_LCDPort__SHIFT))
#define pantallaLCD_READY_BIT              ((uint8) \
                                                (((uint8) 0x08u) << pantallaLCD_LCDPort__SHIFT))
#define pantallaLCD_DATA_MASK              ((uint8) \
                                                (((uint8) 0x0Fu) << pantallaLCD_LCDPort__SHIFT))

/* These names are obsolete and will be removed in future revisions */
#define pantallaLCD_PORT_DR                  pantallaLCD_PORT_DR_REG
#define pantallaLCD_PORT_PS                  pantallaLCD_PORT_PS_REG
#define pantallaLCD_PORT_DM0                 pantallaLCD_PORT_DM0_REG
#define pantallaLCD_PORT_DM1                 pantallaLCD_PORT_DM1_REG
#define pantallaLCD_PORT_DM2                 pantallaLCD_PORT_DM2_REG


/***************************************
*       Obsolete function names
***************************************/
#if(pantallaLCD_CONVERSION_ROUTINES == 1u)
    /* This function names are obsolete and will be removed in future 
    * revisions of the component.
    */
    #define pantallaLCD_PrintDecUint16(x)   pantallaLCD_PrintNumber(x)  
    #define pantallaLCD_PrintHexUint8(x)    pantallaLCD_PrintInt8(x)
    #define pantallaLCD_PrintHexUint16(x)   pantallaLCD_PrintInt16(x)        

#endif /* pantallaLCD_CONVERSION_ROUTINES == 1u */

#endif /* CY_CHARLCD_pantallaLCD_H */


/* [] END OF FILE */
