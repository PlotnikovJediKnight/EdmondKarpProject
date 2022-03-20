#include "main_window.h"
using namespace std;

namespace Widgets {

	MainWindow::MainWindow(MainWindowProcedure* p, HINSTANCE hInstance, int nCmdShow, int width, int height, const wstring& windowTitle)
		: Window(window_class_name_, MainWindowProcedureProc, hInstance) {
		p->SetMainWindowPointer(this);
		InstantiateWindow(window_class_name_, hInstance, nCmdShow, width, height, windowTitle);
	}

}