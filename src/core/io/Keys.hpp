//
// Created by ENDERZOMBI102 on 11/02/2022.
//

#pragma once

#include <hash_map>
#include "raylib.h"

namespace Minicraft::Core::IO {
	/**
	 * All keys mapped from code to:
	 *  - uppercase char name ( ex. ESCAPE )
	 *  - lowercase character ( if applicable )
	 */
	[[maybe_unused]] const std::hash_map<KeyboardKey, std::vector< std::string > > keyToNameChar { // NOLINT(cert-err58-cpp)
			// fist row
			{ KEY_Q,             { "Q", "q" } },
			{ KEY_ESCAPE,        { "ESCAPE", "" } },
			{ KEY_F1,            { "F1", "" } },
			{ KEY_F2,            { "F2", "" } },
			{ KEY_F3,            { "F3", "" } },
			{ KEY_F4,            { "F4", "" } },
			{ KEY_F5,            { "F5", "" } },
			{ KEY_F6,            { "F6", "" } },
			{ KEY_F7,            { "F7", "" } },
			{ KEY_F8,            { "F8", "" } },
			{ KEY_F9,            { "F9", "" } },
			{ KEY_F10,           { "F10", "" } },
			{ KEY_F11,           { "F11", "" } },
			{ KEY_F12,           { "F12", "" } },
			{ KEY_PRINT_SCREEN,  { "PRINT SCREEN", "" } },
			{ KEY_SCROLL_LOCK,   { "SCROLL LOCK", "" } },
			{ KEY_PAUSE,         { "PAUSE", "" } },
			// second row
			{ KEY_GRAVE,         { "GRAVE", "`" } },
			{ KEY_ONE,           { "ONE", "1" } },
			{ KEY_TWO,           { "TWO", "2" } },
			{ KEY_THREE,         { "THREE", "3" } },
			{ KEY_FOUR,          { "FOUR", "4" } },
			{ KEY_FIVE,          { "FIVE", "5" } },
			{ KEY_SIX,           { "SIX", "6" } },
			{ KEY_SEVEN,         { "SEVEN", "7" } },
			{ KEY_EIGHT,         { "EIGHT", "8" } },
			{ KEY_NINE,          { "NINE", "9" } },
			{ KEY_ZERO,          { "ZERO", "0" } },
			{ KEY_MINUS,         { "MINUS", "-" } },
			{ KEY_EQUAL,         { "EQUAL", "=" } },
			{ KEY_BACKSPACE,     { "BACKSPACE", "" } },
			{ KEY_INSERT,        { "INSERT", "" } },
			{ KEY_HOME,          { "HOME", "" } },
			{ KEY_PAGE_UP,       { "PAGE UP", "" } },
			{ KEY_NUM_LOCK,      { "NUM LOCK", "" } },
			{ KEY_KP_DIVIDE,     { "NUMPAD DIVIDE", "/" } },
			{ KEY_KP_MULTIPLY,   { "NUMPAD MULTIPLY", "*" } },
			{ KEY_KP_SUBTRACT,   { "NUMPAD SUBTRACT", "-" } },
			// third row
			{ KEY_TAB,           { "TAB", "\t" } },
			{ KEY_Q,             { "Q", "q" } },
			{ KEY_W,             { "W", "w" } },
			{ KEY_E,             { "E", "e" } },
			{ KEY_R,             { "R", "r" } },
			{ KEY_T,             { "T", "t" } },
			{ KEY_Y,             { "Y", "y" } },
			{ KEY_U,             { "U", "u" } },
			{ KEY_I,             { "I", "i" } },
			{ KEY_O,             { "O", "o" } },
			{ KEY_P,             { "P", "p" } },
			{ KEY_LEFT_BRACKET,  { "LEFT BRACKET", "[" } },
			{ KEY_RIGHT_BRACKET, { "RIGHT BRACKET", "]" } },
			{ KEY_BACKSLASH,     { "BACKSLASH", "\\" } },
			{ KEY_DELETE,        { "DELETE", "" } },
			{ KEY_END,           { "END", "" } },
			{ KEY_PAGE_DOWN,     { "PAGE DOWN", "" } },
			{ KEY_KP_7,          { "NUMPAD 7", "7" } },
			{ KEY_KP_8,          { "NUMPAD 8", "8" } },
			{ KEY_KP_9,          { "NUMPAD 9", "9" } },
			{ KEY_KP_ADD,        { "NUMPAD ADD", "+" } },
			// forth row
			{ KEY_CAPS_LOCK,     { "CAPS LOCK", "" } },
			{ KEY_A,             { "A", "a" } },
			{ KEY_S,             { "S", "s" } },
			{ KEY_D,             { "D", "d" } },
			{ KEY_F,             { "F", "f" } },
			{ KEY_G,             { "G", "g" } },
			{ KEY_H,             { "H", "h" } },
			{ KEY_J,             { "J", "j" } },
			{ KEY_K,             { "K", "k" } },
			{ KEY_L,             { "L", "l" } },
			{ KEY_SEMICOLON,     { "SEMICOLON", ";" } },
			{ KEY_APOSTROPHE,    { "APOSTROPHE", "'" } },
			{ KEY_ENTER,         { "ENTER", "\n" } },

			{ KEY_KP_4,          { "NUMPAD 4", "4" } },
			{ KEY_KP_5,          { "NUMPAD 5", "5" } },
			{ KEY_KP_6,          { "NUMPAD 6", "6" } },
			{ KEY_KP_ADD,        { "NUMPAD ADD", "+" } },
			// fifth row
			{ KEY_LEFT_SHIFT,    { "LEFT SHIFT", "" } },
			{ KEY_Z,             { "Z", "z" } },
			{ KEY_X,             { "X", "x" } },
			{ KEY_C,             { "C", "c" } },
			{ KEY_V,             { "V", "v" } },
			{ KEY_B,             { "B", "b" } },
			{ KEY_N,             { "N", "n" } },
			{ KEY_M,             { "M", "m" } },
			{ KEY_COMMA,         { "COMMA", "," } },
			{ KEY_PERIOD,        { "PERIOD", "." } },
			{ KEY_SLASH,         { "SLASH", "/" } },
			{ KEY_RIGHT_SHIFT,   { "RIGHT SHIFT", "" } },

			{ KEY_UP,            { "UP", "" } },
			{ KEY_KP_1,          { "NUMPAD 1", "1" } },
			{ KEY_KP_2,          { "NUMPAD 2", "2" } },
			{ KEY_KP_3,          { "NUMPAD 3", "3" } },
			// sixth row
			{ KEY_LEFT_CONTROL,  { "LEFT CTRL", "" } },
			{ KEY_LEFT_SUPER,    { "LEFT SUPER", "" } },
			{ KEY_LEFT_ALT,      { "LEFT ALT", "" } },
			{ KEY_SPACE,         { "SPACE", " " } },
			{ KEY_RIGHT_ALT,     { "RIGHT ALT", "" } },
			{ KEY_RIGHT_SUPER,   { "RIGHT SUPER", "" } },
			{ KEY_KB_MENU,       { "KB MENU", "" } },
			{ KEY_RIGHT_CONTROL, { "RIGHT CTRL", "" } },
			{ KEY_LEFT,          { "LEFT", "" } },
			{ KEY_DOWN,          { "DOWN", "" } },
			{ KEY_RIGHT,         { "RIGHT", "" } },
			{ KEY_KP_0,          { "NUMPAD 0", "0" } },
			{ KEY_KP_DECIMAL,    { "NUMPAD DECIMAL", "." } },
			{ KEY_KP_ENTER,      { "NUMPAD ENTER", "\n" } },
	};
}
