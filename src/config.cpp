#include "config.hpp"
#include <boost/property_tree/ini_parser.hpp>

namespace Configuration
{
    pt::ptree config;
    void init(std::string filepath)
    {
        pt::read_ini(filepath, config);
    }
}
