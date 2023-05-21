#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "Singleton.h"
#include "stable.h"

#include <user.h>

class DbManager : public Singleton<DbManager> {
public:
    DbManager();
    bool connect();
    bool login(QString, QString);
    void addUser(User);
};

#endif // DBMANAGER_H
