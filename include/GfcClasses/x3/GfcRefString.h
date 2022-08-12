#ifndef GFCREFSTRING_H
#define GFCREFSTRING_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRefString: public GfcRoot
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
