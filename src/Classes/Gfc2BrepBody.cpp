#include "StdAfx.h"
#include "Gfc2BrepBody.h"
#include "Gfc2BrepBodyBinarySerializer.h"
#include "Gfc2BrepBodyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2BrepBody,"Gfc2BrepBody",0)

OBJECTBUF_IMP_OBJECT(Gfc2BrepBodyFieldCacheInitializer,"Gfc2BrepBody",0)

Gfc2BrepBody::Gfc2BrepBody()
{
}

bool Gfc2BrepBody::isInitialized() const
{

    return true;
}

int Gfc2BrepBody::typeId() const
{
    return 16;
}

glodon::objectbuf::EntitySchema* Gfc2BrepBody::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(16))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Body::createSchema());
    pSchema->setName("Gfc2BrepBody");
    pSchema->setId(16);
    m_pDocument->addSchema(pSchema, 16);

    pSchema->addAttribNames("Faces");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Edges");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2BrepBody::entityName() const
{
    return "Gfc2BrepBody";
}

void Gfc2BrepBodyFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2BrepBody_Faces = getFieldId(oFieldIdMap, "Gfc2BrepBody::Faces");
    _FieldCache->_Gfc2BrepBody_Edges = getFieldId(oFieldIdMap, "Gfc2BrepBody::Edges");
}

