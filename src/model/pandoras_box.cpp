#include "pandoras_box.hpp"
#include <cstdlib>

using std::srand;
using std::rand;

PandorasBox::PandorasBox() :
    m_city_generator(),
    m_nothing_generator()
{
    srand(0);
}

POIGenerator &PandorasBox::pick_poi_generator()
{
    if(rand() < RAND_MAX / 2) {
        return m_city_generator;
    }
    return m_nothing_generator;
}
