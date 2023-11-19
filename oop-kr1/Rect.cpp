#include "Rect.h"

Rect::Rect(int left, int top, int right, int bottom, int color, int fillStyle) : color(color), fillStyle(fillStyle)
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