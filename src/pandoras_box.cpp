#include "pandoras_box.hpp"

PandorasBox::PandorasBox() :
    m_city_generator()
{
}

POIGenerator &PandorasBox::pick_poi_generator()
{
    return m_city_generator;
}
