#include "StdAfx.h"
#include "Gfc2RelNests.h"
#include "Gfc2RelNestsBinarySerializer.h"
#include "Gfc2RelNestsTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelNests,"Gfc2RelNests",0)

int Gfc2RelNests::typeId() const
{
    return 103;
}

glodon::objectbuf::EntitySchema* Gfc2RelNests::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(103))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2RelDecomposes::createSchema());
    pSchema->setName("Gfc2RelNests");
    pSchema->setId(103);
    m_pDocument->addSchema(pSchema, 103);

    return pSchema;
}

std::string Gfc2RelNests::entityName() const
{
    return "Gfc2RelNests";
}

