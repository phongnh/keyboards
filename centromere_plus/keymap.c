#include "centromere_plus.h"

enum centromere_plus_layers {
    _BASE_V1,  /* My default mappings that is adapted from ErgoDoxEZ - Space is on left side and Enter is on right side */
    _BASE_V2,  /* Same as _BASE_V1 but Backspace is on left side and Space is on right side */
    _BASE_V3,  /* Same as _BASE_V1 but \ and Backspace are swapped */
    _ERGODOX,  /* ErgoDox EZ Style */
    _QWERTY,   /* Centromere Plus default layer */
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};

enum centromere_plus_keycodes {
    EPRM = SAFE_RANGE,
    LOWER,
    RAISE,
    BASE_V1,
    BASE_V2,
    BASE_V3,
    ERGODOX,
    QWERTY,
};

// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS
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
#define CAG_LBR LCAG_T(KC_LBRC)         // Ctrl+Alt+Gui when held, [ when tapped
#define CAG_RBR LCAG_T(KC_RBRC)         // Ctrl+Alt+Gui when held, ] when tapped

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │  Del   │           │   `    │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │   [    │           │   ]    │   Y    │   U    │   I    │   O    │   P    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │  PgUp  │           │  PgDn  │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││  Home  │       │  End   │││  N     │   M    │   ,    │   .    │ / / CTL│Sft/BkSp│
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/ SPC│││││ Space  │       │  Enter │││││RSE/ ENT│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_BASE_V1] = {
        { KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_DEL,   KC_GRV,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  SFT_BSP },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC,  KC_HOME,  KC_SPC,   XXXXXXX,  XXXXXXX,  KC_ENT,   KC_END,   RSE_ENT,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │  Del   │           │   `    │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │   [    │           │   ]    │   Y    │   U    │   I    │   O    │   P    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │  PgUp  │           │  PgDn  │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││  Home  │       │  End   │││  N     │   M    │   ,    │   .    │ / / CTL│Sft/ Ent│
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/BkSp│││││ BkSpace│       │ Space  │││││RSE/ SPC│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_BASE_V2] = {
        { KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_DEL,   KC_GRV,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  SFT_ENT },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_BSP,  KC_HOME,  KC_BSPC,  XXXXXXX,  XXXXXXX,  KC_SPC,   KC_END,   RSE_SPC,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │  Del   │           │   `    │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │   [    │           │   ]    │   Y    │   U    │   I    │   O    │   P    │ BkSpace│
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │  PgUp  │           │  PgDn  │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││  Home  │       │  End   │││  N     │   M    │   ,    │   .    │ / / CTL│Sft / \ │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/ SPC│││││ Space  │       │ Enter  │││││RSE/ ENT│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_BASE_V3] = {
        { KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_DEL,   KC_GRV,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  SFT_BSL },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC,  KC_HOME,  KC_SPC,   XXXXXXX,  XXXXXXX,  KC_ENT,   KC_END,   RSE_ENT,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │  Del   │           │  Esc   │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │   [    │           │   ]    │   Y    │   U    │   I    │   O    │   P    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │BkSp/CTL│   A    │   S    │   D    │   F    │   G    │  PgUp  │           │  PgDn  │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││  Home  │       │  End   │││  N     │   M    │   ,    │   .    │ / / CTL│ Shift  │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/ SPC│││││ Space  │       │ Enter  │││││RSE/ ENT│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_ERGODOX] = {
        { KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_DEL,   KC_ESC,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC },
        { CTL_BSP,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  KC_RSFT },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC,  KC_HOME,  KC_SPC,   XXXXXXX,  XXXXXXX,  KC_ENT,   KC_END,   RSE_ENT,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   `    │   1    │   2    │   3    │   4    │   5    │   -    │           │   =    │   6    │   7    │   8    │   9    │   0    │ BkSpace│
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │   [    │           │   ]    │   Y    │   U    │   I    │   O    │   P    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │  PgUp  │           │  PgDn  │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││  Home  │       │  End   │││  N     │   M    │   ,    │   .    │ / / CTL│ Shift  │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/ SPC│││││ Space  │       │ Enter  │││││RSE/ ENT│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_QWERTY] = {
        { KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_MINS,  KC_EQL,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  KC_RSFT },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC,  KC_HOME,  KC_SPC,   XXXXXXX,  XXXXXXX,  KC_ENT,   KC_END,   RSE_ENT,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   ~    │   !    │   @    │   #    │   $    │   %    │        │           │        │   ^    │   &    │   *    │   (    │   )    │  Del   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │   `    │   1    │   2    │   3    │   4    │   5    │        │           │        │   6    │   7    │   8    │   9    │   0    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  CAPS  │        │  Left  │ Right  │   Up   │        │  APP   │           │  APP   │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │  Down  │        │││  PgUp  │       │  PgDn  │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │ LOWER  │││││        │       │  Del   │││││ RAISE  │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_LOWER] = {
        { KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  XXXXXXX,  XXXXXXX,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL  },
        { KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     XXXXXXX,  XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS },
        { KC_CAPS,  XXXXXXX,  KC_LEFT,  KC_RGHT,  KC_UP,    XXXXXXX,  KC_APP,   KC_APP,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DOWN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  LOWER,    KC_PGUP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,   KC_PGDN,  RAISE,    XXXXXXX,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │  F12   │   F1   │   F2   │   F3   │   F4   │   F5   │        │           │        │   F6   │   F7   │   F8   │   F9   │  F10   │  F11   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │   Up   │        │        │        │        │           │        │        │        │   Up   │        │        │   |    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  CAPS  │ Left   │  Down  │  Right │        │        │  MENU  │           │  MENU  │        │  Left  │  Down  │  Right │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │││  PgUp  │       │  PgDn  │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │ LOWER  │││││ BkSpace│       │        │││││ RAISE  │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_RAISE] = {
        { KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    XXXXXXX,  XXXXXXX,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11  },
        { XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,  KC_PIPE },
        { KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,  KC_MENU,  KC_MENU,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  LOWER,    KC_PGUP,  KC_BSPC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGDN,  RAISE,    XXXXXXX,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │ POWER  │BASE_V1 │BASE_V2 │BASE_V3 │ERGODOX │ QWERTY │  F14   │           │  F15   │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ RESET  │        │        │        │        │        │ AG_NORM│           │ AG_SWAP│        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │  Vol-  │  Vol+  │  Mute  │        │        │ AG_NORM│           │ AG_SWAP│        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │││        │       │        │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │        │││││        │       │        │││││        │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_ADJUST] = {
        { KC_PWR,   BASE_V1,  BASE_V2,  BASE_V3,  ERGODOX,  QWERTY,   KC_F14,   KC_F15,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  AG_NORM,  AG_SWAP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  KC_VOLD,  KC_VOLU,  KC_MUTE,  XXXXXXX,  XXXXXXX,  AG_NORM,  AG_SWAP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │        │           │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │ MClick │  MS_U  │ RClick │        │        │           │        │        │ RClick │  WH_U  │ MClick │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │ LClick │  MS_L  │  MS_D  │  MS_R  │ LClick │        │           │        │ LClick │  WH_L  │  WH_D  │  WH_R  │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │││        │       │        │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │        │││││        │       │        │││││        │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_MOUSE] = {
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  KC_BTN3,  KC_MS_U,  KC_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BTN2,  KC_WH_U,  KC_BTN3,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  KC_BTN2,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN1,  XXXXXXX,  XXXXXXX,  KC_BTN1,  KC_WH_L,  KC_WH_D,  KC_WH_R,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │        │           │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │           │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │           │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │││        │       │        │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │        │││││        │       │        │││││        │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     *
     * [_SAMPLE] = {
     *     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
     *     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
     *     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
     *     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
     *     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX }
     * },
     */
};


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
        case BASE_V1:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE_V1);
            }
            return false;
            break;
        case BASE_V2:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE_V2);
            }
            return false;
            break;
        case BASE_V3:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE_V3);
            }
            return false;
            break;
        case ERGODOX:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_ERGODOX);
            }
            return false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    return;
}
