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
                           KC_LCTL, KC_LWIN, KC_LALT, KC_SPC, KC_RALT, MO(_FN1), MO(_FN2), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN1] = LAYOUT_ansi_67( // Utility, Mouse & App Launchers (No Media Keys)
        KC_SLEP, KC_BRID, KC_BRIU, KC_CALC, KC_WSCH, KC_MYCM, _______, _______, _______, _______, _______, _______, _______, KC_WAKE, _______,
        _______, KC_TASK, KC_FLXP, _______, _______, _______, MS_WHLU, MS_BTN1, MS_UP,   MS_BTN2, _______, _______, _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FN2] = LAYOUT_ansi_67( // Hardware, RGB & System Config
        QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   RM_PREV, RM_TOGG, RM_NEXT, RM_HUED, RM_HUEU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DB_TOGG, QK_MAKE,
        _______, RM_VALD, RM_VALU, RM_SATD, RM_SATU, KC_NO, KC_NO, KC_NO, KC_NO, QK_LEAD, KC_NO, KC_NO, EE_CLR,  QK_REBOOT,
                 KC_NO,   RM_SPDD, RM_SPDU, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, _______, _______, KC_NO, KC_NO, KC_NO
    ),

    [_FN3] = LAYOUT_ansi_67( // Magic Caps Lock (Navigation, F-Keys & Media Restored)
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, MAC_CTL_PIPE,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,
        _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, KC_END,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN2]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
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

static uint8_t last_rgb_mode;
static uint8_t last_rgb_state;
static hsv_t   last_rgb_hsv;
static bool    is_leader_active = false;
static bool    success          = false;

static uint32_t leader_result_timer = 0; // Tracks how long to show Green/Red
static rgb_t    result_rgb;              // Stores the Success/Fail color

#define LAYER_INDICATOR_RGB RGB_GREEN
#define LEADER_INDICATOR_RGB RGB_RED

#define LAYER_INDICATOR_HSV HSV_GOLDENROD
#define LEADER_INDICATOR_HSV HSV_RED

// void keyboard_post_init_user(void) {
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
//     rgb_matrix_sethsv_noeeprom(HSV_OFF);
// debug_enable = true;
// debug_matrix = true;   // Uncomment if you need matrix scanning details
// debug_keyboard = true; // Uncomment if you need raw keypress details
// }

hsv_t hsvs[] = {{HSV_RED}, {HSV_BLUE}, {HSV_GREEN}};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (is_leader_active) {
        rgb_matrix_set_color_all(RGB_BLACK);
        rgb_matrix_set_color(47, LEADER_INDICATOR_RGB); // V
        rgb_matrix_set_color(48, LEADER_INDICATOR_RGB); // V
        rgb_matrix_set_color(49, LEADER_INDICATOR_RGB); // B
        return false;
    } else if (!timer_expired32(timer_read32(), leader_result_timer)) {
        rgb_matrix_set_color_all(result_rgb.r, result_rgb.g, result_rgb.b);
        return false;
    }

    if (rgb_matrix_is_enabled() && get_highest_layer(layer_state) > 1) {
        uint8_t layer = get_highest_layer(layer_state);

        // hsv_t hsv = {LAYER_INDICATOR_HSV};
        hsv_t hsv = hsvs[layer % 3];
        // Adjust brightness to current brightness
        // if (hsv.v > rgb_matrix_get_val()) {
        //     hsv.v = rgb_matrix_get_val();
        // }
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

    // RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);
    // if (host_keyboard_led_state().caps_lock) {
    //     RGB_MATRIX_INDICATOR_SET_COLOR(5, 255, 255, 255); // assuming caps
    //     lock is at led #5
    // } else {
    //     RGB_MATRIX_INDICATOR_SET_COLOR(5, 0, 0, 0);
    // }

    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_RED);
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
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_V)) {
        success             = true;
        result_rgb          = success ? (rgb_t){RGB_RED} : (rgb_t){RGB_GREEN};
        leader_result_timer = timer_read32() + 1500; // Show result for 500ms

        uprintln("QMK: " QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
                 " | " QMK_BUILDDATE);

        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
                                 " | " QMK_BUILDDATE);
    }

    if (leader_sequence_one_key(KC_B)) {
        success             = true;
        result_rgb          = success ? (rgb_t){RGB_GREEN} : (rgb_t){RGB_RED};
        leader_result_timer = timer_read32() + 1500; // Show result for 500ms

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
        uprintf("%s\r\n", full_str);
        send_string(full_str);
    }

    if (leader_sequence_one_key(KC_C)) {
        success             = true;
        result_rgb          = success ? (rgb_t){RGB_GREEN} : (rgb_t){RGB_RED};
        leader_result_timer = timer_read32() + 1500; // Show result for 500ms
        const char *effect_name =
            rgb_matrix_get_mode_name(rgb_matrix_get_mode());
        uprintf("%s\r\n", effect_name);
        send_string(effect_name);
    }

    if (!success) {
        result_rgb          = success ? (rgb_t){RGB_GREEN} : (rgb_t){RGB_RED};
        leader_result_timer = timer_read32() + 500; // Show result for 500ms
    }

    is_leader_active = false;
    success          = false;

    // rgb_matrix_mode_noeeprom(last_rgb_mode);
    // rgb_matrix_sethsv_noeeprom(last_rgb_hsv.h, last_rgb_hsv.s,
    // last_rgb_hsv.v);

    // if (!last_rgb_state) {
    //     rgb_matrix_disable_noeeprom();
    // } else {
    //     rgb_matrix_enable_noeeprom();
    // }
}

void matrix_scan_user(void) {
    // If the timer is active and has passed the expiration time
    if (leader_result_timer != 0 && timer_elapsed32(leader_result_timer) > 0) {
        // Restore previous LED states
        rgb_matrix_mode_noeeprom(last_rgb_mode);
        rgb_matrix_sethsv_noeeprom(
            last_rgb_hsv.h, last_rgb_hsv.s, last_rgb_hsv.v);

        if (!last_rgb_state) {
            rgb_matrix_disable_noeeprom();
        } else {
            rgb_matrix_enable_noeeprom();
        }

        // Reset timer so it doesn't trigger again
        leader_result_timer = 0;
    }
}
