/*******************************************************************************
* File Name: pantalla.h
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

#if !defined(CY_CHARLCD_pantalla_H)
#define CY_CHARLCD_pantalla_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define pantalla_CONVERSION_ROUTINES     (1u)
#define pantalla_CUSTOM_CHAR_SET         (0u)

/* Custom character set types */
#define pantalla_NONE                     (0u)    /* No Custom Fonts      */
#define pantalla_HORIZONTAL_BG            (1u)    /* Horizontal Bar Graph */
#define pantalla_VERTICAL_BG              (2u)    /* Vertical Bar Graph   */
#define pantalla_USER_DEFINED             (3u)    /* User Defined Fonts   */


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} pantalla_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void pantalla_Init(void) ;
void pantalla_Enable(void) ;
void pantalla_Start(void) ;
void pantalla_Stop(void) ;
void pantalla_WriteControl(uint8 cByte) ;
void pantalla_WriteData(uint8 dByte) ;
void pantalla_PrintString(char8 const string[]) ;
void pantalla_Position(uint8 row, uint8 column) ;
void pantalla_PutChar(char8 character) ;
void pantalla_IsReady(void) ;
void pantalla_SaveConfig(void) ;
void pantalla_RestoreConfig(void) ;
void pantalla_Sleep(void) ;
void pantalla_Wakeup(void) ;

#if((pantalla_CUSTOM_CHAR_SET == pantalla_VERTICAL_BG) || \
                (pantalla_CUSTOM_CHAR_SET == pantalla_HORIZONTAL_BG))

    void  pantalla_LoadCustomFonts(uint8 const customData[])
                        ;

    void  pantalla_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                         ;

    void pantalla_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                        ;

#endif /* ((pantalla_CUSTOM_CHAR_SET == pantalla_VERTICAL_BG) */

#if(pantalla_CUSTOM_CHAR_SET == pantalla_USER_DEFINED)

    void pantalla_LoadCustomFonts(uint8 const customData[])
                            ;

#endif /* ((pantalla_CUSTOM_CHAR_SET == pantalla_USER_DEFINED) */

#if(pantalla_CONVERSION_ROUTINES == 1u)

    /* ASCII Conversion Routines */
    void pantalla_PrintInt8(uint8 value) ;
    void pantalla_PrintInt16(uint16 value) ;
    void pantalla_PrintInt32(uint32 value) ;
    void pantalla_PrintNumber(uint16 value) ; 
    void pantalla_PrintU32Number(uint32 value) ;
    
#endif /* pantalla_CONVERSION_ROUTINES == 1u */

/* Clear Macro */
#define pantalla_ClearDisplay() pantalla_WriteControl(pantalla_CLEAR_DISPLAY)

/* Off Macro */
#define pantalla_DisplayOff() pantalla_WriteControl(pantalla_DISPLAY_CURSOR_OFF)

/* On Macro */
#define pantalla_DisplayOn() pantalla_WriteControl(pantalla_DISPLAY_ON_CURSOR_OFF)

#define pantalla_PrintNumber(value) pantalla_PrintU32Number((uint16) (value))


/***************************************
*           Global Variables
***************************************/

extern uint8 pantalla_initVar;
extern uint8 pantalla_enableState;
extern uint8 const CYCODE pantalla_customFonts[64u];


/***************************************
*           API Constants
***************************************/

/* Full Byte Commands Sent as Two Nibbles */
#define pantalla_DISPLAY_8_BIT_INIT       (0x03u)
#define pantalla_DISPLAY_4_BIT_INIT       (0x02u)
#define pantalla_DISPLAY_CURSOR_OFF       (0x08u)
#define pantalla_CLEAR_DISPLAY            (0x01u)
#define pantalla_CURSOR_AUTO_INCR_ON      (0x06u)
#define pantalla_DISPLAY_CURSOR_ON        (0x0Eu)
#define pantalla_DISPLAY_2_LINES_5x10     (0x2Cu)
#define pantalla_DISPLAY_ON_CURSOR_OFF    (0x0Cu)

#define pantalla_RESET_CURSOR_POSITION    (0x03u)
#define pantalla_CURSOR_WINK              (0x0Du)
#define pantalla_CURSOR_BLINK             (0x0Fu)
#define pantalla_CURSOR_SH_LEFT           (0x10u)
#define pantalla_CURSOR_SH_RIGHT          (0x14u)
#define pantalla_DISPLAY_SCRL_LEFT        (0x18u)
#define pantalla_DISPLAY_SCRL_RIGHT       (0x1Eu)
#define pantalla_CURSOR_HOME              (0x02u)
#define pantalla_CURSOR_LEFT              (0x04u)
#define pantalla_CURSOR_RIGHT             (0x06u)

