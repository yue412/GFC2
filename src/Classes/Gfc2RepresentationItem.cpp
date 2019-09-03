#include "StdAfx.h"
#include "Gfc2RepresentationItem.h"
#include "Gfc2RepresentationItemBinarySerializer.h"
#include "Gfc2RepresentationItemTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2RepresentationItem,"Gfc2RepresentationItem",0)

OBJECTBUF_IMP_OBJECT(Gfc2RepresentationItemFieldCacheInitializer,"Gfc2RepresentationItem",0)

Gfc2RepresentationItem::Gfc2RepresentationItem()
{
    m_nPrimitiveType = (Gfc2PrimitiveType)0;
    m_nGeometryDataType = (Gfc2GeometryDataType)0;
    m_nStateSet = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2RepresentationItem::isInitialized() const
{
    if ((_has_bits_[0] & 0x23) != 0x23) return false;

    return true;
}

int Gfc2RepresentationItem::typeId() const
{
    return 106;
}

glodon::objectbuf::EntitySchema* Gfc2RepresentationItem::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(106))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2RepresentationItem");
    pSchema->setId(106);
    m_pDocument->addSchema(pSchema, 106);

    pSchema->addAttribNames("PrimitiveType");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("GeometryDataType");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Vertexes");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Normals");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Indexes");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("StateSet");
    pSchema->addAttribIds(6);

    return pSchema;
}

std::string Gfc2RepresentationItem::entityName() const
{
    return "Gfc2RepresentationItem";
}

void Gfc2RepresentationItemFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2RepresentationItem_PrimitiveType = getFieldId(oFieldIdMap, "Gfc2RepresentationItem::PrimitiveType");
    _FieldCache->_Gfc2RepresentationItem_GeometryDataType = getFieldId(oFieldIdMap, "Gfc2RepresentationItem::GeometryDataType");
    _FieldCache->_Gfc2RepresentationItem_Vertexes = getFieldId(oFieldIdMap, "Gfc2RepresentationItem::Vertexes");
    _FieldCache->_Gfc2RepresentationItem_Normals = getFieldId(oFieldIdMap, "Gfc2RepresentationItem::Normals");
    _FieldCache->_Gfc2RepresentationItem_Indexes = getFieldId(oFieldIdMap, "Gfc2RepresentationItem::Indexes");
    _FieldCache->_Gfc2RepresentationItem_StateSet = getFieldId(oFieldIdMap, "Gfc2RepresentationItem::StateSet");
}

