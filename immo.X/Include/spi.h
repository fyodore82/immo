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
    LOG_ENTRY_RESET,    // When device has been reset
    LOG_ENTRY_STATE_CHANGE,
} SPILogEntryType;

typedef enum {
    SPI_NO_TASK,
    SPI_SEND_DATA,
    SPI_FIND_STOP,
    SPI_EXEC_USB_CMD,
} SPITask;

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

#define SPI_MAX_ADDR 0x7FFFF
#define SPI_SMALL_SECTOR 0xFFF

#define SPI_SEND_BUFF 8     // 4 bytes: hh, mm, msss
                            // 4 bytes: data

void txSPI(uint32_t addr, uint32_t data);
void spiTasks();
void writeLog(SPILogEntryType logType);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

