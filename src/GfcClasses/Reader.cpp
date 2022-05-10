#include "GfcClasses\x3\Reader.h"
#include "Schema.h"

GFCCLASSES_NAMESPACE_BEGIN

CReader::CReader(): gfc::engine::CReader(g_pModel)
{
}

bool CReader::useStaticClass()
{
    return true;
}

GFCCLASSES_NAMESPACE_END


