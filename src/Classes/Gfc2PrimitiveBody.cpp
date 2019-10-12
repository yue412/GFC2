#include "StdAfx.h"
#include "Gfc2PrimitiveBody.h"
#include "Gfc2PrimitiveBodyBinarySerializer.h"
#include "Gfc2PrimitiveBodyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PrimitiveBody,"Gfc2PrimitiveBody",0)

int Gfc2PrimitiveBody::typeId() const
{
    return 138;
}

glodon::objectbuf::EntitySchema* Gfc2PrimitiveBody::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(138))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Body::createSchema());
    pSchema->setName("Gfc2PrimitiveBody");
    pSchema->setId(138);
    m_pDocument->addSchema(pSchema, 138);

    return pSchema;
}

std::string Gfc2PrimitiveBody::entityName() const
{
    return "Gfc2PrimitiveBody";
}

