#include "services/scientistservice.h"
//#include "utilities/scientistcomparator.h"

#include <algorithm>

using namespace std;

ScientistService::ScientistService()
{

}

std::vector<Scientist> ScientistService::getAllScientists(std::string orderBy, bool orderAscending)
{
    vector<Scientist> scientists = scientistSql.getAllScientists(orderBy, orderAscending);

    return scientists;
}

std::vector<Scientist> ScientistService::searchForScientists(std::string searchTerm)
{
    return scientistSql.searchForScientists(searchTerm);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistSql.addScientist(scientist);
}
