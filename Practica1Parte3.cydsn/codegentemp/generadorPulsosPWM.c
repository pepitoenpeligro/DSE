/*******************************************************************************
* File Name: generadorPulsosPWM.c
* Version 3.30
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks.
*  The compare value output may be configured to be active when the present
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "generadorPulsosPWM.h"

/* Error message for removed <resource> through optimization */
#ifdef generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 generadorPulsosPWM_initVar = 0u;


/*******************************************************************************
* Function Name: generadorPulsosPWM_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  generadorPulsosPWM_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void generadorPulsosPWM_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(generadorPulsosPWM_initVar == 0u)
    {
        generadorPulsosPWM_Init();
        generadorPulsosPWM_initVar = 1u;
    }
    generadorPulsosPWM_Enable();

}


/*******************************************************************************
* Function Name: generadorPulsosPWM_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  generadorPulsosPWM_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void generadorPulsosPWM_Init(void) 
{
    #if (generadorPulsosPWM_UsingFixedFunction || generadorPulsosPWM_UseControl)
        uint8 ctrl;
    #endif /* (generadorPulsosPWM_UsingFixedFunction || generadorPulsosPWM_UseControl) */

    #if(!generadorPulsosPWM_UsingFixedFunction)
        #if(generadorPulsosPWM_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 generadorPulsosPWM_interruptState;
        #endif /* (generadorPulsosPWM_UseStatus) */
    #endif /* (!generadorPulsosPWM_UsingFixedFunction) */

    #if (generadorPulsosPWM_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        generadorPulsosPWM_CONTROL |= generadorPulsosPWM_CFG0_MODE;
        #if (generadorPulsosPWM_DeadBand2_4)
            generadorPulsosPWM_CONTROL |= generadorPulsosPWM_CFG0_DB;
        #endif /* (generadorPulsosPWM_DeadBand2_4) */

        ctrl = generadorPulsosPWM_CONTROL3 & ((uint8 )(~generadorPulsosPWM_CTRL_CMPMODE1_MASK));
        generadorPulsosPWM_CONTROL3 = ctrl | generadorPulsosPWM_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        generadorPulsosPWM_RT1 &= ((uint8)(~generadorPulsosPWM_RT1_MASK));
        generadorPulsosPWM_RT1 |= generadorPulsosPWM_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        generadorPulsosPWM_RT1 &= ((uint8)(~generadorPulsosPWM_SYNCDSI_MASK));
        generadorPulsosPWM_RT1 |= generadorPulsosPWM_SYNCDSI_EN;

    #elif (generadorPulsosPWM_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = generadorPulsosPWM_CONTROL & ((uint8)(~generadorPulsosPWM_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~generadorPulsosPWM_CTRL_CMPMODE1_MASK));
        generadorPulsosPWM_CONTROL = ctrl | generadorPulsosPWM_DEFAULT_COMPARE2_MODE |
                                   generadorPulsosPWM_DEFAULT_COMPARE1_MODE;
    #endif /* (generadorPulsosPWM_UsingFixedFunction) */

    #if (!generadorPulsosPWM_UsingFixedFunction)
        #if (generadorPulsosPWM_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            generadorPulsosPWM_AUX_CONTROLDP0 |= (generadorPulsosPWM_AUX_CTRL_FIFO0_CLR);
        #else /* (generadorPulsosPWM_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            generadorPulsosPWM_AUX_CONTROLDP0 |= (generadorPulsosPWM_AUX_CTRL_FIFO0_CLR);
            generadorPulsosPWM_AUX_CONTROLDP1 |= (generadorPulsosPWM_AUX_CTRL_FIFO0_CLR);
        #endif /* (generadorPulsosPWM_Resolution == 8) */

        generadorPulsosPWM_WriteCounter(generadorPulsosPWM_INIT_PERIOD_VALUE);
    #endif /* (!generadorPulsosPWM_UsingFixedFunction) */

    generadorPulsosPWM_WritePeriod(generadorPulsosPWM_INIT_PERIOD_VALUE);

        #if (generadorPulsosPWM_UseOneCompareMode)
            generadorPulsosPWM_WriteCompare(generadorPulsosPWM_INIT_COMPARE_VALUE1);
        #else
            generadorPulsosPWM_WriteCompare1(generadorPulsosPWM_INIT_COMPARE_VALUE1);
            generadorPulsosPWM_WriteCompare2(generadorPulsosPWM_INIT_COMPARE_VALUE2);
        #endif /* (generadorPulsosPWM_UseOneCompareMode) */

        #if (generadorPulsosPWM_KillModeMinTime)
            generadorPulsosPWM_WriteKillTime(generadorPulsosPWM_MinimumKillTime);
        #endif /* (generadorPulsosPWM_KillModeMinTime) */

        #if (generadorPulsosPWM_DeadBandUsed)
            generadorPulsosPWM_WriteDeadTime(generadorPulsosPWM_INIT_DEAD_TIME);
        #endif /* (generadorPulsosPWM_DeadBandUsed) */

    #if (generadorPulsosPWM_UseStatus || generadorPulsosPWM_UsingFixedFunction)
        generadorPulsosPWM_SetInterruptMode(generadorPulsosPWM_INIT_INTERRUPTS_MODE);
    #endif /* (generadorPulsosPWM_UseStatus || generadorPulsosPWM_UsingFixedFunction) */

    #if (generadorPulsosPWM_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        generadorPulsosPWM_GLOBAL_ENABLE |= generadorPulsosPWM_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        generadorPulsosPWM_CONTROL2 |= generadorPulsosPWM_CTRL2_IRQ_SEL;
    #else
        #if(generadorPulsosPWM_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            generadorPulsosPWM_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            generadorPulsosPWM_STATUS_AUX_CTRL |= generadorPulsosPWM_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(generadorPulsosPWM_interruptState);

            /* Clear the FIFO to enable the generadorPulsosPWM_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            generadorPulsosPWM_ClearFIFO();
        #endif /* (generadorPulsosPWM_UseStatus) */
    #endif /* (generadorPulsosPWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: generadorPulsosPWM_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM block operation
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void generadorPulsosPWM_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (generadorPulsosPWM_UsingFixedFunction)
        generadorPulsosPWM_GLOBAL_ENABLE |= generadorPulsosPWM_BLOCK_EN_MASK;
        generadorPulsosPWM_GLOBAL_STBY_ENABLE |= generadorPulsosPWM_BLOCK_STBY_EN_MASK;
    #endif /* (generadorPulsosPWM_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (generadorPulsosPWM_UseControl || generadorPulsosPWM_UsingFixedFunction)
        generadorPulsosPWM_CONTROL |= generadorPulsosPWM_CTRL_ENABLE;
    #endif /* (generadorPulsosPWM_UseControl || generadorPulsosPWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: generadorPulsosPWM_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void generadorPulsosPWM_Stop(void) 
{
    #if (generadorPulsosPWM_UseControl || generadorPulsosPWM_UsingFixedFunction)
        generadorPulsosPWM_CONTROL &= ((uint8)(~generadorPulsosPWM_CTRL_ENABLE));
    #endif /* (generadorPulsosPWM_UseControl || generadorPulsosPWM_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (generadorPulsosPWM_UsingFixedFunction)
        generadorPulsosPWM_GLOBAL_ENABLE &= ((uint8)(~generadorPulsosPWM_BLOCK_EN_MASK));
        generadorPulsosPWM_GLOBAL_STBY_ENABLE &= ((uint8)(~generadorPulsosPWM_BLOCK_STBY_EN_MASK));
    #endif /* (generadorPulsosPWM_UsingFixedFunction) */
}

