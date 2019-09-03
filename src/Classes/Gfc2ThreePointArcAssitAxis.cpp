#include "StdAfx.h"
#include "Gfc2ThreePointArcAssitAxis.h"
#include "Gfc2ThreePointArcAssitAxisBinarySerializer.h"
#include "Gfc2ThreePointArcAssitAxisTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2ThreePointArcAssitAxis,"Gfc2ThreePointArcAssitAxis",0)

OBJECTBUF_IMP_OBJECT(Gfc2ThreePointArcAssitAxisFieldCacheInitializer,"Gfc2ThreePointArcAssitAxis",0)

Gfc2ThreePointArcAssitAxis::Gfc2ThreePointArcAssitAxis()
{
    m_nRefPoint1 = 0;
    m_nRefPoint2 = 0;
    m_nRefPoint3 = 0;
}

bool Gfc2ThreePointArcAssitAxis::isInitialized() const
{
    if ((_has_bits_[0] & 0x765) != 0x765) return false;

    return true;
}

int Gfc2ThreePointArcAssitAxis::typeId() const
{
    return 132;
}

glodon::objectbuf::EntitySchema* Gfc2ThreePointArcAssitAxis::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(132))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2AssitAxis::createSchema());
    pSchema->setName("Gfc2ThreePointArcAssitAxis");
    pSchema->setId(132);
    m_pDocument->addSchema(pSchema, 132);

    pSchema->addAttribNames("RefPoint1");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("RefPoint2");
    pSchema->addAttribIds(10);

    pSchema->addAttribNames("RefPoint3");
    pSchema->addAttribIds(11);

    return pSchema;
}

std::string Gfc2ThreePointArcAssitAxis::entityName() const
{
    return "Gfc2ThreePointArcAssitAxis";
}

void Gfc2ThreePointArcAssitAxisFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2ThreePointArcAssitAxis_RefPoint1 = getFieldId(oFieldIdMap, "Gfc2ThreePointArcAssitAxis::RefPoint1");
    _FieldCache->_Gfc2ThreePointArcAssitAxis_RefPoint2 = getFieldId(oFieldIdMap, "Gfc2ThreePointArcAssitAxis::RefPoint2");
    _FieldCache->_Gfc2ThreePointArcAssitAxis_RefPoint3 = getFieldId(oFieldIdMap, "Gfc2ThreePointArcAssitAxis::RefPoint3");
}

