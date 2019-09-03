#ifndef BUILDINTYPE_H
#define BUILDINTYPE_H

#include "typeobject.h"

class CBuildinType : public CTypeObject
{
public:
    CBuildinType();
    CBuildinType(const std::wstring& sName);
    virtual CTypeObjectEnum getType() const {return TOE_BUILDIN;}
};

#endif // BUILDINTYPE_H
