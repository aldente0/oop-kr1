#pragma once
#include "RandomRect.h"
#include "OutputerRandomRect.h"
class Quadrant
{
private:
	int quadrantNumber;
	RandomRect* rect;
	OutputerRandomRect* outputer;
	void getRandomOutputer();
	void initRandomRect(int center, int distanceFromCenter);
public:
	Quadrant(int quadrantNumber, int center, int distanceFromCenter) : quadrantNumber(quadrantNumber)
	{
		this->initRandomRect(center, distanceFromCenter);
		this->getRandomOutputer();
	};

	void outputQuadrant(HDC deviceContext)
	{
		this->outputer->output(deviceContext);
	}

	void hide(HDC deviceContext)
	{
		this->outputer->hide(deviceContext);
	}
};

