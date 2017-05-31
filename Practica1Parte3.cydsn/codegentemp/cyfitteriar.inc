#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar.inc
    INCLUDE cydeviceiar_trm.inc

/* Clock_1 */
Clock_1__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
Clock_1__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
Clock_1__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
Clock_1__CFG2_SRC_SEL_MASK EQU 0x07
Clock_1__INDEX EQU 0x00
Clock_1__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_1__PM_ACT_MSK EQU 0x01
Clock_1__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_1__PM_STBY_MSK EQU 0x01

/* Clock_2 */
Clock_2__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
Clock_2__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
Clock_2__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
Clock_2__CFG2_SRC_SEL_MASK EQU 0x07
Clock_2__INDEX EQU 0x01
Clock_2__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_2__PM_ACT_MSK EQU 0x02
Clock_2__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_2__PM_STBY_MSK EQU 0x02

/* Timer_1_TimerUDB */
Timer_1_TimerUDB_rstSts_stsreg__0__MASK EQU 0x01
Timer_1_TimerUDB_rstSts_stsreg__0__POS EQU 0
Timer_1_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
Timer_1_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB08_09_ST
Timer_1_TimerUDB_rstSts_stsreg__2__MASK EQU 0x04
Timer_1_TimerUDB_rstSts_stsreg__2__POS EQU 2
Timer_1_TimerUDB_rstSts_stsreg__3__MASK EQU 0x08
Timer_1_TimerUDB_rstSts_stsreg__3__POS EQU 3
Timer_1_TimerUDB_rstSts_stsreg__MASK EQU 0x0D
Timer_1_TimerUDB_rstSts_stsreg__MASK_REG EQU CYREG_B0_UDB08_MSK
Timer_1_TimerUDB_rstSts_stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB08_MSK_ACTL
Timer_1_TimerUDB_rstSts_stsreg__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB08_MSK_ACTL
Timer_1_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
Timer_1_TimerUDB_rstSts_stsreg__STATUS_CNT_REG EQU CYREG_B0_UDB08_ST_CTL
Timer_1_TimerUDB_rstSts_stsreg__STATUS_CONTROL_REG EQU CYREG_B0_UDB08_ST_CTL
Timer_1_TimerUDB_rstSts_stsreg__STATUS_REG EQU CYREG_B0_UDB08_ST
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB08_09_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB08_09_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB08_09_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB08_09_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB08_09_MSK
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB08_09_MSK
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB08_09_MSK
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB08_09_MSK
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK EQU 0x80
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS EQU 7
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB08_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB08_ST_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG EQU CYREG_B0_UDB08_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB08_ST_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK EQU 0x80
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB08_MSK_ACTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB08_MSK_ACTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB08_MSK
Timer_1_TimerUDB_sT32_timerdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB08_09_A0
Timer_1_TimerUDB_sT32_timerdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB08_09_A1
Timer_1_TimerUDB_sT32_timerdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB08_09_D0
Timer_1_TimerUDB_sT32_timerdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB08_09_D1
Timer_1_TimerUDB_sT32_timerdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
Timer_1_TimerUDB_sT32_timerdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB08_09_F0
Timer_1_TimerUDB_sT32_timerdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB08_09_F1
Timer_1_TimerUDB_sT32_timerdp_u0__A0_A1_REG EQU CYREG_B0_UDB08_A0_A1
Timer_1_TimerUDB_sT32_timerdp_u0__A0_REG EQU CYREG_B0_UDB08_A0
Timer_1_TimerUDB_sT32_timerdp_u0__A1_REG EQU CYREG_B0_UDB08_A1
Timer_1_TimerUDB_sT32_timerdp_u0__D0_D1_REG EQU CYREG_B0_UDB08_D0_D1
Timer_1_TimerUDB_sT32_timerdp_u0__D0_REG EQU CYREG_B0_UDB08_D0
Timer_1_TimerUDB_sT32_timerdp_u0__D1_REG EQU CYREG_B0_UDB08_D1
Timer_1_TimerUDB_sT32_timerdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
Timer_1_TimerUDB_sT32_timerdp_u0__F0_F1_REG EQU CYREG_B0_UDB08_F0_F1
Timer_1_TimerUDB_sT32_timerdp_u0__F0_REG EQU CYREG_B0_UDB08_F0
Timer_1_TimerUDB_sT32_timerdp_u0__F1_REG EQU CYREG_B0_UDB08_F1
Timer_1_TimerUDB_sT32_timerdp_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB08_MSK_ACTL
Timer_1_TimerUDB_sT32_timerdp_u0__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB08_MSK_ACTL
Timer_1_TimerUDB_sT32_timerdp_u1__16BIT_A0_REG EQU CYREG_B0_UDB09_10_A0
Timer_1_TimerUDB_sT32_timerdp_u1__16BIT_A1_REG EQU CYREG_B0_UDB09_10_A1
Timer_1_TimerUDB_sT32_timerdp_u1__16BIT_D0_REG EQU CYREG_B0_UDB09_10_D0
Timer_1_TimerUDB_sT32_timerdp_u1__16BIT_D1_REG EQU CYREG_B0_UDB09_10_D1
Timer_1_TimerUDB_sT32_timerdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
Timer_1_TimerUDB_sT32_timerdp_u1__16BIT_F0_REG EQU CYREG_B0_UDB09_10_F0
Timer_1_TimerUDB_sT32_timerdp_u1__16BIT_F1_REG EQU CYREG_B0_UDB09_10_F1
Timer_1_TimerUDB_sT32_timerdp_u1__A0_A1_REG EQU CYREG_B0_UDB09_A0_A1
Timer_1_TimerUDB_sT32_timerdp_u1__A0_REG EQU CYREG_B0_UDB09_A0
Timer_1_TimerUDB_sT32_timerdp_u1__A1_REG EQU CYREG_B0_UDB09_A1
Timer_1_TimerUDB_sT32_timerdp_u1__D0_D1_REG EQU CYREG_B0_UDB09_D0_D1
Timer_1_TimerUDB_sT32_timerdp_u1__D0_REG EQU CYREG_B0_UDB09_D0
Timer_1_TimerUDB_sT32_timerdp_u1__D1_REG EQU CYREG_B0_UDB09_D1
Timer_1_TimerUDB_sT32_timerdp_u1__DP_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
Timer_1_TimerUDB_sT32_timerdp_u1__F0_F1_REG EQU CYREG_B0_UDB09_F0_F1
Timer_1_TimerUDB_sT32_timerdp_u1__F0_REG EQU CYREG_B0_UDB09_F0
Timer_1_TimerUDB_sT32_timerdp_u1__F1_REG EQU CYREG_B0_UDB09_F1
Timer_1_TimerUDB_sT32_timerdp_u2__16BIT_A0_REG EQU CYREG_B0_UDB10_11_A0
Timer_1_TimerUDB_sT32_timerdp_u2__16BIT_A1_REG EQU CYREG_B0_UDB10_11_A1
Timer_1_TimerUDB_sT32_timerdp_u2__16BIT_D0_REG EQU CYREG_B0_UDB10_11_D0
Timer_1_TimerUDB_sT32_timerdp_u2__16BIT_D1_REG EQU CYREG_B0_UDB10_11_D1
Timer_1_TimerUDB_sT32_timerdp_u2__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
Timer_1_TimerUDB_sT32_timerdp_u2__16BIT_F0_REG EQU CYREG_B0_UDB10_11_F0
Timer_1_TimerUDB_sT32_timerdp_u2__16BIT_F1_REG EQU CYREG_B0_UDB10_11_F1
Timer_1_TimerUDB_sT32_timerdp_u2__A0_A1_REG EQU CYREG_B0_UDB10_A0_A1
Timer_1_TimerUDB_sT32_timerdp_u2__A0_REG EQU CYREG_B0_UDB10_A0
Timer_1_TimerUDB_sT32_timerdp_u2__A1_REG EQU CYREG_B0_UDB10_A1
Timer_1_TimerUDB_sT32_timerdp_u2__D0_D1_REG EQU CYREG_B0_UDB10_D0_D1
Timer_1_TimerUDB_sT32_timerdp_u2__D0_REG EQU CYREG_B0_UDB10_D0
Timer_1_TimerUDB_sT32_timerdp_u2__D1_REG EQU CYREG_B0_UDB10_D1
Timer_1_TimerUDB_sT32_timerdp_u2__DP_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
Timer_1_TimerUDB_sT32_timerdp_u2__F0_F1_REG EQU CYREG_B0_UDB10_F0_F1
Timer_1_TimerUDB_sT32_timerdp_u2__F0_REG EQU CYREG_B0_UDB10_F0
Timer_1_TimerUDB_sT32_timerdp_u2__F1_REG EQU CYREG_B0_UDB10_F1
Timer_1_TimerUDB_sT32_timerdp_u3__16BIT_A0_REG EQU CYREG_B0_UDB11_12_A0
Timer_1_TimerUDB_sT32_timerdp_u3__16BIT_A1_REG EQU CYREG_B0_UDB11_12_A1
Timer_1_TimerUDB_sT32_timerdp_u3__16BIT_D0_REG EQU CYREG_B0_UDB11_12_D0
Timer_1_TimerUDB_sT32_timerdp_u3__16BIT_D1_REG EQU CYREG_B0_UDB11_12_D1
Timer_1_TimerUDB_sT32_timerdp_u3__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
Timer_1_TimerUDB_sT32_timerdp_u3__16BIT_F0_REG EQU CYREG_B0_UDB11_12_F0
Timer_1_TimerUDB_sT32_timerdp_u3__16BIT_F1_REG EQU CYREG_B0_UDB11_12_F1
Timer_1_TimerUDB_sT32_timerdp_u3__A0_A1_REG EQU CYREG_B0_UDB11_A0_A1
Timer_1_TimerUDB_sT32_timerdp_u3__A0_REG EQU CYREG_B0_UDB11_A0
Timer_1_TimerUDB_sT32_timerdp_u3__A1_REG EQU CYREG_B0_UDB11_A1
Timer_1_TimerUDB_sT32_timerdp_u3__D0_D1_REG EQU CYREG_B0_UDB11_D0_D1
Timer_1_TimerUDB_sT32_timerdp_u3__D0_REG EQU CYREG_B0_UDB11_D0
Timer_1_TimerUDB_sT32_timerdp_u3__D1_REG EQU CYREG_B0_UDB11_D1
Timer_1_TimerUDB_sT32_timerdp_u3__DP_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
Timer_1_TimerUDB_sT32_timerdp_u3__F0_F1_REG EQU CYREG_B0_UDB11_F0_F1
Timer_1_TimerUDB_sT32_timerdp_u3__F0_REG EQU CYREG_B0_UDB11_F0
Timer_1_TimerUDB_sT32_timerdp_u3__F1_REG EQU CYREG_B0_UDB11_F1

