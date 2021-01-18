/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

/* RGB LEDs */
#undef RGBLED_NUM
#define RGBLED_NUM 16
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
// #define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LAYERS
#define RGBLIGHT_SLEEP

/* Tap Dance */
#define TAPPING_TERM 200

/* To get layer 5 on VIA */
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// /* One Shot */
// #define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
// #define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */
