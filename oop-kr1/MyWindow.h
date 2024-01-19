#pragma once
#include "Quadrant.h"
class MyWindow
{
private:
	int penWidth = 4;
	int bgColor = RGB(200, 100, 0);
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
				quadrant->hide(deviceContext, this->bgColor);
			}
			Sleep(200);
		}
	}

	void outputWindow() {
		HPEN pen = CreatePen(PS_SOLID, 4, RGB(255, 255, 255));
		HBRUSH brushLines = CreateSolidBrush(RGB(255, 255, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(this->deviceContext, brushLines);
		HPEN oldPen = (HPEN)SelectObject(this->deviceContext, pen);
		RECT r = { 0, 0, this->center + this->center, this->center + this->center };
		HBRUSH brush = CreateSolidBrush(this->bgColor);
		FillRect(this->deviceContext, &r, brush);
		MoveToEx(this->deviceContext, 0, this->center, nullptr);
		LineTo(this->deviceContext, this->center * 2, this->center);
		MoveToEx(this->deviceContext, this->center, 0, nullptr);
		LineTo(this->deviceContext, this->center, this->center * 2);
		SelectObject(this->deviceContext, oldPen);
		SelectObject(this->deviceContext, oldBrush);
		DeleteObject(brush);
		DeleteObject(pen);
	}
	~MyWindow()
	{
	}
};

