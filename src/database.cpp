#include "database.h"


Database::Database():Singleton<Database>(*this)
{
    QSettings config("database.conf", QSettings::IniFormat);
    config.beginGroup("db");
    this->hostname = config.value("hostname").toString();
    this->dbname = config.value("db_name").toString();
    this->password = config.value("password").toString();
    this->port = config.value("port").toInt();
    this->username = config.value("user").toString();
}

bool Database::createConnection()
{

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(this->hostname);
    db.setPort(this->port);
    db.setUserName(this->username);
    db.setPassword(this->password);

    db.open();

    QSqlQuery query(db);
    query.exec("CREATE DATABASE " + this->dbname);
    db.close();

    db.setDatabaseName(this->dbname);
    qDebug() << query.lastError();
    return db.open();;
}

void Database::disconect()
{
    if(db.isOpen())
        db.close();
}

QString Database::lastError()
{
    return db.lastError().text();
}

