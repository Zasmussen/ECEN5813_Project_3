/**
 * @file spi.h
 * @brief M
 *
 * M
 *
 * @author Zachary Asmussen
 * @date March 12th, 2018
 *
 */
#ifndef __SPI_H__
#define __SPI_H__



/**
 * @brief T
 *
 * T
 *
 */
void SPI_init();



/**
 * @brief T
 *
 * T
 *
 * @param byte
 *
 */
void SPI_read_byte(uint8_t byte);



/**
 * @brief T
 *
 * T
 *
 * @param byte
 *
 */
void SPI_write_byte(uint8_t byte);



/**
 * @brief T
 *
 * T
 *
 * @param p
 * @param length
 *
 */
void SPI_send_packet(uint8_t * p, size_t length);



/**
 * @brief T
 *
 * T
 *
 */
void SPI_flush();


#endif
