#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _ADJUST,
    _SHRT,
    _WIN,
    _NUM,
    _FUNC,
};

enum custom_keycodes {
    MY_ARR = SAFE_RANGE,
    MY_TMP,
    MY_LANG,
};

// Aliases for readability
#define QWERTY TO(_QWERTY)
#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define SYM_SPC LT(_SYM, KC_SPC)
#define ONE_SFT OSM(MOD_LSFT)
#define SHRT MO(_SHRT)
#define NUM MO(_NUM)
#define ADJUST MO(_ADJUST)
#define WIN LM(_WIN, MOD_LGUI)
#define ONE_CMD OSM(MOD_LGUI)
#define ONE_CTL OSM(MOD_LCTL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ferris_hlc(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                                  SHRT,        NAV_BSPC,      SYM_SPC,     ONE_SFT,
        KC_MUTE,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_MUTE,      KC_NO,        KC_NO,        KC_NO,        KC_NO
    ),
    [_NAV] = LAYOUT_ferris_hlc(
        A(QK_GESC), G(S(KC_N)), _______, G(KC_SPC), _______,KC_PGUP, KC_TAB , KC_UP, KC_BSPC,  KC_ESC ,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, MY_LANG, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,KC_ENT,
        G(KC_Z), G(KC_X), G(KC_C), G(KC_V), C(KC_C),QK_REP , KC_TAB ,_______,_______,TO(_ADJUST),
                                                  _______, _______,  NUM, WIN,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_SYM] = LAYOUT_ferris_hlc(
      KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC, _______, KC_EQL , KC_PLUS, KC_MINS, KC_UNDS,
      KC_ASTR, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, KC_PIPE, KC_QUOT, KC_DQUO, KC_GRV , KC_ASTR,
      _______, KC_RBRC, KC_RCBR, KC_RPRN, KC_CIRC, _______, KC_TILD, _______, _______, KC_BSLS,
                                                  _______, NUM, _______, _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_ADJUST] = LAYOUT_ferris_hlc(
        TO(_QWERTY),  RM_NEXT,      RM_HUEU,      RM_SATU,      RM_VALU,      RM_SPDU,      MS_BTN1,      MS_WHLU,      MS_BTN2,      KC_TRNS,
        RM_TOGG,      MS_BTN2,      KC_NO,        MS_BTN1,      KC_TRNS,      KC_TRNS,      MS_LEFT,      MS_DOWN,      MS_UP,        MS_RGHT,
        KC_TRNS,      RM_PREV,      RM_HUED,      RM_SATD,      RM_VALD,      RM_SPDD,      MS_WHLL,      MS_WHLD,      MS_WHLR,      KC_TRNS,
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_SHRT] = LAYOUT_ferris_hlc(
        G(KC_Q),      G(KC_W),      G(KC_E),      G(KC_R),      G(KC_T), MEH(KC_Y),MEH(KC_U),MEH(KC_I),MEH(KC_O),MEH(KC_P),
        G(KC_A),      G(KC_S),      G(KC_D),      G(KC_F),      G(KC_G), MEH(KC_H),MEH(KC_J),MEH(KC_K),MEH(KC_L),MEH(KC_SCLN),
        G(KC_Z),      G(KC_X),      G(KC_C),      G(KC_V),      G(KC_B), MEH(KC_N),MEH(KC_M),MEH(KC_COMM),MEH(KC_DOT),MEH(KC_SLSH),
                                                  _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_WIN] = LAYOUT_ferris_hlc(
        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      _______,      _______,      _______,      _______,      _______,
        KC_GRV,      S(KC_TAB),       KC_Q,     KC_TAB,       _______,      _______,      _______,      _______,      _______,      _______,
        _______,      _______,   _______,       _______,     _______,      _______,      _______,      _______,      _______,      _______,
                                                  _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_NUM] = LAYOUT_ferris_hlc(
        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , KC_F5, 
        KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10,
        _______,      _______,   _______,       _______,     _______,      KC_F11,  KC_F12,  _______,      _______,      _______, 
                                                  _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
};
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_NAV] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_SYM] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_ADJUST] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_SHRT] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_WIN] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_NUM] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MY_ARR:
        if (record->event.pressed) {
            SEND_STRING("=>");
        }
        break;
    case MY_TMP:
        if (record->event.pressed) {
            SEND_STRING("${");
        }
        break;
    case MY_LANG:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            wait_ms(10);
            register_code(KC_SPC);
            wait_ms(10);
            unregister_code(KC_SPC);
            wait_ms(10);
            unregister_code(KC_LCTL);
        }
        break;
    }
    return true;
};


const uint16_t PROGMEM esc_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM lang_combo[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM lcmd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM rcmd_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM ctrl_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM rctrl_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM win_combo[] = {KC_M, KC_K, COMBO_END};
const uint16_t PROGMEM arr_combo[] = {KC_U, KC_O, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, LT(_SYM, KC_ESC)),
    COMBO(tab_combo, LT(_SYM, KC_TAB)),
    COMBO(lang_combo, MY_LANG),
    COMBO(lcmd_combo, ONE_CMD),
    COMBO(rcmd_combo, ONE_CMD),
    COMBO(ctrl_combo, ONE_CTL),
    COMBO(rctrl_combo, ONE_CTL),
    COMBO(win_combo, WIN),
    COMBO(arr_combo, MY_ARR)
};
