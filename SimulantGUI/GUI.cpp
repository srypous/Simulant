#include "GUI.h"
#include "Controller.h"

GUI::GUI(HINSTANCE hInstance)
	: controller(nullptr)
	, hInstance(hInstance)
{
	int rmW = 446;
	int width = 1000;
	int height = 600;
	
	Gdiplus::GdiplusStartup(&this->gdiplusToken, &this->gdiplusStartupInput, NULL);

	this->reelMachine = new ReelMachine(50, 100, rmW, 5, 3);
	this->mainWindow = new MainWindow(this, hInstance, L"Hra 17 - simulátor", width, height);
	this->mainWindow->show();
	this->reelMachine->draw(this->mainWindow->getDC(), this->symbols);
	this->mainWindow->refresh();
}

GUI::~GUI()
{
	delete this->reelMachine;
	for (int i = 0; i < this->symbols.size(); i++)
		DeleteObject(this->symbols[i]);
	delete this->mainWindow;
}

void GUI::setNewSpin(const Spin& spin)
{
	this->reelMachine->draw(this->mainWindow->getDC(), this->symbols, &spin);
	this->mainWindow->refresh();
}

void GUI::setNewDescription(const std::wstring& description)
{
	this->mainWindow->setDescription(description);
}

void GUI::assignController(Controller * controller)
{
	this->controller = controller;
}

void GUI::addSymbol(int resourceID)
{
	this->symbols.push_back(LoadBitmap(this->hInstance, MAKEINTRESOURCE(resourceID)));
}

void GUI::userStartClicked()
{
	this->controller->userStartClicked();
}

void GUI::userBackClicked()
{
	this->controller->userBackClicked();
}

void GUI::userBetUpClicked()
{
	this->controller->userBetUpClicked();
}

void GUI::userBetDownClicked()
{
	this->controller->userBetDownClicked();
}

void GUI::setGoBackEnabled(bool enabled)
{
	this->mainWindow->setButtonBackEnabled(enabled);
}
