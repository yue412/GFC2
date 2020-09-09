#ifndef GFCREADER_H
#define GFCREADER_H

#include "GfcEngine\Reader.h"
#include "GfcClasses.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcReader: public gfc::engine::CReader
{
public:
    GfcReader();
protected:
    virtual bool useStaticClass();
};

GFCCLASSES_NAMESPACE_END

#endif // !GFCREADER_H