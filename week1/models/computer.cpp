#include "models/Computer.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

using namespace std;


Computer::Computer(string name, int buildYear, string type, bool isBuilt)
{
    this->name = name;
    this->buildYear = buildYear;
    this->type = type;
    this->isBuilt= isBuilt;
}

string Computer::getName() const
{
    return name;
}

int Computer::getBuiltYear() const
{
    return buildYear;
}

string Computer::getType() const
{
    return type;
}

bool Computer::getIsBuilt() const
{
    return isBuilt;
}
