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
        KC_BSPC, KC_QUOT, KC_COMM, MT(MOD_LCTL, KC_DOT), MT(MOD_LALT, KC_P), KC_Y,

        KC_F, MT(MOD_LALT, KC_G), MT(MOD_LCTL, KC_C), KC_R, KC_L, KC_RBRC,
        // Row 3
        KC_BSLS, KC_A, KC_O, MT(MOD_LGUI, KC_E), LT(1, KC_U), LT(2, KC_I),

        LT(2, KC_D), LT(1, KC_H), MT(MOD_LGUI, KC_T), KC_N, KC_S, KC_MINS,
        // Row 4, plus top thumb keys
        KC_GRV, KC_SCLN, KC_Q, KC_J, KC_K, KC_X,

        HYPR(KC_NO), MEH(KC_NO),

        KC_B, KC_M, KC_W, KC_V, KC_Z, KC_SLSH,
        // Row 5, remaining thumb keys
        KC_LALT, MT(MOD_LSFT, KC_TAB), KC_ENT,

        KC_SPC, KC_RGUI, MO(3)

            ),

    [_LOWER] = LAYOUT(
        // TODO
        // Row 1
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,

        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        // Row 2
        _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,
        // Row 3
        _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,

        // Row 4, plus top thumb keys
        _______, _______, _______, _______, _______, _______,

        KC_TRNS, KC_TRNS,

        _______, _______, _______, _______, _______, _______,
        // Row 5, remaining thumb keys
        KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS

        ),

    [_RAISE] = LAYOUT(
        // TODO
        // Row 1
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,

        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        // Row 2
        _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,
        // Row 3
        _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,

        // Row 4, plus top thumb keys
        _______, _______, _______, _______, _______, _______,

        KC_TRNS, KC_TRNS,

        _______, _______, _______, _______, _______, _______,
        // Row 5, remaining thumb keys
        KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS

        ),
    [_MEDIA] = LAYOUT(
        // TODO: Maybe add QK_BOOT somewhere so the right half can be flashed
        // Row 1
        KC_TRNS, HYPR(KC_ENT), HYPR(KC_LEFT), HYPR(KC_RGHT), C(KC_UP), C(KC_DOWN),

        _______, _______, _______, _______, _______, _______,
        // Row 2
        _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,
        // Row 3
        _______, KC_MPRV, KC_MNXT, KC_VOLU, _______, _______,

        _______, _______, _______, _______, _______, _______,

        // Row 4, plus top thumb keys
        _______, KC_MSTP, KC_MPLY, KC_VOLD, _______, _______,

        KC_TRNS, KC_TRNS,

        _______, _______, _______, _______, _______, _______,
        // Row 5, remaining thumb keys
        KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS

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

// TODO: Debug. Either holds on white or turns off all LEDs.
// // See https://docs.qmk.fm/features/rgb_matrix#callbacks
// bool rgb_matrix_indicators_user(void) {
//     if (keyboard_report->mods & MOD_BIT(KC_LGUI)) {
//         rgb_matrix_mode(1);
//         set_rgb_matrix(HSV_WHITE);
//         return true;
//     }
//     rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
//     return false;
// }

// // Enable/disable RGB matrix
// rgb_matrix_enable();
// rgb_matrix_disable();
// rgb_matrix_toggle();

// // Set brightness (0-255)
// rgb_matrix_set_color_all(r, g, b);

// // Set individual LED color
// rgb_matrix_set_color(led_index, r, g, b);

// // Set HSV color for all LEDs
// rgb_matrix_sethsv(hue, sat, val);

// // Change animation modes
// rgb_matrix_mode(mode_number);
