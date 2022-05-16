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
SOURCEFILES_QUOTED_IF_SPACED=Source/USB/Usb_HID_tasks.c Source/USB/usb_config.c Source/USB/usb_descriptors.c Source/USB/usb_device.c Source/USB/usb_function_hid.c Source/main.c Source/addressConvertion.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o ${OBJECTDIR}/Source/USB/usb_config.o ${OBJECTDIR}/Source/USB/usb_descriptors.o ${OBJECTDIR}/Source/USB/usb_device.o ${OBJECTDIR}/Source/USB/usb_function_hid.o ${OBJECTDIR}/Source/main.o ${OBJECTDIR}/Source/addressConvertion.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d ${OBJECTDIR}/Source/USB/usb_config.o.d ${OBJECTDIR}/Source/USB/usb_descriptors.o.d ${OBJECTDIR}/Source/USB/usb_device.o.d ${OBJECTDIR}/Source/USB/usb_function_hid.o.d ${OBJECTDIR}/Source/main.o.d ${OBJECTDIR}/Source/addressConvertion.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Source/USB/Usb_HID_tasks.o ${OBJECTDIR}/Source/USB/usb_config.o ${OBJECTDIR}/Source/USB/usb_descriptors.o ${OBJECTDIR}/Source/USB/usb_device.o ${OBJECTDIR}/Source/USB/usb_function_hid.o ${OBJECTDIR}/Source/main.o ${OBJECTDIR}/Source/addressConvertion.o

# Source Files
SOURCEFILES=Source/USB/Usb_HID_tasks.c Source/USB/usb_config.c Source/USB/usb_descriptors.c Source/USB/usb_device.c Source/USB/usb_function_hid.c Source/main.c Source/addressConvertion.c



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
${OBJECTDIR}/Source/USB/Usb_HID_tasks.o: Source/USB/Usb_HID_tasks.c  .generated_files/2d89fd1a9fb02e3e68ae1150d0ee83152dbf3a36.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d" -o ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o Source/USB/Usb_HID_tasks.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_config.o: Source/USB/usb_config.c  .generated_files/279152006cd15f91e04c7615a66f371f522e5c47.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_config.o.d" -o ${OBJECTDIR}/Source/USB/usb_config.o Source/USB/usb_config.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_descriptors.o: Source/USB/usb_descriptors.c  .generated_files/3ae56721e4fcbe3c3450c0a1578fb28969fac777.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_descriptors.o.d" -o ${OBJECTDIR}/Source/USB/usb_descriptors.o Source/USB/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_device.o: Source/USB/usb_device.c  .generated_files/c9ddfab31425bc8d88e4f1c3eef58ab28fc72bab.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_device.o.d" -o ${OBJECTDIR}/Source/USB/usb_device.o Source/USB/usb_device.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_function_hid.o: Source/USB/usb_function_hid.c  .generated_files/c3950e59eb6681bb6d48af6b9c0e73e826027020.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_function_hid.o.d" -o ${OBJECTDIR}/Source/USB/usb_function_hid.o Source/USB/usb_function_hid.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/main.o: Source/main.c  .generated_files/67fa964acb131e43065f5ea904544162ef18d2d2.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/main.o.d 
	@${RM} ${OBJECTDIR}/Source/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/main.o.d" -o ${OBJECTDIR}/Source/main.o Source/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/addressConvertion.o: Source/addressConvertion.c  .generated_files/cb3e4b4e010721e3121300e77a2cc474e7375c63.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/addressConvertion.o.d 
	@${RM} ${OBJECTDIR}/Source/addressConvertion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/addressConvertion.o.d" -o ${OBJECTDIR}/Source/addressConvertion.o Source/addressConvertion.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/Source/USB/Usb_HID_tasks.o: Source/USB/Usb_HID_tasks.c  .generated_files/6259270f96869fe67a8c2a2cf49b2f43c92d3fa0.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/USB/Usb_HID_tasks.o.d" -o ${OBJECTDIR}/Source/USB/Usb_HID_tasks.o Source/USB/Usb_HID_tasks.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_config.o: Source/USB/usb_config.c  .generated_files/894a2fc9df5e2139cbb181037cc2e736c97c8524.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_config.o.d" -o ${OBJECTDIR}/Source/USB/usb_config.o Source/USB/usb_config.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_descriptors.o: Source/USB/usb_descriptors.c  .generated_files/833a09f3d540c5d89a414989f8fe11025842eaac.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_descriptors.o.d" -o ${OBJECTDIR}/Source/USB/usb_descriptors.o Source/USB/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_device.o: Source/USB/usb_device.c  .generated_files/c266bc4f7adf4edfe7e65a086cc67bea6db04134.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_device.o.d" -o ${OBJECTDIR}/Source/USB/usb_device.o Source/USB/usb_device.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/USB/usb_function_hid.o: Source/USB/usb_function_hid.c  .generated_files/4b92c965f3db7f187590499bc0ba61b1fa4bcdd4.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source/USB" 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o.d 
	@${RM} ${OBJECTDIR}/Source/USB/usb_function_hid.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/USB/usb_function_hid.o.d" -o ${OBJECTDIR}/Source/USB/usb_function_hid.o Source/USB/usb_function_hid.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/main.o: Source/main.c  .generated_files/82f3f93fd84a0d191aaf8b234aef903bfa328c52.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/main.o.d 
	@${RM} ${OBJECTDIR}/Source/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/main.o.d" -o ${OBJECTDIR}/Source/main.o Source/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Source/addressConvertion.o: Source/addressConvertion.c  .generated_files/6cb458bbafc46cdef6bcc95202b1fb4298f8cc0.flag .generated_files/35b059e026b463500ba6e17fe172f881244224c5.flag
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/addressConvertion.o.d 
	@${RM} ${OBJECTDIR}/Source/addressConvertion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -mips16 -mno-float -O2 -DTRANSPORT_LAYER_USB -MP -MMD -MF "${OBJECTDIR}/Source/addressConvertion.o.d" -o ${OBJECTDIR}/Source/addressConvertion.o Source/addressConvertion.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    app_32MX220F032B.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -O2 -mno-float -o dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   app_32MX220F032B.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -O2 -mno-float -o dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/immo.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

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
