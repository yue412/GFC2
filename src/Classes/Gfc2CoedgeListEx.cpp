#include "StdAfx.h"
#include "Gfc2CoedgeListEx.h"
#include "Gfc2CoedgeListExBinarySerializer.h"
#include "Gfc2CoedgeListExTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2CoedgeListEx,"Gfc2CoedgeListEx",0)

OBJECTBUF_IMP_OBJECT(Gfc2CoedgeListExFieldCacheInitializer,"Gfc2CoedgeListEx",0)

Gfc2CoedgeListEx::Gfc2CoedgeListEx()
{
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2CoedgeListEx::isInitialized() const
{

    return true;
}

int Gfc2CoedgeListEx::typeId() const
{
    return 23;
}

glodon::objectbuf::EntitySchema* Gfc2CoedgeListEx::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(23))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2CoedgeListEx");
    pSchema->setId(23);
    m_pDocument->addSchema(pSchema, 23);

    pSchema->addAttribNames("CoedgeExs");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2CoedgeListEx::entityName() const
{
    return "Gfc2CoedgeListEx";
}

void Gfc2CoedgeListExFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2CoedgeListEx_CoedgeExs = getFieldId(oFieldIdMap, "Gfc2CoedgeListEx::CoedgeExs");
}

