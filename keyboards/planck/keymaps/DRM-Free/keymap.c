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
    CT_COMM,
    CT_TILD_D,
    CT_DOL_B,
    CT_HASH_H,
    CT_CL_G,
    CT_DIA_P,
    CT_DEG_K,
    CT_QUOTE_W,
    CT_DQUOTE_I,
    CT_BACKSLASH_N,
    CT_EXCL_O,
    CT_INTER_M,
    CT_Ù_U,
    CT_À_A,
    CT_CIRC_V,
    CT_PAR,
    CT_ANGLE_BRA,
    CT_SQUARE_BRA,
    CT_BRACES,
    CT_DOT,
    CT_HYPHEN,
    CT_DIV,
    CT_STAR,
    CT_PLUS,
    CT_ESC,
    CT_META,
    CT_DEL,
    CT_TAB,
    CT_EQUAL,
    CCT_E_É_È,
};

typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void e_finished(qk_tap_dance_state_t *state, void *user_data);
void e_reset(qk_tap_dance_state_t *state, void *user_data);
void bl_finished(qk_tap_dance_state_t *state, void *user_data);
void bl_reset(qk_tap_dance_state_t *state, void *user_data);

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
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
    TD(CT_ESC),TD(CT_TILD_D),TD(CT_DOL_B),FR_X,FR_Y,FR_Z,TD(CT_HASH_H),FR_F,TD(CT_CL_G),TD(CT_DIA_P),TD(CT_DEG_K),QK_BOOTLOADER,
    KC_DEL,TD(CT_QUOTE_W),TD(CT_DQUOTE_I),TD(CT_BACKSLASH_N),TD(CT_EXCL_O),TD(CT_INTER_M),MT(MOD_LSFT,FR_L),TD(CT_Ù_U),KC_UP,TD(CT_CIRC_V),MT(MOD_LSFT,FR_J), TD(CT_PAR),
    KC_BACKSPACE, MT(MOD_LCTL,FR_C),MT(MOD_LALT,FR_T),MT(MOD_LSFT,FR_S),TD(CCT_E_É_È),TD(CT_À_A),MT(MOD_LCTL,FR_R),KC_LEFT,KC_DOWN,KC_RIGHT,MT(MOD_LCTL,FR_Q),TD(CT_ANGLE_BRA),
    TD(CT_META), TD(CT_COMM), TD(CT_DOT), KC_ENTER, TD(CT_TAB),   KC_SPC,  KC_SPC,  TD(CT_EQUAL),   TD(CT_PLUS), TD(CT_HYPHEN), TD(CT_STAR),TD(CT_DIV)
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
    [CT_COMM] = ACTION_TAP_DANCE_TAP_HOLD(FR_COMM, FR_SCLN),
    [CT_TILD_D] = ACTION_TAP_DANCE_TAP_HOLD(FR_D, FR_TILD),
    [CT_DOL_B] = ACTION_TAP_DANCE_TAP_HOLD(FR_B,FR_DLR),
    [CT_HASH_H] = ACTION_TAP_DANCE_TAP_HOLD(FR_H,FR_HASH),
    [CT_CL_G] = ACTION_TAP_DANCE_TAP_HOLD(FR_G,KC_CAPS),
    [CT_DIA_P] = ACTION_TAP_DANCE_TAP_HOLD(FR_P,FR_DIAE),
    [CT_DEG_K] = ACTION_TAP_DANCE_TAP_HOLD(FR_K,FR_DEG),
    [CT_QUOTE_W] = ACTION_TAP_DANCE_TAP_HOLD(FR_W,FR_QUES),
    [CT_DQUOTE_I] = ACTION_TAP_DANCE_TAP_HOLD(FR_I,FR_DQUO),
    [CT_BACKSLASH_N] = ACTION_TAP_DANCE_TAP_HOLD(FR_N,FR_BSLS),
    [CT_EXCL_O] = ACTION_TAP_DANCE_TAP_HOLD(FR_O,FR_EXLM),
    [CT_INTER_M] = ACTION_TAP_DANCE_TAP_HOLD(FR_M,FR_QUES),
    [CT_Ù_U] = ACTION_TAP_DANCE_TAP_HOLD(FR_U,FR_UGRV),
    [CT_À_A] = ACTION_TAP_DANCE_TAP_HOLD(FR_A,FR_AGRV),
    [CT_CIRC_V] = ACTION_TAP_DANCE_TAP_HOLD(FR_V,FR_CIRC),
    [CT_PAR] = ACTION_TAP_DANCE_TAP_HOLD(FR_LPRN,FR_RPRN),
    [CT_ANGLE_BRA] = ACTION_TAP_DANCE_TAP_HOLD(FR_LABK,FR_RABK),
    [CT_SQUARE_BRA] = ACTION_TAP_DANCE_TAP_HOLD (FR_LBRC,FR_RBRC),
    [CT_BRACES] = ACTION_TAP_DANCE_TAP_HOLD(FR_LCBR,FR_RCBR),
    [CT_DOT] = ACTION_TAP_DANCE_TAP_HOLD(FR_DOT, FR_COLN),
    [CT_HYPHEN] = ACTION_TAP_DANCE_TAP_HOLD(FR_MINS,FR_UNDS),
    [CT_DIV] = ACTION_TAP_DANCE_TAP_HOLD(FR_SLSH,FR_PERC),
    [CT_STAR] = ACTION_TAP_DANCE_TAP_HOLD(FR_ASTR, FR_AMPR),
    [CT_PLUS] = ACTION_TAP_DANCE_TAP_HOLD(KC_KP_PLUS,FR_PIPE),
    [CT_ESC] = ACTION_TAP_DANCE_TAP_HOLD(KC_ESCAPE,KC_KB_POWER),
    [CT_META] = ACTION_TAP_DANCE_TAP_HOLD(KC_LGUI,LGUI(FR_L)),
    [CT_DEL] = ACTION_TAP_DANCE_TAP_HOLD(KC_DEL,KC_HOME),
    [CT_TAB] = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB,LOWER),
    [CT_EQUAL] = ACTION_TAP_DANCE_TAP_HOLD(KC_KP_EQUAL, RAISE),
    [CCT_E_É_È] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, e_finished, e_reset),
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

    case TD(CT_COMM)...TD(CT_EQUAL):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
  }
  return true;
}
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else return TD_DOUBLE_TAP;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void e_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(FR_E); break;
        case TD_SINGLE_HOLD: register_code(FR_EACU); break;
        case TD_DOUBLE_TAP: register_code(FR_EGRV); break;
        default: break;
    }
}

void e_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(FR_E); break;
        case TD_SINGLE_HOLD: unregister_code(FR_EACU); break;
        case TD_DOUBLE_TAP: unregister_code(FR_EGRV); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}
