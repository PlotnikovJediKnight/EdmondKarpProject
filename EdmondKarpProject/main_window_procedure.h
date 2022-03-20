#pragma once
#include "window_procedure.h"

namespace Widgets {
	class Window;

	inline GENERATE_WINDOW_PROCEDURE_CODE(MainWindowProcedure);

	class MainWindowProcedure : public WindowProcedure {
	public:
		MainWindowProcedure();
		virtual LRESULT CALLBACK Procedure(HWND, UINT, WPARAM, LPARAM) override;
		void SetMainWindowPointer(Window* wndPointer);
	private:
		Window* main_window_p_;
	};

}
