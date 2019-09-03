#include "StdAfx.h"
#include "Gfc2RelDefinesByElement.h"
#include "Gfc2RelDefinesByElementBinarySerializer.h"
#include "Gfc2RelDefinesByElementTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelDefinesByElement,"Gfc2RelDefinesByElement",0)

OBJECTBUF_IMP_OBJECT(Gfc2RelDefinesByElementFieldCacheInitializer,"Gfc2RelDefinesByElement",0)

Gfc2RelDefinesByElement::Gfc2RelDefinesByElement()
{
    m_nRelatingElement = 0;
}

bool Gfc2RelDefinesByElement::isInitialized() const
{
    if ((_has_bits_[0] & 0x2) != 0x2) return false;

    return true;
}

int Gfc2RelDefinesByElement::typeId() const
{
    return 101;
}

glodon::objectbuf::EntitySchema* Gfc2RelDefinesByElement::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(101))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2RelDefines::createSchema());
    pSchema->setName("Gfc2RelDefinesByElement");
    pSchema->setId(101);
    m_pDocument->addSchema(pSchema, 101);

    pSchema->addAttribNames("RelatingElement");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2RelDefinesByElement::entityName() const
{
    return "Gfc2RelDefinesByElement";
}

void Gfc2RelDefinesByElementFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2RelDefinesByElement_RelatingElement = getFieldId(oFieldIdMap, "Gfc2RelDefinesByElement::RelatingElement");
}

