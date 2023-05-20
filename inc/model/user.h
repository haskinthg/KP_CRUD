#ifndef USER_H
#define USER_H

#include "stable.h"

class User
{
public:
    User(): id(0) {}
    long id;
    QString fname;
    QString lname;
    QString login;
    QString password;

    QString role;

    virtual ~User() {}
};

#endif // USER_H
