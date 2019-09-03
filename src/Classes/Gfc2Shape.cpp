#include "StdAfx.h"
#include "Gfc2Shape.h"
#include "Gfc2ShapeBinarySerializer.h"
#include "Gfc2ShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Shape,"Gfc2Shape",0)

OBJECTBUF_IMP_OBJECT(Gfc2ShapeFieldCacheInitializer,"Gfc2Shape",0)

Gfc2Shape::Gfc2Shape()
{
    m_nLocalCoordinate = 0;
    m_nBoundingBox = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2Shape::isInitialized() const
{
    if ((_has_bits_[0] & 0x1) != 0x1) return false;

    return true;
}

int Gfc2Shape::typeId() const
{
    return 111;
}

glodon::objectbuf::EntitySchema* Gfc2Shape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(111))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2Shape");
    pSchema->setId(111);
    m_pDocument->addSchema(pSchema, 111);

    pSchema->addAttribNames("LocalCoordinate");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("BoundingBox");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2Shape::entityName() const
{
    return "Gfc2Shape";
}

void Gfc2ShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Shape_LocalCoordinate = getFieldId(oFieldIdMap, "Gfc2Shape::LocalCoordinate");
    _FieldCache->_Gfc2Shape_BoundingBox = getFieldId(oFieldIdMap, "Gfc2Shape::BoundingBox");
}

