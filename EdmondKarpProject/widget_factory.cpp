#include "widget_factory.h"

namespace Widgets {

    std::unique_ptr<SRCButton> WidgetFactory::CreateSRCButton(HWND hOwner, Logistics::WIDGET_ID srcID, int x, int y, int width, int height) {
        return std::make_unique<SRCButton>(hOwner, srcID, x, y, width, height);
    }

    std::unique_ptr<MEDButton> WidgetFactory::CreateMEDButton(HWND hOwner, Logistics::WIDGET_ID medID, int x, int y, int width, int height) {
        return std::make_unique<MEDButton>(hOwner, medID, x, y, width, height);
    }

    std::unique_ptr<SNKButton> WidgetFactory::CreateSNKButton(HWND hOwner, Logistics::WIDGET_ID snkID, int x, int y, int width, int height) {
        return std::make_unique<SNKButton>(hOwner, snkID, x, y, width, height);
    }

    std::unique_ptr<MaxFlowButton> WidgetFactory::CreateMaxFlowButton(HWND hOwner, Logistics::WIDGET_ID maxflowID, int x, int y, int width, int height, const std::wstring& buttonText) {
        return std::make_unique<MaxFlowButton>(hOwner, maxflowID, x, y, width, height, buttonText);
    }

    std::unique_ptr<Label> WidgetFactory::CreateLabel(HWND hOwner, Logistics::WIDGET_ID labelID, int x, int y, int width, int height, const std::wstring& textLabel) {
        return std::make_unique<Label>(hOwner, labelID, x, y, width, height, textLabel);
    }

    std::unique_ptr<WindowFrame> WidgetFactory::CreateWindowFrame(HWND hOwner, Logistics::WIDGET_ID wndFrameID, int x, int y, int width, int height) {
        return std::make_unique<WindowFrame>(hOwner, wndFrameID, x, y, width, height);
    }

    std::unique_ptr<NetworkArea> WidgetFactory::CreateNetworkArea(HWND hOwner, int x, int y, int width, int height) {
        return std::make_unique<NetworkArea>(hOwner, x, y, width, height);
    }

    Window::ClientAreaHolder WidgetFactory::CreateClientArea() {
        return std::make_unique<ClientArea>();
    }

}