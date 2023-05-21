#ifndef USER_H
#define USER_H

#include "stable.h"

#include <base.h>

class User: public Base
{
public:
    User() {}
    QString fname;
    QString lname;
    QString login;
    QString password;

    QString role;

    virtual ~User() {}
};

#endif // USER_H
