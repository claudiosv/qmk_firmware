/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "version.h"
#include "print.h"
// #include "rgb_matrix.h"

// clang-format off

enum layers{
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _FN2,
    _FN3
};

#define ENCODER_MAP_KEY_DELAY 10
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define MAC_CTL_UNDRS C(S(KC_MINS))
// ⌃ + ⇧ + - (Sends Underscore with Control)
#define MAC_CTL_UPPER C(S(KC_EQL))
// ⌃ + ⇧ + = (Sends Underscore with Control)
#define MAC_CTL_PIPE C(S(KC_BSLS))
// ⌃ + ⇧ + \ (Sends Pipe with Control)

// #define MAC_OPT_MINUS S(A(KC_MINS))
// #define MAC_OPT_PLUS S(A(KC_EQL))
// #define MAC_OPT_ S(A(KC_EQL))

// #define MAC_OPT_PLUS  S(A(KC_EQL)) // ⌥ + ⇧ + = (Plus)
// #define MAC_OPT_MINUS S(A(KC_MINS)) // ⌥ + ⇧ + - (Minus)

// https://docs.qmk.fm/keycodes#quantum-keycodes
// https://docs.qmk.fm/cli_commands#qmk-console
// https://docs.qmk.fm/features/command#configuration
// Fn+C = db toggle
// Fn+esc = bootloader
// Fn+K, then V = print version
// Fn+K, then B = print brightness/saturation/value of RGB Matrix
// Fn+N, NKRO toggle
// Fn+M, print make
// Fn+entr, reboot
// Fn+P, clear eeprom
// QK_MAKE		Sends qmk compile -kb (keyboard) -km (keymap), or qmk flash if shift is held. Puts keyboard into bootloader mode if shift & control are held

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_67(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MUTE,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        MO(_FN3), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME,
                  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
                           KC_LCTL, KC_LOPT, KC_LCMD, KC_SPC, KC_RCMD, MO(_FN1), MO(_FN2), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [WIN_BASE] = LAYOUT_ansi_67(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MUTE,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        MO(_FN3), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME,
                  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
                           KC_LCTL, KC_LWIN, KC_LALT, KC_SPC, KC_RALT, MO(_FN2), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN1] = LAYOUT_ansi_67(
        QK_BOOT,  KC_BRID, KC_BRIU, KC_NO,   KC_NO,   RM_VALD, RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,   _______, _______,
        RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, _______, _______, _______, _______, EE_CLR,  _______, _______,   _______, _______,
        _______, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD, _______, _______, QK_LEAD, _______, _______, _______, QK_REBOOT, _______,
                 _______, _______, _______, DB_TOGG, _______, _______, _______, QK_MAKE, _______, _______, _______, _______,   _______,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FN2] = LAYOUT_ansi_67(
        KC_GRV,  KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RM_VALD, RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
        RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD, _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FN3] = LAYOUT_ansi_67(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, MAC_CTL_PIPE,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, _______, _______,
        _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_END,  _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    // [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    // [_FN1]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    // [_FN2]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    // [_FN3]   = { ENCODER_CCW_CW(_______, _______)}
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN2]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    // [WIN_BASE] = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    // [_FN1]     = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    // [_FN2]     = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    // [_FN3]     = {ENCODER_CCW_CW(LCMD(KC_PMNS), LCMD(KC_PPLS))}};
    // [_FN3]     = {ENCODER_CCW_CW(LCMD(KC_PMNS), LCMD(KC_PPLS))}};
    [_FN3]     = {ENCODER_CCW_CW(MAC_CTL_UNDRS, MAC_CTL_UPPER)}};
#endif // ENCODER_MAP_ENABLE

// clang-format on
// clang-format { ColumnLimit: 80, BinPackArguments: false, AlignOperands: true
// }

void config_debug_rgb_matrix(void) {
    uprintf("rgb_matrix_config EEPROM\n");
    uprintf("rgb_matrix_config.enable = %d\n", rgb_matrix_config.enable);
#ifdef RGB_MATRIX_MODE_NAME_ENABLE
    uprintf("rgb_matrix_config.mode = %d (%s)\n",
            rgb_matrix_config.mode,
            rgb_matrix_get_mode_name(rgb_matrix_config.mode));
#else
    uprintf("rgb_matrix_config.mode = %d\n", rgb_matrix_config.mode);
#endif // RGB_MATRIX_MODE_NAME_ENABLE
    uprintf("rgb_matrix_config.hsv.h = %d\n", rgb_matrix_config.hsv.h);
    uprintf("rgb_matrix_config.hsv.s = %d\n", rgb_matrix_config.hsv.s);
    uprintf("rgb_matrix_config.hsv.v = %d\n", rgb_matrix_config.hsv.v);
    uprintf("rgb_matrix_config.speed = %d\n", rgb_matrix_config.speed);
    uprintf("rgb_matrix_config.flags = %d\n", rgb_matrix_config.flags);
}

