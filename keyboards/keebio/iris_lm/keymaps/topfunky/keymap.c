// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers { _QWERTY, _LOWER, _RAISE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DT_PRNT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_HOME, KC_END, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
        KC_LGUI, TL_LOWR, KC_ENT, KC_SPC, TL_UPPR, KC_RALT
        // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_LOWER] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_GRV, _______, KC_UP, _______, QK_BOOT, _______, _______, KC_P7, KC_P8, KC_P9, KC_P0, KC_PGDN,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LBRC, KC_RBRC, KC_P4, KC_P5, KC_P6, KC_PLUS, KC_PIPE,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        RM_NEXT, EE_CLR, _______, _______, _______, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_P1, KC_P2, KC_P3, KC_MINS, _______,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
        _______, _______, KC_DEL, KC_DEL, _______, KC_P0
        // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_RAISE] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        RM_TOGG, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_BOOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        RM_NEXT, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS, KC_EQL, KC_HOME, RM_HUEU, RM_SATU, RM_VALU, KC_BSLS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN, _______, KC_PLUS, KC_END, RM_HUED, RM_SATD, RM_VALD, EE_CLR,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
        _______, _______, _______, _______, _______, _______
        // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
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
            set_rgb_matrix(HSV_BLUE);
            break;
        case _RAISE:
            set_rgb_matrix(HSV_GREEN);
            break;
        default: //  for any other layers, or the default layer
            set_rgb_matrix(HSV_RED);
            break;
    }

    return state;
}

// // https://docs.qmk.fm/features/rgb_matrix
// // HSV_CYAN HSV_ORANGE etc.
// void keyboard_post_init_user(void) {
//     rgblight_enable_noeeprom(); // enables Rgb, without saving settings
//     rgblight_mode_noeeprom(1);
//     layer_state_set_user(layer_state);
// }

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     for (uint8_t i = led_min; i < led_max; i++) {
//         switch (get_highest_layer(layer_state | default_layer_state)) {
//             case 2:
//                 rgb_matrix_set_color(i, RGB_BLUE);
//                 break;
//             case 1:
//                 rgb_matrix_set_color(i, RGB_YELLOW);
//                 break;
//             default:
//                 break;
//         }
//     }
//     return false;
// }

// // FIXME:Doesn't work
// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case _RAISE:
//             rgb_matrix_sethsv(200, 255, 255);
//             break;
//         case _LOWER:
//             rgb_matrix_sethsv(127, 255, 255);
//             break;
//         default: //  for any other layers, or the default layer
//             rgb_matrix_sethsv(0, 255, 255);
//             break;
//     }
//     return state;
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
// rgb_matrix_step();           // Next mode
// rgb_matrix_step_reverse();   // Previous mode