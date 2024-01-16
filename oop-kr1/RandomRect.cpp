#include "RandomRect.h"

void RandomRect::changeAll()
{
	int const minRightSize = this->minLeft + 50, const minBottomSize = this->minTop + 50, const startColor = 0, const endColor = 255;
	rect.right = rand() % (this->maxRight - minRightSize + 1) + minRightSize;
	rect.bottom = rand() % (this->maxBottom - minBottomSize + 1) + minBottomSize;
	
	color = RGB(
		rand() % (endColor - startColor + 1) + startColor,
		rand() % (endColor - startColor + 1) + startColor,
		rand() % (endColor - startColor + 1) + startColor
	);
}