// static bool    last_rgb_state;
// static hsv_t   leader_hsv       = {HSV_MAGENTA};

static uint8_t last_rgb_mode;
static uint8_t last_rgb_state;
static hsv_t   last_rgb_hsv;
// static rgb_t leader_rgb       = (rgb_t){RGB_MAGENTA};
static bool is_leader_active = false;
static bool success          = false;

static uint32_t leader_result_timer = 0; // Tracks how long to show Green/Red
static rgb_t    result_rgb;              // Stores the Success/Fail color

#define LAYER_INDICATOR_RGB RGB_GREEN
#define LEADER_INDICATOR_RGB RGB_RED

#define LAYER_INDICATOR_HSV HSV_GOLDENROD
#define LEADER_INDICATOR_HSV HSV_RED

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (is_leader_active) {
        rgb_matrix_set_color_all(RGB_BLACK);
        rgb_matrix_set_color(48, LEADER_INDICATOR_RGB); // V
        rgb_matrix_set_color(49, LEADER_INDICATOR_RGB); // B
        return false;
    } else if (!timer_expired32(timer_read32(), leader_result_timer)) {
        rgb_matrix_set_color_all(result_rgb.r, result_rgb.g, result_rgb.b);
        return false;
    }

    if (get_highest_layer(layer_state) > 1) {
        uint8_t layer = get_highest_layer(layer_state);

        hsv_t hsv = {LAYER_INDICATOR_HSV};
        if (hsv.v > rgb_matrix_get_val()) {
            hsv.v = rgb_matrix_get_val();
        }
        rgb_t rgb = hsv_to_rgb(hsv);
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if ((index >= led_min) && (index < led_max) &&
                    (index != NO_LED)) {
                    if (keymap_key_to_keycode(layer, (keypos_t){col, row}) >
                        KC_TRNS) {
                        rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
                    } else {
                        rgb_matrix_set_color(index, RGB_BLACK);
                    }
                }
            }
        }
    }

    return false;
}

void leader_start_user(void) {
    is_leader_active = true;
    // 1. Suspend the current animation engine
    last_rgb_mode  = rgb_matrix_get_mode();
    last_rgb_state = rgb_matrix_is_enabled();
    last_rgb_hsv   = rgb_matrix_get_hsv();

    rgb_matrix_enable_noeeprom();
    // rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    // rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);

    // leader_rgb = (rgb_t){RGB_MAGENTA};
}

