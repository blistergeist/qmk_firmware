/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

uint16_t copy_paste_timer;

enum layers {
	COLEMAK = 0,
	LOWER,
	RAISE,
    GAME,
    GLOWER,
    GRAISE,
	AOE,
	AOERAISE,
	MINE,
	MINERAISE,
	ADJUST
};

enum custom_keycodes {
	KC_CCCV = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   XXX  |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  | ;  : |  XXX   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   GUI  |   A  |   R  |   S  |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  .-------------+------+------+------+------+------+--------|
 * |   Alt  |   Z  |   X  |   C  |   V  |   B  | XXX  |      |  |      | XXX  |   K  |   M  | ,  < | . >  | /  ? |  CAPS  |
 * `----------------------+------+------+------+------+      |  |      +------+------+------+------+----------------------'
 *                        | Play | Tab  |      | Space|  Esc |  | Bksp |      |  Del | Enter| MUTE |
 *                        | Pause| Ctrl | Lower|      |      |  |      | Shift| Raise| Ctrl |      |
 *                        `----------------------------------'  `----------------------------------'
*/
	[COLEMAK] = LAYOUT(
        KC_NO,      KC_Q,       LT(0,KC_W), LT(0,KC_F), KC_P,           KC_G,                           /**/                            KC_J,               LT(0,KC_L),     KC_U,           KC_Y,           KC_SCLN,        KC_NO,
        KC_LGUI,    LT(0,KC_A), LT(0,KC_R), LT(0,KC_S), LT(0,KC_T),     LT(0,KC_D),                     /**/                            KC_H,               LT(0,KC_N),     KC_E,           LT(0,KC_I),     LT(0,KC_O),     KC_QUOT,
        KC_LALT,    LT(0,KC_Z), LT(0,KC_X), LT(0,KC_C), LT(0,KC_V),     LT(0,KC_B), TO(LOWER),  KC_NO,  /**/    KC_NO,      TO(RAISE),  KC_K,               CTL_T(KC_M),    SFT_T(KC_COMM), ALT_T(KC_DOT),  GUI_T(KC_SLSH), KC_CAPS,
                                            KC_MPLY,    CTL_T(KC_TAB),  MO(LOWER),  KC_SPC,     KC_ESC, /**/    KC_BSPC,    KC_LSFT,    LT(RAISE, KC_DEL),  CTL_T(KC_ENT),  KC_MUTE
    ),

/*
 * Lower Layer: Symbols, F Keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  {   |  }   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  -   |  _   |  =   |  +   |  `   |                              |   |  |  (   |  )   |  [   |  ]   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   F12  |  F1  |  F2  |  F3  |  F4  |  F5  |SG(S) |      |  |      | XXX  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * `----------------------+------+------+------+------+      |  |      +------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |  .   |      |
 *                        |      |      |      |      |      |  |      |      |Adjust|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
	[LOWER] = LAYOUT(
	  KC_TRNS,  KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,	    KC_PERC,                                /**/                            KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LCBR,    KC_RCBR,    KC_TRNS,
	  KC_TRNS,  KC_MINS,    KC_UNDS,    KC_EQL,     KC_PLUS,    KC_GRV,                                 /**/                            KC_TILDE,   KC_LPRN,    KC_RPRN,    KC_LBRC,    KC_RBRC,    KC_TRNS,
	  KC_F12,   KC_F1,      KC_F2,      KC_F3,      KC_F4,	    KC_F5,      SGUI(KC_S),	KC_NO,          /**/    KC_NO,      KC_NO,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    TO(COLEMAK),    /**/    KC_TRNS,    KC_TRNS,    MO(ADJUST), KC_TRNS,    KC_TRNS
	),

/*
 * Raise Layer: Numbers, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   XXX  |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |  XXX   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   XXX  | HOME | PGDN | PGUP |  END |   `  |                              |  XXX | LEFT | DOWN |  UP  | RIGHT|  XXX   |
 * |--------+------+------+------+------+------+-------------.  .-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |   ~  | XXX  |      |  |      | XXX  |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+      |  |      +------+------+------+------+----------------------'
 *                        |      |      |      | Shift|      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
	[RAISE] = LAYOUT(
	  KC_NO,	KC_1,	    KC_2,	    KC_3,	    KC_4,	    KC_5,						            /**/					        KC_6,	    KC_7,	    KC_8,	    KC_9,	KC_0,       KC_NO,
	  KC_NO,	KC_HOME,    KC_PGDN,    KC_PGUP,	KC_END,	    KC_NO,							        /**/					        KC_NO,		KC_LEFT,    KC_DOWN,    KC_UP,	KC_RIGHT,   KC_NO,
	  KC_F12,   KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    KC_NO,      KC_NO,	    KC_NO,		    /**/	KC_NO,	    KC_NO,	    KC_NO,		KC_NO,      KC_NO,      KC_NO,  KC_BSLS,	KC_PIPE,
									    KC_TRNS,    KC_TRNS,    MO(ADJUST),	KC_LSFT,	TO(COLEMAK),	/**/	KC_TRNS,	KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
	),

