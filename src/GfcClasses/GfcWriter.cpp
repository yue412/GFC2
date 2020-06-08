#include "GfcWriter.h"
#include "GfcSchema.h"
#include "GfcSchema\Model.h"

GfcWriter::GfcWriter(const std::wstring& sProductCode): CWriter(g_pModel->version(), sProductCode)
{
}


GfcWriter::~GfcWriter()
{
}
