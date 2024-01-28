/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/properties.h>
#include <libinit_utils.h>

#include <libinit_variant.h>

using android::base::GetProperty;

#define HWNAME_PROP "ro.boot.hwname"
#define SKU_PROP "ro.boot.product.hardware.sku"

void search_variant(const std::vector<variant_info_t> variants) {
    std::string hwname_value = GetProperty(HWNAME_PROP, "");
    std::string sku_value = GetProperty(SKU_PROP, "");

    for (const auto& variant : variants) {
        if ((variant.hwname_value == "" || variant.hwname_value == hwname_value) &&
            (variant.sku_value == "" || variant.sku_value == sku_value)) {
            set_variant_props(variant);
            break;
        }
    }
}

void set_variant_props(const variant_info_t variant) {
    set_ro_build_prop("brand", variant.brand, true);
    set_ro_build_prop("device", variant.device, true);
    set_ro_build_prop("name", variant.device, true);
    set_ro_build_prop("model", variant.model, true);

    // Set safetynet workarounds
    property_override("ro.boot.warranty_bit", "0");
    property_override("ro.is_ever_orange", "0");
    property_override("ro.vendor.boot.warranty_bit", "0");
    property_override("ro.vendor.warranty_bit", "0");
    property_override("ro.warranty_bit", "0");
    property_override("vendor.boot.vbmeta.device_state", "locked");
    property_override("vendor.boot.verifiedbootstate", "green");

    property_override("ro.boot.hardware.sku", variant.device);
    if (variant.nfc)
        property_override(SKU_PROP, "nfc");
}
