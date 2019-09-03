#include "StdAfx.h"
#include "Gfc2SolidShape.h"
#include "Gfc2SolidShapeBinarySerializer.h"
#include "Gfc2SolidShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SolidShape,"Gfc2SolidShape",0)

OBJECTBUF_IMP_OBJECT(Gfc2SolidShapeFieldCacheInitializer,"Gfc2SolidShape",0)

Gfc2SolidShape::Gfc2SolidShape()
{
    m_nBody = 0;
}

bool Gfc2SolidShape::isInitialized() const
{
    if ((_has_bits_[0] & 0x1) != 0x1) return false;

    return true;
}

int Gfc2SolidShape::typeId() const
{
    return 119;
}

glodon::objectbuf::EntitySchema* Gfc2SolidShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(119))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Shape3d::createSchema());
    pSchema->setName("Gfc2SolidShape");
    pSchema->setId(119);
    m_pDocument->addSchema(pSchema, 119);

    pSchema->addAttribNames("Body");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("EdgeDatas");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2SolidShape::entityName() const
{
    return "Gfc2SolidShape";
}

void Gfc2SolidShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SolidShape_Body = getFieldId(oFieldIdMap, "Gfc2SolidShape::Body");
    _FieldCache->_Gfc2SolidShape_EdgeDatas = getFieldId(oFieldIdMap, "Gfc2SolidShape::EdgeDatas");
}

