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
SOURCEFILES_QUOTED_IF_SPACED=Source/USB/Usb_HID_tasks.c Source/USB/usb_config.c Source/USB/usb_descriptors.c Source/USB/usb_device.c Source/USB/usb_function_hid.c Source/USB/addressConvertion.c Source/main.c Source/init.c Source/globalState.c Source/beanTasks.c Source/Custom_HID.c Source/ports.c Source/spi.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o ${OBJECTDIR}/Source/USB/usb_config.o ${OBJECTDIR}/Source/USB/usb_descriptors.o ${OBJECTDIR}/Source/USB/usb_device.o ${OBJECTDIR}/Source/USB/usb_function_hid.o ${OBJECTDIR}/Source/USB/addressConvertion.o ${OBJECTDIR}/Source/main.o ${OBJECTDIR}/Source/init.o ${OBJECTDIR}/Source/globalState.o ${OBJECTDIR}/Source/beanTasks.o ${OBJECTDIR}/Source/Custom_HID.o ${OBJECTDIR}/Source/ports.o ${OBJECTDIR}/Source/spi.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d ${OBJECTDIR}/Source/USB/usb_config.o.d ${OBJECTDIR}/Source/USB/usb_descriptors.o.d ${OBJECTDIR}/Source/USB/usb_device.o.d ${OBJECTDIR}/Source/USB/usb_function_hid.o.d ${OBJECTDIR}/Source/USB/addressConvertion.o.d ${OBJECTDIR}/Source/main.o.d ${OBJECTDIR}/Source/init.o.d ${OBJECTDIR}/Source/globalState.o.d ${OBJECTDIR}/Source/beanTasks.o.d ${OBJECTDIR}/Source/Custom_HID.o.d ${OBJECTDIR}/Source/ports.o.d ${OBJECTDIR}/Source/spi.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o ${OBJECTDIR}/Source/USB/usb_config.o ${OBJECTDIR}/Source/USB/usb_descriptors.o ${OBJECTDIR}/Source/USB/usb_device.o ${OBJECTDIR}/Source/USB/usb_function_hid.o ${OBJECTDIR}/Source/USB/addressConvertion.o ${OBJECTDIR}/Source/main.o ${OBJECTDIR}/Source/init.o ${OBJECTDIR}/Source/globalState.o ${OBJECTDIR}/Source/beanTasks.o ${OBJECTDIR}/Source/Custom_HID.o ${OBJECTDIR}/Source/ports.o ${OBJECTDIR}/Source/spi.o

