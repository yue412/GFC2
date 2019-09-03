#include "StdAfx.h"
#include "Gfc2GeometryShape.h"
#include "Gfc2GeometryShapeBinarySerializer.h"
#include "Gfc2GeometryShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2GeometryShape,"Gfc2GeometryShape",0)

OBJECTBUF_IMP_OBJECT(Gfc2GeometryShapeFieldCacheInitializer,"Gfc2GeometryShape",0)

Gfc2GeometryShape::Gfc2GeometryShape()
{
    m_nGeo = 0;
}

bool Gfc2GeometryShape::isInitialized() const
{
    if ((_has_bits_[0] & 0x5) != 0x5) return false;

    return true;
}

int Gfc2GeometryShape::typeId() const
{
    return 51;
}

glodon::objectbuf::EntitySchema* Gfc2GeometryShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(51))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Shape::createSchema());
    pSchema->setName("Gfc2GeometryShape");
    pSchema->setId(51);
    m_pDocument->addSchema(pSchema, 51);

    pSchema->addAttribNames("Geo");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2GeometryShape::entityName() const
{
    return "Gfc2GeometryShape";
}

void Gfc2GeometryShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2GeometryShape_Geo = getFieldId(oFieldIdMap, "Gfc2GeometryShape::Geo");
}

