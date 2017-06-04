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

void MuestraCadena(char* linea1,  char* linea2){
    pantallaLCD_ClearDisplay();
    pantallaLCD_Position(0U, 0U);
    pantallaLCD_PrintString(linea1);
    pantallaLCD_Position(1U, 0U);
    pantallaLCD_PrintString(linea2);
    // pantalla_PrintString(linea2);
    
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    pantallaLCD_Start();
    pantallaLCD_PrintNumber(registro_Read());
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        pantallaLCD_ClearDisplay();
        pantallaLCD_PrintNumber(registro_Read());
        CyDelay(600);

    }
}

/* [] END OF FILE */
