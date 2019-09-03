#include "StdAfx.h"
#include "Gfc2SimpleVertex.h"
#include "Gfc2SimpleVertexBinarySerializer.h"
#include "Gfc2SimpleVertexTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SimpleVertex,"Gfc2SimpleVertex",0)

OBJECTBUF_IMP_OBJECT(Gfc2SimpleVertexFieldCacheInitializer,"Gfc2SimpleVertex",0)

Gfc2SimpleVertex::Gfc2SimpleVertex()
{
    m_nPoint = 0;
    m_dRadius = 0.0;
    m_nArcType = (Gfc2ArcType)0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2SimpleVertex::isInitialized() const
{
    if ((_has_bits_[0] & 0x1) != 0x1) return false;

    return true;
}

int Gfc2SimpleVertex::typeId() const
{
    return 116;
}

glodon::objectbuf::EntitySchema* Gfc2SimpleVertex::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(116))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2SimpleVertex");
    pSchema->setId(116);
    m_pDocument->addSchema(pSchema, 116);

    pSchema->addAttribNames("Point");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Radius");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("ArcType");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2SimpleVertex::entityName() const
{
    return "Gfc2SimpleVertex";
}

void Gfc2SimpleVertexFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SimpleVertex_Point = getFieldId(oFieldIdMap, "Gfc2SimpleVertex::Point");
    _FieldCache->_Gfc2SimpleVertex_Radius = getFieldId(oFieldIdMap, "Gfc2SimpleVertex::Radius");
    _FieldCache->_Gfc2SimpleVertex_ArcType = getFieldId(oFieldIdMap, "Gfc2SimpleVertex::ArcType");
}

