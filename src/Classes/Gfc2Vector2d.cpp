#include "StdAfx.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2dBinarySerializer.h"
#include "Gfc2Vector2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Vector2d,"Gfc2Vector2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2Vector2dFieldCacheInitializer,"Gfc2Vector2d",0)

Gfc2Vector2d::Gfc2Vector2d()
{
    m_dX = 0.0;
    m_dY = 0.0;
}

bool Gfc2Vector2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2Vector2d::typeId() const
{
    return 136;
}

glodon::objectbuf::EntitySchema* Gfc2Vector2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(136))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2Vector2d");
    pSchema->setId(136);
    m_pDocument->addSchema(pSchema, 136);

    pSchema->addAttribNames("X");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Y");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2Vector2d::entityName() const
{
    return "Gfc2Vector2d";
}

void Gfc2Vector2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Vector2d_X = getFieldId(oFieldIdMap, "Gfc2Vector2d::X");
    _FieldCache->_Gfc2Vector2d_Y = getFieldId(oFieldIdMap, "Gfc2Vector2d::Y");
}

