#include "StdAfx.h"
#include "Gfc2Coedge.h"
#include "Gfc2CoedgeBinarySerializer.h"
#include "Gfc2CoedgeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Coedge,"Gfc2Coedge",0)

OBJECTBUF_IMP_OBJECT(Gfc2CoedgeFieldCacheInitializer,"Gfc2Coedge",0)

Gfc2Coedge::Gfc2Coedge()
{
    m_nCurve = 0;
    m_nEdgeIndex = 0;
    m_bEdgeSameDir = false;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2Coedge::isInitialized() const
{
    if ((_has_bits_[0] & 0x7) != 0x7) return false;

    return true;
}

int Gfc2Coedge::typeId() const
{
    return 21;
}

glodon::objectbuf::EntitySchema* Gfc2Coedge::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(21))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2Coedge");
    pSchema->setId(21);
    m_pDocument->addSchema(pSchema, 21);

    pSchema->addAttribNames("Curve");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("EdgeIndex");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("EdgeSameDir");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2Coedge::entityName() const
{
    return "Gfc2Coedge";
}

void Gfc2CoedgeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Coedge_Curve = getFieldId(oFieldIdMap, "Gfc2Coedge::Curve");
    _FieldCache->_Gfc2Coedge_EdgeIndex = getFieldId(oFieldIdMap, "Gfc2Coedge::EdgeIndex");
    _FieldCache->_Gfc2Coedge_EdgeSameDir = getFieldId(oFieldIdMap, "Gfc2Coedge::EdgeSameDir");
}

