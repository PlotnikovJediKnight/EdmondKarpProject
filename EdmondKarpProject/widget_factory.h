#pragma once
#include "widgets.h"
#include "window.h"
#include "src_button.h"
#include "snk_button.h"
#include "med_button.h"
#include "max_flow_button.h"
#include "network_area.h"

namespace Logistics {
    enum class WIDGET_ID;
}

namespace Widgets {

    class WidgetFactory {
    public:
        static std::unique_ptr<SRCButton> CreateSRCButton(HWND hOwner, Logistics::WIDGET_ID srcID, int x, int y, int width, int height);
        static std::unique_ptr<MEDButton> CreateMEDButton(HWND hOwner, Logistics::WIDGET_ID medID, int x, int y, int width, int height);
        static std::unique_ptr<SNKButton> CreateSNKButton(HWND hOwner, Logistics::WIDGET_ID snkID, int x, int y, int width, int height);
        static std::unique_ptr<MaxFlowButton> CreateMaxFlowButton(HWND hOwner, Logistics::WIDGET_ID maxflowID, int x, int y, int width, int height, const std::wstring& buttonText);
        static std::unique_ptr<Label> CreateLabel(HWND hOwner, Logistics::WIDGET_ID labelID, int x, int y, int width, int height, const std::wstring& textLabel);
        static std::unique_ptr<WindowFrame> CreateWindowFrame(HWND hOwner, Logistics::WIDGET_ID wndFrameID, int x, int y, int width, int height);
        static std::unique_ptr<NetworkArea> CreateNetworkArea(HWND hOwner, int x, int y, int width, int height);

        static Window::ClientAreaHolder CreateClientArea();
    };

}