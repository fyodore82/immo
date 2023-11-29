/*
 * File:   spi.h
 * Author: fedor
 *
 * Created on 27 ???? 2022 ?., 12:24
 */

#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

typedef enum {
    DONT_LOG,
    LOG_ENTRY_RESET,    // When device has been reset
    LOG_ENTRY_STATE_CHANGE,
    // When no IMMO_IN have come for last 5secs or more (lost 2 transmitions)
    LOG_ENTRY_IMMO_IN_5S_DELAY,
} SPILogEntryType;

//typedef enum {
//    SPI_NO_TASK,
//    SPI_SEND_DATA,
////    SPI_FIND_STOP,
//    SPI_EXEC_USB_CMD,
//} SPIUSBTask;

typedef union {
    struct {
        uint8_t spiLogType:8;
        uint16_t resetBits:16;
        uint8_t dummy:8;  // To adjust to 4bytes boundary
    };
    struct {
        uint32_t w32:32;
    };
} SPIEntry;

// Skip start of SPI addr space as it seems to be buggy
#define SPI_INITIAL_ADDR 0
#define SPI_MAX_ADDR 0x7FFFF
#define SPI_SMALL_SECTOR 0xFFF

#define SPI_SEND_BUFF 2 * 30     // 1st word: hh, mm, msss
                                 // 2nd word: data
#define SPI_REC_BUFF 4

void findStop();
void logSpi(SPILogEntryType logType);

uint32_t getSpiAddr();
void spiUsbTasks();
void setUsbAddrData(uint32_t addr, uint32_t data);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

