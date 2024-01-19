#pragma once
#include "RandomRect.h"
#include "OutputerRandomRect.h"
class Quadrant
{
private:
	int distanceFromCenter;
	int quadrantNumber;
	RandomRect* rect;
	OutputerRandomRect* outputer;
	void getRandomOutputer();
	void initRandomRect(int center, int distanceFromCenter);
public:
	Quadrant(int quadrantNumber, int penWidth) : quadrantNumber(quadrantNumber)
	{
		this->distanceFromCenter = floor(penWidth / 2);
	};

	void outputQuadrant(HDC deviceContext, int center)
	{
		this->initRandomRect(center, this->distanceFromCenter);
		this->getRandomOutputer();
		this->outputer->output(deviceContext);
	}

	void hide(HDC deviceContext, int backgroundColor)
	{
		this->outputer->hide(deviceContext, backgroundColor);
	}
};

