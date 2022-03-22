#pragma once
#include "widgets.h"

namespace Logistics {
	class ApplicationMediator;
}

namespace Widgets {

	class SNKButton : public CustomButton {
	public:
		using CustomButton::CustomButton;
		virtual std::optional<LRESULT> HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM) override;
	protected:
		virtual void DrawCustomButton(HDC, HWND, LPDRAWITEMSTRUCT) override;
	};
}