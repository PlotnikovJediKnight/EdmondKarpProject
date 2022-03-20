#pragma once
#include <Windows.h>
#include <memory>
#include <optional>
#include <vector>
#include <stdexcept>

namespace Logistics {
	enum class WIDGET_ID;
}

namespace Widgets {

	class Widget {
	public:
		using WidgetHolder = std::unique_ptr<Widget>;

		virtual std::optional<LRESULT> HandleWindowEvent(HWND, UINT, WPARAM, LPARAM) = 0;

		virtual Widget& AddWidget(WidgetHolder);
		virtual void RemoveWidget(size_t index);
		virtual const Widget* GetChild(size_t index) const;

		virtual void UpdateWidgetVisuals();

		virtual ~Widget() = default;
	};

	class ClientArea : public Widget {
	public:
		virtual ClientArea& AddWidget(WidgetHolder newWidget) override;
		virtual void RemoveWidget(size_t index) override;
		virtual const Widget* GetChild(size_t index) const override;
		virtual std::optional<LRESULT> HandleWindowEvent(HWND hWnd, UINT uInt, WPARAM wParam, LPARAM lParam) override;

	private:
		std::vector<std::unique_ptr<Widget>> widgets_;
	};

	class Button : public Widget {
	public:
		Button(HWND ownerHandler, Logistics::WIDGET_ID buttonID, int x, int y, int width, int height, const std::wstring& buttonText);
	protected:
		HWND hWndButton;
		Logistics::WIDGET_ID hButtonID;
	};

	class CustomButton : public Widget {
	public:
		CustomButton(HWND ownerHandler, Logistics::WIDGET_ID buttonID, int x, int y, int width, int height);
	protected:
		HWND hWndButton;
		Logistics::WIDGET_ID hButtonID;
	};

	class Label : public Widget {
	public:
		Label(HWND ownerHandler, Logistics::WIDGET_ID labelID, int x, int y, int width, int height, const std::wstring& labelText);
		virtual std::optional<LRESULT> HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM lParam);
	protected:
		HWND hWndLabel;
		Logistics::WIDGET_ID hLabelID;
	};

	class WindowFrame : public Widget {
	public:
		WindowFrame(HWND ownerHandler, Logistics::WIDGET_ID frameID, int x, int y, int width, int height);
		virtual std::optional<LRESULT> HandleWindowEvent(HWND, UINT uMsg, WPARAM wParam, LPARAM lParam);
	protected:
		HWND hWndFrame;
		Logistics::WIDGET_ID hFrameID;
	};

	class MenuArea : public Widget {

	};

}