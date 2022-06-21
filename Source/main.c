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

// From Bootloader.h
#if defined(TRANSPORT_LAYER_USB)
#include "..\Include\Usb\Usb_Tasks.h"
#endif


// Configuring the Device Configuration Registers
// 80Mhz Core/Periph, Pri Osc w/PLL, Write protect Boot Flash
#if defined(TRANSPORT_LAYER_USB) || defined(TRANSPORT_LAYER_USB_HOST)
#pragma config UPLLEN   = ON        // USB PLL Enabled
#pragma config UPLLIDIV = DIV_5     // USB PLL Input Divider = Divide by 5 (20 / 5 = 4)
#endif

#pragma config DEBUG    = OFF           // Background Debugger disabled
#pragma config FPLLMUL = MUL_20         // PLL Multiplier: Multiply by 20 (4 * 20 = 80))
#pragma config FPLLIDIV = DIV_5         // PLL Input Divider:  Divide by 5 (20 / 5 = 4)

#if defined(__PIC32MX1XX_2XX__)
// For PIC32MX1xx, PIC32MX2xx devices the output divisor is set to 2 to produce max 40MHz clock.
// 40Mhz clock
#pragma config FPLLODIV = DIV_2         // PLL Output Divider: Divide by 2 (80 / 2 = 40)
#elif defined (__PIC32MX3XX_7XX__)
//For PIC32MX3xx, PIC32MX4xx, PIC32MX5xx, PIC32MX6xx and PIC32MX7xx devices, 
//the output divisor is set to 1 to produce max 80MHz clock.
#pragma config FPLLODIV = DIV_1         // PLL Output Divider: Divide by 1
#endif

#pragma config FWDTEN = OFF             // WD timer: OFF
#pragma config POSCMOD = HS             // Primary Oscillator Mode: High Speed xtal
#pragma config FNOSC = PRIPLL           // Oscillator Selection: Primary oscillator  w/ PLL
#pragma config FPBDIV = DIV_1           // Peripheral Bus Clock: Divide by 1
#pragma config BWP = OFF                // Boot write protect: OFF

#if defined(__PIC32MX1XX_2XX__)
// For PIC32MX1xx, PIC32MX2xx devices there are jumpers on PIM to choose from PGx1/PGx2.
#pragma config ICESEL = ICS_PGx3    // ICE pins configured on PGx1 (PGx2 is multiplexed with USB D+ and D- pins).
#elif defined(__PIC32MX3XX_7XX__)
// For PIC32MX3xx, PIC32MX4xx, PIC32MX5xx, PIC32MX6xx and PIC32MX7xx 
// devices the ICE connection is on PGx2. .
#pragma config ICESEL = ICS_PGx2    // ICE pins configured on PGx2, Boot write protect OFF.
#endif

#if defined(TRANSPORT_LAYER_ETH)
#pragma config FMIIEN = OFF, FETHIO = OFF	// external PHY in RMII/alternate configuration. Applicable for devices with internal MAC only.
#endif

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
  }
  // Close trasnport layer.
  TRANS_LAYER_Close();
  return 0;
}

/*********************End of File************************************/


