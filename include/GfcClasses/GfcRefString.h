#ifndef GFCREFSTRING_H
#define GFCREFSTRING_H

#include "GfcClasses.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRefString: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcRefString, gfc::engine::CEntity)
public:
    GfcRefString();
    GfcRefString(bool bSetSchema);
    void setVal(const std::wstring& sValue);
    std::wstring getVal() const;
    bool hasVal() const;

};

GFCCLASSES_NAMESPACE_END

#endif
