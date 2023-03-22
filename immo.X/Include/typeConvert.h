/* 
 * File:   typeConvert.h
 * Author: fedor
 *
 * Created on 30 ???? 2022 ?., 10:51
 */

#ifndef TYPECONVERT_H
#define	TYPECONVERT_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>

uint32_t byteArrToUint32ForSPI (unsigned char *byte);
void uint32ToByteArr (unsigned char *byte, uint32_t uint);

#ifdef	__cplusplus
}
#endif

#endif	/* TYPECONVERT_H */

