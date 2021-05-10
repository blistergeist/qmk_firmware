#include QMK_KEYBOARD_H

enum custom_keycodes {
    TRAGEDY = SAFE_RANGE,
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |   1   |   2   |   3   |
 * |-------+-------+-------|
 * |   4   |TRAGEDY|   6   |
 * |-------+-------+-------|
 * |   0   |   8   |   9   |
 * `-----------------------'
 */
[0] = LAYOUT( \
  KC_1, KC_2,       KC_3,       \
  KC_4, TRAGEDY,    KC_6,       \
  KC_7, KC_8,       LT(1, KC_9) \
)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QMKBEST:
        if (record->event.pressed) {
            // when keycode TRAGEDY is pressed
            SEND_STRING("Did you ever hear the tragedy of Darth Plagueis The Wise? I thought not. It’s not a story the Jedi would tell you. It’s a Sith legend. Darth Plagueis was a Dark Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to create life… He had such a knowledge of the dark side that he could even keep the ones he cared about from dying. The dark side of the Force is a pathway to many abilities some consider to be unnatural. He became so powerful… the only thing he was afraid of was losing his power, which eventually, of course, he did. Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep. Ironic. He could save others from death, but not himself.");
        } else {
            // when keycode TRAGEDY is released
        }
        break;
    }
    return true;
};

};
