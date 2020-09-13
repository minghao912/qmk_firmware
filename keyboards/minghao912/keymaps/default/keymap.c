#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FN 1
#define _LX 2	//LATEX layer

//Define LATEX keycodes
enum custom_keycodes {
    EXAMPLE = SAFE_RANGE,
    LATEX_INT,
    LATEX_FRAC,
};

#define LX_INT LATEX_INT
#define LX_FRC LATEX_FRAC

#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BL] = LAYOUT(
		KC_ESC,	KC_F1,	KC_F2, 	KC_F3, 	KC_F4, 	KC_F5, 	KC_F6, 	KC_F7, 	KC_F8, 	KC_F9, 	KC_F10,	KC_F11,	KC_F12, 			KC_PSCR,	KC_SLCK,	KC_PAUS, 
		
		KC_GRV, KC_1, 	KC_2,	KC_3, 	KC_4, 	KC_5, 	KC_6, 	KC_7, 	KC_8, 	KC_9, 	KC_0, 	KC_MINS,KC_EQL,	KC_BSPC, 	KC_INS, 	KC_HOME,	KC_PGUP, 
		KC_TAB, KC_Q, 	KC_W, 	KC_E, 	KC_R, 	KC_T, 	KC_Y, 	KC_U,	KC_I, 	KC_O, 	KC_P, 	KC_LBRC,KC_RBRC,KC_ENT, 	KC_DEL, 	KC_END,		KC_PGDN, 
		KC_CAPS,KC_A, 	KC_S, 	KC_D, 	KC_F, 	KC_G, 	KC_H, 	KC_J, 	KC_K, 	KC_L, 	KC_SCLN,KC_QUOT,KC_BSLS, 											 
		KC_LSFT,KC_Z, 	KC_X, 	KC_C, 	KC_V, 	KC_B, 	KC_N, 	KC_M, 	KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,								KC_UP, 				 
		KC_LCTL,KC_LGUI,KC_LALT,				KC_SPC, 				KC_RALT,KC_RGUI,MO(_FN),KC_RCTL, 					KC_LEFT, 	KC_DOWN, 	KC_RIGHT),

	
	[_FN] = LAYOUT(
		RESET,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______, 			______,		______,		______,	 
		______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,		______,		______,		______,	
		______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,		______,		______,		______, 
		______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	OSL(_LX),												 
		______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,									______,				 
		______,	______,	______,					______,					______,	______,	______,	______,						______,		______,		______),

	[_LX] = LAYOUT(
		______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______, 			______,		______,		______,	 
		______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,		______,		______,		______,	
		______,	______,	______,	______,	______,	______,	______,	______,	LX_INT,	______,	______,	______,	______,	______,		______,		______,		______, 
		______,	______,	______,	______,	LX_FRC,	______,	______,	______,	______,	______,	______,	______,	______,												 
		______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,	______,									______,				 
		______,	______,	______,					______,					______,	______,	______,	______,						______,		______,		______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case EXAMPLE:
			if (record -> event.pressed) {
				//When EXAMPLE is pressed
				SEND_STRING("Example text.");
			} else {
				//When EXAMPLE is released
			}
			break;

		case LATEX_INT:
			if (record -> event.pressed) {
				SEND_STRING("\\int{_}" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
			} else;
			break;

		case LATEX_FRAC:
			if (record -> event.pressed) {
					SEND_STRING("\\frac{_}" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
			} else;
			break;
	}

	return true;
}