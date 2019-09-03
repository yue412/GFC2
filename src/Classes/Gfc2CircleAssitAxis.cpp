#include "StdAfx.h"
#include "Gfc2CircleAssitAxis.h"
#include "Gfc2CircleAssitAxisBinarySerializer.h"
#include "Gfc2CircleAssitAxisTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2CircleAssitAxis,"Gfc2CircleAssitAxis",0)

OBJECTBUF_IMP_OBJECT(Gfc2CircleAssitAxisFieldCacheInitializer,"Gfc2CircleAssitAxis",0)

Gfc2CircleAssitAxis::Gfc2CircleAssitAxis()
{
    m_nCenter = 0;
    m_dRadius = 0.0;
}

bool Gfc2CircleAssitAxis::isInitialized() const
{
    if ((_has_bits_[0] & 0x365) != 0x365) return false;

    return true;
}

int Gfc2CircleAssitAxis::typeId() const
{
    return 20;
}

glodon::objectbuf::EntitySchema* Gfc2CircleAssitAxis::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(20))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2AssitAxis::createSchema());
    pSchema->setName("Gfc2CircleAssitAxis");
    pSchema->setId(20);
    m_pDocument->addSchema(pSchema, 20);

    pSchema->addAttribNames("Center");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("Radius");
    pSchema->addAttribIds(10);

    return pSchema;
}

std::string Gfc2CircleAssitAxis::entityName() const
{
    return "Gfc2CircleAssitAxis";
}

void Gfc2CircleAssitAxisFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2CircleAssitAxis_Center = getFieldId(oFieldIdMap, "Gfc2CircleAssitAxis::Center");
    _FieldCache->_Gfc2CircleAssitAxis_Radius = getFieldId(oFieldIdMap, "Gfc2CircleAssitAxis::Radius");
}

