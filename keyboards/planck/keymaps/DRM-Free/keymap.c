/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"
#include "keymap_french.h"

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  BASE = SAFE_RANGE,
};

enum {
    CT_CLN,
    CT_PAR,
    CT_SQUARE_BRA,
    CT_ANGLE_BRA,
    CT_BRACES,
    CT_DOT,
    CT_COMMA,
    CT_HYPHEN,
    CT_DIV,
    CT_STAR,
    CT_PLUS,
    CT_VOL,
    CT_DEL,
    CT_TAB,
    CT_EQUAL,
    CT_TILD,
    CT_F3,
    CT_F4,
    CT_F5,
    CT_ALTF3,
    CT_ALTF4,
    CT_EXCLM,
    CT_U,
    DT_ESC,
    DT_A,
    DT_E,
    DT_META_L,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MT_BAK MT(KC_LEFT_SHIFT,KC_BACKSPACE)
#DEFINE
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    DT_ESC,  DT_CRTL_V,    CT_F3,    CT_F4,    CT_F5,    FR_Z,    FR_J,    FR_F,    FR_G,    FR_P,    FR_K,    CT_EXCLM,
    CT_VOL,  CT_DEL,    CT_ALTF3,    CT_ALTF4,    FR_N,    FR_O,    FR_I,    FR_L,    FR_M,    CT_TILD,    CT_SQUARE_BRA, CT_BRACES,
    MT_BAK, _______,    _______,    _______,    _______,    FR_E,    FR_A,    _______,    _______, _______,  CT_PAR, CT_PLUS,
    DT_META_L, CT_COMMA, CT_DOT, KC_ENTER, CT_TAB,   KC_SPC,  KC_SPC,  CT_EQUAL,   CT_ANGLE_BRA, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Base  |Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT,   DEBUG,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, BASE,  _______,  _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_CLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_COLN, KC_SCLN),
    [CT_PAR] = ACTION_TAP_DANCE_TAP_HOLD(KC_LEFT_PAREN,KC_RIGHT_PAREN),
    [CT_SQUARE_BRA] = ACTION_TAP_DANCE_TAP_HOLD(KC_LBRACKET,KC_RBRACKET),
    [CT_ANGLE_BRA] = ACTION_TAP_DANCE_TAP_HOLD(KC_LEFT_ANGLE_BRACKET,KC_RIGHT_ANGLE_BRACKET),
    [CT_BRACES] = ACTION_TAP_DANCE_TAP_HOLD(KC_LEFT_CURLY_BRACE,KC_RIGHT_CURLY_BRACE),
    [CT_DOT] = ACTION_TAP_DANCE_TAP_HOLD(FR_DOT, FR_COLN),
    [CT_COMMA] = ACTION_TAP_DANCE_TAP_HOLD(FR_COMM, FR_SCLN),
    [CT_HYPHEN] = ACTION_TAP_DANCE_TAP_HOLD(FR_MINS,FR_UNDS),
    [CT_DIV] = ACTION_TAP_DANCE_TAP_HOLD(FR_SLSH,FR_PERC),
    [CT_STAR] = ACTION_TAP_DANCE_TAP_HOLD(FR_ASTR, FR_AMPR),
    [CT_PLUS] = ACTION_TAP_DANCE_TAP_HOLD(KC_KP_PLUS,FR_PIPE),
    [CT_VOL] = ACTION_TAP_DANCE_TAP_HOLD(KC_KB_VOLUME_DOWN,KC_KB_MUTE),
    [CT_DEL] = ACTION_TAP_DANCE_TAP_HOLD(KC_DEL,KC_HOME),
    [CT_TAB] = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB,LOWER),
    [CT_EQUAL] = ACTION_TAP_DANCE_TAP_HOLD(KC_KP_EQUAL, RAISE),
    [CT_TILD] = ACTION_TAP_DANCE_TAP_HOLD(FR_D, FR_TILD),
    [CT_F3] = ACTION_TAP_DANCE_TAP_HOLD(FR_B,KC_F3),
    [CT_F4] = ACTION_TAP_DANCE_TAP_HOLD(FR_X,KC_F4),
    [CT_F5] = ACTION_TAP_DANCE_TAP_HOLD(FR_Y,KC_F5),
    [CT_ALTF3] = ACTION_TAP_DANCE_TAP_HOLD(FR_U,LALT(KC_F3)),
    [CT_ALTF4] = ACTION_TAP_DANCE_TAP_HOLD(FR_N,LALT(KC_F4)),
    [CT_EXCLM] = ACTION_TAP_DANCE_TAP_HOLD(FR_EXLM,FR_QUES),
    [CT_U] = ACTION_TAP_DANCE_TAP_HOLD(FR_U, FR_EACU)
    [DT_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESCAPE,KC_KB_POWER),
    [DT_A] = ACTION_TAP_DANCE_DOUBLE(ACTION_TAP_DANCE_TAP_HOLD(FR_A, FR_AGRV),FR_AT)
    [DT_E] = ACTION_TAP_DANCE_DOUBLE(ACTION_TAP_DANCE_TAP_HOLD(FR_E, FR_EACU),FR_EGRV)
    [DT_META_L] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI,LGUI(FR_L)),
    [DT_CRTL_C] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI,KC_LCTRL(FR_C)),
    [DT_CRTL_V] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI,KC_LCTRL(FR_V)),
    [DT_CRTL_Q] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI,KC_LCTRL(FR_Q)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  qk_tap_dance_action_t *action;
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        print("mode just switched to base and this is a huge string\n");
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;

    case TD(CT_CLN) ... TD(CT_EXCLM):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
