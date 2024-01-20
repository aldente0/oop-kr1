#pragma once
#include "Quadrant.h"
class MyWindow
{
private:
	int penWidth = 4;
	int bgColor = RGB(200, 100, 0);
	int center = 500;
	Quadrant* quadrants[4];
	void initQuadrants()
	{
		for (int i = 0; i < 4; i++) {
			int quadrantNumber = i + 1;
			this->quadrants[i] = new Quadrant(quadrantNumber, this->penWidth, this->center);
		}
	}
public:
	MyWindow(int center = 300, int bgColor = RGB(0, 0, 0)) : center(center), bgColor(bgColor)
	{
		this->initQuadrants();
	}

	void output(HDC deviceContext)
	{
		this->outputWindow(deviceContext);

		while (true) {
			for (int i = 0; i < 4; i++) {
				Quadrant* quadrant = this->quadrants[i];
				quadrant->outputQuadrant(deviceContext);
			}
			Sleep(1000);
			for (int i = 0; i < 4; i++) {
				Quadrant* quadrant = this->quadrants[i];
				quadrant->hide(deviceContext, this->bgColor);
			}
			Sleep(200);
		}
	}

	void outputWindow(HDC deviceContext) {
		HPEN pen = CreatePen(PS_SOLID, 4, RGB(255, 255, 255));
		HBRUSH brushLines = CreateSolidBrush(RGB(255, 255, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(deviceContext, brushLines);
		HPEN oldPen = (HPEN)SelectObject(deviceContext, pen);
		RECT r = { 0, 0, this->center + this->center, this->center + this->center };
		HBRUSH brush = CreateSolidBrush(this->bgColor);
		FillRect(deviceContext, &r, brush);
		MoveToEx(deviceContext, 0, this->center, nullptr);
		LineTo(deviceContext, this->center * 2, this->center);
		MoveToEx(deviceContext, this->center, 0, nullptr);
		LineTo(deviceContext, this->center, this->center * 2);
		SelectObject(deviceContext, oldPen);
		SelectObject(deviceContext, oldBrush);
		DeleteObject(brush);
		DeleteObject(pen);
	}

	~MyWindow()
	{
		for (int i = 0; i < 4; i++) {
			delete this->quadrants[i];
		}
	}
};

