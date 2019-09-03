#include "StdAfx.h"
#include "Gfc2PolyhedralEdge.h"
#include "Gfc2PolyhedralEdgeBinarySerializer.h"
#include "Gfc2PolyhedralEdgeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedralEdge,"Gfc2PolyhedralEdge",0)

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedralEdgeFieldCacheInitializer,"Gfc2PolyhedralEdge",0)

Gfc2PolyhedralEdge::Gfc2PolyhedralEdge()
{
    m_nStartVertexIndex = 0;
    m_nEndVertexIndex = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2PolyhedralEdge::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2PolyhedralEdge::typeId() const
{
    return 88;
}

glodon::objectbuf::EntitySchema* Gfc2PolyhedralEdge::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(88))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2PolyhedralEdge");
    pSchema->setId(88);
    m_pDocument->addSchema(pSchema, 88);

    pSchema->addAttribNames("StartVertexIndex");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("EndVertexIndex");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2PolyhedralEdge::entityName() const
{
    return "Gfc2PolyhedralEdge";
}

void Gfc2PolyhedralEdgeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PolyhedralEdge_StartVertexIndex = getFieldId(oFieldIdMap, "Gfc2PolyhedralEdge::StartVertexIndex");
    _FieldCache->_Gfc2PolyhedralEdge_EndVertexIndex = getFieldId(oFieldIdMap, "Gfc2PolyhedralEdge::EndVertexIndex");
}

