#include "GfcClasses\x3\GfcReader.h"
#include "GfcSchema.h"

GFCCLASSES_NAMESPACE_BEGIN

CReader::CReader(): gfc::engine::CReader(g_pModel)
{
}

bool CReader::useStaticClass()
{
    return true;
}

GFCCLASSES_NAMESPACE_END


