#include "StdAfx.h"
#include "Gfc2SimplePolygon.h"
#include "Gfc2SimplePolygonBinarySerializer.h"
#include "Gfc2SimplePolygonTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SimplePolygon,"Gfc2SimplePolygon",0)

OBJECTBUF_IMP_OBJECT(Gfc2SimplePolygonFieldCacheInitializer,"Gfc2SimplePolygon",0)

Gfc2SimplePolygon::Gfc2SimplePolygon()
{
}

bool Gfc2SimplePolygon::isInitialized() const
{

    return true;
}

int Gfc2SimplePolygon::typeId() const
{
    return 115;
}

glodon::objectbuf::EntitySchema* Gfc2SimplePolygon::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(115))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Polygon::createSchema());
    pSchema->setName("Gfc2SimplePolygon");
    pSchema->setId(115);
    m_pDocument->addSchema(pSchema, 115);

    pSchema->addAttribNames("Loops");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2SimplePolygon::entityName() const
{
    return "Gfc2SimplePolygon";
}

void Gfc2SimplePolygonFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SimplePolygon_Loops = getFieldId(oFieldIdMap, "Gfc2SimplePolygon::Loops");
}