/* Point to Character Generator Ram 0 */
#define pantalla_CGRAM_0                  (0x40u)

/* Point to Display Data Ram 0 */
#define pantalla_DDRAM_0                  (0x80u)

/* LCD Characteristics */
#define pantalla_CHARACTER_WIDTH          (0x05u)
#define pantalla_CHARACTER_HEIGHT         (0x08u)

#if(pantalla_CONVERSION_ROUTINES == 1u)
    #define pantalla_NUMBER_OF_REMAINDERS_U32 (0x0Au)
    #define pantalla_TEN                      (0x0Au)
    #define pantalla_8_BIT_SHIFT              (8u)
    #define pantalla_32_BIT_SHIFT             (32u)
    #define pantalla_ZERO_CHAR_ASCII          (48u)
#endif /* pantalla_CONVERSION_ROUTINES == 1u */

/* Nibble Offset and Mask */
#define pantalla_NIBBLE_SHIFT             (0x04u)
#define pantalla_NIBBLE_MASK              (0x0Fu)

/* LCD Module Address Constants */
#define pantalla_ROW_0_START              (0x80u)
#define pantalla_ROW_1_START              (0xC0u)
#define pantalla_ROW_2_START              (0x94u)
#define pantalla_ROW_3_START              (0xD4u)

/* Custom Character References */
#define pantalla_CUSTOM_0                 (0x00u)
#define pantalla_CUSTOM_1                 (0x01u)
#define pantalla_CUSTOM_2                 (0x02u)
#define pantalla_CUSTOM_3                 (0x03u)
#define pantalla_CUSTOM_4                 (0x04u)
#define pantalla_CUSTOM_5                 (0x05u)
#define pantalla_CUSTOM_6                 (0x06u)
#define pantalla_CUSTOM_7                 (0x07u)

/* Other constants */
#define pantalla_BYTE_UPPER_NIBBLE_SHIFT  (0x04u)
#define pantalla_BYTE_LOWER_NIBBLE_MASK   (0x0Fu)
#define pantalla_U16_UPPER_BYTE_SHIFT     (0x08u)
#define pantalla_U16_LOWER_BYTE_MASK      (0xFFu)
#define pantalla_CUSTOM_CHAR_SET_LEN      (0x40u)

#define pantalla_LONGEST_CMD_US           (0x651u)
#define pantalla_WAIT_CYCLE               (0x10u)
#define pantalla_READY_DELAY              ((pantalla_LONGEST_CMD_US * 4u)/(pantalla_WAIT_CYCLE))


/***************************************
*             Registers
***************************************/

/* Device specific registers */
#if (CY_PSOC4)

    #define pantalla_PORT_DR_REG           (*(reg32 *) pantalla_LCDPort__DR)  /* Data Output Register */
    #define pantalla_PORT_DR_PTR           ( (reg32 *) pantalla_LCDPort__DR)
    #define pantalla_PORT_PS_REG           (*(reg32 *) pantalla_LCDPort__PS)  /* Pin State Register */
    #define pantalla_PORT_PS_PTR           ( (reg32 *) pantalla_LCDPort__PS)
    
    #define pantalla_PORT_PC_REG           (*(reg32 *) pantalla_LCDPort__PC)
    #define pantalla_PORT_PC_PTR           (*(reg32 *) pantalla_LCDPort__PC)
    
#else

    #define pantalla_PORT_DR_REG           (*(reg8 *) pantalla_LCDPort__DR)  /* Data Output Register */
    #define pantalla_PORT_DR_PTR           ( (reg8 *) pantalla_LCDPort__DR)
    #define pantalla_PORT_PS_REG           (*(reg8 *) pantalla_LCDPort__PS)  /* Pin State Register */
    #define pantalla_PORT_PS_PTR           ( (reg8 *) pantalla_LCDPort__PS)

    #define pantalla_PORT_DM0_REG          (*(reg8 *) pantalla_LCDPort__DM0) /* Port Drive Mode 0 */
    #define pantalla_PORT_DM0_PTR          ( (reg8 *) pantalla_LCDPort__DM0)
    #define pantalla_PORT_DM1_REG          (*(reg8 *) pantalla_LCDPort__DM1) /* Port Drive Mode 1 */
    #define pantalla_PORT_DM1_PTR          ( (reg8 *) pantalla_LCDPort__DM1)
    #define pantalla_PORT_DM2_REG          (*(reg8 *) pantalla_LCDPort__DM2) /* Port Drive Mode 2 */
    #define pantalla_PORT_DM2_PTR          ( (reg8 *) pantalla_LCDPort__DM2)

