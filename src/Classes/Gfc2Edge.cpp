#include "StdAfx.h"
#include "Gfc2Edge.h"
#include "Gfc2EdgeBinarySerializer.h"
#include "Gfc2EdgeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Edge,"Gfc2Edge",0)

OBJECTBUF_IMP_OBJECT(Gfc2EdgeFieldCacheInitializer,"Gfc2Edge",0)

Gfc2Edge::Gfc2Edge()
{
    m_nCurve = 0;
    m_nFaceIndex1 = 0;
    m_nFaceIndex2 = 0;
    m_nLoopIndex1 = 0;
    m_nLoopIndex2 = 0;
    m_nCoedgeIndex1 = 0;
    m_nCoedgeIndex2 = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2Edge::isInitialized() const
{
    if ((_has_bits_[0] & 0x7f) != 0x7f) return false;

    return true;
}

int Gfc2Edge::typeId() const
{
    return 35;
}

glodon::objectbuf::EntitySchema* Gfc2Edge::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(35))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2Edge");
    pSchema->setId(35);
    m_pDocument->addSchema(pSchema, 35);

    pSchema->addAttribNames("Curve");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("FaceIndex1");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("FaceIndex2");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("LoopIndex1");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("LoopIndex2");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("CoedgeIndex1");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("CoedgeIndex2");
    pSchema->addAttribIds(7);

    return pSchema;
}

std::string Gfc2Edge::entityName() const
{
    return "Gfc2Edge";
}

void Gfc2EdgeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Edge_Curve = getFieldId(oFieldIdMap, "Gfc2Edge::Curve");
    _FieldCache->_Gfc2Edge_FaceIndex1 = getFieldId(oFieldIdMap, "Gfc2Edge::FaceIndex1");
    _FieldCache->_Gfc2Edge_FaceIndex2 = getFieldId(oFieldIdMap, "Gfc2Edge::FaceIndex2");
    _FieldCache->_Gfc2Edge_LoopIndex1 = getFieldId(oFieldIdMap, "Gfc2Edge::LoopIndex1");
    _FieldCache->_Gfc2Edge_LoopIndex2 = getFieldId(oFieldIdMap, "Gfc2Edge::LoopIndex2");
    _FieldCache->_Gfc2Edge_CoedgeIndex1 = getFieldId(oFieldIdMap, "Gfc2Edge::CoedgeIndex1");
    _FieldCache->_Gfc2Edge_CoedgeIndex2 = getFieldId(oFieldIdMap, "Gfc2Edge::CoedgeIndex2");
}

