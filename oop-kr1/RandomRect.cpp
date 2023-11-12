#include "RandomRect.h"

void RandomRect::changeAll()
{
	int const minSize = 100, const maxSize = 400, const startColor = 0, const endColor = 255;
	rect.right = rand() % (maxSize - minSize + 1) + minSize;
	rect.bottom = rand() % (maxSize - minSize + 1) + minSize;
	
	color = RGB(rand() % (endColor - startColor + 1) + startColor,
		rand() % (endColor - startColor + 1) + startColor,
		rand() % (endColor - startColor + 1) + startColor);
}