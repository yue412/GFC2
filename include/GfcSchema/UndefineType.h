#ifndef UNDEFINETYPE_H
#define UNDEFINETYPE_H

#include "GfcSchema/TypeObject.h"

GFC_NAMESPACE_BEGIN

class GFCSCHEMA_API CUndefineType : public CTypeObject
{
public:
    CUndefineType();
    CUndefineType(const std::wstring& sName);
    virtual CTypeObjectEnum getType() const { return TOE_UNDEFINE; }
};

GFC_NAMESPACE_END

#endif // ! UNDEFINETYPE_H
