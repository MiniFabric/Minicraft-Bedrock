//
// Created by ENDERZOMBI102 on 29/01/2022.
//
#ifndef CKEY_HPP
#define CKEY_HPP


namespace MiniCraft::Input {
	class CInputHandler;

	class CKey {
	private:
		CInputHandler *handler = nullptr;

	public:
		int presses = 0, absorbs = 0;
		bool down = false, clicked = false;
	public:
		CKey() = default;
		~CKey();

		void toggle(bool pressed);
		void tick();
		void setInputHandler( CInputHandler *pHandler );

		bool operator==(const CKey &other) const;
		bool operator!=(const CKey &other) const;
	};
}
#endif
