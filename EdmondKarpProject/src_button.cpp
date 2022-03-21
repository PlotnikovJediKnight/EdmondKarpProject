#include "src_button.h"
#include "application_logistics.h"

namespace Widgets {

	std::optional<LRESULT> SRCButton::HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		using namespace Logistics;
		WORD word = LOWORD(wParam);

		switch (uMsg) {
		case WM_COMMAND: {

			if (word == (WORD)hButtonID) {
				return ApplicationMediator::Instance().SRCButtonClicked();
			}
			break;
		}

		case WM_DRAWITEM: {
			/*LPDRAWITEMSTRUCT pdis;
			pdis = (LPDRAWITEMSTRUCT)lParam;

			HDC hMemDC = CreateCompatibleDC(pdis->hDC);

			if (word == (WORD)hButtonID) {
				if (SNK_IS_SELECTED || MED_IS_SELECTED) {
					SRC_IS_SELECTED = 0;
					return TRUE;
				}
				break;
			}

			DrawItemDependingOnParameters(hWnd, hMemDC, pdis, wParam);

			FillRect(pdis->hDC, &pdis->rcItem, (HBRUSH)(COLOR_WINDOW + 1));
			TransparentBlt(pdis->hDC, 0, 0, 41, 41,
				hMemDC, 0, 0, 41, 41, COLOR_TO_BE_TRANSPARENT);



			DeleteDC(hMemDC);
			*/
			return TRUE;
		}
		}

		return std::nullopt;
	}

}