/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    int32 voltaje;
    
    pantallaLCD_Start();
    pantallaLCD_Position(0U,0U);
    pantallaLCD_ClearDisplay();
    pantallaLCD_PrintString("Voltimetro");
    
    convertidorAnalogicoDigital_Start();
    
    // Comenzamos a convertir la senial analogica a digital
    convertidorAnalogicoDigital_StartConvert();
    
    
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        
        convertidorAnalogicoDigital_IsEndConversion(convertidorAnalogicoDigital_WAIT_FOR_RESULT);
        voltaje = convertidorAnalogicoDigital_CountsTo_mVolts(convertidorAnalogicoDigital_GetResult32());
        
        pantallaLCD_ClearDisplay();
        pantallaLCD_Position(0U,0U);
        pantallaLCD_PrintString("Medicion: ");
        pantallaLCD_Position(1U,0U);
        pantallaLCD_PrintNumber(voltaje);
        CyDelay(1000);
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
