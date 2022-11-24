#pragma once

#include "cfe.h"

/**
 * @brief Initialises the page size, must be called once before any other functions.
 *
 * @return CFE_SUCCESS on success, or OS_ERROR on failure.
 */
int32 mmio_lib_Init(void);

/**
 * @brief Creates a new memory mapping of size bytes rounded up to the nearest page size, starting at startAddress.
 *
 * @param [out] mapping A pointer to the pointer to the mapping in user space. This function will set *mapping to the
 * mapping. It mustn't be null.
 * @param [in] startAddress The physical address to start the mapping at.
 * @param [in] size The size of the mapping in bytes, will be rounded up to the nearest page size. It mustn't be 0.
 *
 * @return The size of the mapping in bytes on success, or a cFS negative error code.
 */
int32 mmio_lib_NewMapping(void **mapping, cpuaddr startAddress, cpusize size);

/**
 * @brief Removes a memory mapped created by mmio_lib_NewMapping.
 *
 * @param mapping A pointer to the mapping, should be the same as the one given by mmio_lib_NewMapping.
 * @param size The size of the memory map, should be the same as the size passed into mmio_lib_NewMapping. This will be rounded up to the nearest page size.
 * @return CFE_SUCCESS on success, or error code otherwise.
 */
int32 mmio_lib_DeleteMapping(void *mapping, cpusize size);
