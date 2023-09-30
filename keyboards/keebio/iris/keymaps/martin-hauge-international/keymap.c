#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define NTAB C(KC_TAB)
#define PTAB S(C(KC_TAB))

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  M_GRAVE,
  M_BSL,
  M_TILDE,
  M_SQUOT,
  M_DQUOT
};

const key_override_t arrow_key_u_shift_override = ko_make_basic(MOD_MASK_SHIFT, KC_UP, KC_PGUP);
const key_override_t arrow_key_d_shift_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOWN, KC_PGDN);
const key_override_t arrow_key_l_shift_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT, KC_HOME);
const key_override_t arrow_key_r_shift_override = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT, KC_END);

const key_override_t **key_overrides = (const key_override_t *[]) {
	&arrow_key_u_shift_override,
	&arrow_key_d_shift_override,
	&arrow_key_l_shift_override,
	&arrow_key_r_shift_override,
	NULL
	};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    C(A(KC_W)),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    LT(_LOWER, KC_D), SFT_T(KC_F), KC_G,                   KC_H, RSFT_T(KC_J), LT(_RAISE, KC_K), KC_L, C(A(KC_L)), C(A(KC_Z)),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,          KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
		  // MACROS, HOTKEYS AND EXTRA SYMBOLS                                  ARROWS
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, UC(0x40), UC(0xA3), UC(0x24), KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_EQL,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     NTAB,    _______, _______, KC_TAB, _______, _______,                            _______, _______, _______, _______, _______, M_TILDE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     PTAB, _______, _______, S(KC_TAB), KC_LALT, _______,                            _______, _______, KC_UP,   _______, _______,  M_SQUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_LEFT, KC_DOWN, KC_RGHT,  KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
		  // SYMBOLS                                                            NUMPAD
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     M_GRAVE, S(KC_1), M_BSL, SAGR(KC_4), S(KC_4), S(KC_5),    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     NTAB,    S(KC_EQL), KC_HASH, KC_LBRC, KC_RBRC, SAGR(KC_QUOT),                    _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PAST,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, M_DQUOT, M_SQUOT, KC_BSLS, KC_SLSH, S(KC_SCLN),                      KC_EQL,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PDOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, S(KC_COMM), S(KC_DOT), S(KC_LBRC), S(KC_RBRC), KC_SCLN, KC_LPRN, _______, _______, KC_P1, KC_P2,   KC_P3,   KC_PENT, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, DT_PRNT, DT_UP, DT_DOWN, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, _______, _______, _______,                            _______, _______, _______, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MSTP, _______, _______, _______, _______, _______,          _______, _______, _______, _______, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case M_GRAVE:
        if (record->event.pressed) {
            SEND_STRING("` ");
        } else {
        }
        break;
    case M_BSL:
        if (record->event.pressed) {
            SEND_STRING("\" ");
        } else {
        }
        break;
    case M_TILDE:
        if (record->event.pressed) {
            SEND_STRING("~ ");
        } else {
        }
        break;
    case M_DQUOT:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT("' "));
        } else {
        }
        break;
    case M_SQUOT:
        if (record->event.pressed) {
            SEND_STRING("' ");
        } else {
        }
        break;
  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
	    if (IS_LAYER_ON(_LOWER)) {
	        tap_code(KC_MFFD);
	    } else if (IS_LAYER_ON(_RAISE)) {
	        tap_code(KC_MNXT);
	    } else {
                tap_code(KC_MS_WH_DOWN);
	    }
        } else {
	    if (IS_LAYER_ON(_LOWER)) {
	        tap_code(KC_MRWD);
	    } else if (IS_LAYER_ON(_RAISE)) {
	        tap_code(KC_MPRV);
	    } else {
                tap_code(KC_MS_WH_UP);
	    }
        }
    }
    return false;
}
