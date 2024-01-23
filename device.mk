#
# Copyright (C) 2022 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Enable updating of APEXes
$(call inherit-product, $(SRC_TARGET_DIR)/product/updatable_apex.mk)

# Include GSI keys
$(call inherit-product, $(SRC_TARGET_DIR)/product/gsi_keys.mk)

# Audio
PRODUCT_PACKAGES += \
    android.hardware.audio.service.mediatek \
    android.hardware.audio@7.0-impl \
    android.hardware.audio@6.0.vendor \
    android.hardware.audio@7.0-util.vendor \
    android.hardware.audio.common@5.0.vendor \
    android.hardware.audio.common@6.0.vendor \
    android.hardware.audio.common@6.0-util.vendor \
    android.hardware.audio.common@7.0.vendor \
    android.hardware.audio.common@7.0-enums.vendor \
    android.hardware.audio.common@7.0-util.vendor \
    android.hardware.audio.common-util.vendor \
    android.hardware.audio.effect@6.0-impl \
    android.hardware.audio.effect@7.0-impl \
    audio.primary.default \
    audio.r_submix.default \
    audio.usb.default \
    audio_policy.stub \
    libalsautils \
    libaudiofoundation.vendor \
    libavservices_minijail.vendor \
    libbluetooth_audio_session

# Bluetooth
PRODUCT_PACKAGES += \
    android.hardware.bluetooth@1.0.vendor \
    android.hardware.bluetooth@1.1.vendor \
    audio.bluetooth.default \
    android.hardware.bluetooth.audio-impl

# CAS
PRODUCT_PACKAGES += \
    android.hardware.cas@1.2-service-lazy

# DRM
PRODUCT_PACKAGES += \
    android.hardware.drm@1.4-service.clearkey \
    android.hardware.drm@1.0.vendor:64 \
    android.hardware.drm@1.1.vendor:64 \
    android.hardware.drm@1.2.vendor:64 \
    android.hardware.drm@1.3.vendor:64 \
    android.hardware.drm@1.4.vendor:64 

# Gatekeeper
PRODUCT_PACKAGES += \
    android.hardware.gatekeeper@1.0-service \
    android.hardware.gatekeeper@1.0-impl

# Health
PRODUCT_PACKAGES += \
   android.hardware.health@2.1-service \
   android.hardware.health@2.1-impl

# IR
PRODUCT_PACKAGES += \
    android.hardware.ir@1.0-service \
    android.hardware.ir@1.0-impl
    
# Overlays
PRODUCT_ENFORCE_RRO_TARGETS := *

# Shipping API level
PRODUCT_SHIPPING_API_LEVEL := 30

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Inherit the proprietary files
$(call inherit-product, vendor/xiaomi/fleur/fleur-vendor.mk)
