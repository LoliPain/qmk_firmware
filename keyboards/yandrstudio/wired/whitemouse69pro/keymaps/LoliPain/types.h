#include QMK_KEYBOARD_H

enum layer_list {
	_QWERTY,
	_SUPPLY,
	_LOCKS,
	_VIMABLE,
	_RGB,
};

enum special_keycodes {
	KC_L_SPACE = SAFE_RANGE,
	KC_VIM_LEFT,
	KC_VIM_DOWN,
	KC_VIM_UP,
	KC_VIM_RIGHT,
    KC_SUPPLY,
    KC_LAYER_LOCK,
	KC_LOCKS,
    KC_RGB
};

#define KC_R_SPACE LT(0, KC_NO)
