//
// Created by ENDERZOMBI102 on 28/01/2022.
//

#include <iostream>
#include "InputHandler.hpp"

namespace MiniCraft::Input {

	CInputHandler::CInputHandler() {
		this->up.setInputHandler( this );
		this->up.addBoundKey( { KEY_KP_8, KEY_W, KEY_UP } );
		this->down.setInputHandler( this );
		this->down.addBoundKey( { KEY_KP_8, KEY_W, KEY_UP } );
		this->left.setInputHandler( this );
		this->left.addBoundKey({ KEY_KP_2, KEY_S, KEY_DOWN } );
		this->right.setInputHandler( this );
		this->right.addBoundKey({ KEY_KP_4, KEY_A, KEY_LEFT } );
		this->menu.setInputHandler( this );
		this->menu.addBoundKey({ KEY_TAB, KEY_LEFT_ALT, KEY_RIGHT_ALT, KEY_ENTER, KEY_KP_ENTER, KEY_X } );
		this->attack.setInputHandler( this );
		this->attack.addBoundKey({ KEY_SPACE, KEY_RIGHT_CONTROL, KEY_LEFT_CONTROL, KEY_KP_0, KEY_INSERT, KEY_C } );
	}

	auto CInputHandler::releaseAll() -> void {
		for ( auto binding : bindings ) {
			binding->down = false;
		}
	}

	auto CInputHandler::tick() -> void {
		for ( auto key = GetKeyPressed(); key != 0; key = GetKeyPressed() ) {
			for ( auto binding : this->bindings )
				binding->handle( static_cast<KeyboardKey>(key) );
		}
		std::cout << __FILE__ << " " << __LINE__ << std::endl;
		for ( auto binding : bindings ) {
			binding->tick();
		}
	}

	auto CInputHandler::printState() const -> void {
		std::cout << "up: " << up.down <<
					" down: " << down.down <<
					" left: " << left.down <<
					" right: " << right.down <<
					" menu: " << menu.down <<
					" attack: " << attack.down << std::endl;
	}
}
