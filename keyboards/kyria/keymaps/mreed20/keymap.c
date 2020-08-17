/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
 */
#include QMK_KEYBOARD_H

// Layers
enum {
    _BASE = 0,  // Main RSTHD layout
    _SYML,      // Left symbols
    _SYMR,      // Right symbols
    _NUM,       // Numbers
    _NAV,       // Navigation
};

// Custom key names
enum {
    // left bottom row
    MOD_SLSH = ALT_T(KC_SLSH),
    MOD_V    = CTL_T(KC_V),
    MOD_G    = GUI_T(KC_G),
    MOD_P    = SFT_T(KC_P),

    // right bottom row
    MOD_W   = SFT_T(KC_W),
    MOD_DOT = GUI_T(KC_DOT),
    MOD_TAB = CTL_T(KC_TAB),
    MOD_ESC = ALT_T(KC_ESC),

    // KC_(CUT|COPY|PASTE) do not seem to work on macOS.
    MAC_CUT = G(KC_X),
    MAC_COPY = G(KC_C),
    MAC_PSTE = G(KC_V),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        _______, KC_J,     KC_C,  KC_Y,    KC_F,    KC_K,                                                                         KC_Z,    KC_L,    KC_COMM, KC_U,    KC_Q,    _______,
        _______, KC_R,     KC_S,  KC_T,    KC_H,    KC_D,                                                                         KC_M,    KC_N,    KC_A,    KC_I,    KC_O,    _______,
        _______, MOD_SLSH, MOD_V, MOD_G,   MOD_P,   KC_B,    _______,          _______,        _______,          _______,         KC_X,    MOD_W,   MOD_DOT, MOD_TAB, MOD_ESC, _______,
                                  _______, _______, KC_VOLD, LT(_NAV,KC_BSPC), LT(_SYMR,KC_E), LT(_SYML,KC_SPC), LT(_NUM,KC_ENT), KC_VOLU, _______, _______
    ),
    [_SYML] = LAYOUT(
        _______, _______, KC_COLN, KC_LABK, KC_RABK, KC_SCLN,                                     _______, _______, _______, _______, _______, _______,
        _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,                                       _______, _______, KC_EQL,  KC_PLUS, KC_PERC, _______,
        _______, _______, KC_EXLM, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_SYMR] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                     _______, KC_UNDS, KC_PIPE, KC_QUOT, _______, _______,
        _______, KC_CIRC, KC_ASTR, KC_AMPR, _______, _______,                                     KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_BSLS, KC_GRV,  _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NUM] = LAYOUT(
        _______, _______, KC_7, KC_8,    KC_9,    _______,                                     _______,  _______, _______, _______, _______, _______,
        _______, KC_0,    KC_1, KC_2,    KC_3,    _______,                                     _______,  _______, _______, _______, _______, _______,
        _______, _______, KC_4, KC_5,    KC_6,    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
    ),
    [_NAV] = LAYOUT(
        _______, _______, _______, _______,  _______,  _______,                                     _______, _______, KC_PGUP, _______, _______, _______,
        _______, _______, _______, KC_LCTL,  KC_LALT,  _______,                                     _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, MAC_CUT, MAC_COPY, MAC_PSTE, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END,  _______, _______,
                                   _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______
    )
};
