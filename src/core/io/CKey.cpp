//
// Created by ENDERZOMBI102 on 11/02/2022.
//
#include <string>
#include <format>
#include "CKey.hpp"

namespace Minicraft::Core::IO {

	auto CKey::toggle(bool pressed) -> void {
		down = pressed; // Set down to the passed in value; the if statement is probably unnecessary...
		if ( pressed && !sticky )
			presses++; // Add to the number of total presses.
	}

	auto CKey::tick() -> void {
		if ( absorbs < presses ) { // If there are more key presses to process...
			absorbs++; // Process them!
			if ( presses - absorbs > 3 )
				absorbs = presses - 3;
			clicked = true; // Make clicked true, since key presses are still being processed.
		} else { // All key presses so far for this key have been processed.
			if (! sticky )
				sticky = presses > 3;
			else
				sticky = down;
			// Set clicked to false, since we're done processing;
			// UNLESS the key has been held down for a bit, and hasn't yet been released.
			clicked = sticky;
			// Reset the presses and absorbs, to ensure they don't get too high, or something:
			presses = 0;
			absorbs = 0;
		}
	}

	auto CKey::release() -> void {
		down = false;
		clicked = false;
		presses = 0;
		absorbs = 0;
		sticky = false;
	}

	auto CKey::toString() const -> std::string {
		return std::format( "down: {}; clicked: {}; presses={}; absorbs={}", down, clicked, presses, absorbs );
	}
}
