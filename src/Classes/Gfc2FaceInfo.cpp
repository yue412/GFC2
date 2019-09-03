#include "StdAfx.h"
#include "Gfc2FaceInfo.h"
#include "Gfc2FaceInfoBinarySerializer.h"
#include "Gfc2FaceInfoTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceInfo,"Gfc2FaceInfo",0)

Gfc2FaceInfo::Gfc2FaceInfo()
{
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

int Gfc2FaceInfo::typeId() const
{
    return 45;
}

glodon::objectbuf::EntitySchema* Gfc2FaceInfo::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(45))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2FaceInfo");
    pSchema->setId(45);
    m_pDocument->addSchema(pSchema, 45);

    return pSchema;
}

std::string Gfc2FaceInfo::entityName() const
{
    return "Gfc2FaceInfo";
}

