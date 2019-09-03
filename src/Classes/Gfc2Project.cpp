#include "StdAfx.h"
#include "Gfc2Project.h"
#include "Gfc2ProjectBinarySerializer.h"
#include "Gfc2ProjectTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Project,"Gfc2Project",0)

int Gfc2Project::typeId() const
{
    return 93;
}

glodon::objectbuf::EntitySchema* Gfc2Project::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(93))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Object::createSchema());
    pSchema->setName("Gfc2Project");
    pSchema->setId(93);
    m_pDocument->addSchema(pSchema, 93);

    return pSchema;
}

std::string Gfc2Project::entityName() const
{
    return "Gfc2Project";
}

