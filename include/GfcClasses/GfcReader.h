#ifndef GFCREADER_H
#define GFCREADER_H

#include "GfcEngine\Reader.h"
#include "GfcClasses.h"

class GFCCLASSES_API GfcReader: public gfc::engine::CReader
{
public:
    GfcReader();
protected:
    virtual bool useStaticClass();
};

#endif // !GFCREADER_H