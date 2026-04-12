#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _SYM,
    _NAV,
    _NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        MO(_NAV),LCTL_T(KC_A),LSFT_T(KC_S),LALT_T(KC_D),LGUI_T(KC_F),KC_G,  KC_H,RGUI_T(KC_J),RALT_T(KC_K),RSFT_T(KC_L),RCTL_T(KC_SCLN),RSFT_T(KC_QUOT),
        LSFT_T(KC_TAB), KC_Z, KC_X, KC_C,  KC_V,    KC_B,    KC_MUTE,      KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
                 KC_LALT, KC_LGUI, MEH_T(KC_SPC),  KC_NO,                         KC_NO,   KC_LCTL, MO(_SYM),MO(_NUM)
    ),
    [_SYM] = LAYOUT(
        KC_PERC, KC_HASH, KC_PIPE, KC_AMPR, KC_ASTR,                       KC_GRV,  KC_QUOT, KC_DQUO, KC_P,    S(KC_P),
        KC_TRNS, KC_LABK, KC_SLSH, KC_EQL,  KC_RABK, KC_PLUS,             KC_MINS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE,
        KC_TRNS, KC_CIRC, KC_AT,   KC_QUES, KC_EXLM, KC_DLR,  KC_MUTE,   KC_NO,   KC_UNDS, KC_LPRN, KC_RPRN, KC_TILD, KC_SLSH, KC_BSLS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                         KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_NAV] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_F15,  KC_F16,  KC_TRNS,                      KC_DEL,  KC_PGUP, KC_UP,   KC_HOME, KC_TRNS,
        KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_TRNS,            KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,   KC_NO,   KC_TRNS, KC_PGDN, KC_TRNS, KC_END,  KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                         KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_NUM] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,                        KC_ASTR, KC_7,    KC_8,    KC_9,    KC_SLSH,
        KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_BSPC,            KC_PLUS, KC_4,    KC_5,    KC_6,    KC_0,    KC_EQL,
        KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_MUTE,   KC_NO,   KC_MINS, KC_1,    KC_2,    KC_3,    KC_DOT,  KC_COMM,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                         KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_SYM]  = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_NAV]  = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_NUM]  = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
};
#endif
