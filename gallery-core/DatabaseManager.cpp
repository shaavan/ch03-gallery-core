#include "DatabaseManager.h"

#include <QSqlDatabase>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::DatabaseManager(const QString& path) :
    mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLite")))
{
    mDatabase->setDatabaseName(path);
    mDatabase->open();
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
    delete mDatabase;
}