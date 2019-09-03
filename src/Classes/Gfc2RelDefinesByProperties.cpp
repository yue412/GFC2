#include "StdAfx.h"
#include "Gfc2RelDefinesByProperties.h"
#include "Gfc2RelDefinesByPropertiesBinarySerializer.h"
#include "Gfc2RelDefinesByPropertiesTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelDefinesByProperties,"Gfc2RelDefinesByProperties",0)

OBJECTBUF_IMP_OBJECT(Gfc2RelDefinesByPropertiesFieldCacheInitializer,"Gfc2RelDefinesByProperties",0)

Gfc2RelDefinesByProperties::Gfc2RelDefinesByProperties()
{
    m_nRelatingPropertySet = 0;
}

bool Gfc2RelDefinesByProperties::isInitialized() const
{
    if ((_has_bits_[0] & 0x2) != 0x2) return false;

    return true;
}

int Gfc2RelDefinesByProperties::typeId() const
{
    return 102;
}

glodon::objectbuf::EntitySchema* Gfc2RelDefinesByProperties::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(102))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2RelDefines::createSchema());
    pSchema->setName("Gfc2RelDefinesByProperties");
    pSchema->setId(102);
    m_pDocument->addSchema(pSchema, 102);

    pSchema->addAttribNames("RelatingPropertySet");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2RelDefinesByProperties::entityName() const
{
    return "Gfc2RelDefinesByProperties";
}

void Gfc2RelDefinesByPropertiesFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2RelDefinesByProperties_RelatingPropertySet = getFieldId(oFieldIdMap, "Gfc2RelDefinesByProperties::RelatingPropertySet");
}

