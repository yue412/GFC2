#include <assert.h>
#include <fstream>
#include "GfcEngine\EntityFactory.h"
#include "GfcEngine\Entity.h"
#include "EntityAttributeDataHandler.h"
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
    finalize(m_pModel);
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

void EntityFactory::initClass(gfc2::schema::CClass * pClass)
{
    if (pClass->getDataSize() >= 0)
    {
        // ÒÑ³õÊ¼»¯
        return;
    }
    int nDataSize = 0;
    if (pClass->getParent()) 
    {
        initClass(pClass->getParent());
        nDataSize = pClass->getParent()->getDataSize();
    }
    for (int j = 0; j < pClass->getAttributeCount(); j++)
    {
        auto pAttr = pClass->getAttribute(j);
        initAttr(pAttr);
        pAttr->getDataHandler()->setOffset(nDataSize);
        nDataSize += pAttr->getDataHandler()->getDataSize();
    }
    pClass->setDataSize(nDataSize);
}

void EntityFactory::clear()
{
    delete m_pModel; m_pModel = nullptr;
    delete m_pTempModel; m_pTempModel = nullptr;
}

void EntityFactory::finalize(gfc2::schema::CModel * pModel)
{
    for (int i = 0; i < pModel->getTypeObjectCount(); i++)
    {
        auto pClass = dynamic_cast<gfc2::schema::CClass*>(pModel->getTypeObject(i));
        if (pClass)
        {
            initClass(pClass);
        }
    }
}

void EntityFactory::initAttr(gfc2::schema::CAttribute * pAttribute)
{
    auto nType = pAttribute->getType()->getDataType();
    gfc2::schema::CAttributeDataHandler* pHandler = nullptr;
    if (pAttribute->getRepeatFlag())
    {
        switch (nType)
        {
        case gfc2::schema::EDT_BOOLEAN:
            pHandler = new BooleanListAttributeDataHandler(pAttribute);
            break;
        case gfc2::schema::EDT_INTEGER:
            pHandler = new IntegerListAttributeDataHandler(pAttribute);
            break;
        case gfc2::schema::EDT_DOUBLE:
            pHandler = new DoubleListAttributeDataHandler(pAttribute);
            break;
        case gfc2::schema::EDT_STRING:
            pHandler = new StringListAttributeDataHandler(pAttribute);
            break;
        case gfc2::schema::EDT_ENUM:
            pHandler = new IntegerListAttributeDataHandler(pAttribute);
            break;
        case gfc2::schema::EDT_ENTITY:
            pHandler = new EntityRefListAttributeDataHandler(pAttribute);
            break;
        default:
            break;
        }
    }
    else
    {
        switch (nType)
        {
        case gfc2::schema::EDT_BOOLEAN:
            pHandler = new BooleanAttributeDataHandler(pAttribute);
            break;
        case gfc2::schema::EDT_INTEGER:
            pHandler = new IntegerAttributeDataHandler(pAttribute);
            break;
        case gfc2::schema::EDT_DOUBLE:
            pHandler = new DoubleAttributeDataHandler(pAttribute);
            break;
        case gfc2::schema::EDT_STRING:
            pHandler = new StringAttributeDataHandler(pAttribute);
            break;
        case gfc2::schema::EDT_ENUM:
            pHandler = new IntegerAttributeDataHandler(pAttribute);
            break;
        case gfc2::schema::EDT_ENTITY:
            pHandler = new EntityRefAttributeDataHandler(pAttribute);
            break;
        default:
            break;
        }
    }
    if (pHandler == nullptr)
    {
        assert(false);
        pHandler = new EntityAttributeDataHandler(pAttribute); // mock
    }
    pAttribute->setDataHandler(pHandler);
}

GFCENGINE_NAMESPACE_END
