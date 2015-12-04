#include "sql.h"

#include <cstdlib>

using namespace std;
Sql::Sql()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Scientists_db.sqlite";
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


