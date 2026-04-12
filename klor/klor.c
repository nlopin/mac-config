// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

// Big font layer names — 12x16px letters, centered with spacing
// A=80 B=84 E=88 M=8C N=90 S=94 U=98 V=9C Y=A0 C=A4 D=A8 F=AC L=B0 T=B4
static const char PROGMEM base_top[] = {' ',' ',' ',' ',' ', 0x84,0x85,' ',0x80,0x81,' ',0x94,0x95,' ',0x88,0x89, 0};
static const char PROGMEM base_bot[] = {' ',' ',' ',' ',' ', 0x86,0x87,' ',0x82,0x83,' ',0x96,0x97,' ',0x8A,0x8B, 0};
static const char PROGMEM sym_top[]  = {' ',' ',' ',' ',' ',' ', 0x94,0x95,' ',0xA0,0xA1,' ',0x8C,0x8D, 0};
static const char PROGMEM sym_bot[]  = {' ',' ',' ',' ',' ',' ', 0x96,0x97,' ',0xA2,0xA3,' ',0x8E,0x8F, 0};
static const char PROGMEM nav_top[]  = {' ',' ',' ',' ',' ',' ', 0x90,0x91,' ',0x80,0x81,' ',0x9C,0x9D, 0};
static const char PROGMEM nav_bot[]  = {' ',' ',' ',' ',' ',' ', 0x92,0x93,' ',0x82,0x83,' ',0x9E,0x9F, 0};
static const char PROGMEM num_top[]  = {' ',' ',' ',' ',' ',' ', 0x90,0x91,' ',0x98,0x99,' ',0x8C,0x8D, 0};
static const char PROGMEM num_bot[]  = {' ',' ',' ',' ',' ',' ', 0x92,0x93,' ',0x9A,0x9B,' ',0x8E,0x8F, 0};

// Big font modifier labels (8 chars each: XX_XX_XX with spaces between)
// SFT
static const char PROGMEM sft_top[] = {0x94,0x95,' ',0xAC,0xAD,' ',0xB4,0xB5, 0};
static const char PROGMEM sft_bot[] = {0x96,0x97,' ',0xAE,0xAF,' ',0xB6,0xB7, 0};
// CTL
static const char PROGMEM ctl_top[] = {0xA4,0xA5,' ',0xB4,0xB5,' ',0xB0,0xB1, 0};
static const char PROGMEM ctl_bot[] = {0xA6,0xA7,' ',0xB6,0xB7,' ',0xB2,0xB3, 0};
// ALT
static const char PROGMEM alt_top[] = {0x80,0x81,' ',0xB0,0xB1,' ',0xB4,0xB5, 0};
static const char PROGMEM alt_bot[] = {0x82,0x83,' ',0xB2,0xB3,' ',0xB6,0xB7, 0};
// CMD
static const char PROGMEM cmd_top[] = {0xA4,0xA5,' ',0x8C,0x8D,' ',0xA8,0xA9, 0};
static const char PROGMEM cmd_bot[] = {0xA6,0xA7,' ',0x8E,0x8F,' ',0xAA,0xAB, 0};
// blank (8 spaces)
static const char PROGMEM blank8[]  = {' ',' ',' ',' ',' ',' ',' ',' ', 0};

static void render_mod_label(uint8_t col, uint8_t row, const char *top, const char *bot, bool active) {
    oled_set_cursor(col, row);
    oled_write_P(active ? top : blank8, false);
    oled_set_cursor(col, row + 1);
    oled_write_P(active ? bot : blank8, false);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        // Left screen: layer name in big font
        oled_write_ln_P(PSTR(""), false);
        const char *top;
        const char *bot;
        switch (get_highest_layer(layer_state)) {
            case 0: top = base_top; bot = base_bot; break;
            case 1: top = sym_top;  bot = sym_bot;  break;
            case 2: top = nav_top;  bot = nav_bot;  break;
            case 3: top = num_top;  bot = num_bot;  break;
            default: top = base_top; bot = base_bot; break;
        }
        oled_write_ln_P(top, false);
        oled_write_ln_P(bot, false);
    } else {
        // Right screen: modifier quadrants
        // Layout: SFT(top-left) CTL(top-right) ALT(bot-left) CMD(bot-right)
        uint8_t mods = get_mods();
        render_mod_label(1, 1, sft_top, sft_bot, mods & MOD_MASK_SHIFT);
        render_mod_label(12, 1, ctl_top, ctl_bot, mods & MOD_MASK_CTRL);
        render_mod_label(1, 5, alt_top, alt_bot, mods & MOD_MASK_ALT);
        render_mod_label(12, 5, cmd_top, cmd_bot, mods & MOD_MASK_GUI);
    }
    return false;
}
#endif
