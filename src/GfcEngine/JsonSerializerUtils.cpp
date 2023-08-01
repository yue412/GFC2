#include "GfcEngine\JsonSerializerUtils.h"
#include <fstream>
#include <stack>
#include <Windows.h>
#include <sstream>
#include <time.h>
#include <io.h>
#include <iomanip>
#include <algorithm>
#include "rapidjson/document.h"
#include "GfcSchema\Model.h"
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EntityAttribute.h"
#include "GfcSchema\EnumType.h"
#include "Common.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\Document.h"
#include "GfcEngine\GfcEngineUtils.h"
#include "GfcEngine\Container.h"

GFCENGINE_NAMESPACE_BEGIN

class CWriterJsonUtils
{
public:
    static void writeValueToObject(JsonWrapper& rootJson, const CEntity* pEntity, CProperty * pProp, UINT nCodePage = CP_UTF8);
    static void writeValueToArray(JsonWrapper& rootJson, const CEntity* pEntity, gfc::schema::CTypeObject * pType, CPropValue* pValue, UINT nCodePage = CP_UTF8);
    static void writeProperty(JsonWrapper& rootJson, const CEntity* pEntity, CProperty* pProp, UINT nCodePage = CP_UTF8);
};


class CReaderJsonUtils
{
public:
    static bool parseProperty(gfc::schema::CModel* pModel, CDocument* pDoc, JsonWrapper& rootJson, std::shared_ptr<CEntity> pEntity, CProperty* pProp);
    static bool parseArrayProperty(gfc::schema::CModel* pModel, CDocument* pDoc, JsonWrapper& rootJson, std::shared_ptr<CEntity> pEntity, CProperty* pProp, int index);
    static bool parseSingleProperty(gfc::schema::CModel* pModel, CDocument* pDoc, JsonWrapper& rootJson, std::shared_ptr<CEntity> pEntity, CProperty* pProp);
};


void CJsonSerializerUtils::writeEntity(JsonWrapper& rootJson, const CEntity * pEntity, UINT nCodePage)
{
    std::string sName = WStringToMBString(pEntity->entityName(), nCodePage);

    rootJson.Add("$$typeName", sName);
    if (pEntity->getPropCount() > 0)
    {
        for (int i = 0; i < pEntity->getPropCount(); i++)
        {
            auto pProp = pEntity->getProps(i);
            CWriterJsonUtils::writeProperty(rootJson, pEntity, pProp, nCodePage);
        }
    }
}

void CWriterJsonUtils::writeValueToObject(JsonWrapper& rootJson, const CEntity* pEntity, CProperty * pProp, UINT nCodePage)
{
    auto pSchema = pProp->schema();
    auto pType = pSchema->getType();
    auto pValue = pProp->value();

    auto nType = pType->getDataType();
    std::string typeName = WStringToMBString(pSchema->getName(), nCodePage);
    switch (nType)
    {
    case gfc::schema::EDT_BOOLEAN:
        rootJson.AddBool(typeName, pValue->asBoolean());
        break;
    case gfc::schema::EDT_INTEGER:
        rootJson.Add(typeName, pValue->asInteger());
        break;
    case gfc::schema::EDT_DOUBLE:
        rootJson.Add(typeName, pValue->asDouble());
        break;
    case gfc::schema::EDT_STRING:
        rootJson.Add(typeName, WStringToMBString(pValue->asString(), nCodePage));
        break;
    case gfc::schema::EDT_ENUM:
    {
        auto pEnumType = dynamic_cast<gfc::schema::CEnumType*>(pType->getBaseType());
        if (pEnumType && pEnumType->getEnumCount() > 0)
        {
            rootJson.Add(typeName, pValue->asInteger());
        }
    }
    break;
    case gfc::schema::EDT_ENTITY:
    {
        rootJson.AddEmptySubObject(typeName);
        JsonWrapper json = rootJson[typeName];

        auto refId = pValue->asEntityRef();
        IContainer* pContainer = pEntity->getContainer();
        assert(pContainer);
        if(!pContainer) break;

        CEntity * pChildEntity = pContainer->getEntity(refId).get(); 
        assert(pChildEntity);
        if(!pChildEntity) break;

        CJsonSerializerUtils::writeEntity(json, pChildEntity, nCodePage);
    }
        break;
    default:
        assert(false);
        break;
    }
}

