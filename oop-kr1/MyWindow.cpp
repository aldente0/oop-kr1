#include "MyWindow.h"

void MyWindow::initQuadrants()
{
	for (int i = 0; i < 4; i++) {
		int quadrantNumber = i + 1;
		this->quadrants[i] = new Quadrant(quadrantNumber, this->center);
	}
}

void MyWindow::outputWindow()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND console_handle = GetConsoleWindow();
	HDC deviceContext = GetDC(console_handle);

	while (true) {
		system("cls");
		for (int i = 0; i < 4; i++) {
			Quadrant* quadrant = this->quadrants[i];
			quadrant->outputQuadrant(deviceContext, this->center);
		}
		Sleep(1000);
	}
}