#include "sql.h"

#include <cstdlib>

using namespace std;
Sql::Sql()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Scientists.sqlite";
    db.setDatabaseName(dbName);
}

vector<Scientist> Sql::getAllScientists()
{
    vector<Scientist> scientist;
    db.open();

    /*
     * TODO: SQL kóða sem nær í alla vísindamenn úr gagnagrunn
     * og pushar þeim í vector
    */
    return scientist;
}

vector<Scientist> Sql::searchForScientists(string searchTerm)
{
    vector<Scientist> scientist;
    db.open();
    /*
     * TODO: SQL kóða sem leitar í gagnagrunninum eftir searchTerm færibreytunni
     * og pushar leitarniðurstöðum í vector
    */
    return scientist;
}

bool Sql::addScientist(Scientist scientist)
{
    /*
     * Insertar scientist inn í gagnagrunn
     * returnar false ef ekki tekst að bæta scientist við
     */
    return true;
}

vector<Computer> Sql::getAllComputers()
{
    vector<Computer> computers;
    db.open();

    /*
     * TODO: SQL kóða sem nær í allar tölvurnar úr gagnagrunn
     * og pushar þeim í vector
    */
    return computers;
}

vector<Computer> Sql::searchForComputers(std::string searchTerm)
{
    vector<Computer> computer;
    db.open();
    /*
     * TODO: SQL kóða sem leitar í gagnagrunninum eftir searchTerm færibreytunni
     * og pushar leitarniðurstöðum í vector
    */
    return computer;
}

bool Sql::addComputer(Computer)
{
    /*
     * Insertar computer inn í gagnagrunn
     * returnar false ef ekki tekst að bæta scientist við
     */
    return true;
}
