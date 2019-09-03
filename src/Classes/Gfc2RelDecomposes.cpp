#include "StdAfx.h"
#include "Gfc2RelDecomposes.h"
#include "Gfc2RelDecomposesBinarySerializer.h"
#include "Gfc2RelDecomposesTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelDecomposes,"Gfc2RelDecomposes",0)

OBJECTBUF_IMP_OBJECT(Gfc2RelDecomposesFieldCacheInitializer,"Gfc2RelDecomposes",0)

Gfc2RelDecomposes::Gfc2RelDecomposes()
{
    m_nRelatingObject = 0;
}

bool Gfc2RelDecomposes::isInitialized() const
{
    if ((_has_bits_[0] & 0x1) != 0x1) return false;

    return true;
}

int Gfc2RelDecomposes::typeId() const
{
    return 99;
}

glodon::objectbuf::EntitySchema* Gfc2RelDecomposes::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(99))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2RelationShip::createSchema());
    pSchema->setName("Gfc2RelDecomposes");
    pSchema->setId(99);
    m_pDocument->addSchema(pSchema, 99);

    pSchema->addAttribNames("RelatingObject");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("RelatedObjects");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2RelDecomposes::entityName() const
{
    return "Gfc2RelDecomposes";
}

void Gfc2RelDecomposesFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2RelDecomposes_RelatingObject = getFieldId(oFieldIdMap, "Gfc2RelDecomposes::RelatingObject");
    _FieldCache->_Gfc2RelDecomposes_RelatedObjects = getFieldId(oFieldIdMap, "Gfc2RelDecomposes::RelatedObjects");
}

