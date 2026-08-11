#pragma once

// #define RGB_MATRIX_ENABLE

#define RGB_MATRIX_TIMEOUT 60000
#define TAP_HOLD_CAPS_DELAY 200
#define TAP_CODE_DELAY 0
//TAP_CODE_DELAY 100
#define TAPPING_TERM 100
//default is 5ms
#define DEBOUNCE 20

// #define NO_DEBUG
// #define NO_PRINT
// #define USER_PRINT

#define RGB_MATRIX_MODE_NAME_ENABLE
#define RGB_MATRIX_SLEEP
// 60000ms = 1 minute, 600000ms = 10 minutes
// #define RGB_MATRIX_TIMEOUT 600000
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
