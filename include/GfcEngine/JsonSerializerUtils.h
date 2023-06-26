#pragma once

#include <memory>
#include <string>
#if (defined _WIN32 || defined _WIN64)
#include <Windows.h>
#endif
#include "GfcEngine/JsonWrapper.h"
#include "GfcEngine/GfcEngine.h"

namespace gfc {
    namespace schema {
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CEntity;
class CDocument;

class GFCENGINE_API CJsonSerializerUtils
{
public:
    static void writeEntity(JsonWrapper& rootJson, const CEntity* pEntity, unsigned int nCodePage = CP_UTF8);
    static std::shared_ptr<CEntity> parseEntity(gfc::schema::CModel* pModel, CDocument* pDoc, JsonWrapper& rootJson);

};

GFCENGINE_NAMESPACE_END