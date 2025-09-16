#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _ADJUST,
    _SHRT,
    _WIN,
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
#define WIN LM(_WIN, MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ferris_hlc(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                                  SHRT,        NAV_BSPC,      SYM_SPC,     ONE_SFT,
        KC_MUTE,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_MUTE,      KC_NO,        KC_NO,        KC_NO,        KC_NO
    ),
    [_NAV] = LAYOUT_ferris_hlc(
        QWERTY , _______, _______, G(KC_SPC), _______,KC_PGUP, KC_TAB , KC_UP, KC_BSPC,  KC_ESC ,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, MY_LANG, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,KC_ENT,
        G(KC_Z), G(KC_X), G(KC_C), G(KC_V), C(KC_C),QK_REP , KC_TAB ,_______,_______,_______,
                                                  _______, _______, WIN, _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_SYM] = LAYOUT_ferris_hlc(
      KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC, _______, KC_EQL , KC_PLUS, KC_MINS, KC_UNDS,
      KC_ASTR, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, KC_PIPE, KC_QUOT, KC_DQUO, KC_GRV , KC_ASTR,
      _______, KC_RBRC, KC_RCBR, KC_RPRN, KC_CIRC, _______, KC_TILD, _______, _______, KC_BSLS,
                                                  _______, _______, _______, _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_ADJUST] = LAYOUT_ferris_hlc(
        RM_TOGG,      RM_NEXT,      RM_HUEU,      RM_SATU,      RM_VALU,      RM_SPDU,      MS_BTN1,      MS_WHLU,      MS_BTN2,      KC_TRNS,
        KC_TRNS,      MS_BTN2,      KC_NO,        MS_BTN1,      KC_TRNS,      KC_TRNS,      MS_LEFT,      MS_DOWN,      MS_UP,        MS_RGHT,
        KC_TRNS,      RM_PREV,      RM_HUED,      RM_SATD,      RM_VALD,      RM_SPDD,      MS_WHLL,      MS_WHLD,      MS_WHLR,      KC_TRNS,
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_SHRT] = LAYOUT_ferris_hlc(
        G(KC_Q),      G(KC_W),      G(KC_E),      G(KC_R),      G(KC_T),      _______,      _______,      _______,      _______,      _______,
        G(KC_A),      G(KC_S),      G(KC_D),      G(KC_F),      G(KC_G),      _______,      _______,      _______,      _______,      _______,
        G(KC_Z),      G(KC_X),      G(KC_C),      G(KC_V),      G(KC_B),      _______,      _______,      _______,      _______,      _______,
                                                  _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_WIN] = LAYOUT_ferris_hlc(
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        _______,      S(KC_TAB),       _______,     KC_TAB,       _______,      _______,      _______,      _______,      _______,      _______,
        _______,      _______,   _______,       _______,     _______,      _______,      _______,      _______,      _______,      _______,
                                                  _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    )
};
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_NAV] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_SYM] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_ADJUST] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_SHRT] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_WIN] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}
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
const uint16_t PROGMEM lang_combo[] = {KC_D, KC_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(lang_combo, MY_LANG),
    // COMBO(copy_combo, G(KC_C)),
    // COMBO(paste_combo, G(KC_V)),
    // COMBO(cut_combo, G(KC_X)),
    // COMBO(undo_combo, G(KC_Z)),
    // COMBO(redo_combo, G(S(KC_Z))),
    // COMBO(save_combo, G(KC_S)),
    // COMBO(nav_combo, TO(_NAV)),
    // COMBO(sym_combo, OSL(_SYM)),
    // COMBO(arr_combo, MY_ARR),
    // COMBO(tmp_combo, MY_TMP),
    // COMBO(ent_combo, KC_ENT),
    // COMBO(bkspc_combo, KC_BSPC),
    // COMBO(lang_combo, MY_LANG),
    // COMBO(arr_combo, MY_ARR),
    // COMBO(eql_combo, KC_EQL),
    // COMBO(colon_combo, KC_COLN),
    // COMBO(jl_combo, KC_QUOT),
    // COMBO(sf_combo, KC_DQT),
};