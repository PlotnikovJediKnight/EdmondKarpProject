#pragma once
#include "widgets.h"

namespace Logistics {
	class ApplicationMediator;
}

namespace Widgets {

	class MaxFlowButton : public Button {
	public:
		using Button::Button;
		virtual std::optional<LRESULT> HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM) override;
	};
}