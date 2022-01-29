//
// Created by ENDERZOMBI102 on 29/01/2022.
//

#include <algorithm>
#include "CKey.hpp"
#include "InputHandler.hpp"

namespace MiniCraft {

	CKey::~CKey() {
		// remove reference to this key on destruction
		if (
				this->handler != nullptr &&
				std::find(this->handler->keys.begin(), this->handler->keys.end(), this ) != this->handler->keys.end()
		)
			this->handler->keys.erase(
					std::remove( handler->keys.begin(), handler->keys.end(), this ),
					this->handler->keys.end()
			);
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

	void CKey::setInputHandler( MiniCraft::CInputHandler *pHandler ) {
		this->handler = pHandler;
		this->handler->keys.push_back(this);
	}
}