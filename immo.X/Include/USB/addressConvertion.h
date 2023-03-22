/* 
 * File:   addressConvertion.h
 * Author: fedor
 *
 * Created on 1 мая 2022 г., 14:29
 */

#ifndef ADDRESSCONVERTION_H
#define	ADDRESSCONVERTION_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <xc.h>
    
    typedef unsigned long _paddr_t; /* a physical address */
    typedef unsigned long _vaddr_t; /* a virtual address */

    #define KVA_TO_PA(v) 	((_paddr_t)(v) & 0x1fffffff)
    #define PA_TO_KVA0(pa)	((void *) ((pa) | 0x80000000))
    #define PA_TO_KVA1(pa)	((void *) ((pa) | 0xa0000000))

/*********************************************************************
 * SYSTEMConfig Flags
 *********************************************************************/
#define SYS_CFG_WAIT_STATES     0x00000001 //SYSTEMConfig wait states
#define SYS_CFG_PB_BUS          0x00000002 //SYSTEMConfig pb bus
#define SYS_CFG_PCACHE          0x00000004 //SYSTEMConfig cache
#define SYS_CFG_ALL             0xFFFFFFFF //SYSTEMConfig All
    
#define mBMXDisableDRMWaitState() 	(BMXCONCLR = _BMXCON_BMXWSDRM_MASK)
    
unsigned int __attribute__((nomips16)) INTDisableInterrupts(void);
        
 /*********************************************************************
 * Function:        INTRestoreInterrupts(unsigned int status)
 *
 * PreCondition:    None
 *
 * Input:           value of the status registor
 *
 * Output:
 *
 * Side Effects:    Interrupts are restored to previous state
 *
 * Overview:        Interrupts are enabled by setting the IE bit
 *                  in the status register
 ********************************************************************/
void __attribute__((nomips16))  INTRestoreInterrupts(unsigned int status);

unsigned int __attribute__((nomips16))  INTEnableInterrupts(void);
void __attribute__ ((nomips16)) INTEnableSystemMultiVectoredInt(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ADDRESSCONVERTION_H */

