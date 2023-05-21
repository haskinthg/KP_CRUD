#ifndef DATABASE_H
#define DATABASE_H

#include <user.h>

#include "Singleton.h"
#include "stable.h"

class Database : public Singleton<Database> {
public:
    Database();
    bool createConnection();
    void disconect();
    bool createTableUsers();
    bool createTableLicenses();
    bool createTableProgram();
    bool createTableLicensor();
    bool createTableComputer();

    bool login(QString, QString);
    void addUser(User);

    QString lastError();

private:
    QSqlDatabase db;
    int port;
    QString hostname;
    QString dbname;
    QString username;
    QString password;
};

#endif // DATABASE_H
