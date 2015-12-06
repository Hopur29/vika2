#include "computerservice.h"
#include "utilities/Computercomparator.h"
#include <algorithm>

using namespace std;

Computerservice::Computerservice()
{

}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    /*
     * vector<Computer> Computers = ComputerRepo.getAllComputers();

    std::sort(Computers.begin(), Computers.end(), ComputerComparator(orderBy, orderAscending));
    */
    vector<Computer> Computers = ComputerSql.getAllComputers();
    return Computers;
}

std::vector<Computer> ComputerService::searchForComputers(std::string searchTerm)
{
    return ComputerSql.searchForComputers(searchTerm);
}

bool ComputerService::addComputer(Computer Computer)
{
    return ComputerSql.addComputer(Computer);
}
