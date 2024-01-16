#pragma once
#include "OutputerRandomRect.h"
class OutputerRandomEllipse :
    public OutputerRandomRect
{
public:
	OutputerRandomEllipse(RandomRect* randomRect)
		: OutputerRandomRect(randomRect) {};

    void output(HDC deviceContext) override
    {
		randomRect.changeAll();
		RECT r = randomRect.getRect();
		HBRUSH brush = CreateSolidBrush(randomRect.getColor());
		SelectObject(deviceContext, brush);
		Ellipse(deviceContext, r.left, r.top, r.right, r.bottom);
		DeleteObject(brush);
    }

	void hide(HDC deviceContext)
	{
		RECT r = randomRect.getRect();
		HBRUSH brush = CreateSolidBrush(0);
		SelectObject(deviceContext, brush);
		Ellipse(deviceContext, r.left, r.top, r.right, r.bottom);
		DeleteObject(brush);
	}
};

