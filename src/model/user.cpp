#include "user.h"

User::User(QString fn, QString ln, QString login, QString role)
{
    fname = fn;
    lname = ln;
    this-> login = login;
    this-> role = role;
}

User User::getAuth()
{
    return auth;
}

void User::setAuth(const User newAuth)
{
    auth = newAuth;
}

User User::auth = User();
