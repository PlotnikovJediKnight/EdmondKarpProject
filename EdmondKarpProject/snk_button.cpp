#include "snk_button.h"
#include "application_logistics.h"
#include"vertex_image_storage.h"
#include "image_resource.h"

namespace Widgets {

	std::optional<LRESULT> SNKButton::HandleWindowEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		using namespace Logistics;
		WORD word = LOWORD(wParam);

		switch (uMsg) {
		case WM_COMMAND: {

			if (word == (WORD)hButtonID) {
				return ApplicationMediator::Instance().SNKButtonClicked();
			}
			break;
		}

		case WM_DRAWITEM: {
			if (word == (WORD)hButtonID) {
				LPDRAWITEMSTRUCT pdis;
				pdis = (LPDRAWITEMSTRUCT)lParam;


				if (ApplicationMediator::Instance().IsSRCSelected() ||
					ApplicationMediator::Instance().IsMEDSelected()) {
					ApplicationMediator::Instance().SetSNKSelected(false);
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

	void SNKButton::DrawCustomButton(HDC hMemDC, HWND hWnd, LPDRAWITEMSTRUCT pdis) {
		using namespace Logistics;
		using namespace Images;
		const int SNK_VERTEX_ID = -2;

		switch (pdis->itemAction) {
		case ODA_SELECT:
			if ((pdis->itemState & ODS_SELECTED) && !(ApplicationMediator::Instance().IsSNKCreated())) {
				ApplicationMediator::Instance().FlipSNKSelected();
			}
		}

		if (ApplicationMediator::Instance().IsSNKSelected()) {
			SelectObject(hMemDC, VertexImageStorage::Instance(VertexTokenKind::MONO)[SNK_VERTEX_ID]);
		}
		else {
			if (!ApplicationMediator::Instance().IsSNKCreated()) {
				SelectObject(hMemDC, VertexImageStorage::Instance(VertexTokenKind::REGULAR)[SNK_VERTEX_ID]);
				ApplicationMediator::Instance().SetSNKSelected(false);
				ApplicationMediator::Instance().MakeWindowArrowCursor();
			}
			else
				SelectObject(hMemDC, VertexImageStorage::Instance(VertexTokenKind::MONO)[SNK_VERTEX_ID]);
		}

		FillRect(pdis->hDC, &pdis->rcItem, (HBRUSH)(COLOR_WINDOW + 1));
		TransparentBlt(pdis->hDC, 0, 0, 41, 41, hMemDC, 0, 0, 41, 41, COLOR_TO_BE_TRANSPARENT);
	}

}