#include "GfcReader.h"
#include "GfcSchema.h"

GfcReader::GfcReader(): CReader(g_pModel)
{
}

bool GfcReader::useStaticClass()
{
    return true;
}


