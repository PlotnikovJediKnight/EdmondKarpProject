#include "window_procedure.h"
#include <stdexcept>
using namespace std;

namespace Widgets {

	WindowProcedure& WindowProcedure::Instance(const wstring& name) {
		WindowProcedure* p = LookUp(name);
		return *p;
	}

	void WindowProcedure::Register(const wstring& name, WindowProcedure* pWndProc) {
		instances_[name] = pWndProc;
	}

	WindowProcedure* WindowProcedure::LookUp(const wstring& name) {
		auto it = instances_.find(name);

		if (it == instances_.end())
			throw out_of_range("No window procedure with name was registered!");
		else
			return it->second;
	}

	map<wstring, WindowProcedure*> WindowProcedure::instances_;

}