void CWriterJsonUtils::writeValueToArray(JsonWrapper& rootJson, const CEntity* pEntity, gfc::schema::CTypeObject * pType, CPropValue * pValue, UINT nCodePage)
{
    auto nType = pType->getDataType();
    switch (nType)
    {
    case gfc::schema::EDT_BOOLEAN:
        rootJson.AddBool(pValue->asBoolean());
        break;
    case gfc::schema::EDT_INTEGER:
        rootJson.Add(pValue->asInteger());
        break;
    case gfc::schema::EDT_DOUBLE:
        rootJson.Add(pValue->asDouble());
        break;
    case gfc::schema::EDT_STRING:
        rootJson.Add(transString(WStringToMBString(pValue->asString(), nCodePage)));
        break;
    case gfc::schema::EDT_ENUM:
    {
        auto pEnumType = dynamic_cast<gfc::schema::CEnumType*>(pType->getBaseType());
        if (pEnumType && pEnumType->getEnumCount() > 0)
        {
            rootJson.Add(pValue->asInteger());
        }
    }
    break;
    case gfc::schema::EDT_ENTITY:
    {
        JsonWrapper json(rootJson.GetAllocator(), rapidjson::kObjectType);

        auto refId = pValue->asEntityRef();
        IContainer* pContainer = pEntity->getContainer();
        assert(pContainer);
        if(!pContainer) break;

        CEntity * pChildEntity = pContainer->getEntity(refId).get(); 
        assert(pChildEntity);
        if(!pChildEntity) break;

        CJsonSerializerUtils::writeEntity(json, pChildEntity, nCodePage);
		rootJson.Add(json);
    }
        break;
    default:
        assert(false);
        break;
    }
}

void CWriterJsonUtils::writeProperty(JsonWrapper& rootJson, const CEntity* pEntity, CProperty * pProp, UINT nCodePage)
{
    auto pSchema = pProp->schema();
    auto pType = pSchema->getType();
    if (pSchema->getRepeatFlag())
    {

        auto pValue = pProp->value();
        if (pValue->getCount() != 0)
        {
            std::string typeName = WStringToMBString(pSchema->getName(), nCodePage);
            rootJson.AddEmptySubArray(typeName);
            JsonWrapper json = rootJson[typeName];
            for(int i = 0; i < pValue->getCount(); i++){
                writeValueToArray(json, pEntity, pType, pValue->getItems(i), nCodePage);
            }
        }
    }
    else
    {
        if (!pProp->value()->isNull())
            writeValueToObject(rootJson, pEntity, pProp, nCodePage);
    }

}


std::shared_ptr<CEntity> CJsonSerializerUtils::parseEntity(gfc::schema::CModel* pModel, CDocument* pDoc, JsonWrapper& rootJson)
{
    std::string entityName;
    if(!rootJson.Get("$$typeName", entityName)){
       assert(false);
       return false;
    }

    std::wstring wEntityName = Utf8ToUnicode(entityName);
    if (!pModel)
    {
        wEntityName = transformCompatibleName(wEntityName);
    }

    std::shared_ptr<CEntity>pEntity(!pModel ? dynamic_cast<CEntity*>(CEntity::GetFactory()->Create(UpperString(wEntityName)))
                : CEngineUtils::createEntity(pModel, wEntityName));

    assert(pEntity);
    if(!pEntity) {
        return false;
    }
    pDoc->add(pEntity);
    
    if (pEntity->getPropCount() > 0)
    {
        for (int i = 0; i < pEntity->getPropCount(); i++)
        {
            auto pProp = pEntity->getProps(i);
			CReaderJsonUtils::parseProperty(pModel, pDoc, rootJson, pEntity, pProp);
        }
    }

    return pEntity;
}

bool CReaderJsonUtils::parseProperty(gfc::schema::CModel* pModel, CDocument* pDoc, JsonWrapper& rootJson, std::shared_ptr<CEntity> pEntity, CProperty* pProp){
    auto pSchema = pProp->schema();
    auto pType = pSchema->getType();
    std::string typeName = UnicodeToUtf8(pSchema->getName());

    if(!rootJson.HasMember(typeName)){
        return true;
    }

    if (pSchema->getRepeatFlag())
    {
        JsonWrapper arr(rootJson.GetAllocator());
        bool ret = rootJson.Get(typeName, arr);
        if(!ret || !arr.IsArray()){
            assert(false);
            return false;
        }

        int len = arr.GetArraySize();
        for (int i = 0; i < len; i++)
        {
            bool ret = parseArrayProperty(pModel, pDoc, arr, pEntity, pProp, i);
            assert(ret);
        }
        
        return true;
    }
    else
    {
        bool ret = parseSingleProperty(pModel, pDoc, rootJson, pEntity, pProp);
        assert(ret);
        return ret;
    }
}


