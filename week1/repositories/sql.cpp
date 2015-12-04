#include "sql.h"
#include <QtSql>

Sql::Sql()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "student_db.sqlite";
        db.setDatabaseName(dbName);
}

