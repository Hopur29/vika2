#ifndef SQL_H
#define SQL_H
#include <QtSql>

#include <vector>
#include <string>
#include "models/scientist.h"
#include "models/computer.h"

class Sql
{
public:
    Sql();
    std::vector<Scientist> getAllScientists(std::string orderBy, bool orderAscending);
    std::vector<Scientist> searchForScientists(std::string searchTerm);
    bool addScientist(Scientist);
    std::vector<Computer> getAllComputers(std::string orderBy, bool orderAscending);
    std::vector<Computer> searchForComputers(std::string searchTerm);
    bool addComputer(Computer comp);

private:
    QSqlDatabase db;
    QSqlQuery query;
    Scientist getScientistQuery(QSqlQuery query);
    Computer getComputerQuery(QSqlQuery query);
};

#endif // SQL_H
