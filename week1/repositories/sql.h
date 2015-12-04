#ifndef SQL_H
#define SQL_H
#include <QtSql>
#include <QSqlQuery>
#include <vector>
#include <string>
#include "models/scientist.h"
class Sql
{
public:
    Sql();
    std::vector<Scientist> getAllScientists();
private:
    QSqlDatabase db;
};

#endif // SQL_H
