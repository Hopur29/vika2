#include "services/service.h"
//#include "utilities/scientistcomparator.h"
// #include "utilities/Computercomparator.h"

#include <algorithm>

using namespace std;

Service::Service()
{

}

std::vector<Scientist> Service::getAllScientists(std::string orderBy, bool orderAscending)
{
    /*
     * vector<Scientist> scientists = scientistRepo.getAllScientists();

    std::sort(scientists.begin(), scientists.end(), ScientistComparator(orderBy, orderAscending));
    */
    vector<Scientist> scientists = sqlDatabase.getAllScientists();
    return scientists;
}

std::vector<Scientist> Service::searchForScientists(std::string searchTerm)
{
    return sqlDatabase.searchForScientists(searchTerm);
}

bool Service::addScientist(Scientist scientist)
{
    return sqlDatabase.addScientist(scientist);
}

std::vector<Computer> Service::getAllComputers(std::string orderBy, bool orderAscending)
{
    /*
     * vector<Computer> Computers = ComputerRepo.getAllComputers();

    std::sort(Computers.begin(), Computers.end(), ComputerComparator(orderBy, orderAscending));
    */
    vector<Computer> Computers = sqlDatabase.getAllComputers();
    return Computers;
}

std::vector<Computer> Service::searchForComputers(std::string searchTerm)
{
    return sqlDatabase.searchForComputers(searchTerm);
}

bool Service::addComputer(Computer computer)
{
    return sqlDatabase.addComputer(computer);
}

