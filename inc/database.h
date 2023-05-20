#ifndef DATABASE_H
#define DATABASE_H

#include "Singleton.h"
#include "stable.h"

class Database: public Singleton<Database>
{
public:
    Database();
    bool createConnection();
    void disconect();
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
