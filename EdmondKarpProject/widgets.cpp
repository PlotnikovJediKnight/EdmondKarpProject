#include "widgets.h"

namespace Widgets {

	Widget& Widget::AddWidget(WidgetHolder) {
		throw std::runtime_error("AddWidget() is not implemented!");
	}

	void Widget::RemoveWidget(size_t index) {
		throw std::runtime_error("RemoveWidget() is not implemented!");
	}

	const Widget* Widget::GetChild(size_t index) const { throw std::runtime_error("Widget() is not implemented!"); }

	void Widget::UpdateWidgetVisuals() {
		throw std::runtime_error("UpdateWidgetVisuals() is not implemented!");
	}

	//===============================================================================================================

	ClientArea& ClientArea::AddWidget(WidgetHolder newWidget) {
		widgets_.push_back(std::move(newWidget));
		return *this;
	}

	void ClientArea::RemoveWidget(size_t index) {
		widgets_.erase(widgets_.begin() + index);
	}

	const Widget* ClientArea::GetChild(size_t index) const {
		return widgets_.at(index).get();
	}

	std::optional<LRESULT> ClientArea::HandleWindowEvent(HWND hWnd, UINT uInt, WPARAM wParam, LPARAM lParam) {
		for (auto& widget : widgets_) {
			auto result = widget->HandleWindowEvent(hWnd, uInt, wParam, lParam);
			if (result) return result;
		}
		return std::nullopt;
	}

	//===============================================================================================================

	Button::Button(HWND ownerHandler, Logistics::WIDGET_ID buttonID, int x, int y, int width, int height, const std::wstring& buttonText) : hButtonID(buttonID) {

		hWndButton = CreateWindowEx(WS_EX_WINDOWEDGE, L"Button", buttonText.c_str(), WS_VISIBLE | WS_CHILD | BS_MULTILINE,
			x, y,
			width, height,
			ownerHandler, (HMENU)static_cast<int>(buttonID),
			NULL, NULL);
	}

	//===============================================================================================================

	CustomButton::CustomButton(HWND ownerHandler, Logistics::WIDGET_ID buttonID, int x, int y, int width, int height) : hButtonID(buttonID) {

		hWndButton = CreateWindowEx(WS_EX_WINDOWEDGE, L"Button", NULL, WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
			x, y,
			width, height,
			ownerHandler, (HMENU)static_cast<int>(buttonID),
			NULL, NULL);
	}

	//===============================================================================================================

	Label::Label(HWND ownerHandler, Logistics::WIDGET_ID labelID, int x, int y, int width, int height, const std::wstring& labelText) : hLabelID(labelID) {

		hWndLabel = CreateWindowEx(WS_EX_WINDOWEDGE, L"Static", L"ST_U", WS_VISIBLE | WS_CHILD | DT_CENTER,
			x, y,
			width, height,
			ownerHandler, (HMENU)static_cast<int>(labelID),
			NULL, NULL);

		SetWindowText(hWndLabel, labelText.c_str());
	}

	std::optional<LRESULT> Label::HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM lParam) {

		static HBRUSH hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
		switch (uMsg) {
		case WM_CTLCOLORSTATIC: {
			if (hWndLabel == (HWND)lParam) {
				HDC hdcStatic = (HDC)wParam;
				SetTextColor(hdcStatic, RGB(0, 0, 0));
				SetBkColor(hdcStatic, RGB(255, 255, 255));
				return (INT_PTR)hBrush;
			}
		}
		}

		return std::nullopt;
	}

	//===============================================================================================================

	WindowFrame::WindowFrame(HWND ownerHandler, Logistics::WIDGET_ID frameID, int x, int y, int width, int height) : hFrameID(frameID) {

		hWndFrame = CreateWindowEx(WS_EX_WINDOWEDGE, L"Button", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | BS_GROUPBOX,
			x, y,
			width, height,
			ownerHandler, (HMENU)static_cast<int>(frameID),
			NULL, NULL);
	}
	
	std::optional<LRESULT> WindowFrame::HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		return std::nullopt;
	}
}