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
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Source/USB/Usb_HID_tasks.c Source/USB/usb_config.c Source/USB/usb_descriptors.c Source/USB/usb_device.c Source/USB/usb_function_hid.c Source/USB/addressConvertion.c Source/main.c Source/init.c Source/globalState.c Source/beanTasks.c Source/Custom_HID.c Source/ports.c Source/spi.c Source/typeConvert.c Source/sounds.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o ${OBJECTDIR}/Source/USB/usb_config.o ${OBJECTDIR}/Source/USB/usb_descriptors.o ${OBJECTDIR}/Source/USB/usb_device.o ${OBJECTDIR}/Source/USB/usb_function_hid.o ${OBJECTDIR}/Source/USB/addressConvertion.o ${OBJECTDIR}/Source/main.o ${OBJECTDIR}/Source/init.o ${OBJECTDIR}/Source/globalState.o ${OBJECTDIR}/Source/beanTasks.o ${OBJECTDIR}/Source/Custom_HID.o ${OBJECTDIR}/Source/ports.o ${OBJECTDIR}/Source/spi.o ${OBJECTDIR}/Source/typeConvert.o ${OBJECTDIR}/Source/sounds.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d ${OBJECTDIR}/Source/USB/usb_config.o.d ${OBJECTDIR}/Source/USB/usb_descriptors.o.d ${OBJECTDIR}/Source/USB/usb_device.o.d ${OBJECTDIR}/Source/USB/usb_function_hid.o.d ${OBJECTDIR}/Source/USB/addressConvertion.o.d ${OBJECTDIR}/Source/main.o.d ${OBJECTDIR}/Source/init.o.d ${OBJECTDIR}/Source/globalState.o.d ${OBJECTDIR}/Source/beanTasks.o.d ${OBJECTDIR}/Source/Custom_HID.o.d ${OBJECTDIR}/Source/ports.o.d ${OBJECTDIR}/Source/spi.o.d ${OBJECTDIR}/Source/typeConvert.o.d ${OBJECTDIR}/Source/sounds.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o ${OBJECTDIR}/Source/USB/usb_config.o ${OBJECTDIR}/Source/USB/usb_descriptors.o ${OBJECTDIR}/Source/USB/usb_device.o ${OBJECTDIR}/Source/USB/usb_function_hid.o ${OBJECTDIR}/Source/USB/addressConvertion.o ${OBJECTDIR}/Source/main.o ${OBJECTDIR}/Source/init.o ${OBJECTDIR}/Source/globalState.o ${OBJECTDIR}/Source/beanTasks.o ${OBJECTDIR}/Source/Custom_HID.o ${OBJECTDIR}/Source/ports.o ${OBJECTDIR}/Source/spi.o ${OBJECTDIR}/Source/typeConvert.o ${OBJECTDIR}/Source/sounds.o

