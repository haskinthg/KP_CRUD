#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "Singleton.h"
#include "stable.h"

class DbManager: public Singleton<DbManager>
{
public:
    DbManager();
    bool connect();
};

#endif // DBMANAGER_H
