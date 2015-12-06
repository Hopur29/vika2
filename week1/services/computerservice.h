#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "repositories/sql.h"
#include "repositories/scientistrepository.h"

/**
 * @brief The computerService acts as a middle layer between the UI and Data layers, also handles sorting
 */
class ComputerService
{
public:
    ComputerService();

    /**
     * @brief getAllcomputers fetches computers from the computerRepository and sorts them
     * @param orderBy Which column the computers should be sorted on
     * @param orderAscending Should the list be sorted in ascending order?
     * @return a vector containing all computers in the repository
     */
    std::vector<Computer> getAllComputers(std::string orderBy, bool orderAscending);

    /**
     * @brief searchForcomputers fetches all computers from file and filters them on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of computers filtered by searchTerm
     */
    std::vector<Computer> searchForComputers(std::string searchTerm);

    /**
     * @brief addcomputer saves a computer model to a file
     * @param computer The model to save
     * @return true if it was a success, false if it was a failure
     */
    bool addComputer(Computer computer);
private:
    //Repository computerRepo;
    Sql computerSql;
};
#endif // COMPUTERSERVICE_H
