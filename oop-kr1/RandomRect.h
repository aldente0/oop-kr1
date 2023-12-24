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
	RandomRect(int left, int top, int right, int bottom)
		: Rect(left, top, right, bottom)
	{
		this->maxBottom = bottom;
		this->maxRight = right;
		this->minLeft = left;
		this->minTop = top;
	};
	void changeAll();
};

