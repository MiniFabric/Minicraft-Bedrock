//
// Created by ENDERZOMBI102 on 28/01/2022.
//
#include <algorithm>
#include "InputHandler.hpp"

namespace MiniCraft {
	CKey::CKey() noexcept {
		keys->push_back(*this);
	}

	CKey::~CKey() {
		// remove reference to this key on destruction
		keys->erase(std::remove(keys->begin(), keys->end(), this), keys->end());
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
}
