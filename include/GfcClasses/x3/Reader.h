#ifndef _GFC_READER_H
#define _GFC_READER_H

#include "GfcEngine/Reader.h"
#include "GfcClasses/x3/_Gfc_Classes.h"

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