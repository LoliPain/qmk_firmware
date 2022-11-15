#include QMK_KEYBOARD_H

enum layer_list {
	_QWERTY,
	_SUPPLY,
	_LOCKS,
	_VIMOVEMENT,
	_VIMOUSE,
	_VIWINDOWS,
	_RGB,
};

enum special_keycodes {
	L_SPACE = SAFE_RANGE,
	R_SPACE,
	LOCKS,
	WINNEXT,
	WINPREV,
	LLOCK
};

