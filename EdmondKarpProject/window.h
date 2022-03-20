#pragma once
#include <memory>
#include <Windows.h>
#include <string>
#include <map>
#include "widgets.h"

namespace Widgets {


	class Window {
	public:
		using ClientAreaHolder = std::unique_ptr<ClientArea>;
		using MenuAreaHolder = std::unique_ptr<MenuArea>;
		using WindowProcedurePointer = LRESULT(CALLBACK*)(HWND, UINT, WPARAM, LPARAM);


		Window(const Window&) = delete;
		Window& operator = (const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(Window&&) = delete;

		void SetClientAreaHolder(ClientAreaHolder holder);
		void Show();
		HWND GetWindowHandle();
		std::optional<LRESULT> ProcessWindowEvent(HWND hWnd, UINT uInt, WPARAM wParam, LPARAM lParam);
	protected:
		Window(const std::wstring&, WindowProcedurePointer, HINSTANCE);

		int nCmdShow_;
		int width_;
		int height_;
		HWND hWnd_;
		std::wstring window_title_;
		ClientAreaHolder client_area_h_;

		void InstantiateWindow(const std::wstring&, HINSTANCE, int nCmdShow, int width, int height, const std::wstring& windowTitle);
	};
}
