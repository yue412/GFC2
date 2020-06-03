#ifndef GFCENGINEUTILS_H
#define GFCENGINEUTILS_H

#include <string>
#include "GfcEngine\GfcEngine.h"

namespace gfc {
    namespace schema {
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class Entity;

class GFCENGINE_API GfcEngineUtils
{
public:
    static bool loadSchema(const std::wstring& sFileName, gfc::schema::CModel* pModel);
    static bool loadSchema(const char* buf, int len, gfc::schema::CModel* pModel);
    static Entity* createEntity(gfc::schema::CModel* pModel, const std::wstring& sName);
};

GFCENGINE_NAMESPACE_END


#endif // !GFCENGINEUTILS_H

