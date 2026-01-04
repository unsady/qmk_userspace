#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _NUM,
    _ADJUST,
    _SHRT,
    _WIN,
    _FUNC,
    _GAME,
};

enum custom_keycodes {
    MY_ARR = SAFE_RANGE,
    MY_TMP,
    MY_LANG,
    NUMWORD,
};

// NUM WORD state variables
static bool numword_enabled = false;

// Helper function to check if a keycode is a number key
bool is_num_key(uint16_t keycode) {
    return (keycode >= KC_1 && keycode <= KC_0) || 
           (keycode >= KC_KP_1 && keycode <= KC_KP_0) ||
           keycode == KC_DOT || keycode == KC_COMM ||
           keycode == KC_MINUS || keycode == KC_PLUS ||
           keycode == KC_EQUAL ||
           keycode == KC_BSPC || keycode == KC_DEL;
}

// Aliases for readability
#define QWERTY TO(_QWERTY)
#define GAME TO(_GAME)
#define SYM MO(_SYM)
#define NAV LT(_NAV, KC_BSPC)
#define SYM_SPC LT(_SYM, KC_SPC)
#define SHRT MO(_SHRT)
#define NUM MO(_NUM)
#define ADJUST MO(_ADJUST)
#define WIN LM(_WIN, MOD_LGUI)
#define ONE_CMD OSM(MOD_LGUI)
#define ONE_CTL OSM(MOD_LCTL)
#define ONE_ALT OSM(MOD_LALT)
#define ONE_SFT OSM(MOD_LSFT)
#define NUM_WORD NUMWORD
#define WIN_TAB LT(_WIN, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ferris_hlc(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                                  SHRT,        NAV,           SYM_SPC,     ONE_SFT,
        KC_MUTE,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_MUTE,      KC_NO,        KC_NO,        KC_NO,        KC_NO
    ),
    [_NAV] = LAYOUT_ferris_hlc(
        G(KC_SPC), HYPR(KC_W), HYPR(KC_E), HYPR(KC_R), HYPR(KC_T), KC_PGUP, KC_TAB , KC_UP, KC_BSPC,  KC_ESC ,
        ONE_CTL, ONE_ALT, ONE_CMD, ONE_SFT, MY_LANG, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,KC_ENT,
        G(KC_Z), G(KC_X), G(KC_C), G(KC_V), C(KC_C),G(S(KC_N)), KC_TAB , QK_REP,_______,_______,
                                                  _______, _______,  NUM, WIN,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_SYM] = LAYOUT_ferris_hlc(
      KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC, _______, KC_EQL , KC_PLUS, KC_MINS, KC_UNDS,
      KC_ASTR, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, KC_PIPE, KC_QUOT, KC_DQUO, KC_GRV , KC_ASTR,
      _______, KC_RBRC, KC_RCBR, KC_RPRN, KC_CIRC, _______, KC_TILD, _______, _______, KC_BSLS,
                                                  _______, _______, _______, _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_NUM] = LAYOUT_ferris_hlc(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ASTR, KC_7,    KC_8,    KC_9,    KC_SLSH,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PLUS, KC_4,    KC_5,    KC_6,    KC_MINS,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,
                                                  KC_NO,KC_BSPC,_______,KC_0,
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
        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_GRV,      S(KC_TAB),       KC_Q,     KC_TAB,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,   KC_NO,       KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                  _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_ADJUST] = LAYOUT_ferris_hlc(
        TO(_QWERTY),  RM_NEXT,      RM_HUEU,      RM_SATU,      RM_VALU,      RM_SPDU,      MS_BTN1,      MS_WHLU,      MS_BTN2,      KC_TRNS,
        RM_TOGG,      MS_BTN2,      KC_NO,        MS_BTN1,      KC_NO  ,      KC_NO  ,      MS_LEFT,      MS_DOWN,      MS_UP,        MS_RGHT,
        KC_NO  ,      RM_PREV,      RM_HUED,      RM_SATD,      RM_VALD,      RM_SPDD,      MS_WHLL,      MS_WHLD,      MS_WHLR,      KC_NO  ,
                                                  _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_GAME] = LAYOUT_ferris_hlc(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                                  KC_ESC,      KC_SPC,       TO(_QWERTY),      TO(_QWERTY),
        KC_MUTE,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      KC_NO,        KC_NO,        KC_NO,        KC_NO
    ),
};
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_NAV] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_SYM] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_NUM] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_SHRT] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_WIN] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_ADJUST] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_GAME] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C


