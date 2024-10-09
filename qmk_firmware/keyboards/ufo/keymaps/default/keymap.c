#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *        ,----------------------------------.                                    ,----------------------------------.
 *        |   1  | 2(@) | 3(#) | 4($) | 5(%) |                                    |   6  |   7  |   8  |   9  |   0  |
 * ,------+------+------+------+------+------+------.                     .-------+------+------+------+------+------+------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |  Alt  |                    | Del   |   Y  |   U  |   I  |   O  |   P  | Home |
 * |------+------+------+------+------+------+-------|                    |-------+------+------+------+------+------|------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |  +    |                    | Bspc  |   H  |   J  |   K  |   L  | '(") | End  |
 * |------+------+------+------+------+------|-------|                    |-------+------+------+------+------+------|------|
 * |AltGr |   Z  |   X  |   C  |   V  |   B  | LWin  |                    | Enter |   N  |   M  | ,(<) | .(>) | ;(:) |Ctrl |
 * `-------------------------------------------------´                    `-------------------------------------------------'
 *                                |LOWER | / Shift / ,------.      ,------. \ Shift \ |RAISE |
 *                                `---------------' / Ctrl  /      \ Spc   \ '--------------´ 
 *                                                  `------'        `------'
 */

 [_QWERTY] = LAYOUT(
  KC_1,     KC_2,  KC_3,  KC_4,   KC_5,                        KC_6,     KC_7,   KC_8,    KC_9,    KC_0, 
  KC_Q,     KC_W,  KC_E,  KC_R,   KC_T,    KC_LALT,  KC_DEL,   KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,
  KC_ESC,   KC_S,  KC_D,  KC_F,   KC_G,    KC_PPLS,  KC_BSPC,  KC_H,     KC_J,   KC_K,    KC_L,    KC_HOME,
  KC_TAB,   KC_A,  KC_C,  KC_V,   KC_B,    KC_LGUI,  KC_ENT,   KC_N,     KC_M,   KC_COMM, KC_QUOT, KC_END, 
  KC_ALGR,  KC_Z,  KC_X,  LOWER,  KC_LSFT, KC_LCTL,  KC_SPC,   KC_RSFT,  RAISE,  KC_DOT,  KC_SCLN, KC_RCTL
),
/* LOWER
 *        ,----------------------------------.                                    ,----------------------------------.
 *        |  F1  |  F2  |  F3  |  F4  |  F5  |                                    |  F6  |  F7  |  F8  |  F9  | F10  |
 * ,------+------+------+------+------+------+------.                     .-------+------+------+------+------+------+------.
 * |      |      |      |      |      |      |       |                    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------+-------|                    |-------+------+------+------+------+------|------|
 * |      |      |      |      |      |      |       |                    |       |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|-------|                    |-------+------+------+------+------+------|------|
 * |      |      |      |      |      |      |       |                    |       |      | Left | Down | Right|      |      |
 * `-------------------------------------------------´                    `-------------------------------------------------'
 *                                |      | /       / ,------.      ,------. \      \ |      |
 *                                `--------------' /       /        \       \ '-------------´ 
 *                                                 `------'          `------'
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,
  _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______,  _______, _______,
  _______, _______, _______, _______, _______, _______,    _______,    _______, _______, KC_UP,    _______, _______,
  _______, _______, _______, _______, _______, _______,    _______,    _______, KC_LEFT, KC_DOWN,  _______, _______,
  _______, _______, _______, _______, _______, _______,    _______,    _______, _______, KC_RIGHT, _______, _______
),
/* RAISE
 *        ,----------------------------------.                                    ,----------------------------------.
 *        |  F1  |  F2  |  F3  |  F4  |  F5  |                                    |  F6  |  F7  |  F8  |  F9  | F10  |
 * ,------+------+------+------+------+------+------.                     .-------+------+------+------+------+------+------.
 * |      |      |      |      |      |      |       |                    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------+-------|                    |-------+------+------+------+------+------|------|
 * |      |      |      |      |      |      |       |                    |       |      |      |CS_Up |      |      |      |
 * |------+------+------+------+------+------|-------|                    |-------+------+------+------+------+------|------|
 * |      |      |      |      |      |      |       |                    |       |      |CS_Le |CS_Do |CS_Ri |      |      |
 * `-------------------------------------------------´                    `-------------------------------------------------'
 *                                |      | /       / ,------.      ,------. \      \ |      |
 *                                `--------------' /       /        \       \ '-------------´ 
 *                                                 `------'          `------'
 */
[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,
  _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______,  _______, _______,
  _______, _______, _______, _______, _______, _______,    _______,    _______, _______, C(S(KC_UP)),    _______, _______,
  _______, _______, _______, _______, _______, _______,    _______,    _______, C(S(KC_LEFT)), C(S(KC_DOWN)),  _______, _______, 
  _______, _______, _______, _______, _______, _______,    _______,    _______, _______, C(S(KC_RIGHT)), _______, _______
),
[_ADJUST] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,
  _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______,  _______, _______, 
  _______, _______, _______, _______, _______, _______,    _______,    _______, _______, KC_UP,    _______, _______, 
  _______, _______, _______, _______, _______, _______,    _______,    _______, KC_LEFT, KC_DOWN,  _______, _______, 
  _______, _______, _______, _______, _______, _______,    _______,    _______, _______, KC_RIGHT, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); // 
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
