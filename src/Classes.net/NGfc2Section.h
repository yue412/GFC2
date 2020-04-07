#ifndef NGFC2SECTION_H
#define NGFC2SECTION_H

#include "Gfc2Section.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Section: public glodon::objectbufnet::Entity
{
public:
    NGfc2Section();
    NGfc2Section(void* pEntity, bool bOwner);

};
#endif
