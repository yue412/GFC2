#include "StdAfx.h"
#include "Gfc2Shape2d.h"
#include "Gfc2Shape2dBinarySerializer.h"
#include "Gfc2Shape2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Shape2d,"Gfc2Shape2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2Shape2dFieldCacheInitializer,"Gfc2Shape2d",0)

Gfc2Shape2d::Gfc2Shape2d()
{
    m_dElev = 0.0;
}

bool Gfc2Shape2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x5) != 0x5) return false;

    return true;
}

int Gfc2Shape2d::typeId() const
{
    return 112;
}

glodon::objectbuf::EntitySchema* Gfc2Shape2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(112))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2ParametricShape::createSchema());
    pSchema->setName("Gfc2Shape2d");
    pSchema->setId(112);
    m_pDocument->addSchema(pSchema, 112);

    pSchema->addAttribNames("Elev");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2Shape2d::entityName() const
{
    return "Gfc2Shape2d";
}

void Gfc2Shape2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Shape2d_Elev = getFieldId(oFieldIdMap, "Gfc2Shape2d::Elev");
}

