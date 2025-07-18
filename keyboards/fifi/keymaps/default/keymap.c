// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN,
};

#define U_BASE MO(_BASE)
#define U_NAV MO(_NAV)
#define U_MOUSE MO(_MOUSE)
#define U_MEDIA MO(_MEDIA)
#define U_NUM MO(_NUM)
#define U_SYM MO(_SYM)
#define U_FUN MO(_FUN)

#define U_RDO KC_AGIN
#define U_PST KC_PSTE
#define U_CPY KC_COPY
#define U_CUT KC_CUT
#define U_UND KC_UNDO

// Tap Dance declarations
enum {
    TD_BOOT,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_BOOT] = ACTION_TAP_DANCE_DOUBLE(KC_NO, QK_BOOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_v3lmx( // BASE
KC_Q,           KC_W,               KC_F,           KC_P,               KC_B,   KC_NO,          KC_NO,  KC_J,       KC_L,           KC_U,           KC_Y,           KC_QUOT,        \
LGUI_T(KC_A),   LALT_T(KC_R),       LCTL_T(KC_S),   LSFT_T(KC_T),       KC_G,   KC_NO,          KC_NO,  KC_M,       LSFT_T(KC_N),   LCTL_T(KC_E),   LALT_T(KC_I),   LGUI_T(KC_O),   \
KC_Z,           ALGR_T(KC_X),       KC_C,           KC_D,               KC_V,                           KC_K,       KC_H,           KC_COMM,        ALGR_T(KC_DOT), KC_SLSH,        \
                        LT(U_MEDIA,KC_ESC), LT(U_NAV,KC_SPC), LT(U_MOUSE,KC_TAB),                   LT(U_SYM,KC_ENT), LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL)
    ),

    [_NAV] = LAYOUT_v3lmx( // NAV
TD(TD_BOOT),    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,  U_RDO,          U_PST,      U_CPY,      U_CUT,      U_UND,          \
KC_LGUI,        KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,      KC_NO,          KC_NO,  CW_TOGG,        KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,        \
KC_NO,          KC_ALGR,    KC_NO,      KC_NO,      KC_NO,                              KC_INS,         KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,         \
                            KC_NO,      KC_NO,      KC_NO,                              KC_ENT,         KC_BSPC,    KC_DEL
    ),

    [_MOUSE] = LAYOUT_v3lmx( // MOUSE
TD(TD_BOOT),    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,  U_RDO,          U_PST,      U_CPY,      U_CUT,      U_UND,          \
KC_LGUI,        KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,      KC_NO,          KC_NO,  KC_NO,          KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,        \
KC_NO,          KC_ALGR,    KC_NO,      KC_NO,      KC_NO,                              KC_NO,          KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,        \
                            KC_NO,      KC_NO,      KC_NO,                              KC_BTN2,        KC_BTN1,    KC_BTN3
    ),

    [_MEDIA] = LAYOUT_v3lmx( // MEDIA
TD(TD_BOOT),    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,  RGB_TOG,        RGB_MOD,    RGB_HUI,    RGB_SAI,    RGB_VAI,        \
KC_LGUI,        KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,      KC_NO,          KC_NO,  KC_NO,          KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,        \
KC_NO,          KC_ALGR,    KC_NO,      KC_NO,      KC_NO,                              OU_AUTO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,          \
                            KC_NO,      KC_NO,      KC_NO,                              KC_MSTP,        KC_MPLY,    KC_MUTE
    ),

    [_NUM] = LAYOUT_v3lmx( // NUM
KC_LBRC,        KC_7,       KC_8,       KC_9,       KC_RBRC,    KC_NO,          KC_NO,  KC_NO,          KC_NO,      KC_NO,      KC_NO,      TD(TD_BOOT),    \
KC_SCLN,        KC_4,       KC_5,       KC_6,       KC_EQL,     KC_NO,          KC_NO,  KC_NO,          KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,        \
KC_GRV,         KC_1,       KC_2,       KC_3,       KC_BSLS,                            KC_NO,          KC_NO,      KC_NO,      KC_ALGR,    KC_NO,          \
                            KC_DOT,     KC_0,       KC_MINS,                            KC_NO,          KC_NO,      KC_NO
    ),

    [_SYM] = LAYOUT_v3lmx( // SYM
KC_LCBR,        KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RCBR,    KC_NO,          KC_NO,  KC_NO,          KC_NO,      KC_NO,      KC_NO,      TD(TD_BOOT),    \
KC_COLN,        KC_DLR,     KC_PERC,    KC_CIRC,    KC_PLUS,    KC_NO,          KC_NO,  KC_NO,          KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,        \
KC_TILD,        KC_EXLM,    KC_AT,      KC_HASH,    KC_PIPE,                            KC_NO,          KC_NO,      KC_NO,      KC_ALGR,    KC_NO,          \
                            KC_LPRN,    KC_RPRN,    KC_UNDS,                            KC_NO,          KC_NO,      KC_NO
    ),

    [_FUN] = LAYOUT_v3lmx( // FUN
KC_F12,         KC_F7,      KC_F8,      KC_F9,      KC_PSCR,    KC_NO,          KC_NO,  KC_NO,          KC_NO,      KC_NO,      KC_NO,      TD(TD_BOOT),    \
KC_F11,         KC_F4,      KC_F5,      KC_F6,      KC_SCRL,    KC_NO,          KC_NO,  KC_NO,          KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,        \
KC_F10,         KC_F1,      KC_F2,      KC_F3,      KC_PAUS,                            KC_NO,          KC_NO,      KC_NO,      KC_ALGR,    KC_NO,          \
                            KC_APP,     KC_SPC,     KC_TAB,                             KC_NO,          KC_NO,      KC_NO
    ),
    // clang-format on
};
