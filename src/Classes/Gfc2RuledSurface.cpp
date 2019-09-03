#include "StdAfx.h"
#include "Gfc2RuledSurface.h"
#include "Gfc2RuledSurfaceBinarySerializer.h"
#include "Gfc2RuledSurfaceTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2RuledSurface,"Gfc2RuledSurface",0)

OBJECTBUF_IMP_OBJECT(Gfc2RuledSurfaceFieldCacheInitializer,"Gfc2RuledSurface",0)

Gfc2RuledSurface::Gfc2RuledSurface()
{
    m_nApexIndex = 0;
    m_nRangeV = 0;
    m_nRangeU = 0;
    m_nDirectrix1 = 0;
    m_nDirectrix2 = 0;
}

bool Gfc2RuledSurface::isInitialized() const
{
    if ((_has_bits_[0] & 0x1f) != 0x1f) return false;

    return true;
}

int Gfc2RuledSurface::typeId() const
{
    return 108;
}

glodon::objectbuf::EntitySchema* Gfc2RuledSurface::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(108))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Surface::createSchema());
    pSchema->setName("Gfc2RuledSurface");
    pSchema->setId(108);
    m_pDocument->addSchema(pSchema, 108);

    pSchema->addAttribNames("ApexIndex");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("RangeV");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("RangeU");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Directrix1");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Directrix2");
    pSchema->addAttribIds(5);

    return pSchema;
}

std::string Gfc2RuledSurface::entityName() const
{
    return "Gfc2RuledSurface";
}

void Gfc2RuledSurfaceFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2RuledSurface_ApexIndex = getFieldId(oFieldIdMap, "Gfc2RuledSurface::ApexIndex");
    _FieldCache->_Gfc2RuledSurface_RangeV = getFieldId(oFieldIdMap, "Gfc2RuledSurface::RangeV");
    _FieldCache->_Gfc2RuledSurface_RangeU = getFieldId(oFieldIdMap, "Gfc2RuledSurface::RangeU");
    _FieldCache->_Gfc2RuledSurface_Directrix1 = getFieldId(oFieldIdMap, "Gfc2RuledSurface::Directrix1");
    _FieldCache->_Gfc2RuledSurface_Directrix2 = getFieldId(oFieldIdMap, "Gfc2RuledSurface::Directrix2");
}

