/* Copyright 2021 JasonRen(biu)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
*/


/*
	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⣠⣾⣿⣿⣿⣿⡟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣝⢿⣿⣿⣿⣯⢿⣿⣷⡀⠀⠊⠱⣄⠀⠀⠀⠀⠀⠀⠀
	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⣠⣾⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⠿⣿⣿⣷⡉⠙⢷⣦⠀⠀⠘⢦⠀⠀⠀⠀⠀⠀
	⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠞⠁⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢷⡘⢿⣿⣷⡀⠈⣯⣇⠈⢦⡈⣦⠀⠀⠀⠀⠀
	⠀⠀⠀⠀⠀⠀⠀⠀⣰⠋⠀⢠⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣸⣿⣿⣿⣿⡟⣿⣿⣿⣿⣿⣿⡟⢿⠆⠳⠄⢿⣿⣷⡀⢸⡼⣆⠀⠘⠎⣆⠀⠀⠀⠀
	⠀⠀⠀⠀⠀⠀⠀⡼⠁⠀⢠⣿⣿⣿⣿⣿⠛⠛⣹⡟⢿⣿⢫⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢹⠋⣿⣿⣿⣷⣿⣿⡿⣿⣿⣿⡿⠀⠀⠀⠈⢄⢻⣿⣷⣿⣧⢹⣦⣀⠀⠸⡄⠀⠀⠀
	⠀⠀⠀⠀⠀⠀⡜⠁⠀⢀⣾⣿⣿⣿⣿⣧⡀⢸⣿⢀⡼⠁⣸⣿⣿⣿⠉⠛⠛⢣⡿⠋⡿⢸⢰⠻⠿⠏⡟⣿⠌⠉⢻⣿⣧⣠⣤⡄⠀⠀⣌⢧⣿⣿⣿⣿⡎⣧⡉⠙⣲⣷⡠⣄⠀
	⠀⠀⠀⠀⠀⣼⠁⠀⢠⣾⢳⣿⣿⣿⣿⣿⣧⣿⣿⡟⠁⠀⣿⣿⡿⣇⠀⠀⠀⢸⠀⠀⡇⠸⠸⡄⠀⠀⣇⢻⣴⠀⣮⣿⣿⣿⠋⢿⣶⡾⠿⣷⣿⣿⣿⣿⡇⢣⠈⠙⢛⢾⣷⡌⠂
	⠀⠀⠀⠀⢰⠃⠀⢠⡟⢁⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⣿⣿⡇⣿⠀⠀⢸⣾⣦⣸⣄⠀⠀⣿⣄⠀⢻⡜⣿⣧⣸⣿⣿⣇⠀⢸⠏⠀⣰⣿⣿⢿⣿⣿⡇⢸⠀⢠⣿⣾⣿⣧⢠
	⠀⠀⠀⠀⡾⠀⣰⡟⠀⢸⣿⣿⣿⣿⣿⣿⣿⡟⠈⠲⣄⠀⣿⣿⡇⢹⣷⣦⣸⢸⣿⣿⣿⡆⠀⢸⣿⣷⣼⠇⠘⣿⢿⣿⠋⠁⠀⠀⠀⠘⣿⣿⣿⣾⣿⣿⡇⢸⣶⣿⠃⡟⡿⣿⣄
	⠀⠀⠀⠀⡇⣼⠏⠀⠀⣾⣻⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠓⣿⣿⣧⠸⣿⣿⣿⣾⣾⣿⣿⣿⠀⠀⢿⣿⣿⣇⠀⠈⣓⡿⠦⠤⠤⠤⠤⣤⣿⣿⣿⣷⢿⣿⡇⢸⣿⠃⡼⢀⡇⢿⡟
	⠀⠀⠀⠀⣿⠋⠀⠀⠀⡿⣿⣿⣿⣿⣿⢸⣿⡀⠀⠀⠀⠀⢹⣿⣿⠤⣿⣿⣿⣿⡟⢻⣿⣿⣄⠀⠘⣿⣿⣿⡌⠁⠘⠷⣤⡀⠁⢀⠀⠀⡿⠋⠙⢻⣿⣿⡇⣼⣷⣾⣇⣼⠁⣾⣇
	⠀⠀⠀⢠⡇⠀⠀⠀⣸⡏⣿⣿⣿⣿⣿⣿⡏⣇⠀⠀⠀⠠⠼⣿⣿⣆⢸⣿⣿⣻⣷⡈⢿⡀⠙⡄⠀⣸⣿⣿⣷⡀⠀⠀⠀⠈⢹⣷⣶⣾⣿⣀⣠⣿⣿⣿⡇⣿⢁⣿⣿⠃⠀⡿⣿
	⠀⠀⢀⡟⡇⠀⠀⠀⣿⣷⣿⣿⣿⣿⡇⣿⣧⣼⣷⣿⢿⣿⡿⣾⣯⡛⠆⠙⢷⣿⠿⠷⠀⠙⠶⣟⣻⣯⣼⣿⣿⣿⣆⠀⠀⠀⠘⢻⣿⣽⣿⣿⣿⣿⣿⣿⢧⡇⣾⣿⡇⠀⠀⠁⡿
	⠀⠀⣸⠀⣧⠀⠀⢸⢛⣿⣿⣿⣿⣿⣧⣿⡿⣿⠋⠀⢸⣿⣿⣿⣙⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⣹⣿⣬⡭⠛⢿⣿⣦⣄⠀⠀⣿⣿⣿⠿⣛⣛⢿⡿⣼⢸⣿⣽⣇⠀⠀⠀⡇
	⠀⢰⡇⠀⠸⡄⠀⢸⢸⣿⣿⣿⣿⣿⣿⡇⡇⠛⠂⠀⢸⠂⢻⣿⡯⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡿⢿⣽⣷⢺⣿⠙⢿⡭⣥⡿⠟⠁⠘⢿⣿⡬⢿⡟⣼⡏⣿⢹⠀⠀⠀⡇				 LoliPain
	⠀⡾⠀⠀⠀⠹⣄⢸⣾⣿⣿⣿⣿⣿⣿⣹⣿⡄⠀⠀⠨⣷⣤⣭⣴⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣻⣤⣈⣙⣩⣿⠏⠀⠉⠀⡸⢹⠧⣴⣧⣄⣿⡇⣿⠁⣿⢿⡿⡎⢀⠀⠀⡇			Epomaker MiniCat 69
	⢸⠇⠀⠀⠀⠀⠈⢸⣿⡿⣿⣿⣿⣿⣿⢿⣟⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠁⠀⠀⠀⠈⠁⠈⣰⣿⣿⣿⠟⢸⣿⣸⣯⣾⠣⠁⠀⠀⠀⡇
	⣾⠀⠀⠀⠀⠀⢠⣿⣿⣷⢿⣿⣿⣿⣿⣾⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡿⣿⠛⠁⣤⣿⣱⣿⣿⣿⠀⠀⣶⠀⠀⢀
	⣿⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⠏⠈⣿⡟⣿⡟⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀.⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢁⣤⣾⣿⣷⣿⣿⣿⡇⠀⢀⡇⠀⠀⢸				QMK VIM-pref layout
	⡇⠀⠀⠀⢀⣾⣾⣿⣿⣿⣿⣿⡿⠀⢀⡟⢀⡏⠀⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⢤⠀⠀⠀⠀⠀⣠⣾⣷⣶⣾⣿⣯⣿⣝⣼⣿⣿⣿⡇⠀⢸⠀⠀⠀⠀
	⣿⣠⠴⢖⢿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠘⣟⣾⠁⢹⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠀⢸⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣾⢷⣿⡇⣿⡇⠀⣸⠀⠀⠀⠀
	⠙⠷⣤⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⢿⣿⠀⠸⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⢀⢀⡴⣞⣥⣀⣸⣿⣿⣿⣿⣿⣿⢹⣏⣾⣿⡇⣿⠀⠀⡇⠀⠀⠀⠀
	⢀⢼⣷⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠳⣄⠸⣿⠀⠀⣿⠿⣿⣿⣿⣦⣄⠀⠀⠀⣤⢤⡀⠀⠀⠀⣠⡞⠀⢀⣿⣿⠟⠁⢠⢿⣻⣿⣿⣿⣿⣿⣧⣿⣽⣿⣿⡇⣿⡇⠀⡇⠀⠀⠀⠀
	⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠧⠀⠀⠈⢦⣀⣀⣀⡇⠀⢿⣿⣿⡟⠈⡷⣦⡼⠁⢀⣀⣤⣴⢾⣋⠀⣠⣿⠿⠋⠀⣰⣯⣾⣿⣿⣿⣿⣿⣿⣿⣳⣿⣿⣿⣧⣿⣿⢠⡇⠀⠀⠀⠀
	⣿⣿⣿⣿⣿⣟⣿⣿⣿⡇⠀⠀⠈⢦⠀⠈⣧⠀⠉⠉⢳⣼⣿⢿⢁⠞⠁⢀⣭⣷⣞⢿⡭⠗⠉⠉⠙⢯⡀⣀⡤⢞⣿⣿⣿⣿⣿⣹⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⠀⠀⠀⠀⠀
	⣿⣿⣿⣿⣿⡿⠿⣛⠉⠙⢦⠀⠀⠸⡄⢠⣿⣄⣀⣠⣿⣿⣿⣄⣾⣶⣿⣿⣿⣿⡟⠉⠀⢀⡠⠶⠶⣄⡹⢁⣴⣿⣿⣿⣿⣿⣧⣿⣿⣿⣿⠉⠉⠉⣏⠙⠿⣿⣿⣸⠀⠀⠀⠀⠀
	⣿⣿⣿⣿⡿⢡⣾⣿⡇⠀⠈⠳⣄⠀⣷⣠⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⡿⠶⣶⠊⠁⠀⠀⠀⠀⣹⣿⣿⣿⣿⣿⣿⣿⢻⣿⣿⣾⣿⠿⠛⠉⠹⡍⠉⠉⢙⣿⣆⠀⠀⠀⠀
	⣿⣿⣿⣿⡇⢸⣿⠟⠀⠀⠀⠀⣿⡏⠉⠹⣿⣿⣿⣿⣿⣿⣿⣂⣀⡀⠀⠀⠀⠀⠀⢀⣽⠿⠿⠛⢢⢠⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⡿⠛⠁⠀⠀⠀⠀⠹⣦⡴⠛⠁⠸⡆⠀⠀⠀
	⣿⣿⣿⣵⠃⠚⠃⠀⠀⠀⠀⢸⣿⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⠀⠀⠀⠈⠀⢸⣧⣴⣞⢿⣿⣿⣿⣿⣿⣿⣯⣹⣾⡟⠁⠀⠀⠀⠀⠀⣠⡾⠟⠳⣤⡀⠀⣿⠀⠀⢀
	⣿⣿⠛⠛⠀⠀⠀⠀⣼⡇⢀⣾⣿⣷⣄⣀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⣾⡿⢡⣿⠘⢿⣿⣿⣿⣿⣷⣿⣿⣿⣶⣤⣤⣤⣴⣶⠿⠋⠀⠀⠀⠀⠉⠒⢾⠴⠒⠉
	⠏⠁⠀⣥⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣷⣤⣶⡶⠀⠀⣸⡟⠀⢸⣿⠀⠘⣿⣿⣿⣿⢟⣿⣿⣏⠀⠉⠉⠉⢁⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀⠀⠀
	⣴⣷⣶⠟⠀⠀⢠⣿⣿⣿⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⣼⣿⣿⠁⠀⣰⢿⣤⣴⢻⡿⢀⣼⣿⣿⡿⣣⣿⣿⡿⠘⣇⠀⢀⡴⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣀⣀⣠
	⣿⣿⣿⠀⠀⠀⣸⣿⣿⣏⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⣀⣾⣿⣿⡇⣠⣾⣧⠾⣿⡿⠼⢣⣾⣿⣟⣡⣾⣿⣿⡟⠁⠀⣘⣶⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣟⠉⠁
*/


