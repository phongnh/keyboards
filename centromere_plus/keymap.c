#include "centromere_plus.h"

enum centromere_plus_layers {
    _DEFAULT,  /* Centromere Plus default layer */
    _BASE_V0,  /* Centromere Plus default layer but swapped - and = */
    _BASE_V1,  /* Adapted from my ErgoDoxEZ mappings - Space is on left side and Enter is on right side and use Backspace with Right Shift */
    _IRIS,     /* Adapted from Iris - Space is on left side and Enter is on right side, Backespace is at Backslash position, ` and \ are placed at topmost of thumb keys */
    _ATREUS,   /* Adapted from Atreus 44 - Backspace/Ctrl on left side and Space is on right side */
    _ERGODOX,  /* ErgoDox EZ Style */
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};

enum centromere_plus_keycodes {
    EPRM = SAFE_RANGE,
};

// clang-format off
// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS
#define DEFAULT DF(_DEFAULT)
#define BASE_V0 DF(_BASE_V0)
#define BASE_V1 DF(_BASE_V1)
#define IRIS    DF(_IRIS)
#define ATREUS  DF(_ATREUS)
#define ERGODOX DF(_ERGODOX)
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define LWR_SPC LT(_LOWER, KC_SPC)      // Turn on _LOWER layer when held, Space when tapped
#define LWR_BSP LT(_LOWER, KC_BSPC)     // Turn on _LOWER layer when held, Backspace when tapped
#define RSE_ENT LT(_RAISE, KC_ENT)      // Turn on _RAISE layer when held, Enter when tapped
#define RSE_SPC LT(_LOWER, KC_SPC)      // Turn on _RAISE layer when held, Space when tapped
#define RSE_BSP LT(_RAISE, KC_BSPC)     // Turn on _RAISE layer when held, Backspace when tapped
#define MOU_SCL LT(_MOUSE, KC_SCLN)     // Turn on _MOUSE layer when held, ; when tapped
#define CTL_ESC LCTL_T(KC_ESC)          // Left Control when held, Esc when tapped
#define CTL_Z   LCTL_T(KC_Z)            // Left Control when held, z when tapped
#define CTL_BSP RCTL_T(KC_BSPC)         // Left Control when held, Backspace when tapped
#define CTL_SLS RCTL_T(KC_SLSH)         // Right Control when held, / when tapped
#define GUI_QUO RGUI_T(KC_QUOT)         // Right Gui when held, ' when tapped
#define SFT_ENT RSFT_T(KC_ENT)          // Right Shift when held, Enter when tapped
#define SFT_BSP RSFT_T(KC_BSPC)         // Right Shift when held, Backspace when tapped
#define SFT_BSL RSFT_T(KC_BSLS)         // Right Shift when held, \ when tapped
#define CAG_PUP LCAG_T(KC_PGUP)         // Ctrl+Alt+Gui when held, Page Up when tapped
#define CAG_PDN LCAG_T(KC_PGDN)         // Ctrl+Alt+Gui when held, Page Down when tapped
// clang-format on

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = {
        { KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_MINS,  KC_EQL,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  SFT_ENT },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC,  KC_HOME,  KC_SPC,   XXXXXXX,  XXXXXXX,  KC_ENT,   KC_END,   RSE_ENT,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },

    [_BASE_V0] = {
        { KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_EQL,   KC_MINS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  SFT_ENT },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC,  KC_HOME,  KC_SPC,   XXXXXXX,  XXXXXXX,  KC_ENT,   KC_END,   RSE_ENT,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },

    [_BASE_V1] = {
        { KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_DEL,   KC_GRV,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  SFT_BSP },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC,  KC_HOME,  KC_SPC,   XXXXXXX,  XXXXXXX,  KC_ENT,   KC_END,   RSE_ENT,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },

    [_IRIS] = {
        { KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_DEL,   KC_GRV,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  SFT_ENT },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC,  KC_GRV,   KC_SPC,   XXXXXXX,  XXXXXXX,  KC_ENT,   KC_BSLS,  RSE_ENT,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },

    [_ATREUS] = {
        { KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_DEL,   KC_GRV,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  SFT_ENT },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_BSP,  KC_HOME,  CTL_BSP,  XXXXXXX,  XXXXXXX,  KC_SPC,   KC_END,   RSE_SPC,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },

    [_ERGODOX] = {
        { KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_DEL,   KC_ESC,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS },
        { CTL_BSP,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  KC_RSFT },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC,  KC_GRV,   KC_SPC,   XXXXXXX,  XXXXXXX,  KC_ENT,   KC_TAB,   RSE_ENT,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },

    [_LOWER] = {
        { KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  XXXXXXX,  XXXXXXX,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL  },
        { KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     XXXXXXX,  XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS },
        { KC_CAPS,  XXXXXXX,  KC_LEFT,  KC_RGHT,  KC_UP,    XXXXXXX,  KC_HOME,  KC_END,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DOWN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  LOWER,    KC_PGUP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,   KC_PGDN,  RAISE,    XXXXXXX,  XXXXXXX,  XXXXXXX }
    },

    [_RAISE] = {
        { KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    XXXXXXX,  XXXXXXX,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11  },
        { XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,  KC_PIPE },
        { KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,  KC_HOME,  KC_END,   XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  LOWER,    KC_PGUP,  KC_BSPC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGDN,  RAISE,    XXXXXXX,  XXXXXXX,  XXXXXXX }
    },

    [_ADJUST] = {
        { RESET,    DEFAULT,  BASE_V1,  IRIS,     ATREUS,   ERGODOX,  AG_NORM,  AG_SWAP,  BASE_V0,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { KC_PWR,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F14,   KC_F15,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  KC_VOLD,  KC_VOLU,  KC_MUTE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX }
    },

    [_MOUSE] = {
        { RESET,    DEFAULT,  BASE_V1,  IRIS,     ATREUS,   ERGODOX,  AG_NORM,  AG_SWAP,  BASE_V0,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  KC_BTN3,  KC_MS_U,  KC_BTN2,  XXXXXXX,  KC_F14,   KC_F15,   XXXXXXX,  KC_BTN2,  KC_WH_U,  KC_BTN3,  XXXXXXX,  XXXXXXX },
        { KC_CAPS,  KC_BTN2,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN1,  XXXXXXX,  XXXXXXX,  KC_BTN1,  KC_WH_L,  KC_WH_D,  KC_WH_R,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  KC_VOLD,  KC_VOLU,  KC_MUTE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┐      ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │       │       │       │       │       │       │       │      │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤      ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │      │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤      ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │      │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼─┬─────┴─┐  ┌─┴─────┬─┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │││       │  │       │││       │       │       │       │       │       │
     * └───────┴───────┴───────┴─────┬─┴─────┬─┴─────┬─┼─┼───────┤  ├───────┼─┼─┬─────┴─┬─────┴─┬─────┴───────┴───────┴───────┘
     *                               │       │       │││││       │  │       │││││       │       │
     *                               └───────┴───────┴─┴─┴───────┘  └───────┴─┴─┴───────┴───────┘
     * [_SAMPLE] = {
     *     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
     *     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
     *     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
     *     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
     *     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX }
     * },
     */
};
// clang-format on


uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
    }
    return true;
}
