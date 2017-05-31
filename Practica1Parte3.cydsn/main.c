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

int main(void)
{
    
    //interrupcionDelPWM_Start();
    //interrupcionDelPWM_SetVector(&interrupcionDelPWM_Interrupt);
    
    
    isr_GPIO_StartEx(GPIOIsrHandler);
    isr_GPIO_SetPriority(0);
    
    generadorPulsosPWM_Start();
    Timer_1_Start();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
   
    generadorPulsosPWM_WriteCompare(90);
    
    ledSoftwareInterrupcionPWM_Write(1);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    for(;;)
    {
        
        
        generadorPulsosPWM_WriteCompare(40);
        
        
        
        
        /* Place your application code here. */
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
