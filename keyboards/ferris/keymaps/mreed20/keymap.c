#include QMK_KEYBOARD_H

/*
 * Remember:
 * The more novel it is, the harder it will be to learn!
 * So try to balance ergonomics with memorizability and consistency.
 */

// Layers
enum {
    _BASE = 0,  // Main RSTHD layout
    _SYML,      // Left symbols
    _SYMR,      // Right symbols
    _NUM,       // Numbers
    _NAV,       // Navigation
};

/*
 * Makes it easy to have consistent modifiers across layers.
 */
#define MODLAYOUT(K0,  K1,  K2,  K3,  K4,  K5,  K6,  K7,  K8,  K9, \
                  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
                  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
                  K30, K31, K32, K33) \
    LAYOUT( \
        K0,         K1,         K2,         K3,         K4,     K5,  K6,         K7,         K8,         K9, \
        SFT_T(K10), CTL_T(K11), ALT_T(K12), GUI_T(K13), K14,    K15, GUI_T(K16), ALT_T(K17), CTL_T(K18), SFT_T(K19), \
        K20,        K21,        K22,        K23,        K24,    K25, K26,        K27,        K28,        K29, \
        K30, K31, K32, K33)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = MODLAYOUT(
        KC_J,    KC_C, KC_Y, KC_F, KC_K,      KC_Z, KC_L, KC_COMM, KC_U,    KC_Q,
        KC_R,    KC_S, KC_T, KC_H, KC_D,      KC_M, KC_N, KC_A,    KC_I,    KC_O,
        KC_QUOT, KC_V, KC_G, KC_P, KC_B,      KC_X, KC_W, KC_DOT,  KC_SCLN, KC_MINS,
        LT(_NAV,KC_BSPC), LT(_SYMR,KC_E),     LT(_SYML,KC_SPC), LT(_NUM,KC_TAB)
    ),

    [_SYML] = MODLAYOUT(
        _______, KC_COLN, KC_LABK, KC_RABK, _______,     _______, _______, _______, _______, _______,
        KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,       _______, KC_EQL, KC_PLUS, KC_PERC, _______,
        _______, KC_EXLM, KC_LBRC, KC_RBRC, _______,     _______, _______, _______, _______, _______,
        _______, KC_ESC, _______, _______
    ),

    [_SYMR] = MODLAYOUT(
        _______, _______, _______, _______, _______,     _______, KC_UNDS, KC_PIPE, KC_QUOT, _______,
        _______, KC_CIRC, KC_ASTR, KC_AMPR, _______,     KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR,
        _______, _______, _______, _______, _______,     _______, KC_MINS, KC_BSLS, KC_GRV, _______,
        _______, _______, KC_ENT , _______
    ),

    [_NUM] = MODLAYOUT(
        _______, KC_7, KC_8, KC_9, _______,     _______, _______, _______, _______, _______,
        KC_0,    KC_1, KC_2, KC_3, _______,     _______, _______, _______, _______, _______,
        _______, KC_4, KC_5, KC_6, _______,     _______, _______, _______, _______, _______,
        _______, _______, _______, _______
    ),

    /* The keys in this layer are often held for repetition, so I don't make them mod-tap keys. */
    [_NAV] = LAYOUT(
        _______, _______, _______, _______,   _______, _______, _______, KC_PGUP, _______, _______,
        _______, _______, _______, _______,   _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        _______, _______, _______, _______,   _______, _______, KC_HOME, KC_PGDN, KC_END, _______,
        _______, _______, _______, _______
    )
};