#include QMK_KEYBOARD_H
#include "types.h"

static bool layers_locked;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// Double KC_NO in middle is used for non-existent on MiniCat knob (=
    //
    // Base layer for everyday use
    //
	[_QWERTY] = LAYOUT(
		QK_GESC, KC_1,    KC_2,    KC_3,       KC_4, KC_5,    KC_6,       KC_7,       KC_8,      KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSPC, KC_DEL,
		DB_TOGG,  KC_Q,    KC_W,    KC_E,       KC_R, KC_T,    KC_Y,       KC_U,       KC_I,      KC_O,    KC_P,    KC_BSLS, KC_P7,  KC_P8,   KC_P9,
		KC_CAPS, KC_A,    KC_S,    KC_D,       KC_F, KC_G,    KC_H,       KC_J,       KC_K,      KC_L,    KC_ENT,           KC_P4,  KC_P5,   KC_P6,
		KC_LSFT, KC_Z,    KC_X,    KC_C,       KC_V, KC_B,    KC_N,       KC_M,       KC_COMM,   KC_DOT,  KC_SLSH, KC_UP,   KC_P1,  KC_P2,   KC_P3,
		KC_LCTL, KC_LGUI, KC_LALT, KC_L_SPACE,       XXXXXXX, XXXXXXX,    KC_R_SPACE, KC_SUPPLY, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,  KC_PDOT),

    // Extension for _QWERTY layer, contains functional keys and missing characters
    //
	[_SUPPLY] = LAYOUT(
		KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LOCKS, KC_INS,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______,  KC_HOME,
		_______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_QUOT, _______,          _______, _______,  KC_PGUP,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_PGDN,
		_______, _______, _______, _______,          XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______,  KC_END),

    // Placeholders for processing vim emulation
    // Also used for mouse emulation configuration
    //
	[_VIMABLE] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______,     _______,     _______,   _______,      KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
		_______, _______, _______, _______, _______, _______, _______,     _______,     _______,   _______,      _______, KC_BTN2, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, KC_VIM_LEFT, KC_VIM_DOWN, KC_VIM_UP, KC_VIM_RIGHT,          KC_BTN1, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______,     _______,     _______,   _______,      _______, _______, _______, _______, _______,
		_______, _______, _______, _______,          XXXXXXX, XXXXXXX,     _______,     _______,   _______,      _______, _______, _______, _______, _______),

    // Layer that contains all available locking features, such as NumLock, WinLock and LayerLock
    //
	[_LOCKS] = LAYOUT(
		KC_LAYER_LOCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK,
		_______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
		_______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,       KC_F23,  _______, _______,          XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______),

    // Board RGB controls
    //
	[_RGB] = LAYOUT(
		KC_F24,   RGB_M_P, RGB_M_B, RGB_M_R, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
		_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,  _______, _______, RGB_TOG,          XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______)
};


