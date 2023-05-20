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