// Disable all combos in GAME layer
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_GAME)) {
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case NUMWORD:
        if (record->event.pressed) {
            numword_enabled = !numword_enabled;
            if (numword_enabled) {
                layer_on(_NUM);
            } else {
                layer_off(_NUM);
            }
        }
        return false;
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
    case LT(_WIN, KC_SCLN):
        if (!record->tap.count) {
            if (record->event.pressed) {
                layer_on(_WIN);
                register_mods(MOD_BIT(KC_LGUI));
            } else {
                layer_off(_WIN);
                unregister_mods(MOD_BIT(KC_LGUI));
            }
            return false; // блокируем стандартный hold
        }
        return true;             // Return true for normal processing of tap keycode
    }
    
    // Handle NUMWORD auto-disable when non-number keys are pressed
    if (numword_enabled && record->event.pressed) {
        if (!is_num_key(keycode)) {
            // skip KC_NO codes
            if (keycode != KC_NO) {
                tap_code16(keycode);
            }
            numword_enabled = false;
            layer_off(_NUM);
            return false;
        }
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
const uint16_t PROGMEM win_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM arr_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM adjust_combo[] = {KC_Z, KC_P, COMBO_END};
const uint16_t PROGMEM game_combo[] = {KC_Q, KC_SLSH, COMBO_END};
const uint16_t PROGMEM rm_toggle_combo[] = {KC_Y, KC_P, COMBO_END};
// const uint16_t PROGMEM numword_combo[] = {NAV, SYM_SPC, COMBO_END};
const uint16_t PROGMEM colon_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_J, KC_L, COMBO_END};

// num combos
const uint16_t PROGMEM num_one_combo[] = {NAV, KC_M, COMBO_END};
const uint16_t PROGMEM num_two_combo[] = {NAV, KC_COMM, COMBO_END};
const uint16_t PROGMEM num_three_combo[] = {NAV, KC_DOT, COMBO_END};
const uint16_t PROGMEM num_four_combo[] = {NAV, KC_J, COMBO_END};
const uint16_t PROGMEM num_five_combo[] = {NAV, KC_K, COMBO_END};
const uint16_t PROGMEM num_six_combo[] = {NAV, KC_L, COMBO_END};
const uint16_t PROGMEM num_seven_combo[] = {NAV, KC_U, COMBO_END};
const uint16_t PROGMEM num_eight_combo[] = {NAV, KC_I, COMBO_END};
const uint16_t PROGMEM num_nine_combo[] = {NAV, KC_O, COMBO_END};
const uint16_t PROGMEM num_zero_combo[] = {NAV, ONE_SFT, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, LT(_SYM, KC_ESC)),
    COMBO(colon_combo, LT(_SYM, KC_TAB)),
    COMBO(quot_combo, LT(_SYM, KC_QUOT)),
    // COMBO(tab_combo, LT(_SYM, KC_TAB)),
    COMBO(lang_combo, MY_LANG),
    COMBO(lcmd_combo, ONE_CMD),
    COMBO(rcmd_combo, ONE_CMD),
    COMBO(ctrl_combo, ONE_CTL),
    COMBO(rctrl_combo, ONE_CTL),
    COMBO(win_combo, WIN),
    COMBO(arr_combo, MY_ARR),
    COMBO(adjust_combo, TO(_ADJUST)),
    COMBO(game_combo, TO(_GAME)),
    COMBO(rm_toggle_combo, RM_TOGG),
    // COMBO(numword_combo, NUMWORD),

    // num combos
    COMBO(num_one_combo, KC_1),
    COMBO(num_two_combo, KC_2),
    COMBO(num_three_combo, KC_3),
    COMBO(num_four_combo, KC_4),
    COMBO(num_five_combo, KC_5),
    COMBO(num_six_combo, KC_6),
    COMBO(num_seven_combo, KC_7),
    COMBO(num_eight_combo, KC_8),
    COMBO(num_nine_combo, KC_9),
    COMBO(num_zero_combo, KC_0),
};
