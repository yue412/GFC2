#ifndef GFCDOCUMENT_H
#define GFCDOCUMENT_H

#include "GfcEngine\Document.h"
#include "GfcClasses\x3\GfcClasses.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcDocument: public gfc::engine::CDocument
{
public:
    GfcDocument();
};

GFCCLASSES_NAMESPACE_END

#endif // !GFCDOCUMENT_H

