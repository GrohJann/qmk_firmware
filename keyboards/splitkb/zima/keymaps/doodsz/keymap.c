/* Copyright 2019 Thomas Baart
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

#define KC_VD KC__VOLDOWN
#define KC_VU KC__VOLUP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_encoder( /* Base */
        KC_VD, KC_MUTE, KC_VU, TG(1),   TG(2),
        KC_P7, KC_P8,   KC_P9,
        KC_P4, KC_P5,   KC_P6,
        KC_PSCREEN,   KC_P2,   KC_P3
    ),
    [1] = LAYOUT_ortho_encoder( /* Layer 1 */
		RGB_VAD, RGB_TOG,  RGB_VAI, _______, _______,
        RGB_MOD, RGB_RMOD, RGB_M_R,
        RGB_HUI, RGB_SAI,  RGB_VAI,
        RGB_HUD, RGB_SAD,  RGB_VAD
    ),
    [2] = LAYOUT_ortho_encoder( /* Layer 2*/
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
	[3] = LAYOUT_ortho_encoder( /* Layer 3*/
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    )
};

// combo keys to get to layer 3 (by pressing the Layer 1 and 2 buttons)
// as well as to make this 12 key macropad a fully functional macropad
enum combos { 
	P1_P2_P0,
	P2_P3_PEQL,
	P3_P6_PPLS,
	P6_P9_PMNS,
	P8_P9_PAST,
	P7_P8_PSLS
};

const uint16_t PROGMEM p1_p2_p0[] = { KC_P1, KC_P2, COMBO_END};
const uint16_t PROGMEM p2_p3_peql[] = { KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM p3_p6_ppls[] = { KC_P3, KC_P6, COMBO_END};
const uint16_t PROGMEM p6_p9_pmns[] = { KC_P6, KC_P9, COMBO_END};
const uint16_t PROGMEM p8_p9_past[] = { KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM p7_p8_psls[] = { KC_P7, KC_P8, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[P1_P2_P0] = COMBO(p1_p2_p0, KC_P0),
	[P2_P3_PEQL] = COMBO(p2_p3_peql, KC_PEQL),
	[P3_P6_PPLS] = COMBO(p3_p6_ppls, KC_PPLS),
	[P6_P9_PMNS] = COMBO(p6_p9_pmns, KC_PMNS),
	[P8_P9_PAST] = COMBO(p8_p9_past, KC_PAST),
	[P7_P8_PSLS] = COMBO(p7_p8_psls, KC_PSLS)
};

void render_logo(void) {
    // clang-format off
    static const char PROGMEM my_logo[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 
		0x30, 0xc8, 0xb4, 0xba, 0xca, 0x1a, 0x1a, 0x1a, 0x84, 0x08, 0x10, 0x10, 0x10, 0x10, 0xd0, 0x10, 
		0x10, 0x10, 0x10, 0x90, 0xd0, 0xd0, 0xd0, 0xa8, 0xb4, 0x5a, 0x7a, 0xfa, 0xc4, 0x28, 0xe8, 0xd0, 
		0xd0, 0xd0, 0xa0, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x98, 0xe4, 0xfa, 0xfd, 0x7e, 
		0xbf, 0xbf, 0x3f, 0xbf, 0x7f, 0xff, 0x7e, 0x7f, 0xff, 0xfe, 0x7c, 0xfc, 0xfe, 0x7f, 0xbf, 0xbe, 
		0x3c, 0x3e, 0xbf, 0xbf, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfd, 0xf0, 0x8f, 0x7f, 
		0xff, 0xff, 0xff, 0xff, 0xfe, 0xfd, 0xf9, 0xe6, 0x99, 0x60, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0x06, 0x06, 0x0e, 0x1e, 0xbc, 0xf8, 0xf0, 0x00, 0xc0, 
		0xe0, 0x70, 0x30, 0x30, 0x70, 0xe0, 0xc0, 0x00, 0xc0, 0xe0, 0x70, 0x30, 0x30, 0x70, 0xe0, 0xc0, 
		0x00, 0xc0, 0xe0, 0x70, 0x30, 0x30, 0x60, 0xff, 0xff, 0xff, 0x00, 0x60, 0xf0, 0xb0, 0x10, 0x30, 
		0x60, 0x00, 0x00, 0x30, 0x30, 0xb0, 0xf0, 0xf0, 0x70, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0xe2, 0xfd, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xfe, 0xfe, 0xfe, 0xfe, 0xf7, 0xef, 0xef, 0xae, 0x31, 0x2e, 0xae, 0xef, 0xee, 0xf5, 0xfe, 0xfe, 
		0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xc0, 
		0x3f, 0x7f, 0x7f, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0xbf, 0x9f, 0x5e, 0x5e, 0x4e, 0x25, 0x12, 0x0c, 
		0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0c, 0x0c, 0x0e, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x03, 
		0x07, 0x0e, 0x0c, 0x0c, 0x0e, 0x07, 0x03, 0x00, 0x03, 0x07, 0x0e, 0x0c, 0x0c, 0x0e, 0x07, 0x03, 
		0x00, 0x03, 0x07, 0x0e, 0x0c, 0x0c, 0x06, 0x0f, 0x0f, 0x0f, 0x00, 0x04, 0x0c, 0x08, 0x09, 0x0f, 
		0x06, 0x00, 0x0c, 0x0e, 0x0f, 0x0f, 0x0d, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x19, 0x27, 0x5f, 0x5c, 0x5d, 0x5b, 0x5b, 0x2b, 
		0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
		0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x13, 0x2b, 0x5b, 0x59, 0x5d, 0x5c, 0x2c, 0x16, 
		0x16, 0x0b, 0x0b, 0x05, 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
    // clang-format on
    oled_write_raw_P(my_logo, sizeof(my_logo));
}
