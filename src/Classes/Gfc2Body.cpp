#include "StdAfx.h"
#include "Gfc2Body.h"
#include "Gfc2BodyBinarySerializer.h"
#include "Gfc2BodyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Body,"Gfc2Body",0)

int Gfc2Body::typeId() const
{
    return 13;
}

glodon::objectbuf::EntitySchema* Gfc2Body::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(13))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2Body");
    pSchema->setId(13);
    m_pDocument->addSchema(pSchema, 13);

    return pSchema;
}

std::string Gfc2Body::entityName() const
{
    return "Gfc2Body";
}

