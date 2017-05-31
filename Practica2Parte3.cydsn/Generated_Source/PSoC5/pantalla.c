/*******************************************************************************
* File Name: pantalla.c
* Version 2.20
*
* Description:
*  This file provides source code for the Character LCD component's API.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "pantalla.h"


static void pantalla_WrDatNib(uint8 nibble) ;
static void pantalla_WrCntrlNib(uint8 nibble) ;

/* Stores state of component. Indicates whether component is or not
* in enable state.
*/
uint8 pantalla_enableState = 0u;

uint8 pantalla_initVar = 0u;


/*******************************************************************************
* Function Name: pantalla_Init
********************************************************************************
*
* Summary:
*  Performs initialization required for the components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enables a 4-bit interface
*        Clears the display
*        Enables the auto cursor increment
*        Resets the cursor to start position
*  Also, it loads a custom character set to the LCD if it was defined in the customizer.
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
void pantalla_Init(void) 
{
    /* INIT CODE */
    CyDelay(40u);                                                        /* Delay 40 ms */
    pantalla_WrCntrlNib(pantalla_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(5u);                                                         /* Delay 5 ms */
    pantalla_WrCntrlNib(pantalla_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(15u);                                                        /* Delay 15 ms */
    pantalla_WrCntrlNib(pantalla_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(1u);                                                         /* Delay 1 ms */
    pantalla_WrCntrlNib(pantalla_DISPLAY_4_BIT_INIT);    /* Selects 4-bit mode */
    CyDelay(5u);                                                         /* Delay 5 ms */

    pantalla_WriteControl(pantalla_CURSOR_AUTO_INCR_ON);    /* Incr Cursor After Writes */
    pantalla_WriteControl(pantalla_DISPLAY_CURSOR_ON);      /* Turn Display, Cursor ON */
    pantalla_WriteControl(pantalla_DISPLAY_2_LINES_5x10);   /* 2 Lines by 5x10 Characters */
    pantalla_WriteControl(pantalla_DISPLAY_CURSOR_OFF);     /* Turn Display, Cursor OFF */
    pantalla_WriteControl(pantalla_CLEAR_DISPLAY);          /* Clear LCD Screen */
    pantalla_WriteControl(pantalla_DISPLAY_ON_CURSOR_OFF);  /* Turn Display ON, Cursor OFF */
    pantalla_WriteControl(pantalla_RESET_CURSOR_POSITION);  /* Set Cursor to 0,0 */
    CyDelay(5u);

    #if(pantalla_CUSTOM_CHAR_SET != pantalla_NONE)
        pantalla_LoadCustomFonts(pantalla_customFonts);
    #endif /* pantalla_CUSTOM_CHAR_SET != pantalla_NONE */
}


/*******************************************************************************
* Function Name: pantalla_Enable
********************************************************************************
*
* Summary:
*  Turns on the display.
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
* Theory:
*  This function has no effect when it is called the first time as
*  pantalla_Init() turns on the LCD.
*
*******************************************************************************/
void pantalla_Enable(void) 
{
    pantalla_DisplayOn();
    pantalla_enableState = 1u;
}


/*******************************************************************************
* Function Name: pantalla_Start
********************************************************************************
*
* Summary:
*  Performs initialization required for the components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enables 4-bit interface
*        Clears the display
*        Enables auto cursor increment
*        Resets the cursor to start position
*  Also, it loads a custom character set to the LCD if it was defined in the customizer.
*  If it was not the first call in this project, then it just turns on the
*  display
*
*
* Parameters:
*  pantalla_initVar - global variable.
*
* Return:
*  pantalla_initVar - global variable.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void pantalla_Start(void) 
{
    /* If not initialized, perform initialization */
    if(pantalla_initVar == 0u)
    {
        pantalla_Init();
        pantalla_initVar = 1u;
    }

    /* Turn on the LCD */
    pantalla_Enable();
}


/*******************************************************************************
* Function Name: pantalla_Stop
********************************************************************************
*
* Summary:
*  Turns off the display of the LCD screen.
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
void pantalla_Stop(void) 
{
    /* Calls LCD Off Macro */
    pantalla_DisplayOff();
    pantalla_enableState = 0u;
}


