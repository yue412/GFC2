#ifndef BUILDINTYPE_H
#define BUILDINTYPE_H

#include "TypeObject.h"

GFC_NAMESPACE_BEGIN

class CBuildinType : public CTypeObject
{
public:
    CBuildinType();
    CBuildinType(const std::wstring& sName);
    virtual CTypeObjectEnum getType() const {return TOE_BUILDIN;}
};

GFC_NAMESPACE_END

#endif // BUILDINTYPE_H
