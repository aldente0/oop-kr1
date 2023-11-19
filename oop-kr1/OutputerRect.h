#pragma once
#include "winLib.h"
#include "Rect.h"

class OutputerRect
{
private:
	bool isOutputting = false;
protected:
	Rect rect;
public:
	OutputerRect(Rect& rect);
	virtual void output(HDC deviceContext)
	{
		if (! isOutputting) {
			RECT r = rect.getRect();
			HBRUSH brush = CreateSolidBrush(rect.getColor());
			FillRect(deviceContext, &r, brush);
			DeleteObject(brush);
			isOutputting = true;
		} else {
			RECT r = rect.getRect();
			HBRUSH brush = CreateSolidBrush(0);
			FillRect(deviceContext, &r, brush);
			DeleteObject(brush);
			isOutputting = false;
		}
	};
};
