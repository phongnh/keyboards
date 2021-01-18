#pragma once

#undef  MANUFACTURER
#define MANUFACTURER Interdox Wireless
#undef  PRODUCT
#define PRODUCT      Interdox_Wireless
#undef  DESCRIPTION
#define DESCRIPTION  q.m.k. keyboard firmware for Interdox Wireless

// Copy from ErgoDox EZ
#define MOUSEKEY_INTERVAL    20
#define MOUSEKEY_DELAY       0
#define MOUSEKEY_TIME_TO_MAX 5
#define MOUSEKEY_MAX_SPEED   5
#define MOUSEKEY_WHEEL_DELAY 0

#define TAPPING_TERM    200
#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)

// Always send Escape if Alt is pressed
#define GRAVE_ESC_ALT_OVERRIDE
// Always send Escape if Control is pressed
#define GRAVE_ESC_CTRL_OVERRIDE
// Always send Escape if GUI is pressed
#define GRAVE_ESC_GUI_OVERRIDE

#undef  DEBOUNCE
#define DEBOUNCE 35
