#include "OutputerRect.h"

OutputerRect::OutputerRect(Rect& rect) : rect(rect) {};
void OutputerRect::output(HDC deviceContext)
{
	//HBRUSH hb = CreateHatchBrush(rect.getFillStyle(), rect.getColor());
	RECT r = rect.getRect();
	HBRUSH brush = CreateSolidBrush(rect.getColor());
	FillRect(deviceContext, &r, brush);
	DeleteObject(brush);
};

void OutputerRect::hide(HDC deviceContext, HWND hwnd)
{
	RECT r = rect.getRect();
	HBRUSH brush = (HBRUSH)GetClassLong(hwnd, GCLP_HBRBACKGROUND);
	FillRect(deviceContext, &r, brush);
	DeleteObject(brush);
};