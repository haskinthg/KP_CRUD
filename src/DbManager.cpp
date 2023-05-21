#include "DbManager.h"
#include "database.h"

DbManager::DbManager():Singleton<DbManager>(*this)
{

}

bool DbManager::connect()
{
    //подключение  к бд
    return Database::instance().createConnection();
}

bool DbManager::login(QString login, QString password)
{
    return Database::instance().login(login, password);
}

void DbManager::addUser(User u)
{
    Database::instance().addUser(u);
}
