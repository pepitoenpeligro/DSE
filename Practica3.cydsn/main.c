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



int flagInterrupcionPWM = 0;

CY_ISR_PROTO(GPIOIsrHandler);

CY_ISR_PROTO(UARTHandler);

int main(void)
{
    
    //interrupcionDelPWM_Start();
    //interrupcionDelPWM_SetVector(&interrupcionDelPWM_Interrupt);
    
    UART_isr_StartEx(UARTHandler);
    UART_isr_SetPriority(0);
    
    isr_GPIO_StartEx(GPIOIsrHandler);
    isr_GPIO_SetPriority(0);
    
    generadorPulsosPWM_Start();
    Timer_1_Start();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    Pantalla_Start();
    UART_Start();
    Pantalla_ClearDisplay();
    Pantalla_PrintString("Bienvenido");
    
    
    generadorPulsosPWM_WriteCompare(90);
    
    ledSoftwareInterrupcionPWM_Write(1);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    for(;;)
    {
    }
}



CY_ISR(GPIOIsrHandler)
{
    /* Clear pending Interrupt */
    //isr_GPIO_ClearPending();
   
    /* Cause nested software interrupt after 1000 ms */
    //CyDelay(1000u);
    ledSoftwareInterrupcionPWM_Write(~ledSoftwareInterrupcionPWM_Read());
}

CY_ISR(UARTHandler){
    Pantalla_ClearDisplay();
    Pantalla_PrintString("Int");
    char pepito = UART_GetByte();
    if(pepito == 'd'){
        Clock_1_SetSource(CYCLK_SRC_SEL_IMO);
    }else if(pepito == 'u'){
        Clock_1_SetSource(CYCLK_SRC_SEL_PLL);
    }else if(pepito == 'p'){
        generadorPulsosPWM_Stop();
        generadorPulsosPWM_Sleep();
        UART_PutString("Vamos a parar el led");
    }else if(pepito == 'a'){
        generadorPulsosPWM_Start();   
    }
   
    UART_PutChar(pepito);
    Pantalla_PrintString(pepito);
    
}









//CY_ISR(NestedIsrHandler)
//{
//    CyIntClearPending(NESTED_ISR);
//    
////    flagInterrupcionPWM++;
////    if(flagInterrupcionPWM == 100){
////        ledSoftwareInterrupcionPWM_Write(1);
////        flagInterrupcionPWM = 0;
////    }else{
////        ledSoftwareInterrupcionPWM_Write(0);
////    }
//    ledSoftwareInterrupcionPWM_Write(~ledSoftwareInterrupcionPWM_Read());
//   
//    
//}

/* [] END OF FILE */
