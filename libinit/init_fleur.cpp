/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>

#include "vendor_init.h"

#define FINGERPRINT_FL "Redmi/fleur_global/fleur:11/RP1A.200720.011/V13.0.10.0.RKEMIXM:user/release-keys"
#define FINGERPRINT_FLP "POCO/fleur_p_global/fleur:11/RP1A.200720.011/V13.0.10.0.RKEMIXM:user/release-keys"
#define FINGERPRINT_ML "Redmi/miel_global/miel:11/RP1A.200720.011/V13.0.10.0.RKEMIXM:user/release-keys"
#define FINGERPRINT_MLP_IN "POCO/miel_p_in/miel:11/RP1A.200720.011/V13.0.5.0.RKEINXM:user/release-keys"
#define FINGERPRINT_ML_IN "Redmi/miel_in/miel:11/RP1A.200720.011/V13.0.5.0.RKEINXM:user/release-keys"

static const variant_info_t fleur_info = {
    .hwc_value = "Global",
    .sku_value = "fleur",
    .brand = "Redmi",
    .device = "fleur",
    .marketname = "Redmi Note 11S",
    .model = "2201117SY",
    .vendor_sku_value = "fleur_global",
    .build_fingerprint = FINGERPRINT_FL,

    .nfc = false,
};

static const variant_info_t fleurp_info = {
    .hwc_value = "Global",
    .sku_value = "fleurp",
    .brand = "POCO",
    .device = "fleur",
    .marketname = "POCO M4 Pro",
    .model = "2201117PG",
    .vendor_sku_value = "fleur_p_global",
    .build_fingerprint = FINGERPRINT_FLP,

    .nfc = true,
};

static const variant_info_t miel_info = {
    .hwc_value = "Global",
    .sku_value = "miel",
    .brand = "Redmi",
    .device = "miel",
    .marketname = "Redmi Note 11S",
    .model = "2201117SG",
    .vendor_sku_value = "miel_global",
    .build_fingerprint = FINGERPRINT_ML,

    .nfc = false,
};

static const variant_info_t miel_in_info = {
    .hwc_value = "India",
    .sku_value = "miel",
    .brand = "Redmi",
    .device = "miel",
    .marketname = "Redmi Note 11S",
    .model = "2201117SI",
    .vendor_sku_value = "miel_in",
    .build_fingerprint = FINGERPRINT_ML_IN,

    .nfc = false,
};

static const variant_info_t mielp_info = {
    .hwc_value = "India",
    .sku_value = "mielp",
    .brand = "POCO",
    .device = "miel",
    .marketname = "POCO M4 Pro",
    .model = "2201117PI",
    .vendor_sku_value = "miel_p_in",
    .build_fingerprint = FINGERPRINT_MLP_IN,

    .nfc = false,
};


static const std::vector<variant_info_t> variants = {
    fleur_info,
    fleurp_info,
    miel_info,
    mielp_info,
    miel_in_info,
};

void vendor_load_properties() {
    search_variant(variants);
    set_dalvik_heap();

    // SafetyNet workaround
    property_override("ro.boot.verifiedbootstate", "green");
}