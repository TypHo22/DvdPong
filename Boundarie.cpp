#include "Boundarie.h"

Boundarie::Boundarie()
{

}

void Boundarie::setBoundarie(const float width, const float height)
{
    width_ = width;
    height_ = height;
}

bool Boundarie::checkInsideOfBoundarie(const float x, const float y) const
{
    if(x < 0.0 || x > width_)
        return false;

    if(y < 0.0 || y > height_)
        return false;

    return true;
}
