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
	SUPPLY = SAFE_RANGE,
	LOCKS,
	VIWINDOWS,
	L_SPACE,
	R_SPACE,
	WINNEXT,
	WINPREV,
	LLOCK
};

