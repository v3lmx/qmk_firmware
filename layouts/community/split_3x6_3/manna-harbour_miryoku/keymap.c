// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "gpio.h"

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

#include QMK_KEYBOARD_H

enum custom_keycodes {
    MMMM = SAFE_RANGE,
    EAIG,
    EGRV,
    ETRM,
    ECIR,
    AGRV,
    ATRM,
    ACIR,
    UGRV,
    UTRM,
    UCIR,
    IGRV,
    ITRM,
    ICIR,
    OGRV,
    OTRM,
    OCIR,
    CCED,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // E
        case EAIG:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("'") "e");
            }
            return false;
        case EGRV:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("'") "e");
                SEND_STRING(SS_RALT(SS_TAP(X_GRV)) SS_TAP(X_E));
                SEND_STRING(SS_RALT(SS_TAP(X_QUOT)) SS_TAP(X_E));
            }
            return false;
        case ECIR:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("^") "e");
                // SEND_STRING(SS_RALT(SS_LSFT(SS_TAP(X_6))) SS_TAP(X_E));
            }
            return false;
        case ETRM:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("'") "e");
            }
            return false;
        // A
        case AGRV:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("`") "a");
            }
            return false;
        case ACIR:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("^") "a");
            }
            return false;
        case ATRM:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("\"") "a");
            }
            return false;
        // I
        case IGRV:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("`") "i");
            }
            return false;
        case ICIR:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("^") "i");
            }
            return false;
        case ITRM:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("\"") "i");
            }
            return false;
        // O
        case OGRV:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("`") "o");
            }
            return false;
        case OCIR:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("^") "o");
            }
            return false;
        case OTRM:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("\"") "o");
            }
            return false;
        // U
        case UGRV:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("`") "u");
            }
            return false;
        case UCIR:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("^") "u");
            }
            return false;
        case UTRM:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("\"") "u");
            }
            return false;
        // C
        case CCED:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT(",") "c");
            }
            return false;
    }
    return true;
}