/*******************************************************************************
*  Function Name: pantalla_Position
********************************************************************************
*
* Summary:
*  Moves the active cursor location to a point specified by the input arguments
*
* Parameters:
*  row:    Specific row of LCD module to be written
*  column: Column of LCD module to be written
*
* Return:
*  None.
*
* Note:
*  This only applies for LCD displays that use the 2X40 address mode.
*  In this case Row 2 starts with a 0x28 offset from Row 1.
*  When there are more than 2 rows, each row must be fewer than 20 characters.
*
*******************************************************************************/
void pantalla_Position(uint8 row, uint8 column) 
{
    switch (row)
    {
        case (uint8)0:
            pantalla_WriteControl(pantalla_ROW_0_START + column);
            break;
        case (uint8) 1:
            pantalla_WriteControl(pantalla_ROW_1_START + column);
            break;
        case (uint8) 2:
            pantalla_WriteControl(pantalla_ROW_2_START + column);
            break;
        case (uint8) 3:
            pantalla_WriteControl(pantalla_ROW_3_START + column);
            break;
        default:
            /* if default case is hit, invalid row argument was passed.*/
            break;
    }
}


/*******************************************************************************
* Function Name: pantalla_PrintString
********************************************************************************
*
* Summary:
*  Writes a zero terminated string to the LCD.
*
* Parameters:
*  string: Pointer to head of char8 array to be written to the LCD module
*
* Return:
*  None.
*
*******************************************************************************/
void pantalla_PrintString(char8 const string[]) 
{
    uint8 indexU8 = 1u;
    char8 current = *string;

    /* Until null is reached, print next character */
    while((char8) '\0' != current)
    {
        pantalla_WriteData((uint8)current);
        current = string[indexU8];
        indexU8++;
    }
}


/*******************************************************************************
*  Function Name: pantalla_PutChar
********************************************************************************
*
* Summary:
*  Writes a single character to the current cursor position of the LCD module.
*  Custom character names (_CUSTOM_0 through
*  _CUSTOM_7) are acceptable as inputs.
*
* Parameters:
*  character: Character to be written to LCD
*
* Return:
*  None.
*
*******************************************************************************/
void pantalla_PutChar(char8 character) 
{
    pantalla_WriteData((uint8)character);
}


/*******************************************************************************
*  Function Name: pantalla_WriteData
********************************************************************************
*
* Summary:
*  Writes a data byte to the LCD module's Data Display RAM.
*
* Parameters:
*  dByte: Byte to be written to the LCD module
*
* Return:
*  None.
*
*******************************************************************************/
void pantalla_WriteData(uint8 dByte) 
{
    uint8 nibble;

    pantalla_IsReady();
    nibble = dByte >> pantalla_NIBBLE_SHIFT;

    /* Write high nibble */
    pantalla_WrDatNib(nibble);

    nibble = dByte & pantalla_NIBBLE_MASK;
    /* Write low nibble */
    pantalla_WrDatNib(nibble);
}


/*******************************************************************************
*  Function Name: pantalla_WriteControl
********************************************************************************
*
* Summary:
*  Writes a command byte to the LCD module.
*
* Parameters:
*  cByte:  The byte to be written to theLCD module
* 
* Return:
*  None.
*
*******************************************************************************/
void pantalla_WriteControl(uint8 cByte) 
{
    uint8 nibble;

    pantalla_IsReady();

    nibble = cByte >> pantalla_NIBBLE_SHIFT;
    
    /* WrCntrlNib(High Nibble) */
    pantalla_WrCntrlNib(nibble);
    nibble = cByte & pantalla_NIBBLE_MASK;

    /* WrCntrlNib(Low Nibble) */
    pantalla_WrCntrlNib(nibble);
}


