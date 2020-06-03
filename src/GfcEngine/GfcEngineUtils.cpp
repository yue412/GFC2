#include <assert.h>
#include "GfcEngine\GfcEngineUtils.h"
#include "GfcEngine\Entity.h"
#include "GfcSchema\Model.h"
#include "Common.h"
#include "Parser.h"
#include "Scanner.h"

GFCENGINE_NAMESPACE_BEGIN

bool GfcEngineUtils::loadSchema(const std::wstring & sFileName, gfc::schema::CModel * pModel)
{
    if (!fileExists(sFileName))
        return false;
    std::ifstream in(sFileName, std::ios::in);
    if (in)
    {
        // get length of file:
        in.seekg(0, in.end);
        int length = (int)in.tellg();
        in.seekg(0, in.beg);

        char * buffer = new char[length];

        // read data as a block:
        in.read(buffer, length);
        in.close();

        return loadSchema(buffer, (int)in.gcount(), pModel);
    }
    return false;
}

bool GfcEngineUtils::loadSchema(const char * buf, int len, gfc::schema::CModel * pModel)
{
    assert(pModel);
    Scanner oScanner((const unsigned char *)buf, len);
    Parser oParser(&oScanner);
    gfc::schema::CModel oTempModel;
    oParser.m_pModel = pModel;
    oParser.m_pTempModel = &oTempModel;
    try
    {
        oParser.Parse();
    }
    catch (...)
    {
        pModel->clear();
        return false;
    }

    if (oParser.errors->count > 0)
    {
        pModel->clear();
        return false;
    }
    return true;
}

Entity * GfcEngineUtils::createEntity(gfc::schema::CModel* pModel, const std::wstring & sName)
{
    auto pEntity = Entity::GetFactory()->Create(sName);
    if (pEntity)
        return dynamic_cast<Entity*>(pEntity);
    assert(pModel);
    if (pModel == nullptr)
        return nullptr;
    auto pType = pModel->findTypeObject(sName);
    if (pType && pType->getDataType() == gfc::schema::EDT_ENTITY)
    {
        Entity* pEntity = new Entity;
        pEntity->setSchema(pType);
        return pEntity;
    }
    else
    {
        return nullptr;
    }
}

GFCENGINE_NAMESPACE_END
