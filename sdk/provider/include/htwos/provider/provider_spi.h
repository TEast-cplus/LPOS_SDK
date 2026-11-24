/**
 * @file provider_spi.h
 * @brief Versioned C ABI SPI skeleton for HTWOS Providers
 * @author HTW_DEV
 * @date 2026-11-24
 * @version 2026-11-24_v1.0
 *
 * Copyright (c) 2026 Hantewin. All rights reserved.
 *
 * modify history:
 * | Date       | Author  | Notes              |
 * |------------|---------|--------------------|
 * | 2026-11-24 | HTW_DEV | Initial SPI stub   |
 *
 * Note: Full device class contracts live in Unified HAL.
 * This header only sketches the Provider plugin boundary for SDK users.
 */
#ifndef HTWOS_PROVIDER_SPI_H
#define HTWOS_PROVIDER_SPI_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HTWOS_PROVIDER_SPI_ABI_MAJOR (1)
#define HTWOS_PROVIDER_SPI_ABI_MINOR (0)

typedef struct HtwosProvider HtwosProvider;

typedef struct {
    uint32_t abi_major;     // SPI major
    uint32_t abi_minor;     // SPI minor
    const char* name;       // provider name
    const char* version;    // provider version string
} HTWOSPROVIDERINFO_T;

typedef int32_t (*HtwosProviderInitFn)(HtwosProvider** out_provider);
typedef int32_t (*HtwosProviderShutdownFn)(HtwosProvider* provider);
typedef int32_t (*HtwosProviderGetInfoFn)(
    HtwosProvider* provider,
    HTWOSPROVIDERINFO_T* out_info);

typedef struct {
    HtwosProviderInitFn init;         // create provider instance
    HtwosProviderShutdownFn shutdown; // destroy provider instance
    HtwosProviderGetInfoFn get_info;  // query provider metadata
} HTWOSPROVIDERVTABLE_T;

#ifdef __cplusplus
}
#endif

#endif /* HTWOS_PROVIDER_SPI_H */
