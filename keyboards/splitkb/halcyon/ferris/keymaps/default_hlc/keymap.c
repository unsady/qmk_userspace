#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _ADJUST,
};

// Aliases for readability
#define QWERTY TO(_QWERTY)
#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define NAV_BSPC LT(_NAV, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ferris_hlc(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                                  KC_P0,        KC_BSPC,      KC_SPC,       KC_P1,
        KC_MUTE,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_MUTE,      KC_NO,        KC_NO,        KC_NO,        KC_NO
    ),
    [_NAV] = LAYOUT_ferris_hlc(
        QWERTY , _______, _______, G(KC_SPC), _______,KC_PGUP, KC_TAB , KC_UP, KC_BSPC,  KC_ESC ,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,KC_ENT,
        G(KC_Z), G(KC_X), G(KC_C), G(KC_V), C(KC_C),QK_REP , KC_TAB ,_______,_______,_______,
                                                  _______, _______, _______, _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_SYM] = LAYOUT_ferris_hlc(
        KC_TRNS,      KC_TRNS,      KC_PGUP,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        KC_LEFT,      KC_UP,        KC_DOWN,      KC_RGHT,      KC_TRNS,      KC_TRNS,      KC_LGUI,      KC_NO,        LCTL(KC_LALT), LCA(KC_LSFT),
        KC_TRNS,      KC_HOME,      KC_PGDN,      KC_END,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_ADJUST] = LAYOUT_ferris_hlc(
        RM_TOGG,      RM_NEXT,      RM_HUEU,      RM_SATU,      RM_VALU,      RM_SPDU,      MS_BTN1,      MS_WHLU,      MS_BTN2,      KC_TRNS,
        KC_TRNS,      MS_BTN2,      KC_NO,        MS_BTN1,      KC_TRNS,      KC_TRNS,      MS_LEFT,      MS_DOWN,      MS_UP,        MS_RGHT,
        KC_TRNS,      RM_PREV,      RM_HUED,      RM_SATD,      RM_VALD,      RM_SPDD,      MS_WHLL,      MS_WHLD,      MS_WHLR,      KC_TRNS,
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    )
};
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [3] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [5] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [6] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [7] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C


