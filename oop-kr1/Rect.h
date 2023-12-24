#pragma once
#include "winLib.h"
#include <wingdi.h>

class Rect
{
protected:
	int fillStyle = 4;
	int color = RGB(200, 100, 200);
	RECT rect;
public:
	Rect(int left, int top, int right, int bottom);
	RECT getRect();
	int getColor();
	int getFillStyle();
};