/*
 * Game Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  CTRL  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |  P   |  XXX   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   ALT  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |  ;   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  .-------------+------+------+------+------+------+--------|
 * |   XXX  |   Z  |   X  |   C  |   V  |   B  | XXX  |      |  |      | XXX  |   N  |   M  | ,  < | . >  | /  ? |  CAPS  |
 * `----------------------+------+------+------+------+      |  |      +------+------+------+------+----------------------'
 *                        | XXX  | Tab  |  Esc | Space| Shift|  | XXX  | Bksp |  Del | Enter| MUTE |
 *                        |      |      | Lower|      |      |  |      | Shift| Raise|      |      |
 *                        `----------------------------------'  `----------------------------------'
*/
	[GAME] = LAYOUT(
		KC_TAB,	    KC_Q,	 KC_W,	KC_E,	    KC_R,	    KC_T,								    /**/							KC_Y,	KC_U,	KC_I,		KC_O,   KC_P,		KC_NO,
		KC_LALT,    KC_A,    KC_S,  KC_D,	    KC_F,	    KC_G,								    /**/							KC_H,	KC_J,	KC_K,       KC_L,	KC_SCLN,    KC_QUOT,
		KC_TILDE,	KC_Z,	 KC_X,	KC_C,	    KC_V,	    KC_B,				KC_NO,	    KC_NO,  /**/	KC_NO,	    KC_NO,		KC_K,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_CAPS,
								    KC_MPLY,    KC_LCTRL,   LT(GLOWER, KC_ESC),	KC_LSFT,    KC_SPC,	/**/	KC_BSPC,	KC_LSFT,    KC_DEL,	KC_ENT, KC_MUTE
	),

/*
 * Game Lower Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  6   |  7   |  8   |  9   |  0   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
	[GLOWER] = LAYOUT(
	  KC_NO,    KC_1,	KC_2,	KC_3,	KC_4,	KC_5,					/**/				    KC_NO,	    KC_NO,	KC_NO,	KC_NO,  KC_NO, KC_NO,
	  KC_NO,    KC_6,	KC_7,	KC_8,	KC_9,	KC_0,					/**/				    KC_NO,	    KC_NO,	KC_NO,	KC_NO,  KC_NO,  KC_NO,
	  KC_NO,    KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_NO,	KC_NO,  /**/	KC_NO,	KC_NO,	KC_NO,	    KC_NO,	KC_NO,	KC_NO,  KC_NO, KC_NO,
								KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	/**/	KC_NO,	KC_NO,	MO(ADJUST),	KC_NO,	KC_NO
	),

/*
 * Game Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   XXX  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |  P   |  XXX   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   XXX  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |  ;   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  .-------------+------+------+------+------+------+--------|
 * |   XXX  |   Z  |   X  |   C  |   V  |   B  | XXX  |      |  |      | XXX  |   N  |   M  | ,  < | . >  | /  ? |  CAPS  |
 * `----------------------+------+------+------+------+      |  |      +------+------+------+------+----------------------'
 *                        | XXX  | Tab  |  Esc | Space| Shift|  | XXX  | Bksp |  Del | Enter| MUTE |
 *                        |      |      | Lower|      |      |  |      | Shift| Raise|      |      |
 *                        `----------------------------------'  `----------------------------------'
*/
	[AOE] = LAYOUT(
		KC_LCTRL,	KC_Q,	 KC_W,	KC_E,	    KC_R,	KC_T,								            /**/						    KC_Y,	KC_U,	KC_I,		KC_O,   KC_P,		KC_NO,
		KC_LALT,    KC_A,    KC_S,  KC_D,	    KC_F,	KC_G,								            /**/						    KC_H,	KC_J,	KC_K,       KC_L,	KC_SCLN,    KC_QUOT,
		KC_NO,	    KC_Z,	 KC_X,	KC_C,	    KC_V,	KC_B,				    S(KC_G),	KC_NO,      /**/	KC_NO,	    KC_NO,	    KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_CAPS,
								    KC_MPLY,    KC_TAB, LT(AOERAISE, KC_ESC),	KC_SPC,	    KC_LSFT,	/**/	KC_BSPC,    KC_LSFT,    KC_DEL,	KC_ENT, KC_MUTE
	),

