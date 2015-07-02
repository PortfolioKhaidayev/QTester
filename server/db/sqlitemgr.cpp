#include "sqlitemgr.h"

SQLiteMgr* SQLiteMgr::_instance = nullptr;

SQLiteMgr::SQLiteMgr() : SQLMgr()
{
}

SQLiteMgr::SQLiteMgr(const QString& dbHost, const QString &dbPath)
    : SQLMgr("QSQLITE", dbHost, dbPath, "", "")
{
}

SQLiteMgr* SQLiteMgr::instance(const QString &dbHost, const QString &dbPath)
{
    if( ! _instance ){
        _instance = new SQLiteMgr(dbHost, dbPath);
    }

    return _instance;
}

qlonglong SQLiteMgr::size(const QString &tableName)
{
    QSqlQuery query = select( tableName, {"COUNT(rowid) AS rCount"} );
    query.first();
    return query.value("rCount").toLongLong();
}

bool SQLiteMgr::sessionConfigurate(const DataMap &data)
{
    QSqlQuery query;

    if( ! data.isEmpty() )
    {
        QString query_string;
        for (auto it = data.begin(); it != data.end(); ++it) {
            query_string += "PRAGMA" + it.key() + " = " + it.value() + " \n";
        }

        bool success = false;
        if ( ! query.exec(query_string) ){
            qCritical() << "[SQLiteMgr::sessionConfigurate]\n"
                        << "SqlError: " << query.lastError().text();
            success = false;
        } else {
            success = true;
        }

        return success;
    }

    qCritical() << "[SQLiteMgr::sessionConfigurate]\n"
                << "Data is empty!";
    return false;
}