void leader_end_user(void) {
    // leader_rgb = (rgb_t){RGB_GREEN};
    // rgb_matrix_sethsv_noeeprom(HSV_GREEN);
    // rgb_matrix_update_pwm_buffers();

    if (leader_sequence_one_key(KC_V)) {
        success             = true;
        result_rgb          = success ? (rgb_t){RGB_GREEN} : (rgb_t){RGB_RED};
        leader_result_timer = timer_read32() + 1500; // Show result for 500ms

        // rgb_matrix_sethsv_noeeprom(HSV_GREEN);
        // leader is currently FN+K (fn next to right cmd),
        // so this will print the version when you press FN+K, then V
        // Leader, v  => print keyboard/keymap/version
        // const qmk_v_str = "QMK: " QMK_KEYBOARD "/" QMK_KEYMAP " @ "
        // QMK_VERSION " | " QMK_BUILDDATE; uprintln(QMK_V_STR);
        uprintln("QMK: " QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
                 " | " QMK_BUILDDATE);

        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
                                 " | " QMK_BUILDDATE);
    }

    if (leader_sequence_one_key(KC_B)) {
        success             = true;
        result_rgb          = success ? (rgb_t){RGB_GREEN} : (rgb_t){RGB_RED};
        leader_result_timer = timer_read32() + 1500; // Show result for 500ms
        // rgb_matrix_sethsv_noeeprom(HSV_GREEN);
        // leader is currently FN+K (fn next to right cmd),
        // so this will print the version when you press FN+K, then V
        // Leader, v  => print keyboard/keymap/version
        config_debug_rgb_matrix();

        char full_str[50];
        snprintf(full_str,
                 sizeof(full_str),
                 "Hue: %u, Sat: %u, Val: %u",
                 rgb_matrix_get_hue(),
                 rgb_matrix_get_sat(),
                 rgb_matrix_get_val());

        SEND_STRING(full_str);
    }

    if (!success) {
        result_rgb          = success ? (rgb_t){RGB_GREEN} : (rgb_t){RGB_RED};
        leader_result_timer = timer_read32() + 500; // Show result for 500ms
    }

    // if (success) {
    //     wait_ms(500);
    // } else {
    //     leader_rgb = (rgb_t){RGB_RED};
    //     rgb_matrix_sethsv_noeeprom(HSV_RED);
    //     rgb_matrix_update_pwm_buffers();
    //     wait_ms(500);
    // }

    is_leader_active = false;
    success          = false;

    rgb_matrix_mode_noeeprom(last_rgb_mode);
    rgb_matrix_sethsv_noeeprom(last_rgb_hsv.h, last_rgb_hsv.s, last_rgb_hsv.v);

    if (!last_rgb_state) {
        rgb_matrix_disable_noeeprom();
    } else {
        rgb_matrix_enable_noeeprom();
    }
}

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     if (is_leader_active) {
//         // if (leader_hsv) {
//         // rgb_matrix_sethsv_noeeprom(leader_hsv);
//         // }
//         rgb_matrix_set_color_all(leader_rgb.r, leader_rgb.g, leader_rgb.b);
//         rgb_matrix_set_color(48, LEADER_INDICATOR_RGB); // V
//         rgb_matrix_set_color(49, LEADER_INDICATOR_RGB); // B
//         // leader_hsv
//     } else {
//         if (get_highest_layer(layer_state) > 1) {
//             uint8_t layer = get_highest_layer(layer_state);

//             hsv_t hsv = {LAYER_INDICATOR_HSV};
//             if (hsv.v > rgb_matrix_get_val()) {
//                 hsv.v = rgb_matrix_get_val();
//             }
//             rgb_t rgb = hsv_to_rgb(hsv);
//             for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
//                 for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
//                     uint8_t index = g_led_config.matrix_co[row][col];

//                     if ((index >= led_min) && (index < led_max) &&
//                         (index != NO_LED)) {
//                         if (keymap_key_to_keycode(layer, (keypos_t){col,
//                         row}) >
//                             KC_TRNS) {
//                             // rgb_matrix_set_color(index,
//                             LAYER_INDICATOR_RGB); rgb_matrix_set_color(index,
//                             rgb.r, rgb.g, rgb.b);
//                         } else {
//                             rgb_matrix_set_color(index, RGB_BLACK);
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     // hsv_t hsv = {LEADER_INDICATOR_HSV};
//     // uprintf("Leader active! matrix val: %u, hsv req val: %u\n",
//     //         rgb_matrix_get_val(),
//     //         hsv.v);

//     // if (hsv.v > rgb_matrix_get_val()) {
//     //     hsv.v = rgb_matrix_get_val();
//     // }
//     // rgb_t rgb = hsv_to_rgb(hsv);

//     // uprintf("Setting indicators to HSV: %u, %u, %u -> RGB: %u, %u, %u\n",
//     //         hsv.h,
//     //         hsv.s,
//     //         hsv.v,
//     //         rgb.r,
//     //         rgb.g,
//     //         rgb.b);
//     // rgb_matrix_set_color(48, rgb.r, rgb.g, rgb.b); // V
//     // rgb_matrix_set_color(49, rgb.r, rgb.g, rgb.b); // B

//     // RGB_MATRIX_INDICATOR_SET_COLOR(48, 255, 0, 0); // V
//     // RGB_MATRIX_INDICATOR_SET_COLOR(49, 255, 0, 0); // B
//     // RGB_MATRIX_INDICATOR_SET_COLOR(50, 255,255, 0);

//     return false;
// }

// void leader_start_user(void) {
//     is_leader_active = true;
//     // 1. Suspend the current animation engine
//     // rgb_matrix_disable_noeeprom();
//     // uint8_t mode = rgb_matrix_get_mode();
//     // uint8_t enabled = rgb_matrix_is_enabled();

//     last_rgb_mode  = rgb_matrix_get_mode();
//     last_rgb_state = rgb_matrix_is_enabled();
//     last_rgb_hsv   = rgb_matrix_get_hsv();

//     // uprintf("Last mode/state: %u, %u\n", last_rgb_mode, last_rgb_state);

//     // print_val_bin8(last_rgb_mode);
//     // print_val_bin8(last_rgb_state);
//     // uprintf("Last HSV: %u, %u, %u\n", last_rgb_hsv.h, last_rgb_hsv.s,
//     // last_rgb_hsv.v);

//     rgb_matrix_enable_noeeprom();
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
//     rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
//     // leader_hsv = {HSV_MAGENTA};
//     leader_rgb = (rgb_t){RGB_MAGENTA};
//     // rgb_matrix_sethsv_noeeprom(leader_hsv);
//     // rgb_matrix_sethsv_noeeprom(HSV_OFF);

//     // hsv_t hsv = {LEADER_INDICATOR_HSV};
//     // if (hsv.v > rgb_matrix_get_val()) {
//     //     hsv.v = rgb_matrix_get_val();
//     // }
//     // rgb_t rgb = hsv_to_rgb(hsv);
//     // // RGB_MATRIX_INDICATOR_SET_COLOR(48, 255, 0, 0); // V
//     // rgb_matrix_set_color(48, rgb.r, rgb.g, rgb.b); // V
//     // rgb_matrix_set_color(49, rgb.r, rgb.g, rgb.b); // B
//     // rgb_matrix_set_color(48, LEADER_INDICATOR_RGB); // V
//     // rgb_matrix_set_color(49, LEADER_INDICATOR_RGB); // B

//     // 2. Set all LEDs to Red
//     // Note: This works because even when disabled, we can force a buffer
//     update
//     // rgb_matrix_set_color_all(255, 0, 0);

//     // rgb_matrix_mode_noeeprom(mode);
//     // if (!enabled) {
//     //     rgb_matrix_disable_noeeprom();
//     // }
// }

// // QMK_V_STR = PSTR("QMK: " QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " |
// "
// // QMK_BUILDDATE); send_string_with_delay
// void leader_end_user(void) {
//     leader_rgb = (rgb_t){RGB_GREEN};
//     rgb_matrix_sethsv_noeeprom(HSV_GREEN);

//     if (leader_sequence_one_key(KC_V)) {
//         // rgb_matrix_sethsv_noeeprom(HSV_GREEN);
//         // leader is currently FN+K (fn next to right cmd),
//         // so this will print the version when you press FN+K, then V
//         // Leader, v  => print keyboard/keymap/version
//         // const qmk_v_str = "QMK: " QMK_KEYBOARD "/" QMK_KEYMAP " @ "
//         // QMK_VERSION " | " QMK_BUILDDATE; uprintln(QMK_V_STR);
//         uprintln("QMK: " QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
//                  " | " QMK_BUILDDATE);
//         // send_string_with_delay(QMK_V_STR);

//         SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
//                                  " | " QMK_BUILDDATE);
//         success = true;
//     }

//     if (leader_sequence_one_key(KC_B)) {
//         // rgb_matrix_sethsv_noeeprom(HSV_GREEN);
//         // leader is currently FN+K (fn next to right cmd),
//         // so this will print the version when you press FN+K, then V
//         // Leader, v  => print keyboard/keymap/version
//         config_debug_rgb_matrix();

//         char full_str[50];
//         snprintf(full_str,
//                  sizeof(full_str),
//                  "Hue: %u, Sat: %u, Val: %u",
//                  rgb_matrix_get_hue(),
//                  rgb_matrix_get_sat(),
//                  rgb_matrix_get_val());
//         // uprintf("%s\n", full_str);

//         SEND_STRING(full_str);
//         success = true;
//     }

//     if (success) {
//         // rgb_matrix_sethsv_noeeprom(HSV_GREEN);
//         wait_ms(500);
//     } else {
//         leader_rgb = (rgb_t){RGB_RED};
//         rgb_matrix_sethsv_noeeprom(HSV_RED);
//         wait_ms(500);
//     }

//     is_leader_active = false;

//     // uprintf("Last mode/state: %u, %u\n", last_rgb_mode, last_rgb_state);
//     // print_val_bin8(last_rgb_mode);
//     // print_val_bin8(last_rgb_state);
//     // uprintf("Last HSV: %u, %u, %u\n", last_rgb_hsv.h, last_rgb_hsv.s,
//     // last_rgb_hsv.v);

//     // 3. Resume the previous animation/state
//     // rgb_matrix_enable_noeeprom();
//     // 5. Restore original state using the shared variables
//     rgb_matrix_mode_noeeprom(last_rgb_mode);
//     rgb_matrix_sethsv_noeeprom(last_rgb_hsv.h, last_rgb_hsv.s,
//     last_rgb_hsv.v);

//     if (!last_rgb_state) {
//         rgb_matrix_disable_noeeprom();
//     } else {
//         rgb_matrix_enable_noeeprom();
//     }
// }
