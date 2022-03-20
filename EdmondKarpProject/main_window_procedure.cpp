#include "main_window_procedure.h"
#include <stdexcept>
#include "window.h"
using namespace std;

namespace Widgets {

	MainWindowProcedure::MainWindowProcedure() : main_window_p_(nullptr) { 
		WindowProcedure::Register(L"MainWindowProcedure", this); 
	}

	LRESULT CALLBACK MainWindowProcedure::Procedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		if (main_window_p_ == nullptr) { throw runtime_error("No Main Window bound yet"); }
		else {

			switch (uMsg) {

			case WM_DESTROY: {
				PostQuitMessage(0);
			}


			}

			auto result = main_window_p_->ProcessWindowEvent(hWnd, uMsg, wParam, lParam);
			if (result) return result.value();;

			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
	}

	void MainWindowProcedure::SetMainWindowPointer(Window* wndPointer) {
		main_window_p_ = wndPointer;
	}
}