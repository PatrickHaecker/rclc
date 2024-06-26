// Copyright (c) 2019 - for information on the respective copyright owner
// see the NOTICE file and/or the repository https://github.com/ros2/rclc.
// Copyright 2014 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RCLC__INIT_H_
#define RCLC__INIT_H_

#if __cplusplus
extern "C"
{
#endif

#include <rcl/allocator.h>
#include "rclc/types.h"
#include "rclc/visibility_control.h"

/**
 *  Initializes rcl and creates some support data structures.
 *  Initializes clock as RCL_STEADY_TIME.
 *  * <hr>
 * Attribute          | Adherence
 * ------------------ | -------------
 * Allocates Memory   | Yes (in RCL)
 * Thread-Safe        | No
 * Uses Atomics       | No
 * Lock-Free          | Yes
 *
 * \param[inout] support a zero-initialized rclc_support_t
 * \param[in] argc number of args of main
 * \param[in] argv array of arguments of main
 * \param[in] allocator allocator for allocating memory
 * \return `RCL_RET_OK` if RCL was initialized successfully
 * \return `RCL_RET_INVALID_ARGUMENT` if any null pointer as argument
 * \return `RCL_RET_ERROR` in case of failure
 */
RCLC_PUBLIC
rcl_ret_t
rclc_support_init(
  rclc_support_t * support,
  int argc,
  char const * const * argv,
  rcl_allocator_t * allocator);

/**
 *  Initializes rcl and creates some support data structures.
 *  Initializes clock as RCL_STEADY_TIME.
 *  * <hr>
 * Attribute          | Adherence
 * ------------------ | -------------
 * Allocates Memory   | Yes (in RCL)
 * Thread-Safe        | No
 * Uses Atomics       | No
 * Lock-Free          | Yes
 *
 * \param[inout] support a zero-initialized rclc_support_t
 * \param[in] argc number of args of main
 * \param[in] argv array of arguments of main
 * \param[in] init_options custom initial options
 * \param[in] allocator allocator for allocating memory
 * \return `RCL_RET_OK` if RCL was initialized successfully
 * \return `RCL_RET_INVALID_ARGUMENT` if any null pointer as argument
 * \return `RCL_RET_ERROR` in case of failure
 */
RCLC_PUBLIC
rcl_ret_t
rclc_support_init_with_options(
  rclc_support_t * support,
  int argc,
  char const * const * argv,
  rcl_init_options_t * init_options,
  rcl_allocator_t * allocator);


/**
 *  De-allocates the rclc_support_t object.
 *
 *  * <hr>
 * Attribute          | Adherence
 * ------------------ | -------------
 * Allocates Memory   | Yes (in RCL)
 * Thread-Safe        | No
 * Uses Atomics       | No
 * Lock-Free          | Yes
 *
 * \param[inout] init_obj a preallocated rclc_support_t
 * \return `RCL_RET_OK` if operation was successful
 * \return `RCL_RET_INVALID_ARGUMENT` if any null pointer as argument
 * \return `RCL_RET_ERROR` in case of failure
 */
RCLC_PUBLIC
rcl_ret_t
rclc_support_fini(
  rclc_support_t * support);

/**
 *  Allocates memory for an rclc_support_t object.
 *  Can be used if no stack allocation can or should be used.
 *
 *  * <hr>
 * Attribute          | Adherence
 * ------------------ | -------------
 * Allocates Memory   | Yes
 * Thread-Safe        | No
 * Uses Atomics       | No
 * Lock-Free          | No
 *
 * \param[in] allocator the rcl_allocator_t to be used
 * \return pointer to the support (rclc_support_t)
 * \return NULL, if no memory could be allocated.
 */
RCLC_PUBLIC
rclc_support_t *
rclc_support_alloc(const rcl_allocator_t * const allocator);

/**
 *  Return the pointer to the context member of struct support.
 *
 *  * <hr>
 * Attribute          | Adherence
 * ------------------ | -------------
 * Allocates Memory   | No
 * Thread-Safe        | No
 * Uses Atomics       | No
 * Lock-Free          | Yes
 *
 * \param[inout] support a heap-allocated rclc_support_t
 * \return `RCL_RET_OK` if operation was successful
 * \return `RCL_RET_INVALID_ARGUMENT` if any null pointer as argument
 */
rcl_context_t *
rclc_get_context(
  rclc_support_t * support);

/**
 *  De-allocates an rclc_support_t object.
 *
 *  * <hr>
 * Attribute          | Adherence
 * ------------------ | -------------
 * Allocates Memory   | Yes
 * Thread-Safe        | No
 * Uses Atomics       | No
 * Lock-Free          | No
 *
 * \param[inout] support a heap-allocated rclc_support_t
 * \param[in] allocator the rcl_allocator_t to be used
 * \return `RCL_RET_OK` if operation was successful
 * \return `RCL_RET_INVALID_ARGUMENT` if any null pointer as argument
 */
rcl_ret_t
rclc_support_free(
  rclc_support_t * support,
  const rcl_allocator_t * const allocator);


/**
 *  Allocates the rcl_allocator_t object and sets it to default values.
 *  Can be used as an alternative to rcl_get_default_allocator() if no
 *  stack allocation can or should be used.
 *
 *  * <hr>
 * Attribute          | Adherence
 * ------------------ | -------------
 * Allocates Memory   | Yes
 * Thread-Safe        | No
 * Uses Atomics       | No
 * Lock-Free          | No
 *
 * \return pointer to the allocator (rcl_allocator_t)
 * \return NULL, if no memory could be allocated.
 */
RCLC_PUBLIC
rcl_allocator_t *
rclc_allocator_alloc_default();

/**
 *  De-allocates an rcl_allocator_t object.
 *
 *  * <hr>
 * Attribute          | Adherence
 * ------------------ | -------------
 * Allocates Memory   | Yes
 * Thread-Safe        | No
 * Uses Atomics       | No
 * Lock-Free          | No
 *
 * \param[inout] allocator a heap-allocated rcl_allocator_t
 * \return `RCL_RET_OK` if operation was successful
 * \return `RCL_RET_INVALID_ARGUMENT` if any null pointer as argument
 */
RCLC_PUBLIC
rcl_ret_t
rclc_allocator_free(
  rcl_allocator_t * allocator);


/** Can be used if the node cannot access defines.*/
RCLC_PUBLIC extern const int32_t rcl_ret_ok;
RCLC_PUBLIC extern const int32_t rcl_ret_error;
RCLC_PUBLIC extern const int32_t rcl_ret_timeout;
RCLC_PUBLIC extern const int32_t rcl_ret_unsupported;

#if __cplusplus
}
#endif

#endif  // RCLC__INIT_H_
