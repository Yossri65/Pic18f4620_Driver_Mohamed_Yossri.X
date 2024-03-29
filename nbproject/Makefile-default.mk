#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=${DISTDIR}/Pic18f4620_Driver_Mohamed_Yossri.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=${DISTDIR}/Pic18f4620_Driver_Mohamed_Yossri.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_Layer/Button/ecu_button.c ECU_Layer/Ch_LCD/ecu_ch_lcd.c ECU_Layer/dc_motor/ecu_dc_motor.c ECU_Layer/Key_Pad/ecu_key_pad.c ECU_Layer/LED/ecu_Led.c ECU_Layer/Relay/ecu_relay.c ECU_Layer/seven_segment/ecu_seven_segment.c ECU_Layer/ecu_intialize.c MCAL_Layer/MCAL_ADC/mcal_adc.c MCAL_Layer/CCP1/hal_ccp.c MCAL_Layer/ECCP/hal_eccp.c MCAL_Layer/EEPROM/mcal_eeprom.c MCAL_Layer/GPIO/hal_GPIO.c MCAL_Layer/I2C/hal_i2c.c MCAL_Layer/Interrupt/mcal_internal_interrupt.c MCAL_Layer/Interrupt/mcal_external_interrupt.c MCAL_Layer/Interrupt/mcal_interrupt_manager.c MCAL_Layer/SPI/hal_spi.c MCAL_Layer/Timer0/mcal_timer0.c MCAL_Layer/Timer1/mcal_timer1.c MCAL_Layer/Timer2/mcal_timer2.c MCAL_Layer/Timer3/mcal_timer3.c MCAL_Layer/USART/hal_usart.c MCAL_Layer/Device_config.c Application.c ECU_Layer/Servo_Motor/servo_motor.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1 ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1 ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1 ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1 ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1 ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1 ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1 ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1 ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1 ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1 ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1 ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1 ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1 ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1 ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1 ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1 ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 ${OBJECTDIR}/MCAL_Layer/Device_config.p1 ${OBJECTDIR}/Application.p1 ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1.d ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1.d ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1.d ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1.d ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1.d ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1.d ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1.d ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1.d ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1.d ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1.d ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1.d ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1.d ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1.d ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1.d ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1.d ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1.d ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d ${OBJECTDIR}/MCAL_Layer/Device_config.p1.d ${OBJECTDIR}/Application.p1.d ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1 ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1 ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1 ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1 ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1 ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1 ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1 ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1 ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1 ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1 ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1 ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1 ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1 ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1 ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1 ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1 ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 ${OBJECTDIR}/MCAL_Layer/Device_config.p1 ${OBJECTDIR}/Application.p1 ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1

