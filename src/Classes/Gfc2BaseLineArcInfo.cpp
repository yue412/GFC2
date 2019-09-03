#include "StdAfx.h"
#include "Gfc2BaseLineArcInfo.h"
#include "Gfc2BaseLineArcInfoBinarySerializer.h"
#include "Gfc2BaseLineArcInfoTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2BaseLineArcInfo,"Gfc2BaseLineArcInfo",0)

Gfc2BaseLineArcInfo::Gfc2BaseLineArcInfo()
{
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

int Gfc2BaseLineArcInfo::typeId() const
{
    return 9;
}

glodon::objectbuf::EntitySchema* Gfc2BaseLineArcInfo::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(9))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2BaseLineArcInfo");
    pSchema->setId(9);
    m_pDocument->addSchema(pSchema, 9);

    return pSchema;
}

std::string Gfc2BaseLineArcInfo::entityName() const
{
    return "Gfc2BaseLineArcInfo";
}

