#include "StdAfx.h"
#include "Gfc2SteelTotal.h"
#include "Gfc2SteelTotalBinarySerializer.h"
#include "Gfc2SteelTotalTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SteelTotal,"Gfc2SteelTotal",0)

OBJECTBUF_IMP_OBJECT(Gfc2SteelTotalFieldCacheInitializer,"Gfc2SteelTotal",0)

Gfc2SteelTotal::Gfc2SteelTotal()
{
    m_nCompType = 0;
    m_nLevel = 0;
    m_nDia = 0;
    m_dWeight = 0.0;
    m_nUnit = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2SteelTotal::isInitialized() const
{
    if ((_has_bits_[0] & 0x1f) != 0x1f) return false;

    return true;
}

int Gfc2SteelTotal::typeId() const
{
    return 126;
}

glodon::objectbuf::EntitySchema* Gfc2SteelTotal::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(126))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2SteelTotal");
    pSchema->setId(126);
    m_pDocument->addSchema(pSchema, 126);

    pSchema->addAttribNames("CompType");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Level");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Dia");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Weight");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Unit");
    pSchema->addAttribIds(5);

    return pSchema;
}

std::string Gfc2SteelTotal::entityName() const
{
    return "Gfc2SteelTotal";
}

void Gfc2SteelTotalFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SteelTotal_CompType = getFieldId(oFieldIdMap, "Gfc2SteelTotal::CompType");
    _FieldCache->_Gfc2SteelTotal_Level = getFieldId(oFieldIdMap, "Gfc2SteelTotal::Level");
    _FieldCache->_Gfc2SteelTotal_Dia = getFieldId(oFieldIdMap, "Gfc2SteelTotal::Dia");
    _FieldCache->_Gfc2SteelTotal_Weight = getFieldId(oFieldIdMap, "Gfc2SteelTotal::Weight");
    _FieldCache->_Gfc2SteelTotal_Unit = getFieldId(oFieldIdMap, "Gfc2SteelTotal::Unit");
}

