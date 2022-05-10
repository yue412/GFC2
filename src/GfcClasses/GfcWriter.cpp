#include "GfcClasses\x3\GfcWriter.h"
#include "GfcSchema.h"
#include "GfcSchema\Model.h"

GFCCLASSES_NAMESPACE_BEGIN

CWriter::CWriter(const std::wstring& sProductCode): gfc::engine::CWriter(g_pModel, sProductCode)
{
}


CWriter::~CWriter()
{
}

GFCCLASSES_NAMESPACE_END