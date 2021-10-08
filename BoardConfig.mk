#
# Copyright (C) 2019 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

BOARD_VENDOR := xiaomi

DEVICE_PATH := device/xiaomi/certus

BUILD_BROKEN_DUP_RULES := true

# Architecture
TARGET_ARCH := arm
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := armeabi-v7a
TARGET_CPU_ABI2 := armeabi
TARGET_CPU_VARIANT := generic
TARGET_CPU_VARIANT_RUNTIME := cortex-a53
TARGET_USES_64_BIT_BINDER := true

# Audio
USE_XML_AUDIO_POLICY_CONF := 1

# Board
TARGET_NO_BOOTLOADER := true

# HIDL
# DEVICE_FRAMEWORK_MANIFEST_FILE := $(DEVICE_PATH)/framework_manifest.xml

# Init
TARGET_INIT_VENDOR_LIB := //$(DEVICE_PATH):libinit_certus

# Kernel
BOARD_KERNEL_CMDLINE := bootopt=64S3,32S1,32S1
BOARD_KERNEL_BASE := 0x40000000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_RAMDISK_OFFSET := 0x11b00000
BOARD_KERNEL_TAGS_OFFSET := 0x07880000
BOARD_KERNEL_OFFSET := 0x00008000
BOARD_KERNEL_SECOND_OFFSET := 0x00f00000
BOARD_DTB_OFFSET := 0x07880000
BOARD_BOOT_HEADER_VERSION := 2
BOARD_KERNEL_IMAGE_NAME := zImage-dtb
TARGET_KERNEL_ARCH := arm
TARGET_KERNEL_SOURCE := kernel/xiaomi/mt6765
BOARD_INCLUDE_DTB_IN_BOOTIMG := true
TARGET_KERNEL_CONFIG := certus_defconfig

BOARD_MKBOOTIMG_ARGS += --base $(BOARD_KERNEL_BASE)
BOARD_MKBOOTIMG_ARGS += --pagesize $(BOARD_KERNEL_PAGESIZE)
BOARD_MKBOOTIMG_ARGS += --ramdisk_offset $(BOARD_RAMDISK_OFFSET)
BOARD_MKBOOTIMG_ARGS += --tags_offset $(BOARD_KERNEL_TAGS_OFFSET)
BOARD_MKBOOTIMG_ARGS += --kernel_offset $(BOARD_KERNEL_OFFSET)
BOARD_MKBOOTIMG_ARGS += --second_offset $(BOARD_KERNEL_SECOND_OFFSET)
BOARD_MKBOOTIMG_ARGS += --dtb_offset $(BOARD_DTB_OFFSET)
BOARD_MKBOOTIMG_ARGS += --header_version $(BOARD_BOOT_HEADER_VERSION)

# Kernel toolchains
TARGET_KERNEL_CROSS_COMPILE_PREFIX := arm-linux-gnueabihf-
KERNEL_TOOLCHAIN := $(PWD)/prebuilts/gcc/linux-x86/arm/arm-linux-gnueabihf-7.5/bin

# Lineage hardware
BOARD_HARDWARE_CLASS += \
    $(DEVICE_PATH)/lineagehw

# OTA
TARGET_OTA_ASSERT_DEVICE := certus,cactus,cereus

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 67108864
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 67108864
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2684354560
BOARD_CACHEIMAGE_PARTITION_SIZE := 268435456
BOARD_FLASH_BLOCK_SIZE := 131072 # (BOARD_KERNEL_PAGESIZE * 64)
#BOARD_VENDORIMAGE_PARTITION_SIZE := 805306368
#BOARD_VENDORIMAGE_FILE_SYSTEM_TYPE := ext4

# Properties
BOARD_PROPERTY_OVERRIDES_SPLIT_ENABLED := true

# Recovery
TARGET_RECOVERY_FSTAB := $(DEVICE_PATH)/rootdir/etc/recovery.fstab
TARGET_USERIMAGES_USE_EXT4 := true
TARGET_USERIMAGES_SPARSE_EXT_DISABLED := false

# Releasetools
TARGET_RELEASETOOLS_EXTENSIONS := $(DEVICE_PATH)/releasetools

# SELinux
BOARD_PLAT_PRIVATE_SEPOLICY_DIR += $(DEVICE_PATH)/sepolicy/private
BOARD_PLAT_PUBLIC_SEPOLICY_DIR += $(DEVICE_PATH)/sepolicy/public
SELINUX_IGNORE_NEVERALLOWS := true
TARGET_USES_PREBUILT_VENDOR_SEPOLICY := true
TARGET_HAS_FUSEBLK_SEPOLICY_ON_VENDOR := true
SELINUX_IGNORE_NEVERALLOWS := true

# Treble
BOARD_VNDK_VERSION  := current
TARGET_COPY_OUT_VENDOR := vendor
TARGET_COPY_OUT_PRODUCT := system/product

# Verified Boot
BOARD_AVB_ENABLE := true
BOARD_AVB_MAKE_VBMETA_IMAGE_ARGS += --set_hashtree_disabled_flag
BOARD_AVB_MAKE_VBMETA_IMAGE_ARGS += --flags 2
