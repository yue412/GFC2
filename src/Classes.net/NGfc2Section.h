#ifndef NGFC2SECTION_H
#define NGFC2SECTION_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2Section.h"

public ref class NGfc2Section: public NGfc2Root
{
public:
    NGfc2Section();
    NGfc2Section(void* pEntity, bool bOwner);

};
#endif
