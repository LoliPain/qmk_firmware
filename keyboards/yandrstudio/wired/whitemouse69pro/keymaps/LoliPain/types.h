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

enum layer_switch {
	QWERTY = SAFE_RANGE,
	SUPPLY,
	LOCKS,
	VIMOVEMNT,
	VIMOUSE,
	VIWINDOWS,
	RGB
};



