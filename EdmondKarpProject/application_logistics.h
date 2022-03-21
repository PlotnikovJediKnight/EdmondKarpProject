#pragma once
#include <memory>

namespace Widgets {
	class MainWindow;
	class SRCButton;
	class MEDButton;
	class SNKButton;
	class NetworkArea;
}

namespace Logistics {

	enum class WIDGET_ID { NO_ID, LABELID, SRCBUTTONID, MEDBUTTONID, SNKBUTTONID, MAXFLOWBUTTONID };

	class ApplicationMediator {
	public:

		static void CreateInstance(
			Widgets::MainWindow* mainWndP,
			Widgets::SRCButton* srcBtnP,
			Widgets::MEDButton* medBtnP,
			Widgets::SNKButton* snkBtnP,
			Widgets::NetworkArea* nwAreaP);

		static ApplicationMediator& Instance();
		static void DeleteInstance();

		void MakeWindowCrossCursor();
		void MakeWindowArrowCursor();

		int SRCButtonClicked();
		bool IsSRCSelected();
		void SetSRCSelected(bool);
		bool IsSRCCreated();

		void MEDButtonClicked();
		bool IsMEDSelected();
		void SetMEDSelected(bool);

		void SNKButtonClicked();
		bool IsSNKSelected();
		void SetSNKSelected(bool);

		void MaxFlowButtonClicked();

		ApplicationMediator(const ApplicationMediator&) = delete;
		ApplicationMediator& operator = (const ApplicationMediator&) = delete;

	private:
		ApplicationMediator(
			Widgets::MainWindow* mainWndP,
			Widgets::SRCButton* srcBtnP,
			Widgets::MEDButton* medBtnP,
			Widgets::SNKButton* snkBtnP,
			Widgets::NetworkArea* nwAreaP);

		static ApplicationMediator* _instance;

		Widgets::MainWindow* main_wnd_p_;

		Widgets::SRCButton* src_btn_p_;
		Widgets::MEDButton* med_btn_p_;
		Widgets::SNKButton* snk_btn_p_;
		Widgets::NetworkArea* nw_area_p_;

		bool src_is_selected_;
		bool src_is_created_;

		bool snk_is_selected_;
		bool med_is_selected_;
	};

}
