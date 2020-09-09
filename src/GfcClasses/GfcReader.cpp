#include "GfcReader.h"
#include "GfcSchema.h"

GFCCLASSES_NAMESPACE_BEGIN

GfcReader::GfcReader(): CReader(g_pModel)
{
}

bool GfcReader::useStaticClass()
{
    return true;
}

GFCCLASSES_NAMESPACE_END


