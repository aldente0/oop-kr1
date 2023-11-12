#pragma once
#include "winLib.h"
#include "Rect.h"

class OutputerRect
{
protected:
	Rect rect;
public:
	OutputerRect(Rect& rect);
	void output(HDC deviceContext);
	void hide(HDC deviceContext, HWND hwnd);
};

