#include "StdAfx.h"
#include "Gfc2Coordinates2d.h"
#include "Gfc2Coordinates2dBinarySerializer.h"
#include "Gfc2Coordinates2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Coordinates2d,"Gfc2Coordinates2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2Coordinates2dFieldCacheInitializer,"Gfc2Coordinates2d",0)

Gfc2Coordinates2d::Gfc2Coordinates2d()
{
    m_nOrigin = 0;
    m_nX = 0;
    m_nY = 0;
}

bool Gfc2Coordinates2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x7) != 0x7) return false;

    return true;
}

int Gfc2Coordinates2d::typeId() const
{
    return 26;
}

glodon::objectbuf::EntitySchema* Gfc2Coordinates2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(26))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2Coordinates2d");
    pSchema->setId(26);
    m_pDocument->addSchema(pSchema, 26);

    pSchema->addAttribNames("Origin");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("X");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Y");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2Coordinates2d::entityName() const
{
    return "Gfc2Coordinates2d";
}

void Gfc2Coordinates2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Coordinates2d_Origin = getFieldId(oFieldIdMap, "Gfc2Coordinates2d::Origin");
    _FieldCache->_Gfc2Coordinates2d_X = getFieldId(oFieldIdMap, "Gfc2Coordinates2d::X");
    _FieldCache->_Gfc2Coordinates2d_Y = getFieldId(oFieldIdMap, "Gfc2Coordinates2d::Y");
}

