#ifndef _GFC_WRITER_H
#define _GFC_WRITER_H

#include "GfcEngine/Writer.h"
#include "GfcClasses/x3/_Gfc_Classes.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API CWriter: public gfc::engine::CWriter
{
public:
    CWriter(const std::wstring& sProductCode = L"");
    ~CWriter();
};

GFCCLASSES_NAMESPACE_END

#endif // !GFCWRITER_H