#include "OutputerRect.h"
#include "RandomRect.h"

OutputerRect::OutputerRect(Rect* rect) : rect(*rect) {
	RandomRect* randomRect = static_cast<RandomRect*>(rect);
};