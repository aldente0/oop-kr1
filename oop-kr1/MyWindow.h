#pragma once
#include "Quadrant.h"
class MyWindow
{
private:
	int center = 500;
	Quadrant* quadrants[4];
	void initQuadrants();
public:
	MyWindow(int center = 500) : center(center) {
		this->initQuadrants();
	}

	void outputWindow();
};

