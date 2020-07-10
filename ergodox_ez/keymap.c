#include QMK_KEYBOARD_H
#include "version.h"

enum ergodox_ez_layers {
    _BASE,
    _ARROW,
    _EDGE,
    _ERGO,
    _MOD,
    _LOWER,
    _RAISE,
    _SYMBOL,
    _MEDIA,
};

enum ergodox_ez_custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,
    VRSN,
    EPRM,
};

// clang-format off
#define BASE    DF(_BASE)
#define ARROW   DF(_ARROW)
#define EDGE    DF(_EDGE)
#define ERGO    DF(_ERGO)
#define TT_SYM  TT(_SYMBOL)
#define SYM_GRV LT(_SYMBOL, KC_GRV)
#define SYM_LBR LT(_SYMBOL, KC_LBRC)
#define SYM_RBR LT(_SYMBOL, KC_RBRC)
#define MOD_ESC LT(_MOD, KC_ESC)
#define LWR_LCB LT(_LOWER, KC_LCBR)
#define RSE_RCB LT(_RAISE, KC_RCBR)
#define MED_SCL LT(_MEDIA, KC_SCLN)
#define ALL_LCB ALL_T(KC_LCBR)
#define MEH_RCB MEH_T(KC_RCBR)
#define GUI_QUO GUI_T(KC_QUOT)
#define GUI_RGH GUI_T(KC_RGHT)
#define ALT_UP  ALT_T(KC_UP)
#define ALT_APP ALT_T(KC_APP)
#define ALT_SFT LALT(KC_LSFT)
#define CTL_Z   CTL_T(KC_Z)
#define CTL_SLS CTL_T(KC_SLSH)
#define CTL_ESC CTL_T(KC_ESC)
#define SFT_ENT SFT_T(KC_ENT)
#define CAG_QUO LCAG_T(KC_QUOT)
// clang-format on

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ergodox_pretty(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,     KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    SYM_LBR,     SYM_RBR, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    MED_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    LWR_LCB,     RSE_RCB, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, KC_RSFT,
        SYM_GRV, CAG_QUO, ALT_SFT, KC_LEFT, GUI_RGH,                                         ALT_UP,  KC_DOWN, KC_LBRC, KC_RBRC, TT_SYM,
                                                     ALT_APP, KC_LGUI,     KC_LALT, CTL_ESC,
                                                              KC_HOME,     KC_PGUP,
                                            KC_SPC,  KC_BSPC, KC_END,      KC_PGDN, KC_TAB,  KC_ENT
    ),

    [_ARROW] = LAYOUT_ergodox_pretty(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,     KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    SYM_LBR,     SYM_RBR, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        MOD_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    MED_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    LWR_LCB,     RSE_RCB, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, KC_RSFT,
        SYM_GRV, CAG_QUO, ALT_SFT, KC_LEFT, GUI_RGH,                                         ALT_UP,  KC_DOWN, KC_LBRC, KC_RBRC, TT_SYM,
                                                     ALT_APP, KC_LGUI,     KC_LALT, CTL_ESC,
                                                              KC_HOME,     KC_PGUP,
                                            KC_SPC,  KC_BSPC, KC_END,      KC_PGDN, KC_TAB,  KC_ENT
    ),

    [_EDGE] = LAYOUT_ergodox_pretty(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,     KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    SYM_LBR,     SYM_RBR, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        MOD_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    MED_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    LWR_LCB,     RSE_RCB, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, SFT_ENT,
        SYM_GRV, CAG_QUO, ALT_SFT, KC_LEFT, GUI_RGH,                                         ALT_UP,  KC_DOWN, KC_LBRC, KC_RBRC, TT_SYM,
                                                     ALT_APP, KC_LGUI,     KC_LALT, CTL_ESC,
                                                              KC_HOME,     KC_PGUP,
                                            KC_BSPC, KC_ENT,  KC_END,      KC_PGDN, KC_TAB,  KC_SPC
    ),

    [_ERGO] = LAYOUT_ergodox_pretty(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,     KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    SYM_LBR,     SYM_RBR, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    MED_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    ALL_LCB,     MEH_RCB, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, KC_RSFT,
        SYM_GRV, CAG_QUO, ALT_SFT, KC_LEFT, GUI_RGH,                                         ALT_UP,  KC_DOWN, KC_LBRC, KC_RBRC, TT_SYM,
                                                     ALT_APP, KC_LGUI,     KC_LALT, CTL_ESC,
                                                              KC_HOME,     KC_PGUP,
                                            KC_SPC,  KC_BSPC, KC_END,      KC_PGDN, KC_TAB,  KC_ENT
    ),

    [_MOD] = LAYOUT_ergodox_pretty(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_PGDN, KC_UP,   KC_PGUP, _______, _______, _______,     _______, _______, KC_PGDN, KC_UP,   KC_PGUP, KC_PSCR, KC_HOME,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                       _______, KC_LEFT, KC_DOWN, KC_DOWN, _______, KC_END,
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______,
                                            _______, _______, _______,     _______, _______, _______
    ),

    [_LOWER] = LAYOUT_ergodox_pretty(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,     _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQT,
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,     _______, KC_UNDS, KC_PLUS, KC_LT,   KC_GT,   KC_QUES, _______,
        _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______,
                                            _______, _______, _______,     _______, KC_DEL,  _______
    ),

    [_RAISE] = LAYOUT_ergodox_pretty(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,     _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQT,
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,     _______, KC_UNDS, KC_PLUS, KC_LT,   KC_GT,   KC_QUES, _______,
        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,                                         _______, _______, _______, _______, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______,
                                            _______, KC_DEL,  _______,     _______, _______, _______
    ),

    [_SYMBOL] = LAYOUT_ergodox_pretty(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_DEL,  KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,     _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        KC_CAPS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                        KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_PSCR,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,     _______, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        _______, _______, _______, _______, _______,                                         EPRM,    KC_DOT,  KC_0,    KC_EQL,  _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______,
                                            _______, _______, _______,     _______, _______, _______
    ),

    [_MEDIA] = LAYOUT_ergodox_pretty(
        RESET,   BASE,    ARROW,   EDGE,    ERGO,    _______, AG_NORM,     AG_SWAP, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
        _______, _______, KC_BTN3, KC_MS_U, KC_BTN2, _______, KC_F14,      KC_F15,  _______, KC_BTN2, KC_WH_U, KC_BTN3, _______, _______,
        KC_CAPS, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,                       KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, AG_NORM, AG_SWAP,                                         KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______,
                                            KC_BTN1, KC_BTN2, _______,     _______, KC_BTN1, KC_BTN2
    ),

    /*
     * [_SAMPLE] = LAYOUT_ergodox_pretty(
     *     _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
     *                                                  _______, _______,     _______, _______,
     *                                                           _______,     _______,
     *                                         _______, _______, _______,     _______, _______, _______
     * ),
     */
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
// void matrix_init_user(void) {
// }

// Runs constantly in the background, in a loop.
// void matrix_scan_user(void) {
// }

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_led_all_set(LED_BRIGHTNESS_LO);

    uint8_t layer = biton32(state);
    switch (layer) {
        case _SYMBOL:
            ergodox_right_led_1_on();
            break;
        case _MEDIA:
            ergodox_right_led_2_on();
            break;
        default:
            break;
    }

    // capslock
    if (host_keyboard_leds() & (3 << USB_LED_CAPS_LOCK)) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }

    return state;
}
