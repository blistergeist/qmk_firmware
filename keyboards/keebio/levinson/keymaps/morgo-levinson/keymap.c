#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum preonic_layers {
  _HOME,
  _LAYER_ONE,
  _LAYER_TWO,
  _GAME,
  _GAME_RAISE,
  _UNICODE,
  _CONTROL
};

enum custom_keycodes {
  OHM = SAFE_RANGE,
  TM,
  PLUSMINUS,
  DEGREE,
  DELTA,
  SHRUG,
  MIDDLEFINGER,
  MU
};

const uint32_t PROGMEM unicode_map[] = {
  [0] = 0x0000
};

enum tapdance {
  TD_SHIFT_ALT,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SHIFT_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LSFT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer Zero
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | GUI  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Caps |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | XXXX |Shift | Alt  | ONE  |Space |Shift | TWO  | Del  | XXXX | XXXX |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_HOME] = LAYOUT_ortho_4x12(
  KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,           KC_T,   KC_Y,     KC_U,           KC_I,     KC_O,     KC_P,     KC_BSPC,
  KC_LGUI,  KC_A,     KC_S,     KC_D,     KC_F,           KC_G,   KC_H,     KC_J,           KC_K,     KC_L,     KC_SCLN,  KC_QUOT, 
  KC_TAB,   KC_Z,     KC_X,     KC_C,     KC_V,           KC_B,   KC_N,     KC_M,           KC_COMM,  KC_DOT,   KC_SLSH,  KC_CAPS, 
  KC_LCTL,  KC_TRNS,  MO(_UNICODE),  TD(TD_SHIFT_ALT),  MO(_LAYER_ONE), KC_SPC, KC_RSFT,  MO(_LAYER_TWO), KC_DEL,   KC_TRNS, KC_TRNS,   KC_ENT
),

/* Layer One

 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | GUI  | Home | PgUp | PgDn | End  | XXXX | XXXX | LEFT | DOWN |  UP  |Right |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | Caps |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | XXXX |Shift | Alt  | ONE  |Space |Shift | TWO  | Del  | XXXX | XXXX |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_LAYER_ONE] = LAYOUT_ortho_4x12(
  KC_TRNS, KC_1,    KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,         KC_8,     KC_9,     KC_0,     KC_TRNS, 
  KC_TRNS, KC_HOME, KC_PGUP,  KC_PGDN,  KC_END,   KC_NO,    KC_NO,    KC_LEFT,      KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS, 
  KC_TRNS, KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,        KC_F8,    KC_F9,    KC_F10,   KC_TRNS, 
  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(_CONTROL), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Layer Two
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |Space |Shift |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_LAYER_TWO] = LAYOUT_ortho_4x12(
  KC_TRNS, KC_EXLM, KC_AT,    KC_HASH,  KC_DLR,       KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR,  KC_BSLS, 
  KC_TRNS, KC_MINS, KC_UNDS,  KC_EQL,   KC_PPLS,      KC_GRV,   KC_TILD, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,  KC_TRNS, 
  KC_TRNS, KC_NO,   KC_NO,    KC_NO,    KC_WBAK,      KC_WFWD,  KC_MPLY, KC_VOLU, KC_VOLD, KC_MUTE, KC_NO,    KC_TRNS, 
  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  MO(_CONTROL), KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
),

/* Lower
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_ortho_4x12(
  KC_ESC,   KC_Q,     KC_W,   KC_E,     KC_R,             KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,       KC_TRNS, 
  KC_LSFT,  KC_A,     KC_S,   KC_D,     KC_F,             KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,    KC_TRNS, 
  KC_TAB,   KC_Z,     KC_X,   KC_C,     KC_V,             KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_TRNS, 
  KC_LCTL,  KC_TRNS, KC_DEL,  KC_LALT,  MO(_GAME_RAISE),  KC_LSFT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_HOME),  KC_TRNS
),

/* Raise
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME_RAISE] = LAYOUT_ortho_4x12(
  KC_TRNS, KC_1,        KC_2,       KC_3,       KC_4,       KC_5,       KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
  KC_TRNS, LSFT(KC_1),  LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
  KC_TRNS, KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
  KC_TRNS, KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, MO(_CONTROL),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_CONTROL] = LAYOUT_ortho_4x12(
  RESET,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,      KC_TRNS,        KC_CALC, 
  KC_TRNS,    KC_TRNS, KC_PWR,  KC_SLEP, KC_WAKE,   SGUI(KC_LEFT),  SGUI(KC_RGHT),  LGUI(KC_LEFT),  LGUI(KC_DOWN),  LGUI(KC_UP),  LGUI(KC_RGHT),  KC_TRNS, 
  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, TO(_GAME), KC_TRNS,        KC_TRNS,        TO(_HOME),      KC_TRNS,        KC_TRNS,      KC_TRNS,        KC_TRNS, 
  SGUI(KC_S), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,      KC_TRNS,        KC_TRNS
),

/* UNICODE (formerly known as the extra shift key)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |Delta |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  TM  |      |      |      | Ohm  |PlMin |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Degree|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UNICODE] = LAYOUT_ortho_4x12(
  KC_NO,    KC_NO, KC_NO,   KC_NO,      KC_NO,        TM,           KC_NO,        KC_NO,        KC_NO,        OHM,        PLUSMINUS,    KC_NO, 
  KC_NO,    KC_NO, SHRUG,   DEGREE,     MIDDLEFINGER, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      KC_NO,        KC_NO, 
  KC_NO,    KC_NO, KC_NO,   KC_NO,      KC_NO,        KC_NO,        KC_NO,        MU,           KC_NO,        KC_NO,      KC_NO,        KC_NO, 
  KC_NO,    KC_NO, KC_TRNS, KC_NO,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      KC_NO,        KC_NO
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case TO(_HOME):
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
            PLAY_SONG(game_off);
            #endif
            break;
          }
        case TO(_GAME): 
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
            PLAY_SONG(game_on);
            #endif
            break;
          }
        case OHM:
        if (record->event.pressed){
          send_unicode_string("Ω");
          break;
          }
        case TM:
        if (record->event.pressed){
          send_unicode_string("™️");
          break;
          }
        case PLUSMINUS:
        if (record->event.pressed){
          send_unicode_string("±");
          break;
          }
        case DEGREE:
        if (record->event.pressed){
          send_unicode_string("°");
          break;
          }
        case DELTA:
        if (record->event.pressed){
          send_unicode_string("Δ");
          break;
          }
        case SHRUG:
        if (record->event.pressed){
          send_unicode_string("¯\\_(ツ)_/¯");
          break;
          }
        case MIDDLEFINGER:
        if (record->event.pressed){
          send_unicode_string("🖕");
          break;
          }
        case MU:
        if (record->event.pressed){
          send_unicode_string("μ");
          break;
          }
        }
    return true;
};