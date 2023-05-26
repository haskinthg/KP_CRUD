
#ifndef LICENSE_H
#define LICENSE_H

#include "base.h"

class License : public Base {
public:
    License();
    QDate start;
    QDate end;
    long computer;
    long licensor;
    long program;
};

#endif // LICENSE_H
