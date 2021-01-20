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
    MOD_QUOT = ALT_T(KC_QUOT),
    MOD_V    = CTL_T(KC_V),
    MOD_G    = GUI_T(KC_G),
    MOD_P    = SFT_T(KC_P),

    // right bottom row
    MOD_W   = SFT_T(KC_W),
    MOD_DOT = GUI_T(KC_DOT),
    MOD_SCLN = CTL_T(KC_SCLN),
    MOD_MINS = ALT_T(KC_MINS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_J,     KC_C,  KC_Y,    KC_F,    KC_K,                                               KC_Z,           KC_L,    KC_COMM, KC_U,     KC_Q,
        KC_R,     KC_S,  KC_T,    KC_H,    KC_D,                                               KC_M,           KC_N,    KC_A,    KC_I,     KC_O,
        MOD_QUOT, MOD_V, MOD_G,   MOD_P,   KC_B,                                               KC_X,           MOD_W,   MOD_DOT, MOD_SCLN, MOD_MINS,
                                           LT(_NAV,KC_BSPC), LT(_SYMR,KC_E), LT(_SYML,KC_SPC), LT(_NUM,KC_ENT)
    ),
    [_SYML] = LAYOUT(
        _______, KC_COLN, KC_LABK, KC_RABK, KC_SCLN,                   _______, _______, _______, _______, _______,
        KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,                     _______, KC_EQL,  KC_PLUS, KC_PERC, _______,
        _______, KC_EXLM, KC_LBRC, KC_RBRC, _______,                   _______, _______, _______, _______, _______,
                                            _______, KC_ESC,  _______, _______
    ),
    [_SYMR] = LAYOUT(
        _______, _______, _______, _______, _______,                   _______, KC_UNDS, KC_PIPE, KC_QUOT, _______,
        _______, KC_CIRC, KC_ASTR, KC_AMPR, _______,                   KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR,
        _______, _______, _______, _______, _______,                   _______, KC_MINS, KC_BSLS, KC_GRV,  _______,
                                            _______, _______, _______, _______
    ),
    [_NUM] = LAYOUT(
        _______, KC_7, KC_8, KC_9, _______,                   _______, _______, _______, _______, _______,
        KC_0,    KC_1, KC_2, KC_3, _______,                   _______, _______, _______, _______, _______,
        _______, KC_4, KC_5, KC_6, _______,                   _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT(
        _______, _______, _______,  _______, _______,                   _______, G(KC_TAB), KC_PGUP, C(KC_TAB), _______,
        _______, KC_LCTL, KC_LALT,  KC_LSFT, _______,                   _______, KC_LEFT,   KC_DOWN, KC_UP,     KC_RGHT,
        _______, _______, _______, _______,  _______,                   _______, KC_HOME,   KC_PGDN, KC_END,    _______,
                                             _______, _______, _______, _______
    )
};