/*******************************************************************************
* Function Name: pantalla_IsReady
********************************************************************************
*
* Summary:
*  Polls the LCD until the ready bit is set or a timeout occurs.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  Changes the pins to High-Z.
*
*******************************************************************************/
void pantalla_IsReady(void) 
{
    uint8 value;
    uint32 timeout;
    timeout = pantalla_READY_DELAY;

    /* Clear LCD port*/
    pantalla_PORT_DR_REG &= ((uint8)(~pantalla_PORT_MASK));

    /* PSoC4 has a little different from PSoC3/5 port/pin organization for setting Drive Modes.
  
    */
    #if (CY_PSOC4)
        
        /* Mask off data pins to clear old values out */
        value = pantalla_PORT_PC_REG & ((uint32) (~ pantalla_DM_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        pantalla_PORT_PC_REG = value | pantalla_HIGH_Z_DATA_DM;

    #else
    
        /* Change Port to High-Z Status on data pins */

        /* Mask off data pins to clear old values out */
        value = pantalla_PORT_DM0_REG & ((uint8)(~pantalla_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        pantalla_PORT_DM0_REG = value | (pantalla_HIGH_Z_DM0 & pantalla_DATA_MASK);

        /* Mask off data pins to clear old values out */
        value = pantalla_PORT_DM1_REG & ((uint8)(~pantalla_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        pantalla_PORT_DM1_REG = value;

        /* Mask off data pins to clear old values out */
        value = pantalla_PORT_DM2_REG & ((uint8)(~pantalla_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        pantalla_PORT_DM2_REG = value;
    
    #endif /* CY_PSOC4 */
    
    /* Make sure RS is low */
    pantalla_PORT_DR_REG &= ((uint8)(~pantalla_RS));

    /* Set R/W high to read */
    pantalla_PORT_DR_REG |= pantalla_RW;

    do
    {
        /* 40 ns delay required before rising Enable and 500ns between neighbour Enables */
        CyDelayUs(0u);

        /* Set E high */
        pantalla_PORT_DR_REG |= pantalla_E;

        /* 360 ns delay setup time for data pins */
        CyDelayUs(1u);

        /* Get port state */
        value = pantalla_PORT_PS_REG;

        /* Set enable low */
        pantalla_PORT_DR_REG &= ((uint8)(~pantalla_E));

        /* This gives true delay between disabling Enable bit and polling Ready bit */
        CyDelayUs(0u);

        /* Extract ready bit */
        value &= pantalla_READY_BIT;

        /* Set E high as we in 4-bit interface we need extra operation */
        pantalla_PORT_DR_REG |= pantalla_E;

        /* 360 ns delay setup time for data pins */
        CyDelayUs(1u);

        /* Set enable low */
        pantalla_PORT_DR_REG &= ((uint8)(~pantalla_E));

        /* If LCD is not ready make a delay */
        if (value == 0u)
        {
            CyDelayUs(10u);
        }

        /* Repeat until bit 4 is not zero or until timeout. */
        timeout--;

    } while ((value != 0u) && (timeout > 0u));

    /* Set R/W low to write */
    pantalla_PORT_DR_REG &= ((uint8)(~pantalla_RW));

    /* Clear LCD port*/
    pantalla_PORT_DR_REG &= ((uint8)(~pantalla_PORT_MASK));

    #if (CY_PSOC4)
        
        /* Mask off data pins to clear old values out */
        value = pantalla_PORT_PC_REG & ((uint32)(~ pantalla_DM_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        pantalla_PORT_PC_REG = value | pantalla_STRONG_DATA_DM;

    #else

        /* Change Port to Output (Strong) on data pins */
        /* Mask off data pins to clear high z values out. Configure data pins 
        * to Strong Drive, others unchanged.
        */
        pantalla_PORT_DM0_REG &= ((uint8)(~pantalla_DATA_MASK));
        /* Mask off data pins to clear high z values out */
        value = pantalla_PORT_DM1_REG & ((uint8)(~pantalla_DATA_MASK));
        /* Configure data pins to Strong Drive, others unchanged */
        pantalla_PORT_DM1_REG = value | (pantalla_STRONG_DM1 & pantalla_DATA_MASK);

        /* Mask off data pins to clear high z values out */
        value = pantalla_PORT_DM2_REG & ((uint8)(~pantalla_DATA_MASK));
        /* Configure data pins to Strong Drive, others unchanged */
        pantalla_PORT_DM2_REG = value | (pantalla_STRONG_DM2 & pantalla_DATA_MASK);
    
    #endif /* CY_PSOC4 */
}


/*******************************************************************************
*  Function Name: pantalla_WrDatNib
********************************************************************************
*
* Summary:
*  Writes a data nibble to the LCD module.
*
* Parameters:
*  nibble:  Byte containing nibble in the least significant nibble to be
*           written to the LCD module.
*
* Return:
*  None.
*
*******************************************************************************/
static void pantalla_WrDatNib(uint8 nibble) 
{
    /* RS should be low to select data register */
    pantalla_PORT_DR_REG |= pantalla_RS;
    /* Reset RW for write operation */
    pantalla_PORT_DR_REG &= ((uint8)(~pantalla_RW));

    /* Guaranteed delay between Setting RS and RW and setting E bits */
    CyDelayUs(0u);
    
    /* Clear data pins */
    pantalla_PORT_DR_REG &= ((uint8)(~pantalla_DATA_MASK));

    /* Write data, bring E high */
    #if(0u != pantalla_PORT_SHIFT) /* MISRA forbids shift by 0 so need to handle that */
        pantalla_PORT_DR_REG |= 
            (pantalla_E | ((uint8)(((uint8) nibble) << pantalla_PORT_SHIFT)));
    #else
        pantalla_PORT_DR_REG |= (pantalla_E | nibble);
    #endif /* (0u != pantalla_PORT_SHIFT) */

    /* Minimum of 230 ns delay */
    CyDelayUs(1u);

    pantalla_PORT_DR_REG &= ((uint8)(~pantalla_E));
}


/*******************************************************************************
*  Function Name: pantalla_WrCntrlNib
********************************************************************************
*
* Summary:
*  Writes a control nibble to the LCD module.
*
* Parameters:
*  nibble: The byte containing a nibble in the four least significant bits.????
*
* Return:
*  None.
*
*******************************************************************************/
static void pantalla_WrCntrlNib(uint8 nibble) 
{
    /* RS and RW should be low to select instruction register and  write operation respectively */
    pantalla_PORT_DR_REG &= ((uint8)(~(pantalla_RS | pantalla_RW)));

    /* Two following lines of code will give 40ns delay */
    /* Clear data pins */
    pantalla_PORT_DR_REG &= ((uint8)(~pantalla_DATA_MASK));

    /* Write control data and set enable signal */
    #if(0u != pantalla_PORT_SHIFT) /* MISRA forbids shift by 0 so need to handle that */
        pantalla_PORT_DR_REG |= 
            (pantalla_E | ((uint8)(((uint8) nibble) << pantalla_PORT_SHIFT)));
    #else
        pantalla_PORT_DR_REG |= (pantalla_E | nibble);
    #endif /* (0u != pantalla_PORT_SHIFT) */

    /* Minimum of 230 ns delay */
    CyDelayUs(1u);

    pantalla_PORT_DR_REG &= ((uint8)(~pantalla_E));
}


#if(pantalla_CONVERSION_ROUTINES == 1u)

    /*******************************************************************************
    *  Function Name: pantalla_PrintInt8
    ********************************************************************************
    *
    * Summary:
    *  Print a byte as two ASCII characters.
    *
    * Parameters:
    *  value: The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void pantalla_PrintInt8(uint8 value) 
    {
        static char8 const CYCODE pantalla_hex[16u] = "0123456789ABCDEF";
        
        pantalla_PutChar((char8) pantalla_hex[value >> pantalla_BYTE_UPPER_NIBBLE_SHIFT]);
        pantalla_PutChar((char8) pantalla_hex[value & pantalla_BYTE_LOWER_NIBBLE_MASK]);
    }


    /*******************************************************************************
    *  Function Name: pantalla_PrintInt16
    ********************************************************************************
    *
    * Summary:
    *  Print a uint16 as four ASCII characters.
    *
    * Parameters:
    *  value: The uint16 to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void pantalla_PrintInt16(uint16 value) 
    {
        pantalla_PrintInt8((uint8)(value >> pantalla_U16_UPPER_BYTE_SHIFT));
        pantalla_PrintInt8((uint8)(value & pantalla_U16_LOWER_BYTE_MASK));
    }

    
    /*******************************************************************************
    *  Function Name: pantalla_PrintInt32
    ********************************************************************************
    *
    * Summary:
    *  Print a uint32 hexadecimal number as eight ASCII characters.
    *
    * Parameters:
    *  value: The uint32 to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void pantalla_PrintInt32(uint32 value) 
    {
        uint8 shift = pantalla_32_BIT_SHIFT;
        
        while (shift != 0u)
        {
            /* "shift" var is to be subtracted by 8 prior shifting. This implements 
            * shifting by 24, 16, 8 and 0u. 
            */
            shift -= pantalla_8_BIT_SHIFT;
            
            /* Print 8 bits of uint32 hex number */
            pantalla_PrintInt8((uint8) ((uint32) (value >> shift)));
        }
    }
    
    
    /*******************************************************************************
    *  Function Name: pantalla_PrintNumber
    ********************************************************************************
    *
    * Summary:
    *  Print an uint16 value as a left-justified decimal value.
    *
    * Parameters:
    *  value: A 16-bit value to be printed in ASCII characters as a decimal number
    *
    * Return:
    *  None.
    *
    * Note:
    *  This function is implemented as a macro.
    *
    *******************************************************************************/

    
    /*******************************************************************************
    *  Function Name: pantalla_PrintU32Number
    ********************************************************************************
    *
    * Summary:
    *  Print an uint32 value as a left-justified decimal value.
    *
    * Parameters:
    *  value: A 32-bit value to be printed in ASCII characters as a decimal number
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void pantalla_PrintU32Number(uint32 value) 
    {
        uint8 tmpDigit;
        char8 number[pantalla_NUMBER_OF_REMAINDERS_U32 + 1u];
        uint8 digIndex = pantalla_NUMBER_OF_REMAINDERS_U32;
        
        /* This API will output a decimal number as a string and that string will be 
        * filled from end to start. Set Null termination character first.
        */
        number[digIndex] = (char8) '\0';
        digIndex--;
        
        /* Load these in reverse order */
        while(value >= pantalla_TEN)
        {
            /* Extract decimal digit, indexed by 'digIndex', from 'value' and
            * convert it to ASCII character.
            */
            tmpDigit = (uint8) (((uint8) (value % pantalla_TEN)) + (uint8) pantalla_ZERO_CHAR_ASCII);
            
            /* Temporary variable 'tmpDigit' is used to avoid Violation of MISRA rule 
            * #10.3.
            */
            number[digIndex] = (char8) tmpDigit;
            value /= pantalla_TEN;
            digIndex--;
        }
        
        /* Extract last decimal digit 'digIndex', from the 'value' and convert it
        * to ASCII character.
        */
        tmpDigit = (uint8) (((uint8)(value % pantalla_TEN)) + (uint8) pantalla_ZERO_CHAR_ASCII);
        number[digIndex] = (char8) tmpDigit;

        /* Print out number */
        pantalla_PrintString(&number[digIndex]);
    }
    
#endif /* pantalla_CONVERSION_ROUTINES == 1u */


/* [] END OF FILE */
