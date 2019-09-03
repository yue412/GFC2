#include "StdAfx.h"
#include "Gfc2CommonPolygonEx.h"
#include "Gfc2CommonPolygonExBinarySerializer.h"
#include "Gfc2CommonPolygonExTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2CommonPolygonEx,"Gfc2CommonPolygonEx",0)

OBJECTBUF_IMP_OBJECT(Gfc2CommonPolygonExFieldCacheInitializer,"Gfc2CommonPolygonEx",0)

Gfc2CommonPolygonEx::Gfc2CommonPolygonEx()
{
}

bool Gfc2CommonPolygonEx::isInitialized() const
{

    return true;
}

int Gfc2CommonPolygonEx::typeId() const
{
    return 25;
}

glodon::objectbuf::EntitySchema* Gfc2CommonPolygonEx::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(25))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Polygon::createSchema());
    pSchema->setName("Gfc2CommonPolygonEx");
    pSchema->setId(25);
    m_pDocument->addSchema(pSchema, 25);

    pSchema->addAttribNames("LoopExs");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2CommonPolygonEx::entityName() const
{
    return "Gfc2CommonPolygonEx";
}

void Gfc2CommonPolygonExFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2CommonPolygonEx_LoopExs = getFieldId(oFieldIdMap, "Gfc2CommonPolygonEx::LoopExs");
}

