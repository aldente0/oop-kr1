#include "MyWindow.h"

void MyWindow::initQuadrants()
{
	for (int i = 0; i < 4; i++) {
		int quadrantNumber = i + 1;
		this->quadrants[i] = new Quadrant(quadrantNumber, this->penWidth);
	}
}