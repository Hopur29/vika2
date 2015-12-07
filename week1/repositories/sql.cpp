#include "sql.h"
#include <QSqlQuery>
#include <cstdlib>
#include <QString>
#include "utilities/utils.h"
#include "utilities/constants.h"


using namespace std;
Sql::Sql()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Scientists.sqlite";
    db.setDatabaseName(dbName);
    db.open();
    query = QSqlQuery(db);
}

vector<Scientist> Sql::getAllScientists(std::string orderBy, bool orderAscending)
{
    if(orderBy == "name")
    {
        if(orderAscending)
        {
            query.exec("SELECT * FROM Scientists ORDER BY name ASC");
        }
        else
        {
            query.exec("SELECT * FROM Scientists ORDER BY name DESC");
        }
    }
    if(orderBy == "yearBorn")
    {
        if(orderAscending)
        {
            query.exec("SELECT * FROM Scientists ORDER BY born_year ASC");
        }
        else
        {
            query.exec("SELECT * FROM Scientists ORDER BY born_year DESC");
        }
    }
    if(orderBy == "yearDied")
    {
        if(orderAscending)
        {
            query.exec("SELECT * FROM Scientists ORDER BY death_year ASC");
        }
        else
        {
            query.exec("SELECT * FROM Scientists ORDER BY death_year DESC");
        }
    }

    vector<Scientist> allScientist;
    while(query.next())
    {
        allScientist.push_back(getScientistQuery(query));
    }
    return allScientist;
}

Scientist Sql::getScientistQuery(QSqlQuery query)
{
    string name = query.value("name").toString().toStdString();
    enum sexType sex = utils::stringToSex(query.value("sex").toString().toStdString());
    int birth = query.value("born_year").toUInt();
    int death = query.value("death_year").toUInt();

    return Scientist(name, sex, birth, death);
}

vector<Scientist> Sql::searchForScientists(string searchTerm)
{
    vector<Scientist> allScientists = getAllScientists("name", true);
    vector<Scientist> filteredScientists;

    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        if (allScientists.at(i).contains(searchTerm))
        {
            filteredScientists.push_back(allScientists.at(i));
        }
    }

    return filteredScientists;
}

bool Sql::addScientist(Scientist scientist)
{
    query.prepare("INSERT INTO scientists(name, sex, born_year, death_year)"
               "VALUES(:name, :sex, :born_year, :death_year)");
    query.bindValue(":name", scientist.getName().c_str());
    QString sex = QString::fromStdString(std::to_string(scientist.getSex()));
    query.bindValue(":sex", sex);
    query.bindValue(":born_year", scientist.getYearBorn());
    query.bindValue(":death_year", scientist.getYearDied());
    if(query.exec())
    {
     return true;
    }
    return false;

}

vector<Computer> Sql::getAllComputers()
{
    vector<Computer> computers;
    //db.open();

    /*
     * TODO: SQL kóða sem nær í allar tölvurnar úr gagnagrunn
     * og pushar þeim í vector
    */
    return computers;
}

vector<Computer> Sql::searchForComputers(std::string searchTerm)
{
    vector<Computer> computer;
    //db.open();
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
