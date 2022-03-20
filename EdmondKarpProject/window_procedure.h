#pragma once
#include <Windows.h>
#include <string>
#include <map>

namespace Widgets {

	class WindowProcedure {
	public:
		virtual LRESULT CALLBACK Procedure(HWND, UINT, WPARAM, LPARAM) = 0;

		static WindowProcedure& Instance(const std::wstring& name);

		WindowProcedure(const WindowProcedure&) = delete;
		WindowProcedure& operator = (const WindowProcedure&) = delete;

		virtual ~WindowProcedure() = default;
	protected:
		static void Register(const std::wstring& name, WindowProcedure*);
		WindowProcedure() = default;
	private:
		static WindowProcedure* LookUp(const std::wstring& name);
		static std::map<std::wstring, WindowProcedure*> instances_;
	};

#define GENERATE_WINDOW_PROCEDURE_CODE(WINDOW_PROCEDURE_CLASSNAME)\
	LRESULT CALLBACK WINDOW_PROCEDURE_CLASSNAME##Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { \
		return Widgets::WindowProcedure::Instance(L#WINDOW_PROCEDURE_CLASSNAME).Procedure(hWnd, uMsg, wParam, lParam);\
	}\

}
