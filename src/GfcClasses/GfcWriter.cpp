#include "GfcWriter.h"
#include "GfcSchema.h"
#include "Model.h"

GfcWriter::GfcWriter(const std::wstring& sProductCode): Writer(g_pModel->version(), sProductCode)
{
}


GfcWriter::~GfcWriter()
{
}
