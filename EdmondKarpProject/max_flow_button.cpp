#include "max_flow_button.h"
#include "application_logistics.h"

namespace Widgets {

	std::optional<LRESULT> MaxFlowButton::HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM) {
		switch (uMsg) {
		case WM_COMMAND: {
			WORD word = LOWORD(wParam);

			if (word == (WORD)hButtonID) {
				OutputDebugStringA("YOU CLICKED Max Flow BUTTON!");
				Logistics::ApplicationMediator::Instance().MaxFlowButtonClicked();
				return 0;
			}
		}
		}

		return std::nullopt;
	}

}