/* isr_GPIO */
isr_GPIO__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_GPIO__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_GPIO__INTC_MASK EQU 0x01
isr_GPIO__INTC_NUMBER EQU 0
isr_GPIO__INTC_PRIOR_NUM EQU 7
isr_GPIO__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
isr_GPIO__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_GPIO__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* ledHardwarePWM */
ledHardwarePWM__0__INTTYPE EQU CYREG_PICU2_INTTYPE7
ledHardwarePWM__0__MASK EQU 0x80
ledHardwarePWM__0__PC EQU CYREG_PRT2_PC7
ledHardwarePWM__0__PORT EQU 2
ledHardwarePWM__0__SHIFT EQU 7
ledHardwarePWM__AG EQU CYREG_PRT2_AG
ledHardwarePWM__AMUX EQU CYREG_PRT2_AMUX
ledHardwarePWM__BIE EQU CYREG_PRT2_BIE
ledHardwarePWM__BIT_MASK EQU CYREG_PRT2_BIT_MASK
ledHardwarePWM__BYP EQU CYREG_PRT2_BYP
ledHardwarePWM__CTL EQU CYREG_PRT2_CTL
ledHardwarePWM__DM0 EQU CYREG_PRT2_DM0
ledHardwarePWM__DM1 EQU CYREG_PRT2_DM1
ledHardwarePWM__DM2 EQU CYREG_PRT2_DM2
ledHardwarePWM__DR EQU CYREG_PRT2_DR
ledHardwarePWM__INP_DIS EQU CYREG_PRT2_INP_DIS
ledHardwarePWM__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
ledHardwarePWM__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
ledHardwarePWM__LCD_EN EQU CYREG_PRT2_LCD_EN
ledHardwarePWM__MASK EQU 0x80
ledHardwarePWM__PORT EQU 2
ledHardwarePWM__PRT EQU CYREG_PRT2_PRT
ledHardwarePWM__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
ledHardwarePWM__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
ledHardwarePWM__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
ledHardwarePWM__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
ledHardwarePWM__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
ledHardwarePWM__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
ledHardwarePWM__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
ledHardwarePWM__PS EQU CYREG_PRT2_PS
ledHardwarePWM__SHIFT EQU 7
ledHardwarePWM__SLW EQU CYREG_PRT2_SLW

