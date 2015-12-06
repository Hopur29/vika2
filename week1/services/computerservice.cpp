#include "services/computerservice.h"
// #include "utilities/Computercomparator.h"
#include <algorithm>

using namespace std;

ComputerService::ComputerService()
{

}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    /*
     * vector<Computer> Computers = ComputerRepo.getAllComputers();

    std::sort(Computers.begin(), Computers.end(), ComputerComparator(orderBy, orderAscending));
    */
    vector<Computer> Computers = computerSql.getAllComputers();
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