#if (generadorPulsosPWM_UseOneCompareMode)
    #if (generadorPulsosPWM_CompareMode1SW)


        /*******************************************************************************
        * Function Name: generadorPulsosPWM_SetCompareMode
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm output when in Dither mode,
        *  Center Align Mode or One Output Mode.
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void generadorPulsosPWM_SetCompareMode(uint8 comparemode) 
        {
            #if(generadorPulsosPWM_UsingFixedFunction)

                #if(0 != generadorPulsosPWM_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << generadorPulsosPWM_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != generadorPulsosPWM_CTRL_CMPMODE1_SHIFT) */

                generadorPulsosPWM_CONTROL3 &= ((uint8)(~generadorPulsosPWM_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                generadorPulsosPWM_CONTROL3 |= comparemodemasked;

            #elif (generadorPulsosPWM_UseControl)

                #if(0 != generadorPulsosPWM_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << generadorPulsosPWM_CTRL_CMPMODE1_SHIFT)) &
                                                generadorPulsosPWM_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & generadorPulsosPWM_CTRL_CMPMODE1_MASK;
                #endif /* (0 != generadorPulsosPWM_CTRL_CMPMODE1_SHIFT) */

                #if(0 != generadorPulsosPWM_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << generadorPulsosPWM_CTRL_CMPMODE2_SHIFT)) &
                                               generadorPulsosPWM_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & generadorPulsosPWM_CTRL_CMPMODE2_MASK;
                #endif /* (0 != generadorPulsosPWM_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                generadorPulsosPWM_CONTROL &= ((uint8)(~(generadorPulsosPWM_CTRL_CMPMODE1_MASK |
                                            generadorPulsosPWM_CTRL_CMPMODE2_MASK)));
                generadorPulsosPWM_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (generadorPulsosPWM_UsingFixedFunction) */
        }
    #endif /* generadorPulsosPWM_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (generadorPulsosPWM_CompareMode1SW)


        /*******************************************************************************
        * Function Name: generadorPulsosPWM_SetCompareMode1
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm or pwm1 output
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void generadorPulsosPWM_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != generadorPulsosPWM_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << generadorPulsosPWM_CTRL_CMPMODE1_SHIFT)) &
                                           generadorPulsosPWM_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & generadorPulsosPWM_CTRL_CMPMODE1_MASK;
            #endif /* (0 != generadorPulsosPWM_CTRL_CMPMODE1_SHIFT) */

            #if (generadorPulsosPWM_UseControl)
                generadorPulsosPWM_CONTROL &= ((uint8)(~generadorPulsosPWM_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                generadorPulsosPWM_CONTROL |= comparemodemasked;
            #endif /* (generadorPulsosPWM_UseControl) */
        }
    #endif /* generadorPulsosPWM_CompareMode1SW */

#if (generadorPulsosPWM_CompareMode2SW)


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_SetCompareMode2
    ********************************************************************************
    *
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void generadorPulsosPWM_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != generadorPulsosPWM_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << generadorPulsosPWM_CTRL_CMPMODE2_SHIFT)) &
                                                 generadorPulsosPWM_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & generadorPulsosPWM_CTRL_CMPMODE2_MASK;
        #endif /* (0 != generadorPulsosPWM_CTRL_CMPMODE2_SHIFT) */

        #if (generadorPulsosPWM_UseControl)
            generadorPulsosPWM_CONTROL &= ((uint8)(~generadorPulsosPWM_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            generadorPulsosPWM_CONTROL |= comparemodemasked;
        #endif /* (generadorPulsosPWM_UseControl) */
    }
    #endif /*generadorPulsosPWM_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!generadorPulsosPWM_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_WriteCounter
    ********************************************************************************
    *
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be
    *  implemented for that currently running period and only that period. This API
    *  is valid only for UDB implementation and not available for fixed function
    *  PWM implementation.
    *
    * Parameters:
    *  counter:  The period new period counter value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void generadorPulsosPWM_WriteCounter(uint8 counter) \
                                       
    {
        CY_SET_REG8(generadorPulsosPWM_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_ReadCounter
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint8 generadorPulsosPWM_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(generadorPulsosPWM_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG8(generadorPulsosPWM_CAPTURE_LSB_PTR));
    }

    #if (generadorPulsosPWM_UseStatus)


        /*******************************************************************************
        * Function Name: generadorPulsosPWM_ClearFIFO
        ********************************************************************************
        *
        * Summary:
        *  This function clears all capture data from the capture FIFO
        *
        * Parameters:
        *  None
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void generadorPulsosPWM_ClearFIFO(void) 
        {
            while(0u != (generadorPulsosPWM_ReadStatusRegister() & generadorPulsosPWM_STATUS_FIFONEMPTY))
            {
                (void)generadorPulsosPWM_ReadCapture();
            }
        }

    #endif /* generadorPulsosPWM_UseStatus */

#endif /* !generadorPulsosPWM_UsingFixedFunction */


/*******************************************************************************
* Function Name: generadorPulsosPWM_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0
*           will result in the counter remaining at zero.
*
* Return:
*  None
*
*******************************************************************************/
void generadorPulsosPWM_WritePeriod(uint8 period) 
{
    #if(generadorPulsosPWM_UsingFixedFunction)
        CY_SET_REG16(generadorPulsosPWM_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG8(generadorPulsosPWM_PERIOD_LSB_PTR, period);
    #endif /* (generadorPulsosPWM_UsingFixedFunction) */
}

#if (generadorPulsosPWM_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_WriteCompare
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  compared to the compare value based on the compare mode defined in
    *  Dither Mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void generadorPulsosPWM_WriteCompare(uint8 compare) \
                                       
    {
        #if(generadorPulsosPWM_UsingFixedFunction)
            CY_SET_REG16(generadorPulsosPWM_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG8(generadorPulsosPWM_COMPARE1_LSB_PTR, compare);
        #endif /* (generadorPulsosPWM_UsingFixedFunction) */

        #if (generadorPulsosPWM_PWMMode == generadorPulsosPWM__B_PWM__DITHER)
            #if(generadorPulsosPWM_UsingFixedFunction)
                CY_SET_REG16(generadorPulsosPWM_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG8(generadorPulsosPWM_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (generadorPulsosPWM_UsingFixedFunction) */
        #endif /* (generadorPulsosPWM_PWMMode == generadorPulsosPWM__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_WriteCompare1
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will
    *  reflect the new value on the next UDB clock.  The compare output will be
    *  driven high when the present counter value is less than or less than or
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void generadorPulsosPWM_WriteCompare1(uint8 compare) \
                                        
    {
        #if(generadorPulsosPWM_UsingFixedFunction)
            CY_SET_REG16(generadorPulsosPWM_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG8(generadorPulsosPWM_COMPARE1_LSB_PTR, compare);
        #endif /* (generadorPulsosPWM_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_WriteCompare2
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.
    *  The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  less than or less than or equal to the compare register, depending on the
    *  mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void generadorPulsosPWM_WriteCompare2(uint8 compare) \
                                        
    {
        #if(generadorPulsosPWM_UsingFixedFunction)
            CY_SET_REG16(generadorPulsosPWM_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG8(generadorPulsosPWM_COMPARE2_LSB_PTR, compare);
        #endif /* (generadorPulsosPWM_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (generadorPulsosPWM_DeadBandUsed)


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_WriteDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:
    *  deadtime:  Number of counts for dead time
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void generadorPulsosPWM_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!generadorPulsosPWM_DeadBand2_4)
            CY_SET_REG8(generadorPulsosPWM_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            generadorPulsosPWM_DEADBAND_COUNT &= ((uint8)(~generadorPulsosPWM_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(generadorPulsosPWM_DEADBAND_COUNT_SHIFT)
                generadorPulsosPWM_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << generadorPulsosPWM_DEADBAND_COUNT_SHIFT)) &
                                                    generadorPulsosPWM_DEADBAND_COUNT_MASK;
            #else
                generadorPulsosPWM_DEADBAND_COUNT |= deadtime & generadorPulsosPWM_DEADBAND_COUNT_MASK;
            #endif /* (generadorPulsosPWM_DEADBAND_COUNT_SHIFT) */

        #endif /* (!generadorPulsosPWM_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_ReadDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 generadorPulsosPWM_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!generadorPulsosPWM_DeadBand2_4)
            return (CY_GET_REG8(generadorPulsosPWM_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(generadorPulsosPWM_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(generadorPulsosPWM_DEADBAND_COUNT & generadorPulsosPWM_DEADBAND_COUNT_MASK)) >>
                                                                           generadorPulsosPWM_DEADBAND_COUNT_SHIFT));
            #else
                return (generadorPulsosPWM_DEADBAND_COUNT & generadorPulsosPWM_DEADBAND_COUNT_MASK);
            #endif /* (generadorPulsosPWM_DEADBAND_COUNT_SHIFT) */
        #endif /* (!generadorPulsosPWM_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (generadorPulsosPWM_UseStatus || generadorPulsosPWM_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_SetInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt
    *  source status register.
    *
    * Parameters:
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void generadorPulsosPWM_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(generadorPulsosPWM_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_ReadStatusRegister
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current state of the status register.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 generadorPulsosPWM_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(generadorPulsosPWM_STATUS_PTR));
    }

#endif /* (generadorPulsosPWM_UseStatus || generadorPulsosPWM_UsingFixedFunction) */


#if (generadorPulsosPWM_UseControl)


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_ReadControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the control register. This API is available
    *  only if the control register is not removed.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current control register value
    *
    *******************************************************************************/
    uint8 generadorPulsosPWM_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(generadorPulsosPWM_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_WriteControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Sets the bit field of the control register. This API is available only if
    *  the control register is not removed.
    *
    * Parameters:
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void generadorPulsosPWM_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(generadorPulsosPWM_CONTROL_PTR, control);
    }

#endif /* (generadorPulsosPWM_UseControl) */


#if (!generadorPulsosPWM_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_ReadCapture
    ********************************************************************************
    *
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/
    uint8 generadorPulsosPWM_ReadCapture(void) 
    {
        return (CY_GET_REG8(generadorPulsosPWM_CAPTURE_LSB_PTR));
    }

#endif /* (!generadorPulsosPWM_UsingFixedFunction) */


#if (generadorPulsosPWM_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_ReadCompare
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/
    uint8 generadorPulsosPWM_ReadCompare(void) 
    {
        #if(generadorPulsosPWM_UsingFixedFunction)
            return ((uint8)CY_GET_REG16(generadorPulsosPWM_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG8(generadorPulsosPWM_COMPARE1_LSB_PTR));
        #endif /* (generadorPulsosPWM_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_ReadCompare1
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint8 generadorPulsosPWM_ReadCompare1(void) 
    {
        return (CY_GET_REG8(generadorPulsosPWM_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_ReadCompare2
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint8 generadorPulsosPWM_ReadCompare2(void) 
    {
        return (CY_GET_REG8(generadorPulsosPWM_COMPARE2_LSB_PTR));
    }

#endif /* (generadorPulsosPWM_UseOneCompareMode) */


/*******************************************************************************
* Function Name: generadorPulsosPWM_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:
*  None
*
* Return:
*  uint8/16: Period value
*
*******************************************************************************/
uint8 generadorPulsosPWM_ReadPeriod(void) 
{
    #if(generadorPulsosPWM_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(generadorPulsosPWM_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(generadorPulsosPWM_PERIOD_LSB_PTR));
    #endif /* (generadorPulsosPWM_UsingFixedFunction) */
}

#if ( generadorPulsosPWM_KillModeMinTime)


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_WriteKillTime
    ********************************************************************************
    *
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode
    *  is set to Minimum Time.
    *
    * Parameters:
    *  uint8: Minimum Time kill counts
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void generadorPulsosPWM_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(generadorPulsosPWM_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: generadorPulsosPWM_ReadKillTime
    ********************************************************************************
    *
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set
    *  to Minimum Time.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/
    uint8 generadorPulsosPWM_ReadKillTime(void) 
    {
        return (CY_GET_REG8(generadorPulsosPWM_KILLMODEMINTIME_PTR));
    }

#endif /* ( generadorPulsosPWM_KillModeMinTime) */

/* [] END OF FILE */
