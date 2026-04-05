ifneq ($(RESDEV),1)
include $(DEVKITPRO)/libnx/switch_rules
endif

TARGET := R2D2_Controller
BUILD := build
SOURCES := C:\Users\joel's get off\Documents\R2D2
INCLUDES := include
DATA := data
ICON := icon.jpg

include $(DEVKITPRO)/libnx/switch_rules
