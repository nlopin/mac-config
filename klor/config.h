// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#ifdef POINTING_DEVICE_ENABLE
#    define POINTING_DEVICE_SCLK_PIN D0
#    define POINTING_DEVICE_SDIO_PIN D1
#endif

#ifdef AUDIO_ENABLE
#    define AUDIO_PIN B5
#endif

// Home row mods: longer tapping term so fast typing doesn't trigger mods
#define TAPPING_TERM 250
// If a key is tapped and then held within QUICK_TAP_TERM, repeat the tap (no mod)
#define QUICK_TAP_TERM 150

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#    define OLED_FONT_H "keyboards/geigeigeist/klor/glcdfont.c"
#endif
