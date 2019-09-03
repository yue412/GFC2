#include "StdAfx.h"
#include "Gfc2CuboidBody.h"
#include "Gfc2CuboidBodyBinarySerializer.h"
#include "Gfc2CuboidBodyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2CuboidBody,"Gfc2CuboidBody",0)

OBJECTBUF_IMP_OBJECT(Gfc2CuboidBodyFieldCacheInitializer,"Gfc2CuboidBody",0)

Gfc2CuboidBody::Gfc2CuboidBody()
{
    m_nCoordinate = 0;
    m_nDimension = 0;
}

bool Gfc2CuboidBody::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2CuboidBody::typeId() const
{
    return 28;
}

glodon::objectbuf::EntitySchema* Gfc2CuboidBody::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(28))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Body::createSchema());
    pSchema->setName("Gfc2CuboidBody");
    pSchema->setId(28);
    m_pDocument->addSchema(pSchema, 28);

    pSchema->addAttribNames("Coordinate");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Dimension");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2CuboidBody::entityName() const
{
    return "Gfc2CuboidBody";
}

void Gfc2CuboidBodyFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2CuboidBody_Coordinate = getFieldId(oFieldIdMap, "Gfc2CuboidBody::Coordinate");
    _FieldCache->_Gfc2CuboidBody_Dimension = getFieldId(oFieldIdMap, "Gfc2CuboidBody::Dimension");
}