# Source Files
SOURCEFILES=Source/USB/Usb_HID_tasks.c Source/USB/usb_config.c Source/USB/usb_descriptors.c Source/USB/usb_device.c Source/USB/usb_function_hid.c Source/USB/addressConvertion.c Source/main.c Source/init.c Source/globalState.c Source/beanTasks.c Source/Custom_HID.c Source/ports.c Source/spi.c



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
${OBJECTDIR}/Source/USB/Usb_HID_tasks.o: Source/USB/Usb_HID_tasks.c  .generated_files/e5d819c7cf009febe4179eb9554624430ca86500.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d" -o ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o Source/USB/Usb_HID_tasks.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_config.o: Source/USB/usb_config.c  .generated_files/194c1969c9de2d38d8416b0619749798f170b007.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_config.o.d" -o ${OBJECTDIR}/Source/USB/usb_config.o Source/USB/usb_config.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_descriptors.o: Source/USB/usb_descriptors.c  .generated_files/5103672ce2fc6eadc4fb5c58dbe0e0e63665f508.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_descriptors.o.d" -o ${OBJECTDIR}/Source/USB/usb_descriptors.o Source/USB/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_device.o: Source/USB/usb_device.c  .generated_files/e29207c0fa5c514cc423c140402da702c8448db3.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_device.o.d" -o ${OBJECTDIR}/Source/USB/usb_device.o Source/USB/usb_device.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_function_hid.o: Source/USB/usb_function_hid.c  .generated_files/c68450caff3345d3855bf7ad6a3400e9d3ebce8b.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_function_hid.o.d" -o ${OBJECTDIR}/Source/USB/usb_function_hid.o Source/USB/usb_function_hid.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/addressConvertion.o: Source/USB/addressConvertion.c  .generated_files/ee52be2a88672f4478d4355b2be54adcfd4639c0.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/addressConvertion.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/addressConvertion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/addressConvertion.o.d" -o ${OBJECTDIR}/Source/USB/addressConvertion.o Source/USB/addressConvertion.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/main.o: Source/main.c  .generated_files/3e4816499cc600d0a0aee26799c1a93b2bbcf3c5.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/main.o.d 
	@${RM} ${OBJECTDIR}/Source/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/main.o.d" -o ${OBJECTDIR}/Source/main.o Source/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/init.o: Source/init.c  .generated_files/c0585c5c100cf8cb5e8625d05bf241c980081ffa.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/init.o.d 
	@${RM} ${OBJECTDIR}/Source/init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/init.o.d" -o ${OBJECTDIR}/Source/init.o Source/init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/globalState.o: Source/globalState.c  .generated_files/33eda325d8f2b966c90edff92a9e59390f17d737.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/globalState.o.d 
	@${RM} ${OBJECTDIR}/Source/globalState.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/globalState.o.d" -o ${OBJECTDIR}/Source/globalState.o Source/globalState.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/beanTasks.o: Source/beanTasks.c  .generated_files/c668c9b529930634b9b21ceee2b1c9073ddf1df.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/beanTasks.o.d 
	@${RM} ${OBJECTDIR}/Source/beanTasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/beanTasks.o.d" -o ${OBJECTDIR}/Source/beanTasks.o Source/beanTasks.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/Custom_HID.o: Source/Custom_HID.c  .generated_files/c016f0f9f1710bc87975774f33cadc1a02508dea.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/Custom_HID.o.d 
	@${RM} ${OBJECTDIR}/Source/Custom_HID.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/Custom_HID.o.d" -o ${OBJECTDIR}/Source/Custom_HID.o Source/Custom_HID.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/ports.o: Source/ports.c  .generated_files/ec1fe5034fa17149978a64486520f4d9e1d3b7b5.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/ports.o.d 
	@${RM} ${OBJECTDIR}/Source/ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/ports.o.d" -o ${OBJECTDIR}/Source/ports.o Source/ports.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/spi.o: Source/spi.c  .generated_files/ab7693f01ce40513c120176f991657d320d8a1bc.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/spi.o.d 
	@${RM} ${OBJECTDIR}/Source/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/spi.o.d" -o ${OBJECTDIR}/Source/spi.o Source/spi.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/Source/USB/Usb_HID_tasks.o: Source/USB/Usb_HID_tasks.c  .generated_files/7fc890ec5432043452583b39d15433adfb24335b.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d" -o ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o Source/USB/Usb_HID_tasks.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_config.o: Source/USB/usb_config.c  .generated_files/7cc261b00df9951fbf65ff257a55db1264b17c24.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_config.o.d" -o ${OBJECTDIR}/Source/USB/usb_config.o Source/USB/usb_config.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_descriptors.o: Source/USB/usb_descriptors.c  .generated_files/61e0ad3510fbea87540803deae6cd5caf80bcd2b.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_descriptors.o.d" -o ${OBJECTDIR}/Source/USB/usb_descriptors.o Source/USB/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_device.o: Source/USB/usb_device.c  .generated_files/ed61d84905f3f50bf97f6370e93cfc0c267ceee2.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_device.o.d" -o ${OBJECTDIR}/Source/USB/usb_device.o Source/USB/usb_device.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_function_hid.o: Source/USB/usb_function_hid.c  .generated_files/65a7154277b991034800faa2112fa2127dcaffc4.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_function_hid.o.d" -o ${OBJECTDIR}/Source/USB/usb_function_hid.o Source/USB/usb_function_hid.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/addressConvertion.o: Source/USB/addressConvertion.c  .generated_files/cd04ca52304df2c8c137ae3179b6b4d91077591c.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/addressConvertion.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/addressConvertion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/addressConvertion.o.d" -o ${OBJECTDIR}/Source/USB/addressConvertion.o Source/USB/addressConvertion.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/main.o: Source/main.c  .generated_files/2d51955e6c3bad56e2c7a5a81cb7275faa295d90.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/main.o.d 
	@${RM} ${OBJECTDIR}/Source/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/main.o.d" -o ${OBJECTDIR}/Source/main.o Source/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/init.o: Source/init.c  .generated_files/b533204afbe92d2c5b49587d67279b1c209637a8.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/init.o.d 
	@${RM} ${OBJECTDIR}/Source/init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/init.o.d" -o ${OBJECTDIR}/Source/init.o Source/init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/globalState.o: Source/globalState.c  .generated_files/b8f27eb6764cd863d3eb2524aaf069317f2fb7da.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/globalState.o.d 
	@${RM} ${OBJECTDIR}/Source/globalState.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/globalState.o.d" -o ${OBJECTDIR}/Source/globalState.o Source/globalState.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/beanTasks.o: Source/beanTasks.c  .generated_files/33dbf05bb9ae05f98b46a2fbbdadf207b25fe4d.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/beanTasks.o.d 
	@${RM} ${OBJECTDIR}/Source/beanTasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/beanTasks.o.d" -o ${OBJECTDIR}/Source/beanTasks.o Source/beanTasks.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/Custom_HID.o: Source/Custom_HID.c  .generated_files/7848bd6e01ffa90efb9c3ac5094f410ad25b6c72.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/Custom_HID.o.d 
	@${RM} ${OBJECTDIR}/Source/Custom_HID.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/Custom_HID.o.d" -o ${OBJECTDIR}/Source/Custom_HID.o Source/Custom_HID.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/ports.o: Source/ports.c  .generated_files/9f4d7d421fee29f36a827234c1ed8b271ba030d4.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/ports.o.d 
	@${RM} ${OBJECTDIR}/Source/ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/ports.o.d" -o ${OBJECTDIR}/Source/ports.o Source/ports.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/spi.o: Source/spi.c  .generated_files/9dbfe622fa2394b0c7ba53b206366a74950d1aa6.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/spi.o.d 
	@${RM} ${OBJECTDIR}/Source/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/spi.o.d" -o ${OBJECTDIR}/Source/spi.o Source/spi.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION) -O2 -mno-float -o dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\bean\bean.X\dist\default\debug\bean.X.a      -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../bean/bean.X/dist/default/production/bean.X.a app_32MX220F032B.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -O2 -mno-float -o dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\bean\bean.X\dist\default\production\bean.X.a      -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
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
