// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
     _DVORAK,
     _L1,
     _L2,
     _L3
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
   //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC,

   //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_BSPC,
      KC_QUOT,
      KC_COMM,
      KC_DOT,
      MT(MOD_LALT,KC_P),
      KC_Y,

      KC_F,
      MT(MOD_LALT,KC_G),
      MT(MOD_LCTL,KC_C),
      KC_R,
      KC_L,
      KC_RBRC,
   //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
 KC_BSLS,
      KC_A,
      MT(MOD_LSFT,KC_O),
      MT(MOD_LGUI,KC_E),
      LT(1,KC_U),
      LT(2,KC_I),

      LT(2,KC_D),
      LT(1,KC_H),
      MT(MOD_LGUI,KC_T),
      MT(MOD_LSFT,KC_N),
      KC_S,
   KC_MINS,
   //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_GRV,
      KC_SCLN,
      KC_Q,
      KC_J,
      KC_K,
      KC_X,

      KC_B,
      KC_M,
      KC_W,
      KC_V,
      KC_Z,
  MO(1),
   //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LALT,
      MT(MOD_LSFT,KC_TAB),
      KC_ENT,
      HYPR(KC_NO),

      MEH(KC_NO),
      KC_SPC,
      KC_RGUI,
      MO(3)
   //                  ├────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┤

  ),

  // TODO: Resume editing here (fix the order of keys defined in the right hand half of the keyboard)
  [_L1] = LAYOUT(

       //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
   //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
   //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
   //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
   //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
   //                  ├────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┤

    // Left hand
      KC_TRNS,
      A(KC_D),
      S(KC_2),
      S(KC_3),
      S(KC_4),
      S(KC_5),

      KC_DEL,
      A(KC_Y),
      KC_NO,
      KC_NO,
      KC_NO,
      G(KC_TAB),

      LSG(KC_S),
      LSG(KC_H),
      KC_BSPC,
      KC_TAB,
      KC_DEL,
      G(KC_SPC),

      LSG(KC_A),
      LSG(KC_V),
      KC_TRNS,
      G(KC_ENT),
      KC_ENT,
      LSG(KC_GRV),

      KC_TRNS,
      KC_TRNS,
      KC_BSPC,
      S(KC_9),

    // Right hand

      KC_PGUP,
      S(KC_0),
      S(KC_9),
      S(KC_8),
      S(KC_7),
      S(KC_6),

      KC_PGDN,
      S(KC_EQL),
      C(KC_E),
      KC_UP,
      C(KC_A),
      KC_PGUP,

      KC_NO,
      KC_SLSH,
      KC_RGHT,
      KC_DOWN,
      KC_LEFT,
      KC_PGDN,

      KC_TRNS,
      S(KC_SLSH),
      KC_EQL,
      HYPR(KC_RGHT),
      HYPR(KC_LEFT),
      HYPR(KC_ENT),


      KC_TRNS,
      KC_TRNS,
      KC_DEL,
      S(KC_0)
  ),

  [_L2] = LAYOUT(

      //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      //                  ├────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┤

    // Left hand
     KC_TRNS,
      KC_F1,
      KC_F2,
      KC_F3,
      KC_F4,
      KC_F5,

      RGB_TOG,
      KC_NO,
      LSG(KC_LBRC),
      LSG(KC_A),
      LSG(KC_RBRC),
      KC_TRNS,

      RGB_MOD,
      KC_NO,
      A(KC_BSPC),
      G(KC_Z),
      A(KC_DEL),
      KC_TRNS,

      KC_NO,
      KC_NO,
      KC_NO,
      KC_NO,
      KC_TRNS,
      KC_NO,

      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,



    // Right hand

      KC_F11,
      KC_F10,
      KC_F9,
      KC_F8,
      KC_F7,
      KC_F6,

      KC_NO,
      KC_NO,
      C(KC_R),
      A(KC_UP),
      C(KC_C),
      KC_NO,

      KC_NO,
      RGB_VAI,
      A(KC_RGHT),
      A(KC_DOWN),
      A(KC_LEFT),
      KC_NO,

      KC_TRNS,
      RGB_VAD,
      KC_NO,
      KC_NO,
      C(KC_DOWN),
      C(KC_UP),

      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS

  ),

  [_L3] = LAYOUT(

      //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      //├────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┤
      //                  ├────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┤

    // Left hand
         KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,

      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,

      KC_TRNS,
      KC_MPRV,
      KC_MNXT,
      KC_VOLU,
      KC_TRNS,
      KC_TRNS,

      QK_CLEAR_EEPROM,
      KC_MSTP,
      KC_MPLY,
      KC_VOLD,
      KC_TRNS,
      KC_TRNS,


      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,

    // Right hand
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,

      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,

      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,

      QK_CLEAR_EEPROM,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,


      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS

  )
};
