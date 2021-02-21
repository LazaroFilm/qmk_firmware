/* Copyright 2020 Victor Lucachi
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

/*#####################################
############## TAP DANCE ##############
#####################################*/
// Caps lock
// Tap Dance declarations
enum {
  TD_PLS_PMNS,
  TD_PAST_PSLS,
  TD_ENTER_PEQL,
};

// Tap Dance definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for first key, twice for second key
//     [TD_PLS_PMNS] = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_PMNS),
//     [TD_PAST_PSLS] = ACTION_TAP_DANCE_DOUBLE(KC_PAST, KC_PSLS),
//     [TD_ENTER_PEQL] = ACTION_TAP_DANCE_DOUBLE(KC_ENTER, KC_PEQL),

// };

// Tap Dance keycodes
enum td_keycodes {
    TD_MUTE_FN // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
};

// Define a type containing as many tapdance states as you need
typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
uint8_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void mutefn_finished(qk_tap_dance_state_t *state, void *user_data);
void mutefn_reset(qk_tap_dance_state_t *state, void *user_data);

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,---------------------------.
 * |   7  |   8  |   9  |BSPACE|
 * |------+------+------+------|
 * |   4  |   5  |   6  |  *.  |
 * |------+------+------+------|
 * |   1  |   2  |   3  |  +.  |
 * |------+------+------+------|
 * |  FN .|   0  |   .  |ENTER.|
 * `---------------------------'
 */
[_BASE] = LAYOUT_ortho_4x4(
    KC_P7,      KC_P8,   KC_P9,    KC_BSPC,
    KC_P4,      KC_P5,   KC_P6,    TD(TD_PAST_PSLS),
    KC_P1,      KC_P2,   KC_P3,    TD(TD_PLS_PMNS),
    TD(TD_MUTE_FN), KC_P0,   KC_PDOT,  TD(TD_ENTER_PEQL)
),

/* FN
 * ,---------------------------.
 * | RESET|      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * `---------------------------'
 */
[_FN] = LAYOUT_ortho_4x4(
    RESET,     KC_TRNS,   KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS
)
};

void encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}

// Determine the tapdance state to return
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }
    else return 2; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void mutefn_finished(qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_MUTE);
      break;
    case SINGLE_HOLD:
      layer_on(_FN); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
    // case DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
    //     tap_code16(KC_LPRN);
    //     register_code16(KC_LPRN);
  }
}

void mutefn_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_MUTE);
      break;
    case SINGLE_HOLD:
      layer_off(_FN); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
    // case DOUBLE_SINGLE_TAP:
    //     unregister_code16(KC_LPRN);
  }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_PLS_PMNS] = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_PMNS),
  [TD_PAST_PSLS] = ACTION_TAP_DANCE_DOUBLE(KC_PAST, KC_PSLS),
  [TD_ENTER_PEQL] = ACTION_TAP_DANCE_DOUBLE(KC_ENTER, KC_PEQL),
  [TD_MUTE_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mutefn_finished, mutefn_reset)
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
