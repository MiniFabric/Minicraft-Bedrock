//
// Created by ENDERZOMBI102 on 29/01/2022.
//

#include <algorithm>
#include "CKey.hpp"
#include "InputHandler.hpp"

namespace MiniCraft::Input {

	CKey::~CKey() {
		// remove reference to this key on destruction
		if (
			this->handler != nullptr &&
					std::find(this->handler->bindings.begin(), this->handler->bindings.end(), this ) != this->handler->bindings.end()
		)
			this->handler->bindings.erase(
				std::remove(handler->bindings.begin(), handler->bindings.end(), this ),
				this->handler->bindings.end()
			);
	}

	auto CKey::toggle( bool pressed ) -> void{
		if (pressed != down) {
			down = pressed;
		}

		if (pressed) {
			presses++;
		}
	}

	auto CKey::tick() -> void {
		if ( absorbs < presses ) {
			absorbs++;
			clicked = true;
		} else {
			clicked = false;
		}
	}

	auto CKey::operator==(const CKey &other) const -> bool {
		return other.presses == this->presses &&
		       other.absorbs == this->absorbs &&
		       other.clicked == this->clicked &&
		       other.down == this->down;
	}

	auto CKey::operator!=(const CKey &other) const -> bool {
		return !( *this == other );
	}

	auto CKey::setInputHandler( CInputHandler *pHandler ) -> void {
		this->handler = pHandler;
		this->handler->bindings.push_back(this);
	}

	auto CKey::getBoundKeys() -> std::set<KeyboardKey> {
		return this->boundKeys;
	}

	auto CKey::addBoundKey( std::initializer_list<KeyboardKey> keys ) -> void {
		for ( auto key : keys ) {
			this->boundKeys.insert( key );
		}
	}

	auto CKey::handle( KeyboardKey key ) -> void {
		if ( this->boundKeys.contains(key) ) {
			this->toggle( IsKeyDown(key) );
		}
	}
}