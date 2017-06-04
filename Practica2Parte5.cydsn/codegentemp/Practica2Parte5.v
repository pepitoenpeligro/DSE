// ======================================================================
// Practica2Parte5.v generated from TopDesign.cysch
// 05/13/2017 at 21:32
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_TMA4 2
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 5
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_VOLANS 6
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 7
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 8
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 9
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 10
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_FM0P 4
`define CYDEV_CHIP_FAMILY_FM3 5
`define CYDEV_CHIP_FAMILY_FM4 6
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 3
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 4
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 5
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 6
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 7
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 8
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 9
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 10
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 11
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 12
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 13
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 14
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 15
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 16
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 17
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 18
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_5B 19
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 20
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 21
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 22
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 23
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 24
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 25
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 19
`define CYDEV_CHIP_REVISION_USED 0
// Component: CyControlReg_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`endif

// Component: LUT_v1_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50\LUT_v1_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50\LUT_v1_50.v"
`endif

// Component: CyStatusReg_v1_90
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90\CyStatusReg_v1_90.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90\CyStatusReg_v1_90.v"
`endif

// Component: cydff_v1_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`endif

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// Component: and_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// CharLCD_v2_20(ConversionRoutines=true, CUSTOM0=0,E,8,8,8,E,0, CUSTOM1=0,A,A,4,4,4,0, CUSTOM2=0,E,A,E,8,8,0, CUSTOM3=0,E,A,C,A,A,0, CUSTOM4=0,E,8,C,8,E,0, CUSTOM5=0,E,8,E,2,E,0, CUSTOM6=0,E,8,E,2,E,0, CUSTOM7=0,4,4,4,0,4,0, CustomCharacterSet=0, TypeReplacementString=uint8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=CharLCD_v2_20, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=pantallaLCD, CY_INSTANCE_SHORT_NAME=pantallaLCD, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=20, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=pantallaLCD, )
module CharLCD_v2_20_0 ;



	wire [6:0] tmpOE__LCDPort_net;
	wire [6:0] tmpFB_6__LCDPort_net;
	wire [6:0] tmpIO_6__LCDPort_net;
	wire [0:0] tmpINTERRUPT_0__LCDPort_net;
	electrical [0:0] tmpSIOVREF__LCDPort_net;

	cy_psoc3_pins_v1_10
		#(.id("94153dfb-7545-4aa6-9c8b-9b7dc1f0e996/ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(21'b110_110_110_110_110_110_110),
		  .ibuf_enabled(7'b1_1_1_1_1_1_1),
		  .init_dr_st(7'b0_0_0_0_0_0_0),
		  .input_clk_en(0),
		  .input_sync(7'b1_1_1_1_1_1_1),
		  .input_sync_mode(7'b0_0_0_0_0_0_0),
		  .intr_mode(14'b00_00_00_00_00_00_00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(",,,,,,"),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(7'b0_0_0_0_0_0_0),
		  .oe_reset(0),
		  .oe_sync(7'b0_0_0_0_0_0_0),
		  .output_clk_en(0),
		  .output_clock_mode(7'b0_0_0_0_0_0_0),
		  .output_conn(7'b0_0_0_0_0_0_0),
		  .output_mode(7'b0_0_0_0_0_0_0),
		  .output_reset(0),
		  .output_sync(7'b0_0_0_0_0_0_0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(",,,,,,"),
		  .pin_mode("OOOOOOO"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(7'b1_1_1_1_1_1_1),
		  .sio_ibuf(""),
		  .sio_info(14'b00_00_00_00_00_00_00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(7'b0_0_0_0_0_0_0),
		  .spanning(0),
		  .use_annotation(7'b0_0_0_0_0_0_0),
		  .vtrip(14'b10_10_10_10_10_10_10),
		  .width(7),
		  .ovt_hyst_trim(7'b0_0_0_0_0_0_0),
		  .ovt_needed(7'b0_0_0_0_0_0_0),
		  .ovt_slew_control(14'b00_00_00_00_00_00_00),
		  .input_buffer_sel(14'b00_00_00_00_00_00_00))
		LCDPort
		 (.oe(tmpOE__LCDPort_net),
		  .y({7'b0}),
		  .fb({tmpFB_6__LCDPort_net[6:0]}),
		  .io({tmpIO_6__LCDPort_net[6:0]}),
		  .siovref(tmpSIOVREF__LCDPort_net),
		  .interrupt({tmpINTERRUPT_0__LCDPort_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LCDPort_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{7'b1111111} : {7'b1111111};



endmodule

// top
module top ;

          wire  Granjero;
          wire  Maiz;
          wire  Gallina;
          wire  Zorro;
          wire  clock;
          wire [3:0] step;
          wire [7:0] Net_41;
          wire  Net_40;
          wire  Net_39;
          wire  Net_38;
          wire  Net_37;
          wire  Net_36;
          wire  Net_35;
          wire  Net_34;
          wire [7:0] Net_47;
          wire  Net_46;
          wire  Net_45;
          wire  Net_44;
          wire  Net_43;
          wire  Net_42;
          wire [7:0] Net_27;
          wire  Net_26;
          wire  Net_25;
          wire  Net_24;
          wire  Net_23;
          wire  Net_22;
          wire  Net_21;
          wire  Net_20;
          wire  Net_19;
          wire  Net_18;
          wire  Net_17;
          wire  Net_16;
          wire  Net_15;
          wire  Net_14;
          wire  Net_13;
          wire  Net_12;
          wire  Net_11;
          wire  Net_10;
          wire  Net_9;
          wire  Net_8;
          wire  Net_7;
          wire  Net_6;
          wire  Net_5;
          wire  Net_4;
          wire  Net_3;
          wire  Net_2;
          wire  Net_1;
          wire  Net_206;
          wire  Net_207;
          wire  Net_208;
          wire  Net_209;
          wire  Net_267;
          wire  Net_268;
          wire  Net_270;
          wire  Net_278;
          wire  Net_231;
          wire  Net_277;
          wire  Net_264;
          wire  Net_263;
          wire  Net_258;
          wire  Net_286;
          wire  Net_285;
          wire  Net_230;

    CyControlReg_v1_80 Control_Reg_NextStep (
        .control_1(Maiz),
        .control_2(Gallina),
        .control_3(Zorro),
        .control_0(Granjero),
        .control_4(Net_1),
        .control_5(Net_2),
        .control_6(Net_3),
        .control_7(Net_4),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Reg_NextStep.Bit0Mode = 0;
    defparam Control_Reg_NextStep.Bit1Mode = 0;
    defparam Control_Reg_NextStep.Bit2Mode = 0;
    defparam Control_Reg_NextStep.Bit3Mode = 0;
    defparam Control_Reg_NextStep.Bit4Mode = 0;
    defparam Control_Reg_NextStep.Bit5Mode = 0;
    defparam Control_Reg_NextStep.Bit6Mode = 0;
    defparam Control_Reg_NextStep.Bit7Mode = 0;
    defparam Control_Reg_NextStep.BitValue = 0;
    defparam Control_Reg_NextStep.BusDisplay = 0;
    defparam Control_Reg_NextStep.ExtrReset = 0;
    defparam Control_Reg_NextStep.NumOutputs = 4;

    // -- LUT LUT_Riddle start --
    if (1)
    begin : LUT_Riddle
        reg [3:0] tmp__LUT_Riddle_reg;
        wire [3:0] tmp__LUT_Riddle_ins;
        assign tmp__LUT_Riddle_ins = {Zorro,Gallina,Maiz,Granjero};
        always @(tmp__LUT_Riddle_ins)
        begin
            case (tmp__LUT_Riddle_ins)
                4'b0000 :  tmp__LUT_Riddle_reg = 4'b0000;
                4'b0001 :  tmp__LUT_Riddle_reg = 4'b1111;
                4'b0010 :  tmp__LUT_Riddle_reg = 4'b0100;
                4'b0011 :  tmp__LUT_Riddle_reg = 4'b1111;
                4'b0100 :  tmp__LUT_Riddle_reg = 4'b0010;
                4'b0101 :  tmp__LUT_Riddle_reg = 4'b0001;
                4'b0110 :  tmp__LUT_Riddle_reg = 4'b1111;
                4'b0111 :  tmp__LUT_Riddle_reg = 4'b0011;
                4'b1000 :  tmp__LUT_Riddle_reg = 4'b1111;
                4'b1001 :  tmp__LUT_Riddle_reg = 4'b1111;
                4'b1010 :  tmp__LUT_Riddle_reg = 4'b0110;
                4'b1011 :  tmp__LUT_Riddle_reg = 4'b0101;
                4'b1100 :  tmp__LUT_Riddle_reg = 4'b1111;
                4'b1101 :  tmp__LUT_Riddle_reg = 4'b1111;
                4'b1110 :  tmp__LUT_Riddle_reg = 4'b1111;
                4'b1111 :  tmp__LUT_Riddle_reg = 4'b0111;
            endcase
        end
        assign {step[3],step[2],step[1],step[0]} = tmp__LUT_Riddle_reg;
    end
    // -- LUT LUT_Riddle end --

    CyControlReg_v1_80 Control_Reg_Clock (
        .control_1(Net_13),
        .control_2(Net_14),
        .control_3(Net_15),
        .control_0(clock),
        .control_4(Net_16),
        .control_5(Net_17),
        .control_6(Net_18),
        .control_7(Net_19),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Reg_Clock.Bit0Mode = 0;
    defparam Control_Reg_Clock.Bit1Mode = 0;
    defparam Control_Reg_Clock.Bit2Mode = 0;
    defparam Control_Reg_Clock.Bit3Mode = 0;
    defparam Control_Reg_Clock.Bit4Mode = 0;
    defparam Control_Reg_Clock.Bit5Mode = 0;
    defparam Control_Reg_Clock.Bit6Mode = 0;
    defparam Control_Reg_Clock.Bit7Mode = 0;
    defparam Control_Reg_Clock.BitValue = 0;
    defparam Control_Reg_Clock.BusDisplay = 0;
    defparam Control_Reg_Clock.ExtrReset = 0;
    defparam Control_Reg_Clock.NumOutputs = 1;

    CyStatusReg_v1_90 Status_Reg_CurrentStep (
        .status_0(step[0]),
        .status_1(step[1]),
        .status_2(step[2]),
        .status_3(step[3]),
        .clock(clock),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_26),
        .status_bus(8'b0));
    defparam Status_Reg_CurrentStep.Bit0Mode = 0;
    defparam Status_Reg_CurrentStep.Bit1Mode = 0;
    defparam Status_Reg_CurrentStep.Bit2Mode = 0;
    defparam Status_Reg_CurrentStep.Bit3Mode = 0;
    defparam Status_Reg_CurrentStep.Bit4Mode = 0;
    defparam Status_Reg_CurrentStep.Bit5Mode = 0;
    defparam Status_Reg_CurrentStep.Bit6Mode = 0;
    defparam Status_Reg_CurrentStep.Bit7Mode = 0;
    defparam Status_Reg_CurrentStep.BusDisplay = 0;
    defparam Status_Reg_CurrentStep.Interrupt = 0;
    defparam Status_Reg_CurrentStep.MaskValue = 0;
    defparam Status_Reg_CurrentStep.NumInputs = 4;

    // -- DFF Start --
    reg  cydff_1;
    always @(posedge clock)
    begin
        cydff_1 <= step[0];
    end
    assign Net_206 = cydff_1;
    // -- DFF End --

    // -- DFF Start --
    reg  cydff_2;
    always @(posedge clock)
    begin
        cydff_2 <= step[1];
    end
    assign Net_207 = cydff_2;
    // -- DFF End --

    // -- DFF Start --
    reg  cydff_3;
    always @(posedge clock)
    begin
        cydff_3 <= step[2];
    end
    assign Net_208 = cydff_3;
    // -- DFF End --

    // -- DFF Start --
    reg  cydff_4;
    always @(posedge clock)
    begin
        cydff_4 <= step[3];
    end
    assign Net_209 = cydff_4;
    // -- DFF End --

    CyStatusReg_v1_90 Status_Reg_LastStep (
        .status_0(Net_206),
        .status_1(Net_207),
        .status_2(Net_208),
        .status_3(Net_209),
        .clock(clock),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_46),
        .status_bus(8'b0));
    defparam Status_Reg_LastStep.Bit0Mode = 0;
    defparam Status_Reg_LastStep.Bit1Mode = 0;
    defparam Status_Reg_LastStep.Bit2Mode = 0;
    defparam Status_Reg_LastStep.Bit3Mode = 0;
    defparam Status_Reg_LastStep.Bit4Mode = 0;
    defparam Status_Reg_LastStep.Bit5Mode = 0;
    defparam Status_Reg_LastStep.Bit6Mode = 0;
    defparam Status_Reg_LastStep.Bit7Mode = 0;
    defparam Status_Reg_LastStep.BusDisplay = 0;
    defparam Status_Reg_LastStep.Interrupt = 0;
    defparam Status_Reg_LastStep.MaskValue = 0;
    defparam Status_Reg_LastStep.NumInputs = 4;

    CyStatusReg_v1_90 Status_Reg_Error (
        .status_0(Net_230),
        .status_1(Net_231),
        .status_2(1'b0),
        .status_3(1'b0),
        .clock(clock),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_40),
        .status_bus(8'b0));
    defparam Status_Reg_Error.Bit0Mode = 0;
    defparam Status_Reg_Error.Bit1Mode = 0;
    defparam Status_Reg_Error.Bit2Mode = 0;
    defparam Status_Reg_Error.Bit3Mode = 0;
    defparam Status_Reg_Error.Bit4Mode = 0;
    defparam Status_Reg_Error.Bit5Mode = 0;
    defparam Status_Reg_Error.Bit6Mode = 0;
    defparam Status_Reg_Error.Bit7Mode = 0;
    defparam Status_Reg_Error.BusDisplay = 0;
    defparam Status_Reg_Error.Interrupt = 0;
    defparam Status_Reg_Error.MaskValue = 0;
    defparam Status_Reg_Error.NumInputs = 2;


    assign Net_258 = ~Granjero;


    assign Net_264 = ~Maiz;


    assign Net_263 = ~Gallina;


    assign Net_270 = ~Granjero;


    assign Net_267 = ~Zorro;


    assign Net_268 = ~Gallina;


    assign Net_285 = Net_258 & Gallina & Maiz;


    assign Net_286 = Granjero & Net_263 & Net_264;


    assign Net_278 = Granjero & Net_267 & Net_268;


    assign Net_277 = Net_270 & Zorro & Gallina;


    assign Net_230 = Net_285 | Net_286;


    assign Net_231 = Net_277 | Net_278;

    CharLCD_v2_20_0 pantallaLCD ();

	wire [0:0] tmpOE__nex_net;
	wire [0:0] tmpFB_0__nex_net;
	wire [0:0] tmpIO_0__nex_net;
	wire [0:0] tmpINTERRUPT_0__nex_net;
	electrical [0:0] tmpSIOVREF__nex_net;

	cy_psoc3_pins_v1_10
		#(.id("8d318d8b-cf7b-4b6b-b02c-ab1c5c49d0ba"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		nex
		 (.oe(tmpOE__nex_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__nex_net[0:0]}),
		  .io({tmpIO_0__nex_net[0:0]}),
		  .siovref(tmpSIOVREF__nex_net),
		  .interrupt({tmpINTERRUPT_0__nex_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__nex_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__cross_net;
	wire [0:0] tmpFB_0__cross_net;
	wire [0:0] tmpIO_0__cross_net;
	wire [0:0] tmpINTERRUPT_0__cross_net;
	electrical [0:0] tmpSIOVREF__cross_net;

	cy_psoc3_pins_v1_10
		#(.id("62603ec7-298a-4899-9a13-ee7bf315c9dc"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		cross
		 (.oe(tmpOE__cross_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__cross_net[0:0]}),
		  .io({tmpIO_0__cross_net[0:0]}),
		  .siovref(tmpSIOVREF__cross_net),
		  .interrupt({tmpINTERRUPT_0__cross_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__cross_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};



endmodule

