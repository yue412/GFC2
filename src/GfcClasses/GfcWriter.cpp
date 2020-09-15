#include "GfcWriter.h"
#include "GfcSchema.h"
#include "GfcSchema\Model.h"

GFCCLASSES_NAMESPACE_BEGIN

GfcWriter::GfcWriter(const std::wstring& sProductCode): CWriter(g_pModel, sProductCode)
{
}


GfcWriter::~GfcWriter()
{
}

GFCCLASSES_NAMESPACE_END