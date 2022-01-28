//
// Created by ENDERZOMBI102 on 29/01/2022.
//

#include <algorithm>
#include "CKey.hpp"

namespace MiniCraft {

	CKey::CKey( CInputHandler *handler ) noexcept {
		this->handler = handler;
		handler->keys.push_back(*this);
	}

	CKey::~CKey() {
		// remove reference to this key on destruction
		handler->keys.erase( std::remove( handler->keys.begin(), handler->keys.end(), *this ), handler->keys.end() );
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
}