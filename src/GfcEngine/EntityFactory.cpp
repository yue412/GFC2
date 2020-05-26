#include <assert.h>
#include <fstream>
#include "GfcEngine\EntityFactory.h"
#include "GfcEngine\Entity.h"
#include "Model.h"
#include "Common.h"
#include "BuildinType.h"
#include "EntityClass.h"
#include "Parser.h"
#include "Scanner.h"

GFCENGINE_NAMESPACE_BEGIN

EntityFactory::EntityFactory(): m_pModel(nullptr), m_pTempModel(nullptr)
{
}


EntityFactory::~EntityFactory()
{
    clear();
}

void EntityFactory::loadSchema(const std::string & sFileName)
{
    auto sFile = toWstring(sFileName);
    if (!fileExists(sFile))
        return;
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

        loadSchema(buffer, (int)in.gcount());
    }
}

void EntityFactory::loadSchema(const char * buf, int len)
{
    clear();
    Scanner oScanner((const unsigned char *)buf, len);
    Parser oParser(&oScanner);
    m_pModel = new gfc2::schema::CModel;
    m_pTempModel = new gfc2::schema::CModel;
    oParser.m_pModel = m_pModel;
    oParser.m_pTempModel = m_pTempModel;
    oParser.Parse();
    if (oParser.errors->count > 0)
    {
        assert(false);
    }
}

Entity * EntityFactory::create(const std::string & sName)
{
    auto pType = m_pModel->findTypeObject(toWstring(sName));
    auto pClass = dynamic_cast<gfc2::schema::CClass*>(pType);
    if (pClass)
    {
        Entity* pEntity = new Entity;
        pEntity->setSchema(pClass);
        return pEntity;
    }
    else 
    {
        return nullptr;
    }
}

void EntityFactory::clear()
{
    delete m_pModel; m_pModel = nullptr;
    delete m_pTempModel; m_pTempModel = nullptr;
}

GFCENGINE_NAMESPACE_END
