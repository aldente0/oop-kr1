#pragma once
#include "OutputerRect.h"
#include "RandomRect.h"
class OutputerRandomRect : public OutputerRect
{
public:
	RandomRect randomRect;
	OutputerRandomRect(RandomRect* randomRect)
		: OutputerRect(randomRect),  randomRect(*randomRect) {};

	void output(HDC deviceContext) override
	{
		system("cls");
		randomRect.changeAll();
		RECT r = randomRect.getRect();
		HBRUSH brush = CreateSolidBrush(randomRect.getColor());
		FillRect(deviceContext, &r, brush);
		DeleteObject(brush);
	}
};

