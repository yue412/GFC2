#ifndef NGFC2INTEGERPROPERTY_H
#define NGFC2INTEGERPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "GfcClasses\x3\Gfc2IntegerProperty.h"
#include "NTypeDef.h"

public ref class NGfc2IntegerProperty: public NGfc2SingleProperty
{
public:
    NGfc2IntegerProperty();
    NGfc2IntegerProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    void setVal(NGfc2Integer nValue);
    NGfc2Integer getVal();
    bool hasVal();

};
#endif
