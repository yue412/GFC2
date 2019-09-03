#include "StdAfx.h"
#include "Gfc2TwoPointAssitAxis.h"
#include "Gfc2TwoPointAssitAxisBinarySerializer.h"
#include "Gfc2TwoPointAssitAxisTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2TwoPointAssitAxis,"Gfc2TwoPointAssitAxis",0)

int Gfc2TwoPointAssitAxis::typeId() const
{
    return 134;
}

glodon::objectbuf::EntitySchema* Gfc2TwoPointAssitAxis::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(134))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2AssitAxis::createSchema());
    pSchema->setName("Gfc2TwoPointAssitAxis");
    pSchema->setId(134);
    m_pDocument->addSchema(pSchema, 134);

    return pSchema;
}

std::string Gfc2TwoPointAssitAxis::entityName() const
{
    return "Gfc2TwoPointAssitAxis";
}