#endif /* CY_PSOC4 */


/***************************************
*       Register Constants
***************************************/

/* SHIFT must be 1 or 0 */
#if (0 == pantalla_LCDPort__SHIFT)
    #define pantalla_PORT_SHIFT               (0x00u)
#else
    #define pantalla_PORT_SHIFT               (0x01u)
#endif /* (0 == pantalla_LCDPort__SHIFT) */

#define pantalla_PORT_MASK                ((uint8) (pantalla_LCDPort__MASK))

#if (CY_PSOC4)

    #define pantalla_DM_PIN_STEP              (3u)
    /* Hi-Z Digital is defined by the value of "001b" and this should be set for
    * four data pins, in this way we get - 0x00000249. A similar Strong drive
    * is defined with "110b" so we get 0x00000DB6.
    */
    #define pantalla_HIGH_Z_DATA_DM           ((0x00000249ul) << (pantalla_PORT_SHIFT *\
                                                                          pantalla_DM_PIN_STEP))
    #define pantalla_STRONG_DATA_DM           ((0x00000DB6ul) << (pantalla_PORT_SHIFT *\
                                                                          pantalla_DM_PIN_STEP))
    #define pantalla_DATA_PINS_MASK           (0x00000FFFul)
    #define pantalla_DM_DATA_MASK             ((uint32) (pantalla_DATA_PINS_MASK << \
                                                      (pantalla_PORT_SHIFT * pantalla_DM_PIN_STEP)))

#else

    /* Drive Mode register values for High Z */
    #define pantalla_HIGH_Z_DM0               (0xFFu)
    #define pantalla_HIGH_Z_DM1               (0x00u)
    #define pantalla_HIGH_Z_DM2               (0x00u)

    /* Drive Mode register values for High Z Analog */
    #define pantalla_HIGH_Z_A_DM0             (0x00u)
    #define pantalla_HIGH_Z_A_DM1             (0x00u)
    #define pantalla_HIGH_Z_A_DM2             (0x00u)

    /* Drive Mode register values for Strong */
    #define pantalla_STRONG_DM0               (0x00u)
    #define pantalla_STRONG_DM1               (0xFFu)
    #define pantalla_STRONG_DM2               (0xFFu)

#endif /* CY_PSOC4 */

/* Pin Masks */
#define pantalla_RS                     ((uint8) \
                                                (((uint8) 0x20u) << pantalla_LCDPort__SHIFT))
#define pantalla_RW                     ((uint8) \
                                                (((uint8) 0x40u) << pantalla_LCDPort__SHIFT))
#define pantalla_E                      ((uint8) \
                                                (((uint8) 0x10u) << pantalla_LCDPort__SHIFT))
#define pantalla_READY_BIT              ((uint8) \
                                                (((uint8) 0x08u) << pantalla_LCDPort__SHIFT))
#define pantalla_DATA_MASK              ((uint8) \
                                                (((uint8) 0x0Fu) << pantalla_LCDPort__SHIFT))

/* These names are obsolete and will be removed in future revisions */
#define pantalla_PORT_DR                  pantalla_PORT_DR_REG
#define pantalla_PORT_PS                  pantalla_PORT_PS_REG
#define pantalla_PORT_DM0                 pantalla_PORT_DM0_REG
#define pantalla_PORT_DM1                 pantalla_PORT_DM1_REG
#define pantalla_PORT_DM2                 pantalla_PORT_DM2_REG


/***************************************
*       Obsolete function names
***************************************/
#if(pantalla_CONVERSION_ROUTINES == 1u)
    /* This function names are obsolete and will be removed in future 
    * revisions of the component.
    */
    #define pantalla_PrintDecUint16(x)   pantalla_PrintNumber(x)  
    #define pantalla_PrintHexUint8(x)    pantalla_PrintInt8(x)
    #define pantalla_PrintHexUint16(x)   pantalla_PrintInt16(x)        

#endif /* pantalla_CONVERSION_ROUTINES == 1u */

#endif /* CY_CHARLCD_pantalla_H */


/* [] END OF FILE */