/* botoncitoRegulador */
botoncitoRegulador__0__INTTYPE EQU CYREG_PICU1_INTTYPE5
botoncitoRegulador__0__MASK EQU 0x20
botoncitoRegulador__0__PC EQU CYREG_PRT1_PC5
botoncitoRegulador__0__PORT EQU 1
botoncitoRegulador__0__SHIFT EQU 5
botoncitoRegulador__AG EQU CYREG_PRT1_AG
botoncitoRegulador__AMUX EQU CYREG_PRT1_AMUX
botoncitoRegulador__BIE EQU CYREG_PRT1_BIE
botoncitoRegulador__BIT_MASK EQU CYREG_PRT1_BIT_MASK
botoncitoRegulador__BYP EQU CYREG_PRT1_BYP
botoncitoRegulador__CTL EQU CYREG_PRT1_CTL
botoncitoRegulador__DM0 EQU CYREG_PRT1_DM0
botoncitoRegulador__DM1 EQU CYREG_PRT1_DM1
botoncitoRegulador__DM2 EQU CYREG_PRT1_DM2
botoncitoRegulador__DR EQU CYREG_PRT1_DR
botoncitoRegulador__INP_DIS EQU CYREG_PRT1_INP_DIS
botoncitoRegulador__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
botoncitoRegulador__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
botoncitoRegulador__LCD_EN EQU CYREG_PRT1_LCD_EN
botoncitoRegulador__MASK EQU 0x20
botoncitoRegulador__PORT EQU 1
botoncitoRegulador__PRT EQU CYREG_PRT1_PRT
botoncitoRegulador__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
botoncitoRegulador__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
botoncitoRegulador__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
botoncitoRegulador__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
botoncitoRegulador__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
botoncitoRegulador__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
botoncitoRegulador__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
botoncitoRegulador__PS EQU CYREG_PRT1_PS
botoncitoRegulador__SHIFT EQU 5
botoncitoRegulador__SLW EQU CYREG_PRT1_SLW

