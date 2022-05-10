#ifndef GFCREADER_H
#define GFCREADER_H

#include "GfcEngine\Reader.h"
#include "GfcClasses\x3\GfcClasses.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API CReader: public gfc::engine::CReader
{
public:
    CReader();
protected:
    virtual bool useStaticClass();
};

GFCCLASSES_NAMESPACE_END

#endif // !GFCREADER_H