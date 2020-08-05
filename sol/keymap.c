#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum sol_layers {
    _BASE = 0,
    _ARROW,
    _EDGE,
    _SYMBOL,
    _MOD,
    _FN,
    _ADJUST,
    _MOUSE,
};

enum sol_keycodes {
    RGBRST = SAFE_RANGE,
    RGB_MENU,
    EPRM,
};

// clang-format off
#define BASE    DF(_BASE)
#define ARROW   DF(_ARROW)
#define EDGE    DF(_EDGE)
#define MOD     MO(_MOD)
#define FN      MO(_FN)
#define ADJUST  MO(_ADJUST)
#define FN_ESC  LT(_FN, KC_ESC)
#define SYM_GRV LT(_SYMBOL, KC_GRV)
#define MOU_SCL LT(_MOUSE, KC_SCLN)     // Turn on _MOUSE layer when held, ; when tapped
#define GUI_QUO GUI_T(KC_QUOT)
#define GUI_TAB GUI_T(KC_TAB)
#define CTL_ESC CTL_T(KC_ESC)
#define CTL_Z   CTL_T(KC_Z)
#define CTL_SLS CTL_T(KC_SLSH)
#define CTL_ENT CTL_T(KC_ENT)
#define SFT_ENT SFT_T(KC_ENT)
#define RGB_RST RGBRST
#define RGB_RMO RGB_RMOD
// clang-format on

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT( \
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL,  KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO, \
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, SFT_ENT, \
        SYM_GRV, KC_LALT, KC_LGUI, MOD,     ADJUST,  KC_SPC,  KC_LCBR, KC_RCBR, KC_ENT,  FN,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
                                                     KC_SPC,  KC_BSPC, KC_TAB,  KC_ENT   \
    ),

    [_ARROW] = LAYOUT( \
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL,  KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
        FN_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO, \
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, SFT_ENT, \
        SYM_GRV, KC_LALT, KC_LGUI, MOD,     ADJUST,  KC_SPC,  KC_LCBR, KC_RCBR, KC_ENT,  FN,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
                                                     KC_SPC,  KC_BSPC, KC_TAB,  KC_ENT   \
    ),

    [_EDGE] = LAYOUT( \
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL,  KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
        FN_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO, \
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, SFT_ENT, \
        SYM_GRV, KC_LALT, KC_LGUI, MOD,     ADJUST,  KC_BSPC, KC_LCBR, KC_RCBR, KC_SPC,  FN,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
                                                     KC_BSPC, CTL_ENT, GUI_TAB, KC_SPC   \
    ),

    [_SYMBOL] = LAYOUT( \
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_PSCR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, KC_UP,   KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_HOME, \
        KC_CAPS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______, _______, KC_DOWN, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_END,  \
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, KC_AMPR, KC_P1,   KC_P2,   KC_P3,   KC_BSLS, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT,  KC_P0,   KC_PEQL, _______, \
                                                     _______, _______, _______, _______  \
    ),

    [_MOD] = LAYOUT( \
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_PSCR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
        _______, KC_PGDN, KC_UP,   KC_PGUP, RESET,   _______, KC_NLCK, KC_SLCK, _______, KC_PGDN, KC_UP,   KC_PGUP, KC_PSCR, KC_HOME, \
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_END,  \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                     _______, _______, _______, _______  \
    ),

    [_FN] = LAYOUT( \
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_PSCR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
        _______, KC_PGDN, KC_UP,   KC_PGUP, RESET,   _______, _______, KC_SLCK, _______, KC_PGDN, KC_UP,   KC_PGUP, KC_PSCR, KC_HOME, \
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_END,  \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                     _______, _______, _______, _______  \
    ),

    [_ADJUST] = LAYOUT( \
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
        RGB_RST, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD, AG_NORM, AG_SWAP, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, \
        RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_RMO, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PDOT, KC_P0,   _______, _______, \
                                                     _______, _______, _______, _______  \
    ),

    [_MOUSE] = LAYOUT( \
        RESET,   BASE,    ARROW,   EDGE,    _______, _______, AG_NORM, AG_SWAP, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, \
        _______, _______, KC_BTN3, KC_MS_U, KC_BTN2, _______, KC_F14,  KC_F15,  _______, KC_BTN2, KC_WH_U, KC_BTN3, _______, _______, \
        KC_CAPS, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______, _______, KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        EPRM,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                     _______, _______, _______, _______  \
    ),

   /*
    * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┐
    * │       │       │       │       │       │       │       │                  │       │       │       │       │       │       │       │
    * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    * │       │       │       │       │       │       │       │                  │       │       │       │       │       │       │       │
    * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    * │       │       │       │       │       │       │       │                  │       │       │       │       │       │       │       │
    * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    * │       │       │       │       │       │       │       │                  │       │       │       │       │       │       │       │
    * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    * │       │       │       │       │       │││││││││       │       │  │       │       │││││││││       │       │       │       │       │
    * └───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┤  ├───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────┘
    *                                                 │       │       │  │       │       │
    *                                                 └───────┴───────┘  └───────┴───────┘
    *
    * [_SAMPLE] = LAYOUT( \
    *     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    *     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    *     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    *     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    *     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    *                                                  _______, _______, _______, _______  \
    * )
    */
};
// clang-format on

