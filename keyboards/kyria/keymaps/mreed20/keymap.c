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

enum {
    // Base layer, Norman layout
    _BASE = 0,
    // Left symbols
    _SYML,
    // Right symbols
    _SYMR,
    // Numbers
    _NUM,
    // Navigation
    _NAV,
};

enum {
    // left bottom row
    MOD_Z = GUI_T(KC_Z),
    MOD_X = ALT_T(KC_X),
    MOD_C = CTL_T(KC_C),
    MOD_V = SFT_T(KC_V),

    // right bottom row
    MOD_M    = SFT_T(KC_M),
    MOD_COMM = CTL_T(KC_COMM),
    MOD_DOT  = ALT_T(KC_DOT),
    MOD_SLSH = GUI_T(KC_SLSH),
};

/* [_LAYERINDEX] = LAYOUT( */
/*   _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/* ), */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        _______, KC_Q,  KC_W,  KC_D,    KC_F,    KC_K,                                                                           KC_J,    KC_U,    KC_R,     KC_L,    KC_SCLN,  _______,
        _______, KC_A,  KC_S,  KC_E,    KC_T,    KC_G,                                                                           KC_Y,    KC_N,    KC_I,     KC_O,    KC_H,     _______,
        _______, MOD_Z, MOD_X, MOD_C,   MOD_V,   KC_B,    _______,         _______,           _______,          _______,         KC_P,    MOD_M,   MOD_COMM, MOD_DOT, MOD_SLSH, _______,
                               _______, _______, KC_VOLD, LT(_NAV,KC_TAB), LT(_SYMR,KC_BSPC), LT(_SYML,KC_SPC), LT(_NUM,KC_ENT), KC_VOLU, _______, _______
    ),
    [_SYML] = LAYOUT(
        _______, _______, KC_COLN, KC_LABK, KC_RABK, KC_SCLN,                                     _______, _______, _______, _______, _______, _______,
        _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,                                       _______, _______, KC_EQL,  KC_PLUS, KC_PERC, _______,
        _______, _______, KC_EXLM, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, KC_ESC,  _______, _______, _______, _______, _______
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
                                _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______),
    [_NAV] = LAYOUT(
        _______, _______, _______, _______,    _______, _______,                                     KC_HOME, A(S(KC_TAB)), KC_PGUP, A(KC_TAB), _______, _______,
        _______, _______, _______, A(KC_LCTL), _______, _______,                                     _______, KC_LEFT,      KC_UP,   KC_DOWN,   KC_RGHT, _______,
        _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, KC_END,  C(S(KC_TAB)), KC_PGDN, C(KC_TAB), _______, _______,
                                   _______,    _______, _______, _______, _______, _______, _______, _______, _______,      _______
    )
};

// Disable permissive hold for home row mods.
// Source: MrLinuxFish on Discord channel "splitkb.com".
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOD_Z:
        case MOD_X:
        case MOD_C:
        case MOD_V:
        case MOD_M:
        case MOD_COMM:
        case MOD_DOT:
        case MOD_SLSH:
            // This actually *disables* the permissive hold for these keys.
            // See issue https://github.com/qmk/qmk_firmware/issues/8999
            return true;
        default:
            return false;
    }
}
