/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
                                           LOWER,   KC_LGUI,    KC_SPC,    KC_RALT,  RAISE
  ),
  
  [_LOWER] = LAYOUT_reviung41(
     KC_ESC,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,        KC_7,     KC_8,      KC_9,     KC_0,  KC_BSPC,
    KC_LCTL,  XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,            KC_LEFT,  KC_DOWN,    KC_UP,  KC_RIGHT,  XXXXXXX,  XXXXXXX,
    KC_LSFT,  XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_PGDN,  KC_PGUP,   XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   KC_LGUI,  KC_SPC,   KC_RALT,   ADJUST
  ),
  
  [_RAISE] = LAYOUT_reviung41(
     KC_GRV,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_BSPC,
    KC_LCTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            KC_MINS,   KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_GRV,
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_TILD,
                                             ADJUST,   _______,  KC_SPC,   _______,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  KC_BRID,  KC_BRIU,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_MPLY,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

