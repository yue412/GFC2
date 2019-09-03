#include "StdAfx.h"
#include "Gfc2CommonPolygon.h"
#include "Gfc2CommonPolygonBinarySerializer.h"
#include "Gfc2CommonPolygonTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2CommonPolygon,"Gfc2CommonPolygon",0)

OBJECTBUF_IMP_OBJECT(Gfc2CommonPolygonFieldCacheInitializer,"Gfc2CommonPolygon",0)

Gfc2CommonPolygon::Gfc2CommonPolygon()
{
}

bool Gfc2CommonPolygon::isInitialized() const
{

    return true;
}

int Gfc2CommonPolygon::typeId() const
{
    return 24;
}

glodon::objectbuf::EntitySchema* Gfc2CommonPolygon::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(24))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Polygon::createSchema());
    pSchema->setName("Gfc2CommonPolygon");
    pSchema->setId(24);
    m_pDocument->addSchema(pSchema, 24);

    pSchema->addAttribNames("Loops");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2CommonPolygon::entityName() const
{
    return "Gfc2CommonPolygon";
}

void Gfc2CommonPolygonFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2CommonPolygon_Loops = getFieldId(oFieldIdMap, "Gfc2CommonPolygon::Loops");
}

