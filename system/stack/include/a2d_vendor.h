/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Vendor Specific A2DP Codecs Support
 */

#ifndef A2D_VENDOR_H
#define A2D_VENDOR_H

#include <stdbool.h>
#include "a2d_api.h"

/* Offset for A2DP vendor codec */
#define A2D_VENDOR_CODEC_START_IDX              3

/* Offset for Vendor ID for A2DP vendor codec */
#define A2D_VENDOR_CODEC_VENDOR_ID_START_IDX    A2D_VENDOR_CODEC_START_IDX

/* Offset for Codec ID for A2DP vendor codec */
#define A2D_VENDOR_CODEC_CODEC_ID_START_IDX     \
                (A2D_VENDOR_CODEC_VENDOR_ID_START_IDX + sizeof(uint32_t))

#ifdef __cplusplus
extern "C"
{
#endif

// Checks whether a vendor-specific A2DP source codec is supported.
// |p_codec_info| contains information about the codec capabilities.
// Returns true if the vendor-specific A2DP source codec is supported,
// otherwise false.
bool A2D_IsVendorSourceCodecSupported(const uint8_t *p_codec_info);

// Checks whether a vendor-specific A2DP sink codec is supported.
// |p_codec_info| contains information about the codec capabilities.
// Returns true if the vendor-specific A2DP sink codec is supported,
// otherwise false.
bool A2D_IsVendorSinkCodecSupported(const uint8_t *p_codec_info);

// Checks whether a vendor-specific A2DP source codec for a peer source device
// is supported.
// |p_codec_info| contains information about the codec capabilities of the
// peer device.
// Returns true if the vendor-specific A2DP source codec for a peer source
// device is supported, otherwise false.
bool A2D_IsVendorPeerSourceCodecSupported(const uint8_t *p_codec_info);

// Builds a vendor-specific A2DP preferred Sink capability from a vendor
// Source capability.
// |p_pref_cfg| is the result Sink capability to store. |p_src_cap| is
// the Source capability to use.
// Returns |A2D_SUCCESS| on success, otherwise the corresponding A2DP error
// status code.
tA2D_STATUS A2D_VendorBuildSrc2SinkConfig(uint8_t *p_pref_cfg,
                                          const uint8_t *p_src_cap);

// Gets the Vendor ID for the vendor-specific A2DP codec.
// |p_codec_info| contains information about the codec capabilities.
// Returns the Vendor ID for the vendor-specific A2DP codec.
uint32_t A2D_VendorCodecGetVendorId(const uint8_t *p_codec_info);

// Gets the Codec ID for the vendor-specific A2DP codec.
// |p_codec_info| contains information about the codec capabilities.
// Returns the Codec ID for the vendor-specific A2DP codec.
uint16_t A2D_VendorCodecGetCodecId(const uint8_t *p_codec_info);

// Checks whether the A2DP vendor-specific data packets should contain RTP
// header. |content_protection_enabled| is true if Content Protection is
// enabled. |p_codec_info| contains information about the codec capabilities.
// Returns true if the A2DP vendor-specific data packets should contain RTP
// header, otherwise false.
bool A2D_VendorUsesRtpHeader(bool content_protection_enabled,
                             const uint8_t *p_codec_info);

// Gets the track sampling frequency value for the A2DP vendor-specific codec.
// |p_codec_info| is a pointer to the vendor-specific codec_info to decode.
// Returns the track sampling frequency on success, or -1 if |p_codec_info|
// contains invalid codec information.
int A2D_VendorGetTrackFrequency(const uint8_t *p_codec_info);

// Gets the channel count for the A2DP vendor-specific codec.
// |p_codec_info| is a pointer to the vendor-specific codec_info to decode.
// Returns the channel count on success, or -1 if |p_codec_info|
// contains invalid codec information.
int A2D_VendorGetTrackChannelCount(const uint8_t *p_codec_info);

// Gets the number of subbands for the A2DP vendor-specific codec.
// |p_codec_info| is a pointer to the vendor-specific codec_info to decode.
// Returns the number of subbands on success, or -1 if |p_codec_info|
// contains invalid codec information.
int A2D_VendorGetNumberOfSubbands(const uint8_t *p_codec_info);

// Gets the number of blocks for the A2DP vendor-specific codec.
// |p_codec_info| is a pointer to the vendor-specific codec_info to decode.
// Returns the number of blocks on success, or -1 if |p_codec_info|
// contains invalid codec information.
int A2D_VendorGetNumberOfBlocks(const uint8_t *p_codec_info);

// Gets the allocation method code for the A2DP vendor-specific codec.
// The actual value is codec-specific.
// |p_codec_info| is a pointer to the vendor-specific codec_info to decode.
// Returns the allocation method code on success, or -1 if |p_codec_info|
// contains invalid codec information.
int A2D_VendorGetAllocationMethodCode(const uint8_t *p_codec_info);

// Gets the channel mode code for the A2DP vendor-specific codec.
// The actual value is codec-specific.
// |p_codec_info| is a pointer to the vendor-specific codec_info to decode.
// Returns the channel mode code on success, or -1 if |p_codec_info|
// contains invalid codec information.
int A2D_VendorGetChannelModeCode(const uint8_t *p_codec_info);

// Gets the sampling frequency code for the A2DP vendor-specific codec.
// The actual value is codec-specific.
// |p_codec_info| is a pointer to the vendor-specific codec_info to decode.
// Returns the sampling frequency code on success, or -1 if |p_codec_info|
// contains invalid codec information.
int A2D_VendorGetSamplingFrequencyCode(const uint8_t *p_codec_info);

// Gets the channel type for the A2DP vendor-specific sink codec:
// 1 for mono, or 3 for dual/stereo/joint.
// |p_codec_info| is a pointer to the vendor-specific codec_info to decode.
// Returns the channel type on success, or -1 if |p_codec_info|
// contains invalid codec information.
int A2D_VendorGetSinkTrackChannelType(const uint8_t *p_codec_info);

// Computes the number of frames to process in a time window for the A2DP
// vendor-specific sink codec. |time_interval_ms| is the time interval
// (in milliseconds).
// |p_codec_info| is a pointer to the codec_info to decode.
// Returns the number of frames to process on success, or -1 if |p_codec_info|
// contains invalid codec information.
int A2D_VendorGetSinkFramesCountToProcess(uint64_t time_interval_ms,
                                          const uint8_t *p_codec_info);

#ifdef __cplusplus
}
#endif

#endif /* A2D_VENDOR_H */
