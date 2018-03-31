/**
 * @file nordic.h
 * @brief HAL for the NRF24L01
 *
 * High level abstraction library for communication
 * with the NRF24L01 chip using SPI
 *
 * @author Zachary Asmussen
 * @date March 12th, 2018
 *
 */
#ifndef __NORDIC_H__
#define __NORDIC_H__
#include <stdint.h>
#include <stdlib.h>


/**
 * @brief Reads a register in the NRF
 *
 * Given a certain register this reads the value of that register
 * in the NRF and returns its value
 *
 * @param reg is the register to read
 * @return is the value at that location
 */
uint8_t nrf_read_register(uint8_t reg);



/**
 * @brief Writes to a register
 *
 * Given a register value this writes a certain value to the register
 * in the NRF chip
 *
 * @param reg is the register to change
 * @param value is the value to change it to
 */
void nrf_write_register(uint8_t reg, uint8_t value);



/**
 * @brief Reads status register
 *
 * This reads the value of the status register in the NRF chip
 *
 * @return is the value of the register
 */
uint8_t nrf_read_status();



/**
 * @brief Writes to config register
 *
 * This writes specifically to the configuration register
 * in the NRF chip
 *
 * @param config is the value to write to config
 */
void nrf_write_config(uint8_t config);



/**
 * @brief Reads the config register
 *
 * This reads the value currently in the config register
 * in the NRF chip
 *
 * @return is the value of the register
 */
uint8_t nrf_read_config();



/**
 * @brief Reads RF_SETUP register
 *
 * This reads the value currently in the RF_SETUP register
 * in the NRF chip
 *
 * @return is the value of the register
 */
uint8_t nrf_read_rf_setup();



/**
 * @brief Writes to RF_SETUP register
 *
 * This writes a byte of data to the RF_SETUP register in
 * the NRF chip
 *
 * @param config is the value to write
 */
void nrf_write_rf_setup(uint8_t config);



/**
 * @brief Reads RF_CH register
 *
 * This reads the value currently in the RF_CH register
 * in the NRF chip
 *
 * @return is the value of the register
 */
uint8_t nrf_read_rf_ch();



/**
 * @brief Writes to RF_CH register
 *
 * This writes a byte of data to the RF_CH register in
 * the NRF chip
 *
 * @param config is the value to write
 */
void nrf_write_rf_ch(uint8_t channel);



/**
 * @brief Reads 5 bytes from TX_ADDR register
 *
 * This reads the 5 bytes that are in the TX_ADDR register
 * in the NRF chip
 *
 * @param address is a pointer to the returned array of bytes
 */
void nrf_read_TX_ADDR(uint8_t * address);



/**
 * @brief Writes 5 bytes to the TX_ADDR register
 *
 * This writes 5 bytes to the TX_ADDR register in the NRF chip
 *
 * @param tx_addr is a pointer to the 5 bytes to write
 */
void nrf_write_TX_ADDR(uint8_t * tx_addr);



/**
 * @brief Reads FIFO_STATUS register
 *
 * This reads the value of the FIFO_STATUS register
 * in the NRF chip
 *
 * @return is the value of the register
 */
uint8_t nrf_read_fifo_status();



/**
 * @brief Sends FLUSH_TX command
 *
 * This sends the command FLUSH_TX to the NRF chip to
 * empty the TX buffer
 *
 */
void nrf_flush_tx_fifo();



/**
* @brief Sends FLUSH_RX command
*
* This sends the command FLUSH_RX to the NRF chip to
* empty the RX buffer
 *
 */
void nrf_flush_rx_fifo();


#endif
