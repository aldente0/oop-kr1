#pragma once
#include "Rect.h"
class RandomRect : public Rect
{
public:
	RandomRect(int left, int top, int right, int bottom, int color, int fillStyle)
		: Rect(left, top, right, bottom, color, fillStyle) {};
	void changeAll();
};

