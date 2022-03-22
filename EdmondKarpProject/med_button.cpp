#include "med_button.h"
#include "application_logistics.h"

namespace Widgets {

	std::optional<LRESULT> MEDButton::HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM) {
		switch (uMsg) {
		case WM_COMMAND: {
			WORD word = LOWORD(wParam);

			if (word == (WORD)hButtonID) {
				OutputDebugStringA("YOU CLICKED MED BUTTON!");
				Logistics::ApplicationMediator::Instance().MEDButtonClicked();
				return 0;
			}
		}
		}

		return std::nullopt;
	}

	void MEDButton::DrawCustomButton(HDC, HWND, LPDRAWITEMSTRUCT) {

	}

}