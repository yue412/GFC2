#include "StdAfx.h"
#include "Gfc2RelationShip.h"
#include "Gfc2RelationShipBinarySerializer.h"
#include "Gfc2RelationShipTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelationShip,"Gfc2RelationShip",0)

int Gfc2RelationShip::typeId() const
{
    return 104;
}

glodon::objectbuf::EntitySchema* Gfc2RelationShip::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(104))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Root::createSchema());
    pSchema->setName("Gfc2RelationShip");
    pSchema->setId(104);
    m_pDocument->addSchema(pSchema, 104);

    return pSchema;
}

std::string Gfc2RelationShip::entityName() const
{
    return "Gfc2RelationShip";
}

