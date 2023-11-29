#include <stdlib.h>
#include <xc.h>
#include <bean.h>

#include "..\Include\GenericTypeDefs.h"
#include "..\Include\HardwareProfile\HardwareProfile.h"
#include "..\Include\USB\addressConvertion.h"
#include "..\Include\init.h"
#include "..\Include\globalState.h"
#include "..\Include\stateControl.h"
#include "..\Include\beanTasks.h"
#include "..\Include\spi.h"
#include "..\Include\initialTasks.h"
#include "..\Include\ports.h"

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

INT main(void) {
  initGlobalState(&state);
  
  init();
  
//  UINT pbClk;

  // Setup configuration
//  pbClk = SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
  
  // Initialize the transport layer - UART/USB/Ethernet
  TRANS_LAYER_Init(0);
  
  while (1) {
    findStop();
    spiUsbTasks();
    initialTasks();
    processPortsChange();
    TRANS_LAYER_Task(); // Run Transport layer tasks
    beanTasks();
    globalStateTasks();
    processStateChange();
  }
  // Close trasnport layer.
  TRANS_LAYER_Close();
  return 0;
}

/*********************End of File************************************/


