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

enum layers {
    BASE = 0,
    SYM,
    NUM,
};

/* [_LAYERINDEX] = LAYOUT( */
/*   _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/* ), */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        _______, KC_Q,        KC_W,        KC_D,        KC_F,        KC_K,                                                           KC_J,     KC_U,        KC_R,           KC_L,          KC_SCLN,        _______,
        _______, KC_A,        KC_S,        KC_E,        KC_T,        KC_G,                                                           KC_Y,     KC_N,        KC_I,           KC_O,          KC_H,           _______,
        _______, SFT_T(KC_Z), CTL_T(KC_X), ALT_T(KC_C), CMD_T(KC_V), KC_B,    _______,   _______,         _______,        _______,   KC_P,     CMD_T(KC_M), ALT_T(KC_COMM), CTL_T(KC_DOT), SFT_T(KC_SLSH), _______,
                                           _______,     _______,     _______, KC_TAB,    LT(SYM,KC_BSPC), LT(NUM,KC_SPC), KC_ENT,    _______,  _______, _______
    ),
    [SYM] = LAYOUT(
        _______, KC_LABK,     KC_RABK,     KC_LCBR,     KC_RCBR, KC_HASH,                                                            KC_PERC,  KC_UNDS, KC_PIPE,        KC_QUOT,       KC_COLN,        _______,
        _______, KC_CIRC,     KC_DLR,      KC_LPRN,     KC_RPRN, KC_ASTR,                                                            KC_EQL,   KC_TILD, KC_SLSH,        KC_DQUO,       KC_DLR,         _______,
        _______, KC_EXLM,     KC_AT,       KC_LBRC,     KC_RBRC, KC_AMPR, _______,       _______,       _______,      _______,       KC_PLUS,  KC_MINS, KC_BSLS,        KC_GRV,        KC_QUES,        _______,
                                           _______,     _______, _______, _______,       _______,       KC_ESC,       _______,       _______,  _______, _______
    ),
    [NUM] = LAYOUT(
        _______, _______,     KC_7,        KC_8,        KC_9,    _______,                                                            _______,  _______, _______,         _______,      _______,        _______,
        _______, KC_0,        KC_1,        KC_2,        KC_3,    _______,                                                            _______,  _______, _______,         _______,      _______,        _______,
        _______, _______,     KC_4,        KC_5,        KC_6,    _______, _______,       _______,       _______,      _______,       _______,  _______, _______,         _______,      _______,        _______,
                                           _______,     _______, _______, KC_VOLD,       KC_VOLU,       _______,      _______,       _______,  _______, _______)
};

// Disable permissive hold for home row mods.
// Source: MrLinuxFish on Discord channel "splitkb.com".
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_Z):
        case CTL_T(KC_X):
        case ALT_T(KC_C):
        case GUI_T(KC_V):
        case GUI_T(KC_M):
        case ALT_T(KC_COMM):
        case CTL_T(KC_DOT):
        case SFT_T(KC_SLSH):
            // This actually *disables* the permissive hold for these keys.
            // See issue https://github.com/qmk/qmk_firmware/issues/8999
            return true;
        default:
            return false;
    }
}
