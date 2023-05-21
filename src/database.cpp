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
    if(db.open()){
        createTableLicenses();
        createTableUsers();
        createTableComputer();
        createTableLicensor();
        createTableProgram();
    }
    else return false;
    return true;
}

void Database::disconect()
{
    if(db.isOpen())
        db.close();
}

bool Database::createTableUsers()
{
    QSqlQuery query(db);
    bool res = query.exec(QString("CREATE TABLE IF NOT EXISTS USERS(") +
                          QString("ID SERIAL PRIMARY KEY,") +
                          QString("FNAME VARCHAR,") +
                          QString("LNAME VARCHAR, ") +
                          QString("LOGIN VARCHAR, ") +
                          QString("PASSWORD VARCHAR, ")+
                          QString("UROLE VARCHAR)"));
    qDebug() << query.lastError().text();
    return res;
}

bool Database::createTableLicenses()
{
    QSqlQuery query(db);
    bool res = query.exec(QString("CREATE TABLE IF NOT EXISTS LICENSES(") +
                          QString("ID SERIAL PRIMARY KEY,") +
                          QString("START_L DATE,") +
                          QString("END_L DATE,") +
                          QString("PRICE INTEGER,") +
                          QString("NAME VARCHAR)"));
    qDebug() << query.lastError().text();
    return res;
}

bool Database::createTableProgram()
{
    QSqlQuery query(db);
    bool res = query.exec(QString("CREATE TABLE IF NOT EXISTS PROGRAMS(") +
                          QString("ID SERIAL PRIMARY KEY,") +
                          QString("NAME VARCHAR, ") +
                          QString("LIC_ID INTEGER, ") +
                          QString("FOREIGN KEY (LIC_ID) REFERENCES LICENSES(ID) ON DELETE CASCADE)"));
    qDebug() << query.lastError().text();
    return res;
}

bool Database::createTableLicensor()
{
    QSqlQuery query(db);
    bool res = query.exec(QString("CREATE TABLE IF NOT EXISTS LICENSORS(") +
                          QString("ID SERIAL PRIMARY KEY,") +
                          QString("ADDRESS VARCHAR,") +
                          QString("NAME VARCHAR, ") +
                          QString("LIC_ID INTEGER, ") +
                          QString("FOREIGN KEY (LIC_ID) REFERENCES LICENSES(ID) ON DELETE CASCADE)"));
    qDebug() << query.lastError().text();
    return res;
}

bool Database::createTableComputer()
{
    QSqlQuery query(db);
    bool res = query.exec(QString("CREATE TABLE IF NOT EXISTS COMPUTERS(") +
                          QString("ID SERIAL PRIMARY KEY,") +
                          QString("NAME VARCHAR, ") +
                          QString("LIC_ID INTEGER, ") +
                          QString("FOREIGN KEY (LIC_ID) REFERENCES LICENSES(ID) ON DELETE CASCADE)"));
    qDebug() << query.lastError().text();
    return res;
}

bool Database::login(QString login, QString password)
{
    QSqlQuery query(db);
    query.prepare("SELECT EXISTS (SELECT * FROM USERS WHERE LOGIN = :login AND PASSWORD = :password)");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();
    qDebug() << query.lastError().text();
    return query.result();
}

void Database::addUser(User u)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO USERS(LNAME, FNAME, LOGIN, PASSWORD, UROLE) VALUES (:fn, :ln, :login, :password, :role)");
    query.bindValue(":fn", u.fname);
    query.bindValue(":ln", u.lname);
    query.bindValue(":login", u.login);
    query.bindValue(":password", u.password);
    query.bindValue(":role", u.role);
    query.exec();
    qDebug() << query.lastError();
}

QString Database::lastError()
{
    return db.lastError().text();
}

