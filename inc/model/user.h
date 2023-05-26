#ifndef USER_H
#define USER_H

#include "stable.h"

#include <base.h>

class User : public Base {
public:
    User() { }
    User(long id, QString fn, QString ln, QString login, QString role);
    QString fname;
    QString lname;
    QString login;
    QString password;

    QString role;

    virtual ~User() { }
    static User getAuth();
    static void setAuth(const User newAuth);

private:
    static User auth;
};

#endif // USER_H
