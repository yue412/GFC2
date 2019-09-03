#include "StdAfx.h"
#include "Gfc2PolyhedronBody.h"
#include "Gfc2PolyhedronBodyBinarySerializer.h"
#include "Gfc2PolyhedronBodyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedronBody,"Gfc2PolyhedronBody",0)

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedronBodyFieldCacheInitializer,"Gfc2PolyhedronBody",0)

Gfc2PolyhedronBody::Gfc2PolyhedronBody()
{
}

bool Gfc2PolyhedronBody::isInitialized() const
{

    return true;
}

int Gfc2PolyhedronBody::typeId() const
{
    return 91;
}

glodon::objectbuf::EntitySchema* Gfc2PolyhedronBody::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(91))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Body::createSchema());
    pSchema->setName("Gfc2PolyhedronBody");
    pSchema->setId(91);
    m_pDocument->addSchema(pSchema, 91);

    pSchema->addAttribNames("Faces");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Vertexes");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2PolyhedronBody::entityName() const
{
    return "Gfc2PolyhedronBody";
}

void Gfc2PolyhedronBodyFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PolyhedronBody_Faces = getFieldId(oFieldIdMap, "Gfc2PolyhedronBody::Faces");
    _FieldCache->_Gfc2PolyhedronBody_Vertexes = getFieldId(oFieldIdMap, "Gfc2PolyhedronBody::Vertexes");
}

