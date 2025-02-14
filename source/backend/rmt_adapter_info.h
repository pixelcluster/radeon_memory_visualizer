//=============================================================================
// Copyright (c) 2020-2021 Advanced Micro Devices, Inc. All rights reserved.
/// @author AMD Developer Tools Team
/// @file
/// @brief  The adapter information captured for the target process.
//=============================================================================

#ifndef RMV_BACKEND_RMT_ADAPTER_INFO_H_
#define RMV_BACKEND_RMT_ADAPTER_INFO_H_

#include <rmt_error.h>
#include <rmt_types.h>
#include <rmt_format.h>
#include <rmt_file_format.h>

#ifdef __cplusplus
extern "C" {
#endif  // #ifdef __cplusplus

/// @brief An enumeration of memory types that can be used with an adapter.
typedef enum RmtAdapterInfoMemoryType
{
    kRmtAdapterInfoMemoryTypeUnknown = 0,  ///< Memory is unknown.
    kRmtAdapterInfoMemoryTypeDdr2    = 1,  ///< System DDR2.
    kRmtAdapterInfoMemoryTypeDdr3    = 2,  ///< System DDR3.
    kRmtAdapterInfoMemoryTypeDdr4    = 3,  ///< System DDR4.
    kRmtAdapterInfoMemoryTypeGddr5   = 4,  ///< Graphics DDR 5.
    kRmtAdapterInfoMemoryTypeGddr6   = 5,  ///< Graphics DDR 6.
    kRmtAdapterInfoMemoryTypeHbm     = 6,  ///< First version of High-Bandwidth Memory.
    kRmtAdapterInfoMemoryTypeHbm2    = 7,  ///< Second version of High-Bandwidth Memory.
    kRmtAdapterInfoMemoryTypeHbm3    = 8,  ///< Third version of High-Bandwidth Memory.
    kRmtAdapterInfoMemoryTypeLpddr4  = 9,  ///< Low power DDR4.
    kRmtAdapterInfoMemoryTypeLpddr5  = 10, ///< Low power DDR5.
    kRmtAdapterInfoMemoryTypeDdr5    = 11  ///< System DDR5.
} RmtAdapterInfoMemoryType;

/// @brief A structure encapsulating the information about the adapter.
typedef struct RmtAdapterInfo
{
    char                     name[RMT_MAX_ADAPTER_NAME_LENGTH];  ///< The name of the adapter as a NULL terminated string.
    uint32_t                 pcie_family_id;                     ///< The PCIe family ID of the adapater.
    uint32_t                 pcie_revision_id;                   ///< The PCIe revision ID of the adapter.
    uint32_t                 device_id;                          ///< The PCIe device ID of the adapter.
    uint32_t                 minimum_engine_clock;               ///< The minimum engine clock (in MHz).
    uint32_t                 maximum_engine_clock;               ///< The maximum engine clock (in MHz).
    RmtAdapterInfoMemoryType memory_type;                        ///< The memory type.
    uint32_t                 memory_operations_per_clock;        ///< The number of memory operations that can be performed per clock.
    uint32_t                 memory_bus_width;                   ///< The width of the memory bus (in bits).
    uint32_t                 memory_bandwidth;                   ///< Bandwidth of the memory system (in MB/s).
    uint32_t                 minimum_memory_clock;               ///< The minimum memory clock (in MHz).
    uint32_t                 maximum_memory_clock;               ///< The maximum memory clock (in MHz).
} RmtAdapterInfo;

/// @brief Get the chip type (in string) of the video memory.
///
/// @param [in]     adapter_info             A pointer to a <c><i>RmtAdapterInfo</i></c> structure.
///
/// @returns
/// Pointer to the memory chip type string.
const char* RmtAdapterInfoGetVideoMemoryType(const RmtAdapterInfo* adapter_info);

#ifdef __cplusplus
}
#endif  // #ifdef __cplusplus
#endif  // #ifndef RMV_BACKEND_RMT_ADAPTER_INFO_H_
