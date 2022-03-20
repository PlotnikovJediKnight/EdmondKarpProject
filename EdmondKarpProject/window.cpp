#include "window.h"
#include <stdexcept>
using namespace std;

namespace Widgets {

	Window::Window(const wstring& windowClassName, WindowProcedurePointer wndProc, HINSTANCE hInstance) {
		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = 0;
		wcex.lpfnWndProc = wndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = 0;
		wcex.hCursor = LoadCursor(0, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = windowClassName.c_str();
		wcex.hIconSm = NULL;

		RegisterClassEx(&wcex);
	}

	HWND Window::GetWindowHandle() { return hWnd_; }

	std::optional<LRESULT> Window::ProcessWindowEvent(HWND hWnd, UINT uInt, WPARAM wParam, LPARAM lParam) {
		if (client_area_h_) {
			return client_area_h_->HandleWindowEvent(hWnd, uInt, wParam, lParam);
		}
		return std::nullopt;
	}


	void Window::SetClientAreaHolder(ClientAreaHolder holder) {
		client_area_h_ = move(holder);
	}

	void Window::Show() {
		MSG msg;
		ShowWindow(hWnd_, nCmdShow_);
		while (GetMessage(&msg, 0, 0, 0))
		{
			DispatchMessage(&msg);
		}
	}

	void Window::InstantiateWindow(const wstring& windowClassName, HINSTANCE hInstance, int nCmdShow, int width, int height, const wstring& windowTitle) {
		this->nCmdShow_ = nCmdShow;
		this->width_ = width;
		this->height_ = height;
		hWnd_ = CreateWindowEx(0, windowClassName.c_str(), windowTitle.c_str(),
			WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
			0, 0, width_, height_, 0, 0, hInstance, NULL);
	}
}