# Source Files
SOURCEFILES=ECU_Layer/Button/ecu_button.c ECU_Layer/Ch_LCD/ecu_ch_lcd.c ECU_Layer/dc_motor/ecu_dc_motor.c ECU_Layer/Key_Pad/ecu_key_pad.c ECU_Layer/LED/ecu_Led.c ECU_Layer/Relay/ecu_relay.c ECU_Layer/seven_segment/ecu_seven_segment.c ECU_Layer/ecu_intialize.c MCAL_Layer/MCAL_ADC/mcal_adc.c MCAL_Layer/CCP1/hal_ccp.c MCAL_Layer/ECCP/hal_eccp.c MCAL_Layer/EEPROM/mcal_eeprom.c MCAL_Layer/GPIO/hal_GPIO.c MCAL_Layer/I2C/hal_i2c.c MCAL_Layer/Interrupt/mcal_internal_interrupt.c MCAL_Layer/Interrupt/mcal_external_interrupt.c MCAL_Layer/Interrupt/mcal_interrupt_manager.c MCAL_Layer/SPI/hal_spi.c MCAL_Layer/Timer0/mcal_timer0.c MCAL_Layer/Timer1/mcal_timer1.c MCAL_Layer/Timer2/mcal_timer2.c MCAL_Layer/Timer3/mcal_timer3.c MCAL_Layer/USART/hal_usart.c MCAL_Layer/Device_config.c Application.c ECU_Layer/Servo_Motor/servo_motor.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Pic18f4620_Driver_Mohamed_Yossri.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1: ECU_Layer/Button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1 ECU_Layer/Button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Button/ecu_button.d ${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1: ECU_Layer/Ch_LCD/ecu_ch_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Ch_LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1 ECU_Layer/Ch_LCD/ecu_ch_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.d ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1: ECU_Layer/dc_motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/dc_motor" 
	@${RM} ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1 ECU_Layer/dc_motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.d ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1: ECU_Layer/Key_Pad/ecu_key_pad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Key_Pad" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1 ECU_Layer/Key_Pad/ecu_key_pad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.d ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1: ECU_Layer/LED/ecu_Led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1 ECU_Layer/LED/ecu_Led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.d ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1: ECU_Layer/Relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Relay" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1 ECU_Layer/Relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.d ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1: ECU_Layer/seven_segment/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1 ECU_Layer/seven_segment/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.d ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_intialize.p1: ECU_Layer/ecu_intialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1 ECU_Layer/ecu_intialize.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_intialize.d ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1: MCAL_Layer/MCAL_ADC/mcal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1 MCAL_Layer/MCAL_ADC/mcal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.d ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1: MCAL_Layer/CCP1/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1 MCAL_Layer/CCP1/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.d ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1: MCAL_Layer/ECCP/hal_eccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ECCP" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1 MCAL_Layer/ECCP/hal_eccp.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.d ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1: MCAL_Layer/EEPROM/mcal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 MCAL_Layer/EEPROM/mcal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.d ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1: MCAL_Layer/GPIO/hal_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1 MCAL_Layer/GPIO/hal_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1: MCAL_Layer/I2C/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1 MCAL_Layer/I2C/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.d ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1: MCAL_Layer/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 MCAL_Layer/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1: MCAL_Layer/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 MCAL_Layer/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1: MCAL_Layer/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 MCAL_Layer/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1: MCAL_Layer/SPI/hal_spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1 MCAL_Layer/SPI/hal_spi.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.d ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1: MCAL_Layer/Timer0/mcal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1 MCAL_Layer/Timer0/mcal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.d ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1: MCAL_Layer/Timer1/mcal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1 MCAL_Layer/Timer1/mcal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.d ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1: MCAL_Layer/Timer2/mcal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1 MCAL_Layer/Timer2/mcal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.d ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1: MCAL_Layer/Timer3/mcal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1 MCAL_Layer/Timer3/mcal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.d ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1: MCAL_Layer/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 MCAL_Layer/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.d ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Device_config.p1: MCAL_Layer/Device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Device_config.p1 MCAL_Layer/Device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Device_config.d ${OBJECTDIR}/MCAL_Layer/Device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application.p1: Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.p1.d 
	@${RM} ${OBJECTDIR}/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application.p1 Application.c 
	@-${MV} ${OBJECTDIR}/Application.d ${OBJECTDIR}/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1: ECU_Layer/Servo_Motor/servo_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Servo_Motor" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1 ECU_Layer/Servo_Motor/servo_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.d ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1: ECU_Layer/Button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1 ECU_Layer/Button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Button/ecu_button.d ${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1: ECU_Layer/Ch_LCD/ecu_ch_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Ch_LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1 ECU_Layer/Ch_LCD/ecu_ch_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.d ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Ch_LCD/ecu_ch_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1: ECU_Layer/dc_motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/dc_motor" 
	@${RM} ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1 ECU_Layer/dc_motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.d ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/dc_motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1: ECU_Layer/Key_Pad/ecu_key_pad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Key_Pad" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1 ECU_Layer/Key_Pad/ecu_key_pad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.d ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Key_Pad/ecu_key_pad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1: ECU_Layer/LED/ecu_Led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1 ECU_Layer/LED/ecu_Led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.d ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/ecu_Led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1: ECU_Layer/Relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Relay" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1 ECU_Layer/Relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.d ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1: ECU_Layer/seven_segment/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1 ECU_Layer/seven_segment/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.d ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/seven_segment/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_intialize.p1: ECU_Layer/ecu_intialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1 ECU_Layer/ecu_intialize.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_intialize.d ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_intialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1: MCAL_Layer/MCAL_ADC/mcal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1 MCAL_Layer/MCAL_ADC/mcal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.d ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/mcal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1: MCAL_Layer/CCP1/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1 MCAL_Layer/CCP1/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.d ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/CCP1/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1: MCAL_Layer/ECCP/hal_eccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ECCP" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1 MCAL_Layer/ECCP/hal_eccp.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.d ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ECCP/hal_eccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1: MCAL_Layer/EEPROM/mcal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 MCAL_Layer/EEPROM/mcal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.d ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1: MCAL_Layer/GPIO/hal_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1 MCAL_Layer/GPIO/hal_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1: MCAL_Layer/I2C/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1 MCAL_Layer/I2C/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.d ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/I2C/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1: MCAL_Layer/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 MCAL_Layer/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1: MCAL_Layer/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 MCAL_Layer/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1: MCAL_Layer/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 MCAL_Layer/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1: MCAL_Layer/SPI/hal_spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1 MCAL_Layer/SPI/hal_spi.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.d ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/SPI/hal_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1: MCAL_Layer/Timer0/mcal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1 MCAL_Layer/Timer0/mcal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.d ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer0/mcal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1: MCAL_Layer/Timer1/mcal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1 MCAL_Layer/Timer1/mcal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.d ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer1/mcal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1: MCAL_Layer/Timer2/mcal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1 MCAL_Layer/Timer2/mcal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.d ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer2/mcal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1: MCAL_Layer/Timer3/mcal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1 MCAL_Layer/Timer3/mcal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.d ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer3/mcal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1: MCAL_Layer/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 MCAL_Layer/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.d ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Device_config.p1: MCAL_Layer/Device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Device_config.p1 MCAL_Layer/Device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Device_config.d ${OBJECTDIR}/MCAL_Layer/Device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application.p1: Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.p1.d 
	@${RM} ${OBJECTDIR}/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application.p1 Application.c 
	@-${MV} ${OBJECTDIR}/Application.d ${OBJECTDIR}/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1: ECU_Layer/Servo_Motor/servo_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/Servo_Motor" 
	@${RM} ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1 ECU_Layer/Servo_Motor/servo_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.d ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/Servo_Motor/servo_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Pic18f4620_Driver_Mohamed_Yossri.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Pic18f4620_Driver_Mohamed_Yossri.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Pic18f4620_Driver_Mohamed_Yossri.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Pic18f4620_Driver_Mohamed_Yossri.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Pic18f4620_Driver_Mohamed_Yossri.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Pic18f4620_Driver_Mohamed_Yossri.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Pic18f4620_Driver_Mohamed_Yossri.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