/*
 * Game Lower Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  6   |  7   |  8   |  9   |  0   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
	[AOERAISE] = LAYOUT(
	  KC_0,         KC_1,       KC_2,	    KC_3,	    KC_4,	    KC_5,							/**/				            KC_6,	    KC_7,	KC_8,	KC_9,  KC_0,  KC_NO,
	  S(KC_0),      S(KC_1),    S(KC_2),	S(KC_3),	S(KC_4),	S(KC_5),						/**/			                KC_NO,	    KC_NO,	KC_NO,	KC_NO,  KC_NO,  KC_NO,
	  C(S(KC_G)),   C(S(KC_Q)),	C(S(KC_W)),	C(S(KC_E)),	C(S(KC_R)),	C(S(KC_T)),	KC_NO,	    KC_NO,  /**/	KC_NO,	TO(COLEMAK),	KC_NO,	    KC_NO,	KC_NO,	KC_NO,  KC_NO,  KC_NO,
								            KC_NO,	    KC_NO,	    KC_NO,	    KC_NO,	    KC_NO,	/**/	KC_NO,	KC_NO,	        MO(ADJUST),	KC_NO,	KC_NO
	),

/*
 * Adjust Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |SG(L) |                              | SG(R)|GUI(L)|GUI(D)|GUI(U)|GUI(R)|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  SG(S) |      |      |      |  AOE |      | GAME |      |  |      |      | COLMK|      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
	[ADJUST] = LAYOUT(
	  KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	    KC_NO,								/**/			        KC_NO,			KC_NO,		KC_NO,		KC_NO,		KC_NO,			KC_NO,
	  KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	    SGUI(KC_LEFT),						/**/			        SGUI(KC_RIGHT),	G(KC_LEFT),	G(KC_DOWN),	G(KC_UP),	G(KC_RIGHT),	KC_NO,
	  KC_NO,	KC_NO,	KC_NO,	KC_NO,	TO(AOE),	KC_NO,	        TO(GAME),	KC_NO,  /**/	KC_NO,	KC_NO,	TO(COLEMAK),	KC_NO,		KC_NO,		KC_NO,		KC_NO,			KC_NO,
								KC_NO,	KC_NO,	    KC_NO,	        KC_NO,	    KC_NO,	/**/	KC_NO,	KC_NO,	KC_NO,			KC_NO,		KC_NO
	),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code16(LCTL(KC_Y));
        } else {
            tap_code16(LCTL(KC_Z));
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if ((keycode & 0xFF00) == 0x4000) {
        if (record->tap.count) {
            return true;
        }
        else if (record->event.pressed) {
            keycode = keycode & 0xFF;
            tap_code16(C(keycode));
        return false;
        }
    }
    switch (keycode) {
		case KC_CCCV:  // One key copy/paste
			if (record->event.pressed) {
				copy_paste_timer = timer_read();
			} else {
				if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copytap_code16(LCTL(KC_C));
				} else { // Tap, paste
					tap_code16(LCTL(KC_V));
				}
			}
			break;
	}
	return true;
}


bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;


/*#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) {
		switch (biton32(layer_state)) {
			case COLEMAK:
				// History scrubbing. For Adobe products, hold shift while moving
				// backward to go forward instead.
				if (clockwise) {
					tap_code16(C(KC_Z));
				} else {
					tap_code16(C(KC_Y));
				}
				break;
			default:
				// Switch between windows on Windows with alt tab.
				if (clockwise) {
					if (!is_alt_tab_active) {
						is_alt_tab_active = true;
						register_code(KC_LALT);
					}
					alt_tab_timer = timer_read();
					tap_code16(KC_TAB);
				} else {
					tap_code16(S(KC_TAB));
				}
				break;
		}
	} else if (index == 1) {
		switch (biton32(layer_state)) {
			case COLEMAK:
				// Scrolling with PageUp and PgDn.
				if (clockwise) {
					tap_code(KC_PGDN);
				} else {
					tap_code(KC_PGUP);
				}
				break;
			default:
				// Volume control.
				if (clockwise) {
					tap_code(KC_VOLU);
				} else {
					tap_code(KC_VOLD);
				}
				break;
		}
	}
}
#endif
*/