bool CReaderJsonUtils::parseArrayProperty(gfc::schema::CModel* pModel, CDocument* pDoc, JsonWrapper& rootJson, std::shared_ptr<CEntity> pEntity, CProperty* pProp, int index)
{
    auto pSchema = pProp->schema();
    auto pType = pSchema->getType();
    auto pParentValue = pProp->value();
    auto pValue = CProperty::createValue(pType);

#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
    auto nType = pType->getDataType();
    switch (nType)
    {
    case gfc::schema::EDT_BOOLEAN:
    {
        bool v;
        DO_(rootJson.GetBool(index, v));
        pValue->setAsBoolean(v);

    }
        break;
    case gfc::schema::EDT_INTEGER:
    {
        int v;
        DO_(rootJson.Get(index, v));
        pValue->setAsInteger(v);
    }
        break;
    case gfc::schema::EDT_DOUBLE:
    {
        double v;
        DO_(rootJson.Get(index, v));
        pValue->setAsDouble(v);
    }
        break;
    case gfc::schema::EDT_STRING:
    {
        std::string v;
        DO_(rootJson.Get(index, v));
        pValue->setAsString(Utf8ToUnicode(v));
    }
        break;
    case gfc::schema::EDT_ENUM:
        {
            int v;
            DO_(rootJson.Get(index, v));
            pValue->setAsInteger(v);
        }
        break;
    case gfc::schema::EDT_ENTITY:
    {
        JsonWrapper childEntityJson(rootJson.GetAllocator());
        DO_(rootJson.Get(index, childEntityJson));
        
        std::shared_ptr<CEntity> pChild = CJsonSerializerUtils::parseEntity(pModel, pDoc, childEntityJson);
        assert(pChild);
        if(!pChild) return false;

        pValue->setAsEntityRef(pChild->ref());
    }
        break;
    default:
        assert(false);
        return false;
        break;
    }

    pParentValue->add(pValue);
    return true;
}


bool CReaderJsonUtils::parseSingleProperty(gfc::schema::CModel* pModel, CDocument* pDoc, JsonWrapper& rootJson, std::shared_ptr<CEntity> pEntity, CProperty* pProp)
{
    auto pSchema = pProp->schema();
    auto pType = pSchema->getType();
    auto pValue = pProp->value();
    std::string typeName = UnicodeToUtf8(pSchema->getName());

#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
    auto nType = pType->getDataType();
    switch (nType)
    {
    case gfc::schema::EDT_BOOLEAN:
    {
        bool v;
        DO_(rootJson.GetBool(typeName, v));
        pValue->setAsBoolean(v);

    }
        break;
    case gfc::schema::EDT_INTEGER:
    {
        int v;
        DO_(rootJson.Get(typeName, v));
        pValue->setAsInteger(v);
    }
        break;
    case gfc::schema::EDT_DOUBLE:
    {
        double v;
        DO_(rootJson.Get(typeName, v));
        pValue->setAsDouble(v);
    }
        break;
    case gfc::schema::EDT_STRING:
    {
        std::string v;
        DO_(rootJson.Get(typeName, v));
        pValue->setAsString(Utf8ToUnicode(v));
    }
        break;
    case gfc::schema::EDT_ENUM:
        {
            int v;
            DO_(rootJson.Get(typeName, v));
            pValue->setAsInteger(v);
        }
        break;
    case gfc::schema::EDT_ENTITY:
    {
        JsonWrapper childEntityJson(rootJson.GetAllocator());
        DO_(rootJson.Get(typeName, childEntityJson));
        
        std::shared_ptr<CEntity> pChild = CJsonSerializerUtils::parseEntity(pModel, pDoc, childEntityJson);
        assert(pChild);
        if(!pChild) return false;

        pValue->setAsEntityRef(pChild->ref());
    }
        break;
    default:
        assert(false);
        break;
    }
    return true;
}


GFCENGINE_NAMESPACE_END