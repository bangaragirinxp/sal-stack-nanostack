/*
 * Copyright (c) 2015 ARM. All rights reserved.
 */

/**
 * Public API to handle the Thread management framework message parsing and building.
 */

#ifndef THREAD_MESHCOP_LIB_H_
#define THREAD_MESHCOP_LIB_H_

#include "ns_types.h"

/**
 * TLV Types used in thread network
 */
/**
 * Network configuration TLV
 */
#define MESHCOP_TLV_CHANNEL                                0
#define MESHCOP_TLV_PAN                                    1
#define MESHCOP_TLV_XPANID                                 2
#define MESHCOP_TLV_NETWORK_NAME                           3
#define MESHCOP_TLV_COMMISSIONING_CREDENTIALS              4
#define MESHCOP_TLV_NETWORK_MASTER_KEY                     5
#define MESHCOP_TLV_NETWORK_KEY_SEQUENCE                   6
#define MESHCOP_TLV_NETWORK_MESH_LOCAL_ULA                 7

/**
 * Network management TLV
 */
#define MESHCOP_TLV_STEERING_DATA                          8
#define MESHCOP_TLV_BORDER_ROUTER_LOCATOR                  9
#define MESHCOP_TLV_COMMISSIONER_ID                        10
#define MESHCOP_TLV_COMMISSIONER_SESSION_ID                11
#define MESHCOP_TLV_COMMISSIONING_TIME_STAMP               14
#define MESHCOP_TLV_SECURITY_POLICY                        12
#define MESHCOP_TLV_GET                                    13
#define MESHCOP_TLV_STATE                                  16

/**
 * Relay message TLV
 */
#define MESHCOP_TLV_JOINER_ENCAPSULATION                   17
#define MESHCOP_TLV_JOINER_UDP_PORT                        18
#define MESHCOP_TLV_JOINER_IID                             19
#define MESHCOP_TLV_JOINER_ROUTER_LOCATOR                  20
#define MESHCOP_TLV_JOINER_ROUTER_KEK                      21

/**
 * Application provisioning TLV?
 */
#define MESHCOP_TLV_PROVISIONING_URL                       32
#define MESHCOP_TLV_VENDOR_NAME                            33
#define MESHCOP_TLV_VENDOR_MODEL                           34
#define MESHCOP_TLV_VENDOR_SW_VERSION                      35
#define MESHCOP_TLV_VENDOR_DATA                            36
#define MESHCOP_TLV_VENDOR_STACK_VERSION                   37

/**
 * Tunneling
 */
#define MESHCOP_TLV_UDP_ENCAPSULATION                      48
#define MESHCOP_TLV_IPV6_ADDRESS                           49

/**
 * Write array TLV.
 *
 * \param ptr pointer for array where to write the TLV.
 * \param type Type of TLV.
 * \param length length of the data that is written in TLV.
 * \param data array for TLV value.
 * \return pointer value for writing the next TLV.
 */
uint8_t *thread_meshcop_tlv_data_write(uint8_t *ptr, const  uint8_t type, const  uint16_t length, const uint8_t *data);

/**
 * Write 1 byte length TLV.
 *
 * \param ptr pointer for array where to write the TLV.
 * \param type Type of TLV.
 * \param data value.
 * \return pointer value for writing the next TLV.
 */
uint8_t *thread_meshcop_tlv_data_write_uint8(uint8_t *ptr, const uint8_t type, const uint8_t data);

/**
 * Write 2 byte length TLV.
 *
 * \param ptr pointer for array where to write the TLV.
 * \param type Type of TLV.
 * \param data value.
 * \return pointer value for writing the next TLV.
 */
uint8_t *thread_meshcop_tlv_data_write_uint16(uint8_t *ptr, const uint8_t type, const uint16_t data);

/**
 * Write 4 byte length TLV.
 *
 * \param ptr pointer for array where to write the TLV.
 * \param type Type of TLV.
 * \param data value.
 * \return pointer value for writing the next TLV.
 */
uint8_t *thread_meshcop_tlv_data_write_uint32(uint8_t *ptr, const uint8_t type, const uint32_t data);

/**
 * Find TLV from message.
 *
 * \param ptr Message buffer.
 * \param length Length of the message buffer to validate message.
 * \param type Type of TLV searched.
 * \param result_ptr Pointer value is given as result if length is positive. Can be NULL which only searches for the length.
 * \return The length of the TLV data found
 * \return 0 if TLV is empty or no TLV found.
 * \return negative value indicates corrupted message.
 */
uint16_t thread_meshcop_tlv_find(const uint8_t *ptr, const uint16_t length, const uint8_t type, uint8_t **result_ptr);

/**
 * Read 1 byte length TLV.
 *
 * \param ptr pointer TLV message array.
 * \param length length of TLV message array.
 * \param type Type of TLV.
 * \param data_ptr pointer to variable where the value is read.
 * \return pointer length of TLV 1 if success. 0 means TLV not found or does not have any data.
 * Any other value indicates that TLV is not as expected.
 */
uint8_t thread_meshcop_tlv_data_get_uint8(const uint8_t *ptr, const uint16_t length, const uint8_t type, uint8_t *data_ptr);

/**
 * Read 2 byte length TLV.
 *
 * \param ptr pointer TLV message array.
 * \param length length of TLV message array.
 * \param type Type of TLV.
 * \param data_ptr pointer to variable where the value is read.
 * \return pointer length of TLV 2 if success. 0 means TLV not found or does not have any data.
 * Any other value indicates that TLV is not as expected.
 */
uint8_t thread_meshcop_tlv_data_get_uint16(const uint8_t *ptr, const uint16_t length, const uint8_t type, uint16_t *data_ptr);

/**
 * Read 4 byte length TLV.
 *
 * \param ptr pointer TLV message array.
 * \param length length of TLV message array.
 * \param type Type of TLV.
 * \param data_ptr pointer to variable where the value is read.
 * \return pointer length of TLV 4 if success. 0 means TLV not found or does not have any data.
 * Any other value indicates that TLV is not as expected.
 */
uint8_t thread_meshcop_tlv_data_get_uint32(const uint8_t *ptr, const uint16_t length, const uint8_t type, uint32_t *data_ptr);

#endif /* THREAD_MESHCOP_LIB_H_ */