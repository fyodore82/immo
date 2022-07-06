/*********************************************************************
 *
 *                  PIC32 Boot Loader
 *
 *********************************************************************
 * FileName:        Bootloader.c
 * Dependencies:
 * Processor:       PIC32
 *
 * Compiler:        MPLAB C32
 *                  MPLAB IDE
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the �Company�) for its PIC32 Microcontroller is intended
 * and supplied to you, the Company�s customer, for use solely and
 * exclusively on Microchip PIC32 Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 * $Id:  $
 * $Name: $
 *
 **********************************************************************/
#include <stdlib.h>
#include <xc.h>
#include <bean.h>

#include "..\Include\GenericTypeDefs.h"
#include "..\Include\HardwareProfile\HardwareProfile.h"
#include "..\Include\USB\addressConvertion.h"
#include "..\Include\init.h"
#include "..\Include\globalState.h"
#include "..\Include\beanTasks.h"
#include "..\Include\spi.h"

// From Bootloader.h
#if defined(TRANSPORT_LAYER_USB)
#include "..\Include\Usb\Usb_Tasks.h"
#endif

// All Config registers are set in bootloader as they are not overwritten during programming thru bootloader
// Here they are duplicated for debugging
// DEVCFG0
#pragma config CP = 1
#pragma config BWP = OFF                // Boot write protect: OFF
// #pragma config PWP = 0b111111111       
#pragma config ICESEL = ICS_PGx3    // ICE pins configured on PGx1 (PGx2 is multiplexed with USB D+ and D- pins).
#pragma config JTAGEN = 0
// #pragma config DEBUG = 00        // Debug can be enabled by MPLAB
#pragma config DEBUG    = OFF           // Background Debugger disabled

// DEVCFG1
#pragma config FWDTEN = OFF             // WD timer: OFF
#pragma config FCKSM = 0b11               // Disabled
#pragma config FPBDIV = DIV_1           // Peripheral Bus Clock: Divide by 1
#pragma config OSCIOFNC = 0             // OLKO is disabled
#pragma config POSCMOD = HS             // Primary Oscillator Mode: High Speed xtal
#pragma config IESO = 0                 // Internal External Switchover mode is disabled
#pragma config FSOSCEN = 0              // Disable Secondary Oscillator
#pragma config FNOSC = PRIPLL           // Oscillator Selection: Primary oscillator  w/ PLL

// DEVCFG2
#pragma config FPLLODIV = DIV_2         // PLL Output Divider: Divide by 2 (80 / 2 = 40)
// Configuring the Device Configuration Registers
// 80Mhz Core/Periph, Pri Osc w/PLL, Write protect Boot Flash
#pragma config UPLLEN   = ON        // USB PLL Enabled
#pragma config UPLLIDIV = DIV_5     // USB PLL Input Divider = Divide by 5 (20 / 5 = 4)

#pragma config FPLLMUL = MUL_20         // PLL Multiplier: Multiply by 20 (4 * 20 = 80))
#pragma config FPLLIDIV = DIV_5         // PLL Input Divider:  Divide by 5 (20 / 5 = 4)

// DEVCFG3
#pragma config FVBUSONIO = 0        // pin 25: VBUSON pin is controlled by the port function
#pragma config FUSBIDIO = 0         // pin 14: USBID pin is controlled by the port function

#pragma config IOL1WAY = ON
#pragma config PMDL1WAY = ON


/********************************************************************
 * Function: 	main()
 *
 * Precondition: 
 *
 * Input: 		None.
 *
 * Output:		None.
 *
 * Side Effects:	None.
 *
 * Overview: 	Main entry function. If there is a trigger or 
 *				if there is no valid application, the device 
 *				stays in firmware upgrade mode.
 *
 *			
 * Note:		 	None.
 ********************************************************************/
INT main(void) {
  initGlobalState(&state);
  
  init();
  
  UINT pbClk;

  // Setup configuration
  pbClk = SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
  
  // Initialize the transport layer - UART/USB/Ethernet
  TRANS_LAYER_Init(pbClk);
  while (1) {
    TRANS_LAYER_Task(); // Run Transport layer tasks
    beanTasks();
    spiTasks();
  }
  // Close trasnport layer.
  TRANS_LAYER_Close();
  return 0;
}

/*********************End of File************************************/


