#include "city_center.hpp"

CityCenter::CityCenter(Vector2<float> position) :
    Object(position, Vector2<float>(1,1))
{
}

void CityCenter::update(float /*elapsed_time*/)
{
}

Object::Type CityCenter::get_type() const
{
    return CITY_CENTER;
}
