#include <windows.h>
#include "window.h"
#include "main_window_procedure.h"
#include "main_window.h"
#include "widget_factory.h"
#include "application_logistics.h"
#include <string>
using namespace std;
using namespace Widgets;
using namespace Logistics;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MainWindowProcedure mainProcedure;
	MainWindow mainWindow(&mainProcedure, hInstance, nCmdShow, 800, 600, L"Программное средство для нахождения максимального потока сети");
	
	auto clientArea = WidgetFactory::CreateClientArea();
	auto srcButtonHolder = WidgetFactory::CreateSRCButton(mainWindow.GetWindowHandle(), WIDGET_ID::SRCBUTTONID, 655, 150, 42, 42);
	auto medButtonHolder = WidgetFactory::CreateMEDButton(mainWindow.GetWindowHandle(), WIDGET_ID::MEDBUTTONID, 655, 270, 42, 42);
	auto snkButtonHolder = WidgetFactory::CreateSNKButton(mainWindow.GetWindowHandle(), WIDGET_ID::SNKBUTTONID, 655, 375, 42, 42);
	auto maxFlowButtonHolder = WidgetFactory::CreateMaxFlowButton(mainWindow.GetWindowHandle(), WIDGET_ID::MAXFLOWBUTTONID, 605, 440, 140, 70, L"Найти максимальный поток сети");
	auto networkAreaHolder = WidgetFactory::CreateNetworkArea(mainWindow.GetWindowHandle(), 5, 5, 575, 525);

	ApplicationMediator::CreateInstance(srcButtonHolder.get(), medButtonHolder.get(), snkButtonHolder.get(), networkAreaHolder.get());

	clientArea->AddWidget(move(srcButtonHolder))
		.AddWidget(move(medButtonHolder))
		.AddWidget(move(snkButtonHolder))
		.AddWidget(move(maxFlowButtonHolder))
		.AddWidget(move(networkAreaHolder))
		.AddWidget(WidgetFactory::CreateLabel(mainWindow.GetWindowHandle(), WIDGET_ID::LABELID, 600, 15, 150, 85, L"Поиск \rмаксимального потока\r в сети\rалгоритмом\rЭдмондса-Карпа"))
		.AddWidget(WidgetFactory::CreateLabel(mainWindow.GetWindowHandle(), WIDGET_ID::LABELID, 600, 125, 150, 25, L"Исток сети"))
		.AddWidget(WidgetFactory::CreateLabel(mainWindow.GetWindowHandle(), WIDGET_ID::LABELID, 600, 230, 150, 40, L"Промежуточная вершина"))
		.AddWidget(WidgetFactory::CreateLabel(mainWindow.GetWindowHandle(), WIDGET_ID::LABELID, 600, 355, 150, 20, L"Сток сети"))
		.AddWidget(WidgetFactory::CreateWindowFrame(mainWindow.GetWindowHandle(), WIDGET_ID::NO_ID, 590, 5, 170, 525));

	mainWindow.SetClientAreaHolder(move(clientArea));
	mainWindow.Show();

	ApplicationMediator::DeleteInstance();

	return 0;
}