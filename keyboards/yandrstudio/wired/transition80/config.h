// Copyright 2022 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xAA96
#define PRODUCT_ID      0xAA6F
#define DEVICE_VER      0x0001
#define MANUFACTURER    "swagkeys_Y&R"
#define PRODUCT         "Transition TKL"

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 17

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

//                        0   1   2   3   4   5   6   7   8   9   10  11  12  13   14   15   16
#define MATRIX_COL_PINS { B3, B4, B5, B6, B7, B8, B9, A3, A4, A5, A6, A7, B0, B12, B13, B15, A10 }
#define MATRIX_ROW_PINS { A8, A9, A0, A1, A2, B1 }

#define TAP_HOLD_CAPS_DELAY 250

#define LED_SCROLL_LOCK_PIN  B14
#define LED_CAPS_LOCK_PIN A15
#define LED_PIN_ON_STATE  1