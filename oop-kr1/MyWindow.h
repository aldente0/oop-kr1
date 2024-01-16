#pragma once
#include "Quadrant.h"
class MyWindow
{
private:
	int bgColor = RGB(0, 0, 0);
	int center = 500;
	Quadrant* quadrants[4];
	void initQuadrants();
	HDC deviceContext;
public:
	MyWindow(HDC deviceContext, int center = 300) : center(center), deviceContext(deviceContext) {
		this->initQuadrants();
	}

	void output()
	{
		this->outputWindow();

		while (true) {
			for (int i = 0; i < 4; i++) {
				Quadrant* quadrant = this->quadrants[i];
				quadrant->outputQuadrant(deviceContext, this->center);
			}
			Sleep(1000);
			for (int i = 0; i < 4; i++) {
				Quadrant* quadrant = this->quadrants[i];
				quadrant->hide(deviceContext, this->center);
			}
			Sleep(200);
		}
	}

	void outputWindow() {
		RECT r = { 0, 0, this->center + this->center, this->center + this->center };
		HBRUSH brush = CreateSolidBrush(this->bgColor);
		FillRect(this->deviceContext, &r, brush);
		DeleteObject(brush);
	}
};

