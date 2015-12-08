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

vector<Computer> Sql::getAllComputers(std::string orderBy, bool orderAscending)
{
    if(orderBy == "name")
    {
        if(orderAscending)
        {
            query.exec("SELECT * FROM Computers ORDER BY Name ASC");
        }
        else
        {
            query.exec("SELECT * FROM Computers ORDER BY Name DESC");
        }
    }
    if(orderBy == "born")
    {
        if(orderAscending)
        {
            query.exec("SELECT * FROM Computers ORDER BY build_year ASC");
        }
        else
        {
            query.exec("SELECT * FROM Computers ORDER BY build_year DESC");
        }
    }
    if(orderBy == "yearDied")
    {
        if(orderAscending)
        {
            query.exec("SELECT * FROM Computers ORDER BY type ASC");
        }
        else
        {
            query.exec("SELECT * FROM Computers ORDER BY type DESC");
        }
    }

    vector<Computer> allComputers;
    while(query.next())
    {
        allComputers.push_back(getComputerQuery(query));
    }
    return allComputers;
}

Computer Sql::getComputerQuery(QSqlQuery query)
{
    string name = query.value("name").toString().toStdString();
    int birth = query.value("Build_year").toUInt();
    string type = query.value("type").toString().toStdString();
    bool is_built = query.value("is_Built").toUInt();

    return Computer(name, birth, type, is_built);
}

vector<Computer> Sql::searchForComputers(std::string searchTerm)
{
    vector<Computer> allComputers = getAllComputers("name", true);
    vector<Computer> filteredComputers;

    for (unsigned int i = 0; i < allComputers.size(); i++)
    {
        if (allComputers.at(i).contains(searchTerm))
        {
            filteredComputers.push_back(allComputers.at(i));
        }
    }

    return filteredComputers;
}

bool Sql::addComputer(Computer comp)
{
    query.prepare("INSERT INTO Computers(Name, Build_year, type, Is_built)"
               "VALUES(:Name, :Build_year, :type, :Is_built)");

    query.bindValue(":Name", comp.getName().c_str());
    query.bindValue(":Build_year", comp.getBuiltYear());
    query.bindValue(":type", comp.getType().c_str());
    query.bindValue(":Is_built", comp.getIsBuilt());

    if(query.exec())
    {
        return true;
    }
    return false;
}
