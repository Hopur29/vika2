#ifndef SERVICE_H
#define SERVICE_H
#include "repositories/sql.h"


class Service
{
public:
    Service();

    /**
     * @brief getAllScientists fetches scientists from the ScientistRepository and sorts them
     * @param orderBy Which column the scientists should be sorted on
     * @param orderAscending Should the list be sorted in ascending order?
     * @return a vector containing all scientists in the repository
     */
    std::vector<Scientist> getAllScientists(std::string orderBy, bool orderAscending);

    /**
     * @brief searchForScientists fetches all scientists from file and filters them on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of scientists filtered by searchTerm
     */
    std::vector<Scientist> searchForScientists(std::string searchTerm);

    /**
     * @brief addScientist saves a scientist model to a file
     * @param scientist The model to save
     * @return true if it was a success, false if it was a failure
     */
    bool addScientist(Scientist scientist);

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

    std::vector<Computer> searchForRelation(std::string searchTerm);

private:
    Sql sqlDatabase;
};

#endif // SERVICE_H
