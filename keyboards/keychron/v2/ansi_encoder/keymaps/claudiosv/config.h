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

#pragma once

#define NO_DEBUG
#define NO_PRINT
#define USER_PRINT

#define RGB_MATRIX_MODE_NAME_ENABLE
#define RGB_MATRIX_SLEEP
// 60000ms = 1 minute, 600000ms = 10 minutes
#define RGB_MATRIX_TIMEOUT 600000
#define ENABLE_COMPILE_KEYCODE
#define RGB_MATRIX_DEFAULT_ON true
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR // Sets the default mode, if none has been set
// RGB_MATRIX_TYPING_HEATMAP
// RGB_MATRIX_SOLID_REACTIVE_SIMPLE,   // Pulses keys hit to hue & value then fades value out
//     RGB_MATRIX_SOLID_REACTIVE,      // Static single hue, pulses keys hit to shifted hue then fades to current hue
//     RGB_MATRIX_SOLID_REACTIVE_WIDE,       // Hue & value pulse near a single key hit then fades value out
//     RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE,  // Hue & value pulse near multiple key hits then fades value out
//     RGB_MATRIX_SOLID_REACTIVE_CROSS,      // Hue & value pulse the same column and row of a single key hit then fades value out
//     RGB_MATRIX_SOLID_REACTIVE_MULTICROSS, // Hue & value pulse the same column and row of multiple key hits then fades value out
//     RGB_MATRIX_SOLID_REACTIVE_NEXUS,      // Hue & value pulse away on the same column and row of a single key hit then fades value out
//     RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS,
// RGB Matrix Hue: 08, Saturation: cf, Value: 3f

#define RGB_MATRIX_DEFAULT_HUE 8 // Sets the default hue value, if none has been set
#define RGB_MATRIX_DEFAULT_SAT 207 // Sets the default saturation value, if none has been set
#define RGB_MATRIX_DEFAULT_VAL 63 // Sets the default brightness value, if none has been set
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#define RGB_MATRIX_TYPING_HEATMAP_SPREAD 40
#define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT 16
// #define RGB_MATRIX_TYPING_HEATMAP_SLIM
#define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 32



// By default, all debug (*dprint*) print (*print*, *xprintf*), and user print (*uprint*) messages will be enabled. This will eat up a significant portion of the flash and may make the keyboard .hex file too big to program.

// To disable debug messages (*dprint*) and reduce the .hex file size, include `#define NO_DEBUG` in your `config.h` file.

// To disable print messages (*print*, *xprintf*) and user print messages (*uprint*) and reduce the .hex file size, include `#define NO_PRINT` in your `config.h` file.

// To disable print messages (*print*, *xprintf*) and **KEEP** user print messages (*uprint*), include `#define USER_PRINT` in your `config.h` file (do not also include `#define NO_PRINT` in this case).

// To see the text, open `hid_listen` and enjoy looking at your printed messages.

// **NOTE:** Do not include *uprint* messages in anything other than your keymap code. It must not be used within the QMK system framework. Otherwise, you will bloat other people's .hex files.

// #define RGB_MATRIX_DEFAULT_ON true // Sets the default enabled state, if none has been set
// #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT // Sets the default mode, if none has been set

// #undef ENABLE_RGB_MATRIX_ALPHAS_MODS
// #undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #undef ENABLE_RGB_MATRIX_BREATHING
// #undef ENABLE_RGB_MATRIX_BAND_SAT
// #undef ENABLE_RGB_MATRIX_BAND_VAL
// #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #undef ENABLE_RGB_MATRIX_CYCLE_ALL
// #undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #undef ENABLE_RGB_MATRIX_DUAL_BEACON
// #undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #undef ENABLE_RGB_MATRIX_FLOWER_BLOOMING
// #undef ENABLE_RGB_MATRIX_RAINDROPS
// #undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #undef ENABLE_RGB_MATRIX_HUE_BREATHING
// #undef ENABLE_RGB_MATRIX_HUE_PENDULUM
// #undef ENABLE_RGB_MATRIX_HUE_WAVE
// #undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// #undef ENABLE_RGB_MATRIX_PIXEL_FLOW
// #undef ENABLE_RGB_MATRIX_PIXEL_RAIN

// #undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #undef ENABLE_RGB_MATRIX_SPLASH
// #undef ENABLE_RGB_MATRIX_MULTISPLASH
// #undef ENABLE_RGB_MATRIX_SOLID_SPLASH
// #undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
