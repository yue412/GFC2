#ifndef NGFC2RELDEFINESBYELEMENT_H
#define NGFC2RELDEFINESBYELEMENT_H

#include "NGfc2RelDefines.h"
#include "Gfc2RelDefinesByElement.h"
#include "NGfc2Entity.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelDefinesByElement: public NGfc2RelDefines
{
public:
    NGfc2RelDefinesByElement();
    NGfc2RelDefinesByElement(void* pEntity, bool bOwner);
    void setRelatingElement(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRelatingElement();
    bool hasRelatingElement();
    NGfc2Entity^ getRelatingElementPtr();

};
#endif