/* generadorPulsosPWM_PWMUDB */
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB09_10_MSK
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB09_10_MSK
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__7__MASK EQU 0x80
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__7__POS EQU 7
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__CONTROL_REG EQU CYREG_B1_UDB09_CTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG EQU CYREG_B1_UDB09_ST_CTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__COUNT_REG EQU CYREG_B1_UDB09_CTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG EQU CYREG_B1_UDB09_ST_CTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__MASK EQU 0x80
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
generadorPulsosPWM_PWMUDB_genblk1_ctrlreg__PERIOD_REG EQU CYREG_B1_UDB09_MSK
generadorPulsosPWM_PWMUDB_genblk8_stsreg__0__MASK EQU 0x01
generadorPulsosPWM_PWMUDB_genblk8_stsreg__0__POS EQU 0
generadorPulsosPWM_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
generadorPulsosPWM_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG EQU CYREG_B1_UDB09_10_ST
generadorPulsosPWM_PWMUDB_genblk8_stsreg__2__MASK EQU 0x04
generadorPulsosPWM_PWMUDB_genblk8_stsreg__2__POS EQU 2
generadorPulsosPWM_PWMUDB_genblk8_stsreg__3__MASK EQU 0x08
generadorPulsosPWM_PWMUDB_genblk8_stsreg__3__POS EQU 3
generadorPulsosPWM_PWMUDB_genblk8_stsreg__MASK EQU 0x0D
generadorPulsosPWM_PWMUDB_genblk8_stsreg__MASK_REG EQU CYREG_B1_UDB09_MSK
generadorPulsosPWM_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
generadorPulsosPWM_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
generadorPulsosPWM_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
generadorPulsosPWM_PWMUDB_genblk8_stsreg__STATUS_CNT_REG EQU CYREG_B1_UDB09_ST_CTL
generadorPulsosPWM_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG EQU CYREG_B1_UDB09_ST_CTL
generadorPulsosPWM_PWMUDB_genblk8_stsreg__STATUS_REG EQU CYREG_B1_UDB09_ST
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG EQU CYREG_B1_UDB09_10_A0
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG EQU CYREG_B1_UDB09_10_A1
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG EQU CYREG_B1_UDB09_10_D0
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG EQU CYREG_B1_UDB09_10_D1
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG EQU CYREG_B1_UDB09_10_F0
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG EQU CYREG_B1_UDB09_10_F1
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A0_A1_REG EQU CYREG_B1_UDB09_A0_A1
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A0_REG EQU CYREG_B1_UDB09_A0
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__A1_REG EQU CYREG_B1_UDB09_A1
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D0_D1_REG EQU CYREG_B1_UDB09_D0_D1
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D0_REG EQU CYREG_B1_UDB09_D0
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__D1_REG EQU CYREG_B1_UDB09_D1
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__F0_F1_REG EQU CYREG_B1_UDB09_F0_F1
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__F0_REG EQU CYREG_B1_UDB09_F0
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__F1_REG EQU CYREG_B1_UDB09_F1
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
generadorPulsosPWM_PWMUDB_sP8_pwmdp_u0__PER_DP_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL

