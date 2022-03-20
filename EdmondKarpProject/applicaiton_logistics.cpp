#include "application_logistics.h"
#include "src_button.h"
#include "network_area.h"

namespace Logistics {
	ApplicationMediator* ApplicationMediator::_instance = nullptr;

	ApplicationMediator::ApplicationMediator(Widgets::SRCButton* srcBtnP, Widgets::MEDButton* medBtnP, Widgets::SNKButton* snkBtnP, Widgets::NetworkArea* nwAreaP)
		: src_btn_p_(srcBtnP), med_btn_p_(medBtnP), snk_btn_p_(snkBtnP), nw_area_p_(nwAreaP) {  }

	void ApplicationMediator::CreateInstance(Widgets::SRCButton* srcBtnP, Widgets::MEDButton* medBtnP, Widgets::SNKButton* snkBtnP, Widgets::NetworkArea* nwAreaP) {
		if (_instance == nullptr) {
			_instance = new ApplicationMediator(srcBtnP, medBtnP, snkBtnP, nwAreaP);
		}
	}

	ApplicationMediator& ApplicationMediator::Instance() {
		return *_instance;
	}

	void ApplicationMediator::DeleteInstance()
	{
		delete _instance;
	}

	void ApplicationMediator::SRCButtonClicked() {
	}

	void ApplicationMediator::MEDButtonClicked() {
	}

	void ApplicationMediator::SNKButtonClicked() {
	}

	void ApplicationMediator::MaxFlowButtonClicked() {
	}

}