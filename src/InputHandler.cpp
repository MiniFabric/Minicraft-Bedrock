//
// Created by ENDERZOMBI102 on 28/01/2022.
//
#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <iostream>
#include "InputHandler.hpp"

namespace MiniCraft {

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
				this->up.toggle( pressed );
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