# Source Files
SOURCEFILES=Source/USB/Usb_HID_tasks.c Source/USB/usb_config.c Source/USB/usb_descriptors.c Source/USB/usb_device.c Source/USB/usb_function_hid.c Source/USB/addressConvertion.c Source/main.c Source/init.c Source/globalState.c Source/beanTasks.c Source/Custom_HID.c Source/ports.c Source/spi.c Source/typeConvert.c Source/sounds.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX220F032B
MP_LINKER_FILE_OPTION=,--script="app_32MX220F032B.ld"
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
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Source/USB/Usb_HID_tasks.o: Source/USB/Usb_HID_tasks.c  .generated_files/4307bb49fb22d98eaeb64fbfecee4402c57b62aa.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d" -o ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o Source/USB/Usb_HID_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_config.o: Source/USB/usb_config.c  .generated_files/6ce383c620726c8138746ebb7973366bc3d6e4ff.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_config.o.d" -o ${OBJECTDIR}/Source/USB/usb_config.o Source/USB/usb_config.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_descriptors.o: Source/USB/usb_descriptors.c  .generated_files/7c0124ce57217a3769233c9c3a453dced427737a.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_descriptors.o.d" -o ${OBJECTDIR}/Source/USB/usb_descriptors.o Source/USB/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_device.o: Source/USB/usb_device.c  .generated_files/6f927c33611d429cdf4ed8e12b1968ab4d107add.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_device.o.d" -o ${OBJECTDIR}/Source/USB/usb_device.o Source/USB/usb_device.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_function_hid.o: Source/USB/usb_function_hid.c  .generated_files/14552076c0b106a6f32d248a7f4ee61fbbad899a.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_function_hid.o.d" -o ${OBJECTDIR}/Source/USB/usb_function_hid.o Source/USB/usb_function_hid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/addressConvertion.o: Source/USB/addressConvertion.c  .generated_files/2167dd5b5a2a3dda631a1939d81056aa04d2ce80.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/addressConvertion.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/addressConvertion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/addressConvertion.o.d" -o ${OBJECTDIR}/Source/USB/addressConvertion.o Source/USB/addressConvertion.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/main.o: Source/main.c  .generated_files/6d27db9b80072962c9faac816c820349a1676d8e.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/main.o.d 
	@${RM} ${OBJECTDIR}/Source/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/main.o.d" -o ${OBJECTDIR}/Source/main.o Source/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/init.o: Source/init.c  .generated_files/5712fd88dda9aa782706d91b1f1617551d9fcf28.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/init.o.d 
	@${RM} ${OBJECTDIR}/Source/init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/init.o.d" -o ${OBJECTDIR}/Source/init.o Source/init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/globalState.o: Source/globalState.c  .generated_files/8d57c572095bbe5fbdef5e52fcdeb9a312dbb897.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/globalState.o.d 
	@${RM} ${OBJECTDIR}/Source/globalState.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/globalState.o.d" -o ${OBJECTDIR}/Source/globalState.o Source/globalState.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/beanTasks.o: Source/beanTasks.c  .generated_files/c67c0482973f69a767759059f4b6b7a05812a0.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/beanTasks.o.d 
	@${RM} ${OBJECTDIR}/Source/beanTasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/beanTasks.o.d" -o ${OBJECTDIR}/Source/beanTasks.o Source/beanTasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/Custom_HID.o: Source/Custom_HID.c  .generated_files/b3ac607e04ceeb500c369905d1b8ad597e592615.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/Custom_HID.o.d 
	@${RM} ${OBJECTDIR}/Source/Custom_HID.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/Custom_HID.o.d" -o ${OBJECTDIR}/Source/Custom_HID.o Source/Custom_HID.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/ports.o: Source/ports.c  .generated_files/d52cb4b6cb9831bf135447e33133ae2ee83b5567.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/ports.o.d 
	@${RM} ${OBJECTDIR}/Source/ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/ports.o.d" -o ${OBJECTDIR}/Source/ports.o Source/ports.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/spi.o: Source/spi.c  .generated_files/8c232b76b31217e04cac69e1c1dd599ab3c405e9.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/spi.o.d 
	@${RM} ${OBJECTDIR}/Source/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/spi.o.d" -o ${OBJECTDIR}/Source/spi.o Source/spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/typeConvert.o: Source/typeConvert.c  .generated_files/eec8a77d2c786725013c3a2dd0463dc1da31c2bd.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/typeConvert.o.d 
	@${RM} ${OBJECTDIR}/Source/typeConvert.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/typeConvert.o.d" -o ${OBJECTDIR}/Source/typeConvert.o Source/typeConvert.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/sounds.o: Source/sounds.c  .generated_files/3409f86db2c25796dbb4a45ec61e4054e4abf722.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/sounds.o.d 
	@${RM} ${OBJECTDIR}/Source/sounds.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/sounds.o.d" -o ${OBJECTDIR}/Source/sounds.o Source/sounds.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/Source/USB/Usb_HID_tasks.o: Source/USB/Usb_HID_tasks.c  .generated_files/614e1f1794bcc251494d7206e129a2997265ac7b.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d" -o ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o Source/USB/Usb_HID_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_config.o: Source/USB/usb_config.c  .generated_files/40be72af5afd576463be9e9c2aa2cf4001e9abf8.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_config.o.d" -o ${OBJECTDIR}/Source/USB/usb_config.o Source/USB/usb_config.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_descriptors.o: Source/USB/usb_descriptors.c  .generated_files/e41ed87f4debc1221be034e6251405c1b08c0a30.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_descriptors.o.d" -o ${OBJECTDIR}/Source/USB/usb_descriptors.o Source/USB/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_device.o: Source/USB/usb_device.c  .generated_files/46f6f7cbaf94309650e3cb276745c96e25c872ff.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_device.o.d" -o ${OBJECTDIR}/Source/USB/usb_device.o Source/USB/usb_device.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_function_hid.o: Source/USB/usb_function_hid.c  .generated_files/3debd916a39cedf4702c3e38ad8cb21ac77cf67f.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_function_hid.o.d" -o ${OBJECTDIR}/Source/USB/usb_function_hid.o Source/USB/usb_function_hid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/addressConvertion.o: Source/USB/addressConvertion.c  .generated_files/d29f791683a99ffe94a1ccc83ee68bfa5cf1919b.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/addressConvertion.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/addressConvertion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/addressConvertion.o.d" -o ${OBJECTDIR}/Source/USB/addressConvertion.o Source/USB/addressConvertion.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/main.o: Source/main.c  .generated_files/5b24c44a62c053711db0dd573fe97e2c97731844.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/main.o.d 
	@${RM} ${OBJECTDIR}/Source/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/main.o.d" -o ${OBJECTDIR}/Source/main.o Source/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/init.o: Source/init.c  .generated_files/f54fa5d889a8306d755c9c459982bfb2206d06b8.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/init.o.d 
	@${RM} ${OBJECTDIR}/Source/init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/init.o.d" -o ${OBJECTDIR}/Source/init.o Source/init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/globalState.o: Source/globalState.c  .generated_files/79929227e658dfd969dca8847c086c1d6eeba48a.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/globalState.o.d 
	@${RM} ${OBJECTDIR}/Source/globalState.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/globalState.o.d" -o ${OBJECTDIR}/Source/globalState.o Source/globalState.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/beanTasks.o: Source/beanTasks.c  .generated_files/6f91f5ced7538a0fb3117288451b53a3272f110d.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/beanTasks.o.d 
	@${RM} ${OBJECTDIR}/Source/beanTasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/beanTasks.o.d" -o ${OBJECTDIR}/Source/beanTasks.o Source/beanTasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/Custom_HID.o: Source/Custom_HID.c  .generated_files/7354bbbd32386a23f55b9d01219a4efff8b7a05d.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/Custom_HID.o.d 
	@${RM} ${OBJECTDIR}/Source/Custom_HID.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/Custom_HID.o.d" -o ${OBJECTDIR}/Source/Custom_HID.o Source/Custom_HID.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/ports.o: Source/ports.c  .generated_files/8817296d067835cc15b2431a9ac296204246b8cc.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/ports.o.d 
	@${RM} ${OBJECTDIR}/Source/ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/ports.o.d" -o ${OBJECTDIR}/Source/ports.o Source/ports.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/spi.o: Source/spi.c  .generated_files/b3732733321498c5c4eb4171acdf7edc5d775b51.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/spi.o.d 
	@${RM} ${OBJECTDIR}/Source/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/spi.o.d" -o ${OBJECTDIR}/Source/spi.o Source/spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/typeConvert.o: Source/typeConvert.c  .generated_files/8788fb5b9b2177228ab8bae62ae6cd9a3725859b.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/typeConvert.o.d 
	@${RM} ${OBJECTDIR}/Source/typeConvert.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/typeConvert.o.d" -o ${OBJECTDIR}/Source/typeConvert.o Source/typeConvert.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/sounds.o: Source/sounds.c  .generated_files/242bbf3c760ecc2a61b6cf05fca2f2e8bb6994bf.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/sounds.o.d 
	@${RM} ${OBJECTDIR}/Source/sounds.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/sounds.o.d" -o ${OBJECTDIR}/Source/sounds.o Source/sounds.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../bean/bean.X/dist/default/debug/bean.X.a  app_32MX220F032B.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -O2 -mno-float -o dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\bean\bean.X\dist\default\debug\bean.X.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../bean/bean.X/dist/default/production/bean.X.a app_32MX220F032B.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -O2 -mno-float -o dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\bean\bean.X\dist\default\production\bean.X.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:
	cd ../bean/bean.X && ${MAKE}  -f Makefile CONF=default


# Subprojects
.clean-subprojects:
	cd ../bean/bean.X && rm -rf "build/default" "dist/default"

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
