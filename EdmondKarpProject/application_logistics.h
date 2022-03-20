#pragma once
#include <memory>

namespace Widgets {
	class SRCButton;
	class MEDButton;
	class SNKButton;
	class NetworkArea;
}

namespace Logistics {

	enum class WIDGET_ID { NO_ID, LABELID, SRCBUTTONID, MEDBUTTONID, SNKBUTTONID, MAXFLOWBUTTONID};

	class ApplicationMediator {
	public:

		static void CreateInstance(
			Widgets::SRCButton* srcBtnP,
			Widgets::MEDButton* medBtnP,
			Widgets::SNKButton* snkBtnP,
			Widgets::NetworkArea* nwAreaP);

		static ApplicationMediator& Instance();
		static void DeleteInstance();

		void SRCButtonClicked();
		void MEDButtonClicked();
		void SNKButtonClicked();
		void MaxFlowButtonClicked();

		ApplicationMediator(const ApplicationMediator&) = delete;
		ApplicationMediator& operator = (const ApplicationMediator&) = delete;

	private:
		ApplicationMediator(
			Widgets::SRCButton* srcBtnP,
			Widgets::MEDButton* medBtnP,
			Widgets::SNKButton* snkBtnP,
			Widgets::NetworkArea* nwAreaP);

		static ApplicationMediator* _instance;

		Widgets::SRCButton* src_btn_p_;
		Widgets::MEDButton* med_btn_p_;
		Widgets::SNKButton* snk_btn_p_;
		Widgets::NetworkArea* nw_area_p_;
	};

}
