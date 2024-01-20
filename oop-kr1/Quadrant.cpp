#include "Quadrant.h"

void Quadrant::initRandomRect(int center, int distanceFromCenter)
{
    int left = 0, right = 0, top = 0, bottom = 0, minLeft, maxLeft, minTop, maxTop, minRight, maxRight, minBottom, maxBottom;
    switch (this->quadrantNumber)
    {
    case 1:
        this->center.x = center + floor(center / 2);
        this->center.y = floor(center / 2);
        minLeft = center + distanceFromCenter;
        minTop = 0;
        maxRight = center + center;
        maxBottom = center - distanceFromCenter;
        break;
    case 2:
        this->center.x = floor(center / 2);
        this->center.y = floor(center / 2);
        minLeft = 0;
        minTop = 0;
        maxRight = center + center - distanceFromCenter;
        maxBottom = center - distanceFromCenter;
        break;
    case 3:
        this->center.x = floor(center / 2);
        this->center.y = center + floor(center / 2);
        minLeft = 0;
        minTop = center + distanceFromCenter;
        maxRight = center;
        maxBottom = center - distanceFromCenter;
        break;
    case 4:
        this->center.x = center + floor(center / 2);
        this->center.y = center + floor(center / 2);
        minLeft = center + distanceFromCenter;
        minTop = center + distanceFromCenter;
        maxRight = center + center;
        maxBottom = center - distanceFromCenter;
        break;
    default:
        break;
    }

    int start = 1;
    int end = 2;
    int x = rand() % (end - start + 1) + start;

    switch (x)
    {
    case 1:
        this->rect = new RandomRect(minLeft, minTop, maxRight, maxBottom);
        break;
    case 2:
        this->rect = new RandomEllipse(minLeft, minTop, maxRight, maxBottom);
        break;
    default:
        break;
    }
}