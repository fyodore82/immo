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
SOURCEFILES_QUOTED_IF_SPACED=Source/USB/Usb_HID_tasks.c Source/USB/usb_config.c Source/USB/usb_descriptors.c Source/USB/usb_device.c Source/USB/usb_function_hid.c Source/USB/addressConvertion.c Source/main.c Source/init.c Source/globalState.c Source/beanTasks.c Source/Custom_HID.c Source/ports.c Source/spi.c Source/typeConvert.c Source/sounds.c Source/initialTasks.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o ${OBJECTDIR}/Source/USB/usb_config.o ${OBJECTDIR}/Source/USB/usb_descriptors.o ${OBJECTDIR}/Source/USB/usb_device.o ${OBJECTDIR}/Source/USB/usb_function_hid.o ${OBJECTDIR}/Source/USB/addressConvertion.o ${OBJECTDIR}/Source/main.o ${OBJECTDIR}/Source/init.o ${OBJECTDIR}/Source/globalState.o ${OBJECTDIR}/Source/beanTasks.o ${OBJECTDIR}/Source/Custom_HID.o ${OBJECTDIR}/Source/ports.o ${OBJECTDIR}/Source/spi.o ${OBJECTDIR}/Source/typeConvert.o ${OBJECTDIR}/Source/sounds.o ${OBJECTDIR}/Source/initialTasks.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d ${OBJECTDIR}/Source/USB/usb_config.o.d ${OBJECTDIR}/Source/USB/usb_descriptors.o.d ${OBJECTDIR}/Source/USB/usb_device.o.d ${OBJECTDIR}/Source/USB/usb_function_hid.o.d ${OBJECTDIR}/Source/USB/addressConvertion.o.d ${OBJECTDIR}/Source/main.o.d ${OBJECTDIR}/Source/init.o.d ${OBJECTDIR}/Source/globalState.o.d ${OBJECTDIR}/Source/beanTasks.o.d ${OBJECTDIR}/Source/Custom_HID.o.d ${OBJECTDIR}/Source/ports.o.d ${OBJECTDIR}/Source/spi.o.d ${OBJECTDIR}/Source/typeConvert.o.d ${OBJECTDIR}/Source/sounds.o.d ${OBJECTDIR}/Source/initialTasks.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o ${OBJECTDIR}/Source/USB/usb_config.o ${OBJECTDIR}/Source/USB/usb_descriptors.o ${OBJECTDIR}/Source/USB/usb_device.o ${OBJECTDIR}/Source/USB/usb_function_hid.o ${OBJECTDIR}/Source/USB/addressConvertion.o ${OBJECTDIR}/Source/main.o ${OBJECTDIR}/Source/init.o ${OBJECTDIR}/Source/globalState.o ${OBJECTDIR}/Source/beanTasks.o ${OBJECTDIR}/Source/Custom_HID.o ${OBJECTDIR}/Source/ports.o ${OBJECTDIR}/Source/spi.o ${OBJECTDIR}/Source/typeConvert.o ${OBJECTDIR}/Source/sounds.o ${OBJECTDIR}/Source/initialTasks.o

# Source Files
SOURCEFILES=Source/USB/Usb_HID_tasks.c Source/USB/usb_config.c Source/USB/usb_descriptors.c Source/USB/usb_device.c Source/USB/usb_function_hid.c Source/USB/addressConvertion.c Source/main.c Source/init.c Source/globalState.c Source/beanTasks.c Source/Custom_HID.c Source/ports.c Source/spi.c Source/typeConvert.c Source/sounds.c Source/initialTasks.c



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
${OBJECTDIR}/Source/USB/Usb_HID_tasks.o: Source/USB/Usb_HID_tasks.c  .generated_files/91d4ba7e23501b8134141a61db9265ab2b43e0e1.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d" -o ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o Source/USB/Usb_HID_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_config.o: Source/USB/usb_config.c  .generated_files/5afddbb53d10f61ccb8c92e05a0c1423580630b8.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_config.o.d" -o ${OBJECTDIR}/Source/USB/usb_config.o Source/USB/usb_config.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_descriptors.o: Source/USB/usb_descriptors.c  .generated_files/a7bcad66643356fec7709b6bb9a7e1f32a56a4b.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_descriptors.o.d" -o ${OBJECTDIR}/Source/USB/usb_descriptors.o Source/USB/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_device.o: Source/USB/usb_device.c  .generated_files/b11af3ed68c3c6be846d305b67eb7c098f695b90.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_device.o.d" -o ${OBJECTDIR}/Source/USB/usb_device.o Source/USB/usb_device.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_function_hid.o: Source/USB/usb_function_hid.c  .generated_files/cd8f175b9cf2103946f2db44054f4a426d97ff22.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_function_hid.o.d" -o ${OBJECTDIR}/Source/USB/usb_function_hid.o Source/USB/usb_function_hid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/addressConvertion.o: Source/USB/addressConvertion.c  .generated_files/296ed82d35c59e591382f04cb71c15c31fe790fd.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/addressConvertion.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/addressConvertion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/USB/addressConvertion.o.d" -o ${OBJECTDIR}/Source/USB/addressConvertion.o Source/USB/addressConvertion.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/main.o: Source/main.c  .generated_files/4420cb4e6cb428823997dc78db2d87162ba7dc1d.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/main.o.d 
	@${RM} ${OBJECTDIR}/Source/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/main.o.d" -o ${OBJECTDIR}/Source/main.o Source/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/init.o: Source/init.c  .generated_files/2e9c5a35b8db6c48c049a12445d8e5fb47ac465d.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/init.o.d 
	@${RM} ${OBJECTDIR}/Source/init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/init.o.d" -o ${OBJECTDIR}/Source/init.o Source/init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/globalState.o: Source/globalState.c  .generated_files/1fc7216b418599b9003e008aa642987ba5cb3a32.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/globalState.o.d 
	@${RM} ${OBJECTDIR}/Source/globalState.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/globalState.o.d" -o ${OBJECTDIR}/Source/globalState.o Source/globalState.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/beanTasks.o: Source/beanTasks.c  .generated_files/9b753d5bc1bc3b7c5c008c0eec4df5cf803b346f.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/beanTasks.o.d 
	@${RM} ${OBJECTDIR}/Source/beanTasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/beanTasks.o.d" -o ${OBJECTDIR}/Source/beanTasks.o Source/beanTasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/Custom_HID.o: Source/Custom_HID.c  .generated_files/389fb31ebcf343cd42309e9d53267102585511f5.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/Custom_HID.o.d 
	@${RM} ${OBJECTDIR}/Source/Custom_HID.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/Custom_HID.o.d" -o ${OBJECTDIR}/Source/Custom_HID.o Source/Custom_HID.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/ports.o: Source/ports.c  .generated_files/ed1b58bde7aae42c654b8421e0d0697b0a0dc2b5.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/ports.o.d 
	@${RM} ${OBJECTDIR}/Source/ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/ports.o.d" -o ${OBJECTDIR}/Source/ports.o Source/ports.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/spi.o: Source/spi.c  .generated_files/2b8c0b139370182df80c6b59f831b35f24a02f2.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/spi.o.d 
	@${RM} ${OBJECTDIR}/Source/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/spi.o.d" -o ${OBJECTDIR}/Source/spi.o Source/spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/typeConvert.o: Source/typeConvert.c  .generated_files/672c11282cc0ec1ae578243db91eadae50ac561b.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/typeConvert.o.d 
	@${RM} ${OBJECTDIR}/Source/typeConvert.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/typeConvert.o.d" -o ${OBJECTDIR}/Source/typeConvert.o Source/typeConvert.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/sounds.o: Source/sounds.c  .generated_files/fd57670f529ffd353c17eefd3388ba1f1c0bbcf.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/sounds.o.d 
	@${RM} ${OBJECTDIR}/Source/sounds.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/sounds.o.d" -o ${OBJECTDIR}/Source/sounds.o Source/sounds.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/initialTasks.o: Source/initialTasks.c  .generated_files/30760575fd706c777ba0eb236a84f8542524d4eb.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/initialTasks.o.d 
	@${RM} ${OBJECTDIR}/Source/initialTasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/initialTasks.o.d" -o ${OBJECTDIR}/Source/initialTasks.o Source/initialTasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
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
	
${OBJECTDIR}/Source/initialTasks.o: Source/initialTasks.c  .generated_files/59e025b309ee25b912c2a7609889f149f8689562.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/initialTasks.o.d 
	@${RM} ${OBJECTDIR}/Source/initialTasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -I"../bean/bean.X" -MP -MMD -MF "${OBJECTDIR}/Source/initialTasks.o.d" -o ${OBJECTDIR}/Source/initialTasks.o Source/initialTasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION) -O2 -mno-float -o dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\bean\bean.X\dist\default\debug\bean.X.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
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
