all : flash

ADDITIONAL_C_FILES += blink.S
TARGET = blink

TARGET_MCU?=CH32V003
include ../Libraries/ch32fun/ch32fun/ch32fun.mk

flash : cv_flash
clean : cv_clean

