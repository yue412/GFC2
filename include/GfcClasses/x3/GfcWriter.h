#ifndef GFCWRITER_H
#define GFCWRITER_H

#include "GfcEngine\Writer.h"
#include "GfcClasses\x3\GfcClasses.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcWriter: public gfc::engine::CWriter
{
public:
    GfcWriter(const std::wstring& sProductCode = L"");
    ~GfcWriter();
};

GFCCLASSES_NAMESPACE_END

#endif // !GFCWRITER_H