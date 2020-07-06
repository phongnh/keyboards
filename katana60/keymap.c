#include QMK_KEYBOARD_H


enum katana60_layers {
    _BASE,
    _QWERTY,
    _NUMPAD,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};


enum katana60_keycodes {
    EPRM = SAFE_RANGE,
};

#define BASE    DF(_BASE)
#define QWERTY  DF(_QWERTY)
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define NUMPAD  TG(_NUMPAD)
#define MOU_SCL LT(_MOUSE, KC_SCLN)     // Turn on _MOUSE layer when held, ; when tapped
#define MOU_O   LT(_MOUSE, KC_O)        // Turn on _MOUSE layer when held, o when tapped
#define MOU_S   LT(_MOUSE, KC_S)        // Turn on _MOUSE layer when held, s when tapped
#define LWR_SPC LT(_LOWER, KC_SPC)      // Turn on _LOWER layer when held, Space when tapped
#define LWR_BSP LT(_LOWER, KC_BSPC)     // Turn on _LOWER layer when held, Backspace when tapped
#define RSE_SPC LT(_RAISE, KC_SPC)      // Turn on _RAISE layer when held, Space when tapped
#define RSE_ENT LT(_RAISE, KC_ENT)      // Turn on _RAISE layer when held, Enter when tapped
#define ADJ_GRV LT(_ADJUST, KC_GRV)     // Turn on _ADJUST layer when held, ` when tapped
#define ADJ_TIL LT(_ADJUST, KC_TILD)    // Turn on _ADJUST layer when held, ~ when tapped
#define ADJ_BSL LT(_ADJUST, KC_BSLS)    // Turn on _ADJUST layer when held, \ when tapped
#define CTL_BSP LCTL_T(KC_BSPC)         // Left Control when held, Backspace when tapped
#define CTL_ESC LCTL_T(KC_ESC)          // Left Control when held, Esc when tapped
#define CTL_Z   LCTL_T(KC_Z)            // Left Control when held, z when tapped
#define CTL_SCL LCTL_T(KC_SCLN)         // Left Control when held, ; when tapped
#define CTL_SLS RCTL_T(KC_SLSH)         // Right Control when held, / when tapped
#define GUI_QUO RGUI_T(KC_QUOT)         // Right Gui when held, ' when tapped
#define GUI_DQT RGUI_T(KC_DQT)          // Right Gui when held, " when tapped
#define GUI_MIN RGUI_T(KC_MINS)         // Right Gui when held, - when tapped
#define GUI_ENT RGUI_T(KC_ENT)          // Right Gui when held, Enter when tapped
#define SFT_ENT RSFT_T(KC_ENT)          // Right Shift when held, Enter when tapped
#define SFT_QUO RSFT_T(KC_QUOT)         // Right Shift when held, " when tapped


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_EQL,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    NUMPAD,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,          KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_DEL,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, SFT_ENT,
        ADJ_TIL, KC_LCTL, KC_LALT, KC_LGUI,          LWR_SPC,          KC_BSPC,      RSE_SPC,     ADJ_GRV, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_QWERTY] = LAYOUT(
        KC_GESC, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    NUMPAD,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,          KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_ENT,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_DEL,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, SFT_QUO,
        ADJ_TIL, KC_LCTL, KC_LALT, KC_LGUI,          LWR_SPC,          KC_BSPC,      RSE_SPC,     ADJ_BSL, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_NUMPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_PAST, KC_PMNS, _______, _______, _______, _______,
        _______, _______, _______, KC_MS_U, _______, _______, _______,          KC_7,    KC_8,    KC_9,    KC_PPLS, _______, _______, _______,
        _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,          KC_4,    KC_5,    KC_6,    KC_PPLS, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_PENT, _______, _______, _______,
        _______, _______, _______, _______,          KC_BTN1,          _______,        KC_P0,     KC_PDOT, KC_PENT, _______, _______, _______
    ),

    [_LOWER] = LAYOUT(
        RESET,   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,          _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,          _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, GUI_DQT,
        _______, KC_PLUS, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, _______, _______, _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
        _______, _______, _______, _______,          LOWER,            BASE,        RSE_ENT,      _______, _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
        RESET,   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,          _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,          _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, GUI_QUO,
        _______, KC_PLUS, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, _______, _______, _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
        _______, _______, _______, _______,          LWR_BSP,          BASE,        RAISE,        _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        RESET,   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, KC_UP,   _______, _______, _______, _______,          _______, _______, _______, KC_UP,   _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, AG_NORM,          AG_SWAP, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,          _______,          EPRM,         _______,     _______, _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT(
        _______, _______, BASE,    QWERTY,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, KC_BTN3, KC_MS_U, KC_BTN2, _______, _______,          _______, _______, KC_BTN2, KC_WH_U, KC_BTN3, _______,  _______,
        KC_CAPS, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, AG_NORM,          AG_SWAP, KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,  _______,
        _______, _______, _______, _______,          _______,          EPRM,         _______,     _______, _______, _______, _______,  _______
    ),

    /*
     * ,--------------------------------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
     * |--------------------------------------------------------------------------------------------------------|
     * |          |      |      |      |      |      |      |      |      |      |      |      |      |         |
     * |--------------------------------------------------------------------------------------------------------|
     * |       |      |      |      |      |      |      ||||||      |      |      |      |      |      |       |
     * |--------------------------------------------------------------------------------------------------------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
     * |--------------------------------------------------------------------------------------------------------|
     * |      |       |       |       |                 |      |             |      |      |      |      |      |
     * `--------------------------------------------------------------------------------------------------------'
     *
     * [_SAMPLE] = LAYOUT(
     *     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______,          _______,          _______,      _______,     _______, _______, _______, _______, _______
     * ),
     */
};

uint32_t layer_state_set_user(uint32_t state)
{
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    switch (keycode) {
    case EPRM:
        if (record->event.pressed) {
            eeconfig_init();
        }
        return false;
        break;
    }
    return true;
};
