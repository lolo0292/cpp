#include "Data.hpp"

Data::Data() : number(0), text("default")
{
}

Data::Data(int n, const std::string &t) : number(n), text(t)
{
}
