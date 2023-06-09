#include "database.h"

Database::Database()
    : Singleton<Database>(*this)
{
    QSettings config("database.ini", QSettings::IniFormat);
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
    if (db.open()) {
        createTableUsers();
        createTableComputer();
        createTableLicensor();
        createTableProgram();
        createTableLicenses();
    } else
        return false;
    return true;
}

void Database::disconect()
{
    if (db.isOpen())
        db.close();
}

bool Database::createTableUsers()
{
    QSqlQuery query(db);
    bool res = query.exec(QString("CREATE TABLE IF NOT EXISTS USERS(") + QString("ID SERIAL PRIMARY KEY,") + QString("FNAME VARCHAR NOT NULL,") + QString("LNAME VARCHAR NOT NULL, ") + QString("LOGIN VARCHAR NOT NULL, ") + QString("PASSWORD VARCHAR NOT NULL, ") + QString("UROLE VARCHAR NOT NULL)"));
    qDebug() << query.lastError().text();
    return res;
}

bool Database::createTableLicenses()
{
    QSqlQuery query(db);
    bool res = query.exec(QString("CREATE TABLE IF NOT EXISTS LICENSES(") + QString("ID SERIAL PRIMARY KEY,") + QString("START_L DATE NOT NULL,") + QString("END_L DATE NOT NULL,") + QString("PRICE INTEGER NOT NULL,") + QString("NAME VARCHAR NOT NULL, ") + QString("COMPUTER_ID INTEGER NOT NULL, FOREIGN KEY (COMPUTER_ID) REFERENCES COMPUTERS(ID) ON DELETE CASCADE, ") + QString("PROGRAM_ID INTEGER NOT NULL, FOREIGN KEY (PROGRAM_ID) REFERENCES PROGRAMS(ID) ON DELETE CASCADE, ") + QString("LICENSOR_ID INTEGER NOT NULL, FOREIGN KEY (LICENSOR_ID) REFERENCES LICENSORS(ID) ON DELETE CASCADE)"));
    qDebug() << query.lastError().text();
    return res;
}

bool Database::createTableProgram()
{
    QSqlQuery query(db);
    bool res = query.exec(QString("CREATE TABLE IF NOT EXISTS PROGRAMS(") + QString("ID SERIAL PRIMARY KEY,") + QString("NAME VARCHAR NOT NULL)"));
    qDebug() << query.lastError().text();
    return res;
}

bool Database::createTableLicensor()
{
    QSqlQuery query(db);
    bool res = query.exec(QString("CREATE TABLE IF NOT EXISTS LICENSORS(") + QString("ID SERIAL PRIMARY KEY ,") + QString("ADDRESS VARCHAR NOT NULL,") + QString("NAME VARCHAR NOT NULL)"));
    qDebug() << query.lastError().text();
    return res;
}

bool Database::createTableComputer()
{
    QSqlQuery query(db);
    bool res = query.exec(QString("CREATE TABLE IF NOT EXISTS COMPUTERS(") + QString("ID SERIAL PRIMARY KEY,") + QString("NAME VARCHAR NOT NULL)"));
    qDebug() << query.lastError().text();
    return res;
}

bool Database::login(QString login, QString password)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM USERS WHERE LOGIN = :login AND PASSWORD = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();
    query.first();
    User user(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(5).toString());
    User::setAuth(user);
    return User::getAuth().login != "";
}

void Database::addUser(User u)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO USERS(LNAME, FNAME, LOGIN, PASSWORD, UROLE) VALUES (:ln, :fn, :login, :password, :role)");
    query.bindValue(":fn", u.fname);
    query.bindValue(":ln", u.lname);
    query.bindValue(":login", u.login);
    query.bindValue(":password", u.password);
    query.bindValue(":role", u.role);
    query.exec();
    qDebug() << query.lastError();
}

// QSqlQuery Database::getQueryEndedLics()
//{
//     return QSqlQuery(QString("SELECT LIC.*  FROM LICENSES LIC WHERE END_L < NOW()"));
// }

QSqlQuery Database::getQueryEndedLics()
{
    return QSqlQuery(QString("SELECT LIC.ID, LIC.START_L, LIC.END_L, LIC.PRICE, LIC.NAME, COMP.NAME, PROG.NAME, LICR.NAME FROM LICENSES LIC ") + QString("LEFT JOIN COMPUTERS COMP ON LIC.COMPUTER_ID = COMP.ID ") + QString("LEFT JOIN PROGRAMS PROG ON LIC.PROGRAM_ID = PROG.ID ") + QString("LEFT JOIN LICENSORS LICR ON LIC.LICENSOR_ID = LICR.ID WHERE END_L < NOW()"));
}

QString Database::lastError()
{
    return db.lastError().text();
}
