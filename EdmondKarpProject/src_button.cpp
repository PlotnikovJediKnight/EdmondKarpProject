#include "src_button.h"
#include "application_logistics.h"
#include "vertex_image_storage.h"
#include "image_resource.h"

namespace Widgets {

	std::optional<LRESULT> SRCButton::HandleWindowEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
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
			if (word == (WORD)hButtonID) {
				LPDRAWITEMSTRUCT pdis;
				pdis = (LPDRAWITEMSTRUCT)lParam;

				if (ApplicationMediator::Instance().IsSNKSelected() ||
					ApplicationMediator::Instance().IsMEDSelected()) {
					ApplicationMediator::Instance().SetSRCSelected(false);
					return TRUE;
				}

				HDC hMemDC = CreateCompatibleDC(pdis->hDC);
					DrawCustomButton(hMemDC, hWnd, pdis);
				DeleteDC(hMemDC);

				return TRUE;
			}
			break;
		}

		}

		return std::nullopt;
	}

	void SRCButton::DrawCustomButton(HDC hMemDC, HWND hWnd, LPDRAWITEMSTRUCT pdis) {
		using namespace Logistics;
		using namespace Images;
		const int SRC_VERTEX_ID = -1;

		switch (pdis->itemAction) {
		case ODA_SELECT:
			if ((pdis->itemState & ODS_SELECTED) && !(ApplicationMediator::Instance().IsSRCCreated())) {
				ApplicationMediator::Instance().FlipSRCSelected();
			}
		}

		if (ApplicationMediator::Instance().IsSRCSelected()) {
			SelectObject(hMemDC, VertexImageStorage::Instance(VertexTokenKind::MONO)[SRC_VERTEX_ID]);
		}
		else {
			if (!ApplicationMediator::Instance().IsSRCCreated()) {
				SelectObject(hMemDC, VertexImageStorage::Instance(VertexTokenKind::REGULAR)[SRC_VERTEX_ID]);
				ApplicationMediator::Instance().SetSRCSelected(false);
				ApplicationMediator::Instance().MakeWindowArrowCursor();
			}
			else
				SelectObject(hMemDC, VertexImageStorage::Instance(VertexTokenKind::MONO)[SRC_VERTEX_ID]);
		}

		FillRect(pdis->hDC, &pdis->rcItem, (HBRUSH)(COLOR_WINDOW + 1));
		TransparentBlt(pdis->hDC, 0, 0, 41, 41, hMemDC, 0, 0, 41, 41, COLOR_TO_BE_TRANSPARENT);
	}

}