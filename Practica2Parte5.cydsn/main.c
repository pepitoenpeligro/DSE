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


int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    int estado[4] = {0,0,0,0};
    int uestado = estado[0]+(estado[1]<<1)+(estado[2]<<2)+(estado[3]<<3);
    int pos = 0;
    int error = 0;
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    Control_Reg_NextStep_Write(uestado);
    pantallaLCD_Start();
    for(;;)
    {   
        if (!nex_Read()) {
            pos = (pos+1)%4;
            while(!nex_Read()){}
        } else if (!cross_Read()) {
            if (pos != 3) {
                if ((estado[0] == 0 && estado[pos+1] == 0)||(estado[0] == 1 && estado[pos+1] == 1))
                    estado[pos+1] = (estado[pos+1]+1)%2;
            }
            
            estado[0] = (estado[0]+1)%2;
            uestado = estado[0]+(estado[1]<<1)+(estado[2]<<2)+(estado[3]<<3);
            Control_Reg_NextStep_Write(uestado);
            Control_Reg_Clock_Write(1);
            Control_Reg_Clock_Write(0);
            while(!cross_Read()){}
        }
        error = Status_Reg_Error_Read();
        pantallaLCD_ClearDisplay();
        pantallaLCD_Position(0,0);
        if (error == 1) {            
		    pantallaLCD_PrintString("La gallina se ha");
            pantallaLCD_Position(1,0);
		    pantallaLCD_PrintString("comido el maiz");
            
            CyDelay(10000);
        } else if (error == 2) {            
		    pantallaLCD_PrintString("El zorro se ha");
		    pantallaLCD_Position(1,0);
		    pantallaLCD_PrintString("comido gallina");
            CyDelay(10000);
        } else if (Status_Reg_CurrentStep_Read() != (Status_Reg_LastStep_Read()+1) && (Status_Reg_CurrentStep_Read() != Status_Reg_LastStep_Read())) {
            pantallaLCD_PrintString("Paso incorrecto");
            CyDelay(5000);
        } else if (Status_Reg_CurrentStep_Read() == 7U) {
            pantallaLCD_PrintString("HAS GANADO!");
        } else {            
    		pantallaLCD_PrintString(" M:");
            pantallaLCD_PrintDecUint16((estado[1]+1)%2);
            pantallaLCD_PrintString(" G:");
            pantallaLCD_PrintDecUint16((estado[2]+1)%2);
            pantallaLCD_PrintString(" Z:");
            pantallaLCD_PrintDecUint16((estado[3]+1)%2);
            pantallaLCD_Position(1,0);
    		pantallaLCD_PrintString(" M:");
            pantallaLCD_PrintDecUint16(estado[1]);
            pantallaLCD_PrintString(" G:");
            pantallaLCD_PrintDecUint16(estado[2]);
            pantallaLCD_PrintString(" Z:");
            pantallaLCD_PrintDecUint16(estado[3]);
            if (pos != 3) {
                if (estado[0] == 0)
                    pantallaLCD_Position(0,(pos*4));
                else
                    pantallaLCD_Position(1,(pos*4));
                pantallaLCD_PrintString("*");
            }
        }        

        CyDelay(100);
    }
}


/* [] END OF FILE */
