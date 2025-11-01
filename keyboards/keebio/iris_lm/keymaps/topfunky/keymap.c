// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

// Personal modifications: 2025 Geoffrey Grosenbach (@topfunky)

#include QMK_KEYBOARD_H

enum custom_layers { _DVORAK, _LOWER, _RAISE, _MEDIA };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DVORAK] = LAYOUT(
        // Row 1
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,

        KC_6, KC_7, KC_8, KC_9, KC_0, KC_LBRC,

        // Row 2
        KC_BSPC, KC_QUOT, KC_COMM, MT(MOD_LCTL, KC_DOT), MT(MOD_LSFT, KC_P), MT(MOD_LALT, KC_Y),

        MT(MOD_LALT, KC_F), MT(MOD_LSFT, KC_G), MT(MOD_LCTL, KC_C), KC_R, KC_L, KC_RBRC,

        // Row 3
        KC_BSLS, KC_A, KC_O, MT(MOD_LGUI, KC_E), LT(_LOWER, KC_U), LT(_RAISE, KC_I),

        LT(_RAISE, KC_D), LT(_LOWER, KC_H), MT(MOD_LGUI, KC_T), KC_N, KC_S, KC_MINS,

        // Row 4, plus top thumb keys
        KC_GRV, KC_SCLN, KC_Q, KC_J, KC_K, KC_X,

        OSM(MOD_HYPR), OSM(MOD_MEH),

        KC_B, KC_M, KC_W, KC_V, KC_Z, KC_SLSH,

        // Row 5, remaining thumb keys
        MT(MOD_LALT, KC_TAB), KC_LSFT, KC_ENT,

        KC_SPC, KC_RGUI, OSL(_MEDIA)

            ),

    [_LOWER] = LAYOUT(

        // Row 1
        A(KC_D), S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),

        S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_PGUP,

        // Row 2
        KC_DEL, A(KC_Y), LSG(KC_LBRC), LSG(KC_A), LSG(KC_RBRC), G(KC_TAB),

        KC_PGUP, C(KC_A), KC_UP, C(KC_E), S(KC_EQL), KC_PGDN,

        // Row 3
        LSG(KC_S), LSG(KC_H), KC_BSPC, KC_TAB, KC_DEL, G(KC_SPC),

        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_EQL, _______,

        // Row 4, plus top thumb keys
        LSG(KC_A), LSG(KC_V), A(KC_BSPC), _______, A(KC_DEL), LSG(KC_GRV),

        _______, _______,

        _______, A(KC_LEFT), _______, A(KC_RIGHT), _______, _______,

        // Row 5, remaining thumb keys
        _______, _______, G(KC_ENT),

        _______, _______, _______

        ),

    [_RAISE] = LAYOUT(

        // Row 1
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,

        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,

        // Row 2
        RGB_TOG, _______, _______, _______, _______, _______,

        _______, C(KC_C), A(KC_UP), C(KC_R), KC_NO, KC_NO,

        // Row 3
        RGB_MOD, _______, A(KC_BSPC), G(KC_Z), A(KC_DEL), _______,

        _______, A(KC_LEFT), A(KC_DOWN), A(KC_RGHT), RGB_VAI, _______,

        // Row 4, plus top thumb keys
        _______, _______, _______, _______, _______, _______,

        _______, _______,

        _______, _______, _______, _______, RGB_VAD, _______,

        // Row 5, remaining thumb keys
        _______, _______, _______,

        _______, _______, _______

        ),
    [_MEDIA] = LAYOUT(
        // Row 1
        KC_VOLU, HYPR(KC_ENT), HYPR(KC_LEFT), HYPR(KC_RGHT), C(KC_UP), C(KC_DOWN),

        G(KC_ENT), _______, _______, DT_PRNT, DT_UP, DT_DOWN,

        // Row 2
        KC_VOLD, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT,

        KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, _______,

        // Row 3
        _______, KC_1, KC_2, KC_3, KC_4, KC_5,

        KC_6, KC_7, KC_8, KC_9, KC_0, _______,

        // Row 4, plus top thumb keys
        _______, _______, _______, _______, _______, _______,

        _______, _______,

        _______, _______, LAG(KC_H), _______, _______, _______,

        // Row 5, remaining thumb keys
        _______, _______, _______,

        _______, _______, _______

        )};

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom(); // enables RGB Matrix, without saving settings
    rgb_matrix_mode_noeeprom(1);
    layer_state_set_user(layer_state);
}

void set_rgb_matrix(uint8_t hue, uint8_t sat, uint8_t val) {
    val = rgb_matrix_get_val();
    rgb_matrix_sethsv_noeeprom(hue, sat, val);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _LOWER:
            // Must go to mode 1 to set solid color
            // TODO: Use `noeeprom` variants of the functions
            rgb_matrix_mode(1);
            set_rgb_matrix(HSV_CYAN);
            break;
        case _RAISE:
            rgb_matrix_mode(1);
            set_rgb_matrix(HSV_GREEN);
            break;
        case _MEDIA:
            rgb_matrix_mode(1);
            set_rgb_matrix(HSV_PURPLE);
            break;
        default:
            // Return to animation on default layer
            rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
            break;
    }

    return state;
}