/* ledSoftwareInterrupcionPWM */
ledSoftwareInterrupcionPWM__0__INTTYPE EQU CYREG_PICU1_INTTYPE7
ledSoftwareInterrupcionPWM__0__MASK EQU 0x80
ledSoftwareInterrupcionPWM__0__PC EQU CYREG_PRT1_PC7
ledSoftwareInterrupcionPWM__0__PORT EQU 1
ledSoftwareInterrupcionPWM__0__SHIFT EQU 7
ledSoftwareInterrupcionPWM__AG EQU CYREG_PRT1_AG
ledSoftwareInterrupcionPWM__AMUX EQU CYREG_PRT1_AMUX
ledSoftwareInterrupcionPWM__BIE EQU CYREG_PRT1_BIE
ledSoftwareInterrupcionPWM__BIT_MASK EQU CYREG_PRT1_BIT_MASK
ledSoftwareInterrupcionPWM__BYP EQU CYREG_PRT1_BYP
ledSoftwareInterrupcionPWM__CTL EQU CYREG_PRT1_CTL
ledSoftwareInterrupcionPWM__DM0 EQU CYREG_PRT1_DM0
ledSoftwareInterrupcionPWM__DM1 EQU CYREG_PRT1_DM1
ledSoftwareInterrupcionPWM__DM2 EQU CYREG_PRT1_DM2
ledSoftwareInterrupcionPWM__DR EQU CYREG_PRT1_DR
ledSoftwareInterrupcionPWM__INP_DIS EQU CYREG_PRT1_INP_DIS
ledSoftwareInterrupcionPWM__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
ledSoftwareInterrupcionPWM__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
ledSoftwareInterrupcionPWM__LCD_EN EQU CYREG_PRT1_LCD_EN
ledSoftwareInterrupcionPWM__MASK EQU 0x80
ledSoftwareInterrupcionPWM__PORT EQU 1
ledSoftwareInterrupcionPWM__PRT EQU CYREG_PRT1_PRT
ledSoftwareInterrupcionPWM__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
ledSoftwareInterrupcionPWM__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
ledSoftwareInterrupcionPWM__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
ledSoftwareInterrupcionPWM__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
ledSoftwareInterrupcionPWM__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
ledSoftwareInterrupcionPWM__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
ledSoftwareInterrupcionPWM__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
ledSoftwareInterrupcionPWM__PS EQU CYREG_PRT1_PS
ledSoftwareInterrupcionPWM__SHIFT EQU 7
ledSoftwareInterrupcionPWM__SLW EQU CYREG_PRT1_SLW

/* Miscellaneous */
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 12
CYDEV_CHIP_DIE_PSOC5LP EQU 19
CYDEV_CHIP_DIE_PSOC5TM EQU 20
CYDEV_CHIP_DIE_TMA4 EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 4
CYDEV_CHIP_FAMILY_FM3 EQU 5
CYDEV_CHIP_FAMILY_FM4 EQU 6
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E123069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 12
CYDEV_CHIP_MEMBER_4C EQU 18
CYDEV_CHIP_MEMBER_4D EQU 8
CYDEV_CHIP_MEMBER_4E EQU 4
CYDEV_CHIP_MEMBER_4F EQU 13
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 11
CYDEV_CHIP_MEMBER_4I EQU 17
CYDEV_CHIP_MEMBER_4J EQU 9
CYDEV_CHIP_MEMBER_4K EQU 10
CYDEV_CHIP_MEMBER_4L EQU 16
CYDEV_CHIP_MEMBER_4M EQU 15
CYDEV_CHIP_MEMBER_4N EQU 6
CYDEV_CHIP_MEMBER_4O EQU 5
CYDEV_CHIP_MEMBER_4P EQU 14
CYDEV_CHIP_MEMBER_4Q EQU 7
CYDEV_CHIP_MEMBER_4U EQU 3
CYDEV_CHIP_MEMBER_5A EQU 20
CYDEV_CHIP_MEMBER_5B EQU 19
CYDEV_CHIP_MEMBER_FM3 EQU 24
CYDEV_CHIP_MEMBER_FM4 EQU 25
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 21
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 22
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 23
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000001
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */