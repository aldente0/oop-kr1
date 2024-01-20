#pragma once
#include "Rect.h"
class RandomRect : public Rect
{
protected:
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
	void changeAll(POINT center)
	{
		int const startColor = 0, const endColor = 255;
		int const weight = rand() % (298 - 0 + 1) + 0;
		int const length = rand() % (298 - 0 + 1) + 0;

		rect.left = center.x - floor(weight / 2);
		rect.right = center.x + floor(weight / 2);
		rect.top = center.y - floor(length / 2);
		rect.bottom = center.y + floor(length / 2);

		color = RGB(
			rand() % (endColor - startColor + 1) + startColor,
			rand() % (endColor - startColor + 1) + startColor,
			rand() % (endColor - startColor + 1) + startColor
		);
	}

	virtual void output(HDC deviceContext)
	{
		HBRUSH brush = CreateSolidBrush(color);
		FillRect(deviceContext, &rect, brush);
		DeleteObject(brush);
	}

	virtual void hide(HDC deviceContext, int backgroundColor)
	{
		HBRUSH brush = CreateSolidBrush(backgroundColor);
		FillRect(deviceContext, &rect, brush);
		DeleteObject(brush);
	}
};

