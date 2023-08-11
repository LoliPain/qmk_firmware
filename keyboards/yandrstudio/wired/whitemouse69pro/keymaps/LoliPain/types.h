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
	KC_R_SPACE,
	KC_VIM_LEFT,
	KC_VIM_DOWN,
	KC_VIM_UP,
	KC_VIM_RIGHT,
    KC_SUPPLY,
    KC_LAYER_LOCK,
	KC_LOCKS
};

