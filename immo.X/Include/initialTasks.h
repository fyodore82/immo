/* 
 * File:   initialTasks.h
 * Author: fedor
 *
 * Created on February 2, 2023, 7:33 PM
 */

#ifndef INITIALTASKS_H
#define	INITIALTASKS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define SPI_FIND_STOP_ADDR 0b00000001
#define SPI_WRITE_RESET_REASON 0b00000010
#define PLAY_WELCOME_SOUND 0b00000100

void initialTasks();


#ifdef	__cplusplus
}
#endif

#endif	/* INITIALTASKS_H */

