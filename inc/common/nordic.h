/**
 * @file nordic.h
 * @brief M
 *
 * M
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
 * @brief T
 *
 * T
 *
 * @param reg
 * @return i
 */
uint8_t nrf_read_register(uint8_t reg);



/**
 * @brief T
 *
 * T
 *
 * @param reg
 * @param value
 */
void nrf_write_register(uint8_t reg, uint8_t value);



/**
 * @brief T
 *
 * T
 *
 * @return i
 */
uint8_t nrf_read_status();



/**
 * @brief T
 *
 * T
 *
 * @param config
 */
void nrf_write_config(uint8_t config);



/**
 * @brief T
 *
 * T
 *
 * @return i
 */
uint8_t nrf_read_config();



/**
 * @brief T
 *
 * T
 *
 * @return i
 */
uint8_t nrf_read_rf_setup();



/**
 * @brief T
 *
 * T
 *
 * @param config
 */
void nrf_write_rf_setup(uint8_t config);



/**
 * @brief T
 *
 * T
 *
 * @return i
 */
uint8_t nrf_read_rf_ch();



/**
 * @brief T
 *
 * T
 *
 * @param channel
 */
void nrf_write_rf_ch(uint8_t channel);



/**
 * @brief T
 *
 * T
 *
 * @param address
 */
void nrf_read_TX_ADDR(uint8_t * address);



/**
 * @brief T
 *
 * T
 *
 * @param tx_addr
 */
void nrf_write_TX_ADDR(uint8_t * tx_addr);



/**
 * @brief T
 *
 * T
 *
 * @return i
 */
uint8_t nrf_read_fifo_status();



/**
 * @brief T
 *
 * T
 *
 */
void nrf_flush_tx_fifo();



/**
 * @brief T
 *
 * T
 *
 */
void nrf_flush_rx_fifo();


#endif
