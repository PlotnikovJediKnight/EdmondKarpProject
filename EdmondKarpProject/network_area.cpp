#include "network_area.h"
#include "application_logistics.h"
#include "widget_factory.h"

namespace Widgets {
	NetworkArea::NetworkArea(HWND ownerHandler, int x, int y, int width, int height)
		: hWnd(ownerHandler), draw_area_x_(x + 15), draw_area_y_(y + 15), draw_area_width_(width - 25), draw_area_height_(height - 25) {
		wnd_frame_h_ = WidgetFactory::CreateWindowFrame(ownerHandler, Logistics::WIDGET_ID::NO_ID, x, y, width, height);
	}



	void NetworkArea::RedrawNetworkArea(HDC hdc) {
		HDC hMemDC = CreateCompatibleDC(hdc);
		HBITMAP memBM = CreateCompatibleBitmap(hdc, draw_area_width_, draw_area_height_);
		SelectObject(hMemDC, memBM);

		RedrawBackground(hMemDC);
		//DrawAllEdgesBack(hMemDC);
		//DrawAllVerticesBack(hMemDC);


		BitBlt(hdc, draw_area_x_, draw_area_y_, draw_area_width_, draw_area_height_, hMemDC, 0, 0, SRCCOPY);
		DeleteDC(hMemDC);
		DeleteObject(memBM);
	}

	std::optional<LRESULT> NetworkArea::HandleWindowEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM) {
		switch (uMsg) {
		case WM_PAINT: {
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
				RedrawNetworkArea(hdc);
			EndPaint(hWnd, &ps);
			return 0;
		}
		}

		return std::nullopt;
	}

	void NetworkArea::UpdateWidgetVisuals() {
		HDC hdc = GetDC(hWnd);
		RedrawNetworkArea(hdc);
		ReleaseDC(hWnd, hdc);
	}

	void NetworkArea::RedrawBackground(HDC hMemDC) {
		RECT rect;
		SetRect(&rect, 0, 0, draw_area_width_, draw_area_height_);
		FillRect(hMemDC, &rect, (HBRUSH)(COLOR_3DLIGHT + 1));
	}

}