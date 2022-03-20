#include "snk_button.h"
#include "application_logistics.h"

namespace Widgets {

	std::optional<LRESULT> SNKButton::HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM) {
		switch (uMsg) {
		case WM_COMMAND: {
			WORD word = LOWORD(wParam);

			if (word == (WORD)hButtonID) {
				OutputDebugStringA("YOU CLICKED SNK BUTTON!");
				Logistics::ApplicationMediator::Instance().SNKButtonClicked();
				return 0;
			}
		}
		}

		return std::nullopt;
	}

}