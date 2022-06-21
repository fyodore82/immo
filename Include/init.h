/* 
 * File:   init.h
 * Author: fedor
 *
 * Created on 2 ???? 2022 ?., 18:17
 */

#ifndef INIT_H
#define	INIT_H

#ifdef	__cplusplus
extern "C" {
#endif

void init ();

/*********************************************************************
 * Function:       unsigned int SYSTEMConfig(unsigned int sys_clock, unsigned int flags)
 *
 * PreCondition:    None
 *
 * Input:           sys_clock - system clock in Hz
 *                  flags -
 *                  -    SYS_CFG_WAIT_STATES  - configure the flash wait states from the system clock
 *                  -    SYS_CFG_PB_BUS       - configure the PB bus from the system clock
 *                  -    SYS_CFG_PCACHE      - configure the pCache (if used)
 *                  -    SYS_CFG_ALL          - configure all based off of system clock
 *
 * Output:          the PB clock frequency
 *
 * Side Effects:    Could set the wait state, pb bus and turn on the pre-fetch buffer and cache. Sets the RAM
 *                  wait state to 0.
 *
 * Overview:	    The function sets the PB divider, the Flash Wait states and the DRM wait states to the optimum value.
 *                  It also enables the cacheability for the K0 segment.
 *
 * Note:            The interrupts are disabled shortly, the DMA is suspended and the system is unlocked while performing the operation.
 *                  Upon return the previous status of the interrupts and the DMA are restored. The system is re-locked.
 *
 * Example:	    SYSTEMConfig(72000000, SYS_CFG_ALL);
 ********************************************************************/
inline unsigned int __attribute__((always_inline)) SYSTEMConfig(unsigned int sys_clock, unsigned int flags) {
  unsigned int pb_clk;
  unsigned int int_status;
#ifdef _PCACHE
  unsigned int cache_status;
#endif

  int_status = INTDisableInterrupts();

  mBMXDisableDRMWaitState();

  //    if(flags & SYS_CFG_WAIT_STATES)
  //    {
  //        SYSTEMConfigWaitStates(sys_clock);
  //    }

  //    if(flags & SYS_CFG_PB_BUS)
  //    {
  //        SYSTEMConfigPB(sys_clock);
  //    }


#ifdef _PCACHE
  if (flags & SYS_CFG_PCACHE) {
    cache_status = mCheGetCon();
    cache_status |= CHE_CONF_PF_ALL;
    mCheConfigure(cache_status);
    CheKseg0CacheOn();
  }
#endif

  pb_clk = sys_clock;
  pb_clk >>= OSCCONbits.PBDIV;

  INTRestoreInterrupts(int_status);

  return pb_clk;

}



#ifdef	__cplusplus
}
#endif

#endif	/* INIT_H */

