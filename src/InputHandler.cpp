//
// Created by ENDERZOMBI102 on 28/01/2022.
//
#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#include <algorithm>
#include <iostream>
#include "InputHandler.hpp"

namespace MiniCraft {
	CKey::CKey() noexcept {
		keys.push_back(*this);
	}

	CKey::~CKey() {
		// remove reference to this key on destruction
		keys.erase( std::remove( keys.begin(), keys.end(), *this ), keys.end() );
	}

	void CKey::toggle(bool pressed) {
		if (pressed != down) {
			down = pressed;
		}

		if (pressed) {
			presses++;
		}
	}

	void CKey::tick() {
		if (absorbs < presses) {
			absorbs++;
			clicked = true;
		} else {
			clicked = false;
		}
	}

	bool CKey::operator==(const CKey &other) const {
		return other.presses == this->presses &&
		       other.absorbs == this->absorbs &&
		       other.clicked == this->clicked &&
		       other.down == this->down;
	}

	bool CKey::operator!=(const CKey &other) const {
		return !( *this == other );
	}

	void CInputHandler::releaseAll() {
		for ( auto key : keys ) {
			key.down = false;
		}
	}

	void CInputHandler::tick() {
		for ( auto key : keys ) {
			key.tick();
		}
	}

	void CInputHandler::toggle(SDL_Event *evt, bool pressed) {
		switch ( evt->key.keysym.sym ) {
			// UP
			case SDLK_KP_8:
			case SDLK_w:
			case SDLK_UP:
				up.toggle( pressed );
				break;
			// DOWN
			case SDLK_KP_2:
			case SDLK_s:
			case SDLK_DOWN:
				down.toggle( pressed );
				break;
			// LEFT
			case SDLK_KP_4:
			case SDLK_a:
			case SDLK_LEFT:
				left.toggle( pressed );
				break;
			// RIGHT
			case SDLK_KP_6:
			case SDLK_d:
			case SDLK_RIGHT:
				right.toggle( pressed );
				break;
			// MENU
			case SDLK_TAB:
			case SDLK_LALT:
			case SDLK_RALT:
			case SDLK_RETURN:
			case SDLK_x:
				menu.toggle( pressed );
				break;
			// ATTACK
			case SDLK_SPACE:
			case SDLK_RCTRL:
			case SDLK_LCTRL:
			case SDLK_KP_0:
			case SDLK_INSERT:
			case SDLK_c:
				attack.toggle( pressed );
				break;
			// NOTHINGS
			default:
				break;
		}
	}

	void CInputHandler::printState() {
		std::cout << "up: " << up.down << "down: " << down.down << "left: " << left.down << "right: " << right.down << "menu: " << menu.down << "attack: " << attack.down << "\n";
	}
}

#pragma clang diagnostic pop