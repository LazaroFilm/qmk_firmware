#include QMK_KEYBOARD_H

/*#####################################
############## TAP DANCE ##############
#####################################*/
// Caps lock
// Tap Dance declarations
enum {
    TD_LSFT_CAPS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};
// TD(TD_LSFT_CAPS)
// LSFT_T(KC_CAPS)


/*#####################################
############### MACROS ################
#####################################*/

enum custom_keycodes {
    ARROW = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ARROW:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("=>");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

/*#####################################
############### LAYOUT ################
#####################################*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_4x12(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, TD(TD_LSFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, MO(3), KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_SPC, MO(2), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[1] = LAYOUT_ortho_4x12(KC_DEL, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_BSPC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_EQL, KC_UNDS, KC_LCBR, KC_RCBR, KC_TRNS, KC_PIPE, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LSFT(KC_NUHS), LSFT(KC_NUBS), KC_TRNS, KC_TRNS, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_APPLE_FN, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END),
	[2] = LAYOUT_ortho_4x12(KC_DEL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ARROW, KC_PLUS, KC_MINS, KC_LBRC, KC_RBRC, KC_TRNS, KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NUHS, KC_NUBS, KC_TRNS, KC_TRNS, KC_BSLASH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPACE, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END),
	[3] = LAYOUT_ortho_4x12(KC_SLEP, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_BSPC, KC_TRNS, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PSLS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_PAST, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_MPLY, KC_SPC, KC_TRNS, KC_P0, KC_PDOT, KC_PCMM, KC_PEQL),
	[4] = LAYOUT_ortho_4x12(KC_NO, RESET, DEBUG, EEP_RST, KC_NO, KC_NO, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_M_P, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, MO(4), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

/*#####################################
############ RGB LED SETUP ############
#####################################*/

// Light LEDs 0 to 16 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_GREEN}       // Light all LEDs, starting with LED 1
);
// Light LEDs 0 to 16 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_CYAN}
);
// Light LEDs 0 to 16 in orange when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_ORANGE}
);
// Light LEDs 0 to 16 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_PURPLE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,
	my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    //Debug enable
    debug_enable=true;

    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_sethsv_noeeprom(0, 0, 127);
    // rgblight_sethsv_noeeprom(HSV_GREEN);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
	rgblight_set_layer_state(3, layer_state_cmp(state, 3));

    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    // dprintf("num=%u, cap=%u, scl=%u, cmp=%u, kan=%u\n", led_state.num_lock, led_state.caps_lock, led_state.scroll_lock, led_state.compose, led_state.kana);
    return true;
}