// For RGBRST Keycode
#if defined(RGB_MATRIX_ENABLE)
void rgb_matrix_increase_flags(void) {
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
        } break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
        } break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
        } break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
        } break;
    }
}

void rgb_matrix_decrease_flags(void) {
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
        } break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_set_color_all(0, 0, 0);
        } break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
        } break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_enable_noeeprom();
        } break;
    }
}
#endif

#ifdef RGB_OLED_MENU
uint8_t rgb_encoder_state = 4;

typedef void (*rgb_matrix_f)(void);

// clang-format off
const rgb_matrix_f rgb_matrix_functions[6][2] = {
    { rgb_matrix_increase_hue,   rgb_matrix_decrease_hue   },
    { rgb_matrix_increase_sat,   rgb_matrix_decrease_sat   },
    { rgb_matrix_increase_val,   rgb_matrix_decrease_val   },
    { rgb_matrix_increase_speed, rgb_matrix_decrease_speed },
    { rgb_matrix_step,           rgb_matrix_step_reverse   },
    { rgb_matrix_increase_flags, rgb_matrix_decrease_flags }
};
// clang-format on
#endif

#ifdef ENCODER_ENABLE
static pin_t encoders_pad_a[] = ENCODERS_PAD_A;
#define NUMBER_OF_ENCODERS (sizeof(encoders_pad_a) / sizeof(pin_t))

// clang-format off
const uint16_t PROGMEM encoders[][NUMBER_OF_ENCODERS * 2][2] = {
    [_BASE] = ENCODER_LAYOUT( \
        KC_VOLU, KC_VOLD,
        KC_VOLU, KC_VOLD
    ),
    [_EDGE] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_ARROW] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_SYMBOL] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_MOD] = ENCODER_LAYOUT( \
        _______, _______,
        KC_PGUP, KC_PGDN
    ),
    [_FN] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_ADJUST] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_MOUSE] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    )
};
// clang-format on

void encoder_update_user(uint8_t index, bool clockwise) {
    if (!is_keyboard_master()) {
        return;
    }

#ifdef RGB_OLED_MENU
    if (index == RGB_OLED_MENU) {
        (*rgb_matrix_functions[rgb_encoder_state][clockwise])();
        return;
    }
#endif

    uint8_t  layer = biton32(layer_state);
    uint16_t keycode = pgm_read_word(&encoders[layer][index][clockwise]);
    while (keycode == KC_TRANSPARENT && layer > 0) {
        layer--;
        if ((layer_state & (1 << layer)) != 0)
            keycode = pgm_read_word(&encoders[layer][index][clockwise]);
    }
    if (keycode != KC_TRANSPARENT) {
        tap_code16(keycode);
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    static uint16_t reset_timer;
    switch (keycode) {
        case RGBRST:
#if defined(RGBLIGHT_ENABLE)
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
#elif defined(RGB_MATRIX_ENABLE)
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
#endif
            return false;
            break;
        case RESET:
            if (record->event.pressed) {
                reset_timer = timer_read();
            } else if (timer_elapsed(reset_timer) >= 500) {
                reset_keyboard();
            }
            return false;
            break;
#if defined(RGB_MATRIX_ENABLE) && defined(KEYBOARD_rgbkb_sol_rev2)
        case RGB_TOG:
            if (record->event.pressed) {
                rgb_matrix_increase_flags();
            }
            return false;
            break;
#endif
        case RGB_MENU:
#ifdef RGB_OLED_MENU
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    rgb_encoder_state = (rgb_encoder_state - 1);
                    if (rgb_encoder_state > 5) {
                        rgb_encoder_state = 5;
                    }
                } else {
                    rgb_encoder_state = (rgb_encoder_state + 1) % 6;
                }
            }
#endif
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

// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}

static void render_logo(void) {
    // clang-format off
    static const char PROGMEM sol_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0
    };
    // clang-format on
    oled_write_P(sol_logo, false);
}

static void render_status(void) {
    // Render to mode icon
    // clang-format off
    static const char PROGMEM sol_icon[] = {
        0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
        0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
        0xdb, 0xdc, 0xdd, 0xde, 0xdf, 0
    };
    // clang-format on
    oled_write_P(sol_icon, false);

    // Define layers here
    oled_write_P(PSTR("Layer"), false);
    uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
    switch (layer) {
        case _BASE:
            oled_write_P(PSTR("BASE "), false);
            break;
        case _ARROW:
            oled_write_P(PSTR("ARROW"), false);
            break;
        case _EDGE:
            oled_write_P(PSTR("EDGE "), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("SYM  "), false);
            break;
        case _MOD:
            oled_write_P(PSTR("MOD  "), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN   "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJ  "), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOUSE"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_state = host_keyboard_leds();
    oled_write_P(PSTR("-----"), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR("NUMLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("     "), false);

#ifdef RGB_OLED_MENU
    static char buffer[31] = {0};
    snprintf(buffer, sizeof(buffer), "h%3d s%3d v%3d s%3d m%3d e%3d ", rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s,
             rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode, rgb_matrix_get_flags());
    buffer[4 + rgb_encoder_state * 5] = '<';

    oled_write_P(PSTR("-----"), false);
    oled_write(buffer, false);
#endif
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
        oled_scroll_left();
    }
}

#endif
