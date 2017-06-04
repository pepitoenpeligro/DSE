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


void MuestraCadena(char* linea1, char* linea2);
void MuestraMultiLineas(char * mensaje);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    pantallaLCD_Start();
    //MuestraCadena("Cervezas: 2 u ","En el congelador");
    char * mensajeAMostrar = "No me gustan laspersonas unga unga. He nacido para exterminar a todos los heteros.Nos vemos en la sal. Atte. PSoC 5"; 
    MuestraMultiLineas(mensajeAMostrar);
    for(;;)
    {
        MuestraCadena("Larga vida a", "Elisa");
        CyDelay(100);
        /* Place your application code here. */
    }
}

/* [] END OF FILE */

void MuestraCadena(char* linea1,  char* linea2){
    pantallaLCD_ClearDisplay();
    
    pantallaLCD_Position(0U, 0U);
    pantallaLCD_PrintString(linea1);
    pantallaLCD_Position(1U, 0U);
    pantallaLCD_PrintString(linea2);
    // pantallaLCD_PrintString(linea2);
    
}


void MuestraMultiLineas(char * mensaje){
    int longitud = strlen(mensaje);
    char linea1[17];
    char linea2[17];
    
    int i =0;
    for( i = 0; i < longitud; i+=32){
        pantallaLCD_ClearDisplay();
        pantallaLCD_Position(0U, 0U);
        memcpy( linea1, &mensaje[0+i], 16 );
        linea1[16] = '\0';
        memcpy( linea2, &mensaje[16+i], 16 );
        linea2[16] = '\0';
        pantallaLCD_PrintString(linea1);
        pantallaLCD_Position(1U, 0U);
        pantallaLCD_PrintString(linea2);
        CyDelay(2200);
    }
    
    pantallaLCD_ClearDisplay();
    
    
    
    
}