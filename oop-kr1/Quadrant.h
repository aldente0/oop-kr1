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
	void initRandomRect(int center);
public:
	Quadrant(int quadrantNumber, int center) : quadrantNumber(quadrantNumber)
	{
		this->initRandomRect(center);
		this->getRandomOutputer();
	};

	void outputQuadrant(HDC deviceContext, int center)
	{
		this->initRandomRect(center);
		this->getRandomOutputer();
		this->outputer->output(deviceContext);
	}

	void hide(HDC deviceContext, int center)
	{
		this->outputer->hide(deviceContext);
	}
};

