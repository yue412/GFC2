#include "StdAfx.h"
#include "Gfc2EntityShape.h"
#include "Gfc2EntityShapeBinarySerializer.h"
#include "Gfc2EntityShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2EntityShape,"Gfc2EntityShape",0)

OBJECTBUF_IMP_OBJECT(Gfc2EntityShapeFieldCacheInitializer,"Gfc2EntityShape",0)

Gfc2EntityShape::Gfc2EntityShape()
{
    m_nIdentifier = 0;
    m_nShape = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2EntityShape::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2EntityShape::typeId() const
{
    return 40;
}

glodon::objectbuf::EntitySchema* Gfc2EntityShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(40))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2EntityShape");
    pSchema->setId(40);
    m_pDocument->addSchema(pSchema, 40);

    pSchema->addAttribNames("Identifier");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Shape");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2EntityShape::entityName() const
{
    return "Gfc2EntityShape";
}

void Gfc2EntityShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2EntityShape_Identifier = getFieldId(oFieldIdMap, "Gfc2EntityShape::Identifier");
    _FieldCache->_Gfc2EntityShape_Shape = getFieldId(oFieldIdMap, "Gfc2EntityShape::Shape");
}

