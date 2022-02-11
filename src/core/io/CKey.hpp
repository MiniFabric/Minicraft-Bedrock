//
// Created by ENDERZOMBI102 on 11/02/2022.
//

#pragma once

namespace Minicraft::Core::IO {
	class CKey {
		int presses = 0; // how many times the Key has been pressed.
		int absorbs = 0; // how many key presses have been processed
		bool sticky = false; // true if presses reaches 3, and the key continues to be held down.
		bool stayDown;
	public:
		bool down = false; // if the key is currently physically being held down.
		bool clicked = false; // if the key is still being processed at the current tick.
	public:
		explicit CKey( bool stayDown = false ) {
			this->stayDown = stayDown;
		}
		~CKey() = default;

		/** toggles the key down or not down. */
		virtual auto toggle( bool pressed ) -> void;
		/** Processes the key presses. */
		virtual auto tick() -> void;
		/** Reset everything to initial state. */
		virtual auto release() -> void;

		[[nodiscard]] virtual auto toString() const -> std::string;
	};
}
