/*******************************************************************************
* File Name: convertidorAnalogicoDigital_INT.c
* Version 3.20
*
* Description:
*  This file contains the code that operates during the ADC_DelSig interrupt
*  service routine.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "convertidorAnalogicoDigital.h"
#include "cyapicallbacks.h"


/*******************************************************************************
* Custom Declarations and Variables
* - add user include files, prototypes and variables between the following
*   #START and #END tags
*******************************************************************************/
/* `#START ADC_SYS_VAR`  */

/* `#END`  */

#if(convertidorAnalogicoDigital_IRQ_REMOVE == 0u)


    /*****************************************************************************
    * Function Name: convertidorAnalogicoDigital_ISR1
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( convertidorAnalogicoDigital_ISR1)
    {
        #ifdef convertidorAnalogicoDigital_ISR1_ENTRY_CALLBACK
            convertidorAnalogicoDigital_ISR1_EntryCallback();
        #endif /* convertidorAnalogicoDigital_ISR1_ENTRY_CALLBACK */
        

        /**************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR1`  */

        /* `#END`  */
        
        /* Stop the conversion if conversion mode is single sample and resolution
        *  is above 16 bits.
        */
        #if(convertidorAnalogicoDigital_CFG1_RESOLUTION > 16 && \
            convertidorAnalogicoDigital_CFG1_CONV_MODE == convertidorAnalogicoDigital_MODE_SINGLE_SAMPLE)
            convertidorAnalogicoDigital_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *  resolution is above 16 bits and conversion mode is single sample 
			*/
            convertidorAnalogicoDigital_convDone = convertidorAnalogicoDigital_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */

        #ifdef convertidorAnalogicoDigital_ISR1_EXIT_CALLBACK
            convertidorAnalogicoDigital_ISR1_ExitCallback();
        #endif /* convertidorAnalogicoDigital_ISR1_EXIT_CALLBACK */
    }


    /*****************************************************************************
    * Function Name: convertidorAnalogicoDigital_ISR2
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( convertidorAnalogicoDigital_ISR2)
    {
        #ifdef convertidorAnalogicoDigital_ISR2_ENTRY_CALLBACK
            convertidorAnalogicoDigital_ISR2_EntryCallback();
        #endif /* convertidorAnalogicoDigital_ISR2_ENTRY_CALLBACK */
        
        
        /***************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR2`  */

        /* `#END`  */

        /* Stop the conversion conversion mode is single sample and resolution
        *  is above 16 bits.
        */
        #if(convertidorAnalogicoDigital_CFG2_RESOLUTION > 16 && \
            convertidorAnalogicoDigital_CFG2_CONVMODE == convertidorAnalogicoDigital_MODE_SINGLE_SAMPLE)
            convertidorAnalogicoDigital_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *   resolution is above 16 bits and conversion mode is single sample 
			*/
            convertidorAnalogicoDigital_convDone = convertidorAnalogicoDigital_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */

        #ifdef convertidorAnalogicoDigital_ISR2_EXIT_CALLBACK
            convertidorAnalogicoDigital_ISR2_ExitCallback();
        #endif /* convertidorAnalogicoDigital_ISR2_EXIT_CALLBACK */
    }


    /*****************************************************************************
    * Function Name: convertidorAnalogicoDigital_ISR3
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( convertidorAnalogicoDigital_ISR3)
    {
        #ifdef convertidorAnalogicoDigital_ISR3_ENTRY_CALLBACK
            convertidorAnalogicoDigital_ISR3_EntryCallback();
        #endif /* convertidorAnalogicoDigital_ISR3_ENTRY_CALLBACK */        

        
        /***************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR3`  */

        /* `#END`  */
        
        /* Stop the conversion if conversion mode is set to single sample and
        *  resolution is above 16 bits.
        */
        #if(convertidorAnalogicoDigital_CFG3_RESOLUTION > 16 && \
            convertidorAnalogicoDigital_CFG3_CONVMODE == convertidorAnalogicoDigital_MODE_SINGLE_SAMPLE)
            convertidorAnalogicoDigital_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *  resolution is above 16 bits and conversion mode is single sample 
			*/
            convertidorAnalogicoDigital_convDone = convertidorAnalogicoDigital_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */

        #ifdef convertidorAnalogicoDigital_ISR3_EXIT_CALLBACK
            convertidorAnalogicoDigital_ISR3_ExitCallback();
        #endif /* convertidorAnalogicoDigital_ISR3_EXIT_CALLBACK */        
    }


    /*****************************************************************************
    * Function Name: convertidorAnalogicoDigital_ISR4
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( convertidorAnalogicoDigital_ISR4)
    {
        #ifdef convertidorAnalogicoDigital_ISR4_ENTRY_CALLBACK
            convertidorAnalogicoDigital_ISR4_EntryCallback();
        #endif /* convertidorAnalogicoDigital_ISR4_ENTRY_CALLBACK */            

        
        /***************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR4`  */

        /* `#END`  */

        /* Stop the conversion if conversion mode is set to single sample and
        *  resolution is above 16 bits.
        */
        #if(convertidorAnalogicoDigital_CFG4_RESOLUTION > 16 && \
            convertidorAnalogicoDigital_CFG4_CONVMODE == convertidorAnalogicoDigital_MODE_SINGLE_SAMPLE)
            convertidorAnalogicoDigital_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *  resolution is above 16 bits and conversion mode is single sample 
			*/
            convertidorAnalogicoDigital_convDone = convertidorAnalogicoDigital_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */
        
        #ifdef convertidorAnalogicoDigital_ISR4_EXIT_CALLBACK
            convertidorAnalogicoDigital_ISR4_ExitCallback();
        #endif /* convertidorAnalogicoDigital_ISR4_EXIT_CALLBACK */            
    }

#endif   /* End convertidorAnalogicoDigital_IRQ_REMOVE */


/* [] END OF FILE */
