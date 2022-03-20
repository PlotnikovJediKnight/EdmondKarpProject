#pragma once
#include "widgets.h"

namespace Logistics {
	class ApplicationMediator;
}

namespace Widgets {
	class WidgetFactory;
}

namespace Widgets {

	class WindowFrame;
	using WindowFrameHolder = std::unique_ptr<WindowFrame>;

	class NetworkArea : public Widget {
	public:
		NetworkArea(HWND ownerHandler, int x, int y, int width, int height);

		virtual std::optional<LRESULT> HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM) override;
		virtual void UpdateWidgetVisuals();

	private:
		WindowFrameHolder wnd_frame_h_;

		HWND hWnd;

		size_t draw_area_x_;
		size_t draw_area_y_;
		size_t draw_area_height_;
		size_t draw_area_width_;

		void RedrawNetworkArea(HDC hdc);
		void RedrawBackground(HDC hMemDC);
	};
}