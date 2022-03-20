#include "src_button.h"
#include "application_logistics.h"

namespace Widgets {

	std::optional<LRESULT> SRCButton::HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM) {
		switch (uMsg) {
		case WM_COMMAND: {
			WORD word = LOWORD(wParam);

			if (word == (WORD)hButtonID) {
				OutputDebugStringA("YOU CLICKED SRC BUTTON!");
				Logistics::ApplicationMediator::Instance().SRCButtonClicked();
				return 0;
			}
		}
		}

		return std::nullopt;
	}

}