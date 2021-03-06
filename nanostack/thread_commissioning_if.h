/*
 * Copyright (c) 2015 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: LicenseRef-PBL
 *
 * Licensed under the Permissive Binary License, Version 1.0 (the "License"); you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * https://www.mbed.com/licenses/PBL-1.0
 *
 * See the License for the specific language governing permissions and limitations under the License.
 *
 */

#ifndef NANOSTACK_THREAD_COMMISSIONING_IF_H_
#define NANOSTACK_THREAD_COMMISSIONING_IF_H_

#include "ns_types.h"

/**
 * This interface is used in thread leader role when Thread commissioning interface is enabled.
 */

/**
 * Register commissioner. This data is then registered as commissioner advertisements in thread network.
 *
 * \param interface_id Network Interface
 * \param border_router_address Border router locator address
 * \param commissioner_id_ptr commissioner id that is registering
 * \param session_id created session id for this commissioner
 *
 * return 0, OK
 * return -1 fail
 * return -2 Commissioner already registered.
 */
int thread_commissioning_register(int8_t interface_id, uint8_t border_router_address[static 16], uint8_t *commissioner_id_ptr, uint16_t commissioner_id_len, uint16_t *session_id);

/**
 * Remove commissioner session
 *
 * \param interface_id Network Interface
 * \param session_id Session id for this commissioner
 *
 * return true when OK
 * return false when failed
 */
bool thread_commissioning_unregister(int8_t interface_id, uint16_t session_id);

/**
 * Refresh commissioner keep alive timer
 *
 * \param interface_id Network Interface
 * \param session_id Session id for this commissioner
 *
 * return true when OK
 * return false when failed
 */
bool thread_commissioning_session_refresh(int8_t interface_id, uint16_t session_id);

/**
 * Update steering data. This might also affect permit join bit if that is available
 *
 * \param interface_id Network Interface
 * \param buf_ptr New steering data that is adverticed.
 * \param length length of new steering data
 *
 * return 0, OK
 * return -1 fail
 */
int thread_commissioning_steering_data_set(int8_t interface_id, uint8_t *buf_ptr, uint16_t length);

/**
 * Add pairwise key to allow transfer of network credentials. This can be done by joiner and joiner router.
 * After a timeout the key is deleted.
 *
 * \param interface_id Network Interface
 * \param valid_life_time time in seconds that this key is valid.
 * \param eui64 eui64 of device that key is valid for.
 * \param key fixed key used for this device
 *
 * return 0, OK
 * return -1 fail
 */
int thread_commissioning_pairwise_key_add(int8_t interface_id, uint32_t valid_life_time, uint8_t eui64[static 8], uint8_t key[static 16]);

/**
 * Delete all pairwise keys from the device.
 *
 * \param interface_id Network Interface
 *
 * return 0, OK
 * return -1 fail
 */
int thread_commissioning_pairwise_key_delete_all(int8_t interface_id);

/** @todo
 * This function is interop hack only and should not exists when proper commissioner
 * joiner implementation is made. The Link configuration is learned during commissioning and should be
 * updated using new function in thread management interface thread_managenet_configuration_set.
 * That change would also remove the following functions
 * int thread_managenet_security_material_set(int8_t nwk_interface_id, bool enableSecurity, uint8_t *thrMasterKey, uint32_t thrKeySequenceCounter, uint32_t thrKeyRotation);
 * int thread_management_commission_data_set(int8_t nwk_interface_id);
 * functions
 *
 * */
int thread_commissioning_enable_security(int8_t interface_id);
/**
 * get registered border router locator address
 *
 * \param interface_id interface id
 * \param address_ptr address of the border router where the commissioner is registered.
 *
 * return 0, OK
 * return <0 fail
 */
int thread_commissioning_border_router_locator_get(int8_t interface_id, uint8_t *address_ptr);

/**
 * get registered commissioner ID
 *
 * \param interface_id interface id
 *
 * return pointer to commissioner ID string
 * return NULL if failed
 */
char* thread_commissioning_commissioner_id_get(int8_t interface_id);

/**
 * get registered commissioner session ID
 *
 * \param interface_id interface id
 *
 * return Session ID
 * return 0 if failed
 */
uint16_t thread_commissioning_session_id_get(int8_t interface_id);

#endif /* NANOSTACK_THREAD_COMMISSIONING_IF_H_ */
