#pragma once

#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

namespace Configuration
{
    extern pt::ptree config;
    void init(std::string filepath);
}
