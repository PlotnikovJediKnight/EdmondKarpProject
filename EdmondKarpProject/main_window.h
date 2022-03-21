#pragma once
#include "window.h"
#include "main_window_procedure.h"

namespace Widgets {

	class MainWindow : public Window {
	private:
		static inline const std::wstring window_class_name_{ L"MainWindow" };
	public:
		MainWindow(MainWindowProcedure *p, HINSTANCE hInstance, int nCmdShow, int width, int height, const std::wstring& windowTitle);

		void SelectArrowCursor();
		void SelectCrossCursor();
	};
}
