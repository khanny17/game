#include "random.hpp"
#include <cstdlib>

int Random::between(int min, int max)
{
    return rand() % (max-min + 1) + min;
}
