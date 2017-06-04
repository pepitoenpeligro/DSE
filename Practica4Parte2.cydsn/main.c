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
#include <math.h>



#define PI_DOS (3.14159 * 2)

#define MUESTRAS 4000

#define SENO 0
#define CUADRADA 1
#define SIERRA 2
#define TRIANGULAR 3


char op;
uint8 signal [MUESTRAS];
uint8 type = SENO;
uint8 amp = 127;
uint16 i = 0;
uint8 j = 0;

float incrementarFase = PI_DOS/MUESTRAS;


int main()
{   

    CyGlobalIntEnable; /* Enable global interrupts. */

    generadorOnda_Start();
    USBUART_Start(0, USBUART_5V_OPERATION);
    pantallaLCD_Start();


    for(;;)
    {
        if (0u != USBUART_IsConfigurationChanged()){
            if (0u != USBUART_GetConfiguration()){
                USBUART_CDC_Init();
            }
        }
        if (0u != USBUART_GetConfiguration())
        {
            if (0u != USBUART_DataIsReady())
            {
                op = USBUART_GetChar();

                switch(op)
                {
                    case 'a':
                    case 'A':
                        amp += 5;
                        USBUART_PutString("Amplitud aumentada\r\n");
                        pantallaLCD_ClearDisplay();
                        pantallaLCD_Position(0u, 0u);                            
                        pantallaLCD_PrintString("Amplitud aumentada");
                        
                        break;
                    case 'z':
                    case 'Z':
                        amp -= 5;
                        USBUART_PutString("Amplitud decrementada\r\n");
                        pantallaLCD_ClearDisplay();
                        pantallaLCD_Position(0u, 0u);                            
                        pantallaLCD_PrintString("Amplitud decrementada");                    
                        break;
                    case 's':
                    case 'S':
                        if ( ((Clock_1_GetDividerRegister()+1)/2) >=1 )
                            Clock_1_SetDividerValue((Clock_1_GetDividerRegister()+1)/2);
                        USBUART_PutString("Frecuencia aumentada\r\n");
                        pantallaLCD_ClearDisplay();
                        pantallaLCD_Position(0u, 0u);                            
                        pantallaLCD_PrintString("Frecuencia aumentada");
                        
                        break;
                    case 'x':
                    case 'X':                        
                        Clock_1_SetDividerValue((Clock_1_GetDividerRegister()+1)*2);                        
                        USBUART_PutString("Frecuencia decrementada\r\n");
                        pantallaLCD_ClearDisplay();
                        pantallaLCD_Position(0u, 0u);                            
                        pantallaLCD_PrintString("Frecuencia decrementada");
                        
                        break;
                    case 't':
                    case 'T':
                        type = (type+1)%4;
                        USBUART_PutString("Tipo de onda cambiado\r\n");
                        pantallaLCD_ClearDisplay();
                        pantallaLCD_Position(0u, 0u);                            
                        pantallaLCD_PrintString("Tipo de onda cambiado");
                        break;
                    default:
                        USBUART_PutString("Comando desconocido\r\n");
                        pantallaLCD_ClearDisplay();
                        pantallaLCD_Position(0u, 0u);                            
                        pantallaLCD_PrintString("Comando desconocido");
                        break;
                } /* end of switch(thisCommand) */
                switch (type) {
                    case SENO:
                        for (i=0; i < MUESTRAS; i++) {
                            signal[i] = amp*sin(incrementarFase*i)+amp;
                        }
                        break;
                    case CUADRADA:
                        for (i=0; i < MUESTRAS; i++) {
                            signal[i] = (amp*sin(incrementarFase*i)>=0)?amp*2:0;
                        }
                        break;                        
                    case SIERRA:
                        for (i=0; i < MUESTRAS; i++) {                    
                            signal[i] = 2*amp*(float)(i / MUESTRAS);
                        }
                        break;                        
                    case TRIANGULAR:
                        for (i=0; i < MUESTRAS; i++) {
                            signal[i] = 2*amp - abs(i % (2*2*amp) - 2*amp);
                        }
                        break;                        
                }
                generadorOnda_Stop();
                generadorOnda_Wave1Setup(&signal, 4000);
                generadorOnda_Start();
                

                while (0u == USBUART_CDCIsReady());            
            }
        }
    }
}

/* [] END OF FILE */
