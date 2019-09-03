#include "StdAfx.h"
#include "Gfc2Root.h"
#include "Gfc2RootBinarySerializer.h"
#include "Gfc2RootTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Root,"Gfc2Root",0)

Gfc2Root::Gfc2Root()
{
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

int Gfc2Root::typeId() const
{
    return 107;
}

glodon::objectbuf::EntitySchema* Gfc2Root::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(107))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2Root");
    pSchema->setId(107);
    m_pDocument->addSchema(pSchema, 107);

    return pSchema;
}

std::string Gfc2Root::entityName() const
{
    return "Gfc2Root";
}

