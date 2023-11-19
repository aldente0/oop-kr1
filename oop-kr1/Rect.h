#pragma once
#include "winLib.h"
#include <wingdi.h>

class Rect
{
protected:
	int color, fillStyle;
	RECT rect;
public:
	Rect(int left, int top, int right, int bottom, int color, int fillStyle);
	RECT getRect();
	int getColor();
	int getFillStyle();
};

