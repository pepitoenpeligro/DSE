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
    pantallaLCD_Start();
    
    CyDelay(1000);
    pantallaLCD_PrintString("Bienvenido a la practica 2");
    
    CyDelay(1000);
    pantallaLCD_ClearDisplay();
    
    uint8 a = 0U;
    uint8 b = 0U;
    uint8 modo = 0U;
    uint8 resultado = 0U;
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        
        
        if(siguiente_Read()){
            modo = (modo + 1) % 3;
            while(!siguiente_Read()){
            }
        }
        
        switch(modo){
            case 0:
                if(!inc_Read()){
                    a = (a+1)%4;
                    while(!inc_Read()){
                    }
                }else if(!dec_Read()){
                    a = (a-1)%4;
                    while(!dec_Read()){
                    }
                }
                break;
            case 1:
                 if(!inc_Read()){
                    b = (b+1)%4;
                    while(!inc_Read()){
                    }
                }else if(!dec_Read()){
                    b = (b-1)%4;
                    while(!dec_Read()){
                    }
                }
                break;
            case 2:
                
                registro_Write(a + (b << 2));
                resultado = registro2_Read();
                
                break;
            
        }
        
            pantallaLCD_ClearDisplay();
            pantallaLCD_Position(0U,0U);
            pantallaLCD_PrintString("A: ");
            pantallaLCD_PrintDecUint16(a);
            pantallaLCD_PrintString(" * B: ");
            pantallaLCD_PrintDecUint16(b);
            pantallaLCD_PrintString(" = ");
            pantallaLCD_Position(1U,0U);
            pantallaLCD_PrintDecUint16(resultado);
            CyDelay(1000);
        
        
       
    }
}

/* [] END OF FILE */
