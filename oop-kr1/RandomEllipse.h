#pragma once
#include "RandomRect.h"
class RandomEllipse : public RandomRect
{
public:
	RandomEllipse(int left, int top, int right, int bottom)
		: RandomRect(left, top, right, bottom)
	{};

	void output(HDC deviceContext)
	{
		HBRUSH brush = CreateSolidBrush(color);
		SelectObject(deviceContext, brush);
		Ellipse(deviceContext, rect.left, rect.top, rect.right, rect.bottom);
		DeleteObject(brush);
	}

	void hide(HDC deviceContext)
	{
		HBRUSH brush = CreateSolidBrush(0);
		SelectObject(deviceContext, brush);
		Ellipse(deviceContext, rect.left, rect.top, rect.right, rect.bottom);
		DeleteObject(brush);
	}
};

