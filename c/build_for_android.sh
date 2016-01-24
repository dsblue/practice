#!/bin/bash

SYS_ROOT=/Users/nathan/Downloads/android-ndk-r10e/platforms/android-9/arch-arm
export PATH=$PATH:/Users/nathan/Downloads/android-ndk-r10e/toolchains/arm-linux-androideabi-4.8/prebuilt/darwin-x86_64/bin

arm-linux-androideabi-gcc arm_test.c base64.s  --sysroot $SYS_ROOT -g -o arm_test
adb push arm_test /data/nathan/

arm-linux-androideabi-gdb

# To Debug, In GDB do:
#
# target extended-remote :1234
# set remote exec-file /data/nathan/arm_test
# file ./arm_test
#
