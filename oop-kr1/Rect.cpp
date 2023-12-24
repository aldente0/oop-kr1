#include "Rect.h"

Rect::Rect(int left, int top, int right, int bottom)
{
	rect = { left, top, right, bottom };
}

RECT Rect::getRect()
{
	return rect;
};
int Rect::getColor()
{
	return color;
};
int Rect::getFillStyle()
{
	return fillStyle;
};