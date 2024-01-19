#include "Quadrant.h"
#include "OutputerRandomEllipse.h"

void Quadrant::getRandomOutputer()
{
    int start = 1;
    int end = 2;
    int x = rand() % (end - start + 1) + start;
    
    switch (x)
    {
    case 1:
        this->outputer = new OutputerRandomRect(this->rect);
        break;
    case 2:
        this->outputer = new OutputerRandomEllipse(this->rect);
        break;
    default:
        break;
    }
}

void Quadrant::initRandomRect(int center, int distanceFromCenter)
{
    int left = 0, right = 0, top = 0, bottom = 0;
    switch (this->quadrantNumber)
    {
    case 1:
        left = center + distanceFromCenter;
        top = 0;
        right = center + center;
        bottom = center - distanceFromCenter;
        break;
    case 2: 
        left = 0;
        top = 0;
        right = center - distanceFromCenter;
        bottom = center - distanceFromCenter;
        break;
    case 3:
        left = 0;
        top = center + distanceFromCenter;
        right = center - distanceFromCenter;
        bottom = center + center;
        break;
    case 4:
        left = center + distanceFromCenter;
        top = center + distanceFromCenter;
        right = center + center;
        bottom = center + center;
        break;
    default:
        break;
    }
    this->rect = new RandomRect(left, top, right, bottom);
}