PROTOCOL_DIR = protocol
NRF52_DIR = $(PROTOCOL_DIR)/nrf52


SRC += $(NRF52_DIR)/nrf52.c

VPATH += $(TMK_PATH)/$(PROTOCOL_DIR)

OPT_DEFS += -DFIXED_CONTROL_ENDPOINT_SIZE=64
OPT_DEFS += -DFIXED_NUM_CONFIGURATIONS=1

ifeq ($(strip $(MIDI_ENABLE)), yes)
  include $(TMK_PATH)/protocol/midi.mk
endif
