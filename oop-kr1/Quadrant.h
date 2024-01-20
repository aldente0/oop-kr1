#pragma once
#include "RandomRect.h"
#include "RandomEllipse.h"

class Quadrant
{
private:
	POINT center;
	int distanceFromCenter;
	int quadrantNumber;
	RandomRect* rect;
	void initRandomRect(int center, int distanceFromCenter);
public:
	Quadrant(int quadrantNumber, int penWidth, int center) : quadrantNumber(quadrantNumber)
	{
		this->distanceFromCenter = floor(penWidth / 2);
		this->initRandomRect(center, this->distanceFromCenter);
	};

	void outputQuadrant(HDC deviceContext)
	{
		rect->changeAll(this->center);
		this->rect->output(deviceContext);
	}

	void hide(HDC deviceContext, int backgroundColor)
	{
		this->rect->hide(deviceContext, backgroundColor);
	}
};

