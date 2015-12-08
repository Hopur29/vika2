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
bool Computer::contains(std::string searchTerm)
{
    string searchTermLower = utils::stringToLower(searchTerm);

    string nameLower = utils::stringToLower(name);
    if (nameLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    string yearBuilt = utils::intToString(buildYear);
    if (yearBuilt.find(searchTerm) != string::npos)
    {
        return true;
    }

    string typeLower = utils::stringToLower(type);
    if (typeLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    return false;
}
