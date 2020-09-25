#ifndef GFC2REFSTRING_H
#define GFC2REFSTRING_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RefString: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2RefString, gfc::engine::CEntity)
public:
    Gfc2RefString();
    Gfc2RefString(bool bSetSchema);
    void setVal(const std::wstring& sValue);
    std::wstring getVal() const;
    bool hasVal() const;

};

GFCCLASSES_NAMESPACE_END

#endif
