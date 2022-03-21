#include "application_logistics.h"
#include "main_window.h"
#include "src_button.h"
#include "network_area.h"

namespace Logistics {
	ApplicationMediator* ApplicationMediator::_instance = nullptr;

	ApplicationMediator::ApplicationMediator(Widgets::MainWindow* mainWndP, Widgets::SRCButton* srcBtnP, Widgets::MEDButton* medBtnP, Widgets::SNKButton* snkBtnP, Widgets::NetworkArea* nwAreaP)
		: main_wnd_p_(mainWndP), src_btn_p_(srcBtnP), med_btn_p_(medBtnP), snk_btn_p_(snkBtnP), nw_area_p_(nwAreaP),
		  src_is_selected_(false), src_is_created_(false),
		  snk_is_selected_(false),
		  med_is_selected_(false) {  }

	void ApplicationMediator::CreateInstance(Widgets::MainWindow* mainWndP, Widgets::SRCButton* srcBtnP, Widgets::MEDButton* medBtnP, Widgets::SNKButton* snkBtnP, Widgets::NetworkArea* nwAreaP) {
		if (_instance == nullptr) {
			_instance = new ApplicationMediator(mainWndP, srcBtnP, medBtnP, snkBtnP, nwAreaP);
		}
	}

	ApplicationMediator& ApplicationMediator::Instance() {
		return *_instance;
	}

	void ApplicationMediator::DeleteInstance()
	{
		delete _instance;
	}

	void ApplicationMediator::MakeWindowCrossCursor() {
		main_wnd_p_->SelectCrossCursor();
	}

	void ApplicationMediator::MakeWindowArrowCursor() {
		main_wnd_p_->SelectArrowCursor();
	}

	//====================================================

	int ApplicationMediator::SRCButtonClicked() {
		if (IsSNKSelected() || IsMEDSelected()) {
			SetSRCSelected(false);
			return 0;
		}

		if (!IsSRCCreated() && IsSRCSelected()) {
			MakeWindowCrossCursor();
		}
		else {
			SetSRCSelected(false);
		}

		return 0;
	}

	bool ApplicationMediator::IsSRCSelected() {
		return src_is_selected_;
	}

	void ApplicationMediator::SetSRCSelected(bool selected) {
		src_is_selected_ = selected;
	}

	bool ApplicationMediator::IsSRCCreated() {
		return src_is_created_;
	}

	//====================================================

	void ApplicationMediator::MEDButtonClicked() {
	}

	bool ApplicationMediator::IsMEDSelected() {
		return med_is_selected_;
	}

	void ApplicationMediator::SetMEDSelected(bool selected){
		med_is_selected_ = selected;
	}

	//====================================================

	void ApplicationMediator::SNKButtonClicked() {

	}

	bool ApplicationMediator::IsSNKSelected() {
		return snk_is_selected_;
	}

	void ApplicationMediator::SetSNKSelected(bool selected){
		snk_is_selected_ = selected;
	}

	//====================================================

	void ApplicationMediator::MaxFlowButtonClicked() {
	}

}