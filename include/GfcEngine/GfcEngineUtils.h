#ifndef GFCENGINEUTILS_H
#define GFCENGINEUTILS_H

#include <string>
#include "GfcEngine\GfcEngine.h"

namespace gfc2 {
    namespace schema {
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class EntityFactory;

class GFCENGINE_API GfcEngineUtils
{
public:
    static EntityFactory* createFactory(const std::string& sFileName);
    static EntityFactory* createFactory(const char* buf, int len);
    static bool loadSchema(const std::string& sFileName, gfc2::schema::CModel* pModel);
    static bool loadSchema(const char* buf, int len, gfc2::schema::CModel* pModel);
};

GFCENGINE_NAMESPACE_END


#endif // !GFCENGINEUTILS_H