bool process_locks_layer(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LAYER_LOCK:
			if (record->event.pressed) {
                layers_locked = !layers_locked;
                return true;
            }
            break;

    }
    return false;
}


bool process_supply_layer(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // Process _SUPPLY layer switching
        //
        case KC_LOCKS:
            if (record->event.pressed) layer_on(_LOCKS);
            else layer_off(_LOCKS);
            break;

    }
    return false;
}


bool process_qwerty_layer(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
        // All special keycodes should be processed as normal
        //
		case KC_L_SPACE:
			if (record->event.pressed) register_code(KC_SPC);
			else unregister_code(KC_SPC);
			break;

		case KC_R_SPACE:
            if (layers_locked) {

                // Normal KC_SPC if layers locked
                //
                if (record->event.pressed) register_code(KC_SPC);
                else unregister_code(KC_SPC);
            }
            else {
                    // Tap process as KC_SPC
                    //
                    if (record->tap.count && record->event.pressed) {
                        tap_code16(KC_SPC);
                    }

                    // Switch to vim layer on hold
                    //
                    else if (record->event.pressed) layer_on(_VIMABLE);
                    else if (layer_state_is(_VIMABLE)) layer_off(_VIMABLE);

            }
            return true;


        case KC_SUPPLY:
        // Process _SUPPLY layer switching
        //
            if (record->event.pressed) layer_on(_SUPPLY);
            else layer_off(_SUPPLY);
			break;
    }
    return false;
}


// Global layers processing
// Interrupts default KC processing if any of layers returned true
//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if(process_qwerty_layer(keycode, record)) return false;
	if(process_supply_layer(keycode, record)) return false;
	if(process_locks_layer(keycode, record)) return false;

    return true;
}

