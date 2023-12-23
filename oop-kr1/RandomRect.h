#pragma once
#include "Rect.h"
class RandomRect : public Rect
{
private:
	int maxRight;
	int maxBottom;
	int minTop;
	int minLeft;
public:
	RandomRect(int left, int top, int right, int bottom, int color, int fillStyle)
		: Rect(left, top, right, bottom, color, fillStyle)
	{
		this->maxBottom = bottom;
		this->maxRight = right;
		this->minLeft = left;
		this->minTop = top;
	};
	void changeAll();
};

