#include "StdAfx.h"
#include "Gfc2RelAggregates.h"
#include "Gfc2RelAggregatesBinarySerializer.h"
#include "Gfc2RelAggregatesTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelAggregates,"Gfc2RelAggregates",0)

int Gfc2RelAggregates::typeId() const
{
    return 98;
}

glodon::objectbuf::EntitySchema* Gfc2RelAggregates::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(98))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2RelDecomposes::createSchema());
    pSchema->setName("Gfc2RelAggregates");
    pSchema->setId(98);
    m_pDocument->addSchema(pSchema, 98);

    return pSchema;
}

std::string Gfc2RelAggregates::entityName() const
{
    return "Gfc2RelAggregates";
}

