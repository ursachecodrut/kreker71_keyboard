/*
- This is a keymap for the Corne keyboard.
- The layout is a split 3x6 with 3 thumb keys.
-
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC,
  BACKLIT,
  SCRNSHT
};

/**
 * Custom keycodes
 *
 * Define an enum entry for each layer for a better readability. You can use entirely numeric values if you prefer.
 */
enum custom_layers {
  L_QWERTY,
  L_LOWER,
  L_RAISE,
  L_FUNC
};


/**
 * Some configuration for the QWERTY layer
 *
 * OSM   - One Shot Modifier = This allows you to hold the key to activate the modifier, and then the next key you press will be modified.
 * OSL   - One Shot Layer    = This allows you to hold the key to activate the layer, and then the next key you press will be from that layer.
 * GUI_T - GUI Tap           = This allows you to tap the key to send the GUI key, but on hold it will act as a normal key.
 * LT    - Layer Tap         = This allows you to tap the key to send the key, but on hold it will act as if you were on that layer.
 */
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_AGR  OSM(MOD_RALT)
#define OSL_FUN  OSL(L_FUNC)
#define GUI_ENT  GUI_T(KC_ENT)
#define LOW_TAB  LT(L_LOWER, KC_TAB)
#define RSE_BSP  LT(L_RAISE, KC_BSPC)
#define OSM_SFT  OSM(MOD_LSFT)

/**
 * Some configuration for the RAISE layer
 *
 * LCTL_T - Left Control Tap = This allows you to tap the key to send the Control key, but on hold it will act as a normal key.
 */
#define CTL_ESC  LCTL_T(KC_ESC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
OSM(MOD_LALT),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, OSM_AGR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
OSM(MOD_LSFT),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, OSL_FUN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         OSM_LCTL, GUI_ENT, LOW_TAB,    RSE_BSP,  KC_SPC, OSM_SFT
                                      //`--------------------------'  `--------------------------'
  ),

  [L_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD,  KC_GRV, KC_LPRN, KC_LBRC, KC_LCBR,                      KC_RCBR, KC_RBRC, KC_RPRN, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,   LOWER,    _______, _______,KC_COLON
                                      //`--------------------------'  `--------------------------'
  ),

  [L_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  KC_DEL, XXXXXXX, KC_UNDS, KC_PLUS, KC_PGUP,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_PIPE, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME,  KC_END, KC_MINS,  KC_EQL, KC_PGDN,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_APP, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_LT,   KC_GT, KC_COPY, KC_PSTE, KC_SCLN,                      KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CTL_ESC, _______, XXXXXXX,      RAISE, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      SCRNSHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CAPS, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    FUNC, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  /* return rotation; */
  /* return OLED_ROTATION_180; */
  /* return OLED_ROTATION_90; */
  return OLED_ROTATION_270;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* show ctrl-gui swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM plantes_logo[] = {
        // 'pixel_art', 32x128px
        0x7f, 0xff, 0x80, 0x09, 0x03, 0x03, 0xe7, 0xc6, 0xce, 0x8c, 0x0c, 0x0c, 0x4c, 0xcc, 0xcc, 0x8e,
        0x0e, 0x07, 0x37, 0x83, 0xc1, 0xe4, 0x74, 0x30, 0x38, 0x3c, 0x98, 0x03, 0x3f, 0x7f, 0xff, 0xf8,
        0x00, 0x0f, 0x7f, 0xf8, 0xc0, 0xc0, 0x10, 0x03, 0x3f, 0x7f, 0xfe, 0xfe, 0xc0, 0x81, 0x0f, 0x07,
        0xf0, 0xf8, 0xfe, 0xdf, 0x03, 0xc1, 0xf8, 0xfc, 0xfe, 0x3f, 0x8f, 0x07, 0x62, 0xe0, 0xa0, 0xc3,
        0x40, 0x00, 0x00, 0x01, 0x0f, 0x0f, 0x1c, 0x38, 0xfb, 0xf0, 0xf1, 0xf3, 0xe7, 0xcf, 0xcf, 0x9e,
        0x10, 0x11, 0x07, 0x1f, 0x3c, 0x70, 0xe1, 0xe3, 0xe7, 0xcc, 0xc8, 0xc8, 0xc4, 0xc4, 0xc0, 0xe4,
        0x00, 0x00, 0x00, 0x60, 0x70, 0x20, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3d, 0x3b, 0x73,
        0xe7, 0xc7, 0xc7, 0x8f, 0x0e, 0x0c, 0x1c, 0x3d, 0x39, 0x39, 0x73, 0xf3, 0xe3, 0xc3, 0x83, 0x9b,
        0x00, 0x00, 0x80, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c,
        0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x0f, 0x0e, 0x0e, 0x1c, 0x1c, 0x1d, 0x1d, 0x19, 0x33,
        0x00, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xc0, 0xc0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x60, 0xf0, 0x60, 0x00, 0x00, 0x03, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x70, 0x78, 0x18, 0x0c,
        0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xe0, 0x40, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xfc, 0x7e, 0x07, 0x83, 0xe0, 0xf8, 0x3e, 0x3e, 0xd8, 0x61,
        0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x3f, 0xff, 0x81, 0x0c, 0x0e, 0x7f, 0xe0,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x3f, 0x78, 0xf0, 0xc1, 0xc3, 0xc7, 0x8e, 0x8c, 0x8c,
        0x30, 0x60, 0xc0, 0x86, 0x0e, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x40, 0xe0, 0xe0, 0x40, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x1f,
        0x04, 0x0c, 0xc8, 0x19, 0x13, 0x16, 0x9c, 0xf8, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x20, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x9e, 0x8e, 0x8e, 0x8e, 0x9f, 0x8f, 0x87, 0xc7, 0xc7, 0xc3, 0xff, 0xff, 0xfc, 0xc0, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x9f, 0x9f, 0x8f, 0x8f, 0xc7, 0xc3, 0xc3, 0xc1, 0xe1, 0xed, 0xe0, 0xf0, 0xf8, 0xff, 0xff, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x8f, 0xcf, 0xcf, 0xcf, 0xc7, 0xc7, 0xd7, 0xc3, 0xeb, 0xeb, 0xe3, 0xe1, 0xf0, 0xf8, 0xff, 0xff,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x1f, 0x0f, 0x0f, 0x87, 0xc7, 0xc7, 0xe7, 0xf7, 0x73, 0x73, 0x73, 0x73, 0x73, 0xf9, 0xff, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00
    };

    oled_write_raw_P(plantes_logo, sizeof(plantes_logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SCRNSHT:
      if (record->event.pressed) {
        // Send the Command + Control + Shift + 4 shortcut
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LSFT("4"))));
      }
      return false;  // Skip further processing
  }

  if (record->event.pressed) {
    set_keylog(keycode, record);
  }

  return true;
}
#endif // OLED_ENABLE
