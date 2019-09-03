#include "StdAfx.h"
#include "Gfc2Bevel.h"
#include "Gfc2BevelBinarySerializer.h"
#include "Gfc2BevelTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Bevel,"Gfc2Bevel",0)

OBJECTBUF_IMP_OBJECT(Gfc2BevelFieldCacheInitializer,"Gfc2Bevel",0)

Gfc2Bevel::Gfc2Bevel()
{
    m_nCoord = 0;
    m_dHeight = 0.0;
    m_nRangeV = 0;
    m_nCurve = 0;
}

bool Gfc2Bevel::isInitialized() const
{
    if ((_has_bits_[0] & 0xf) != 0xf) return false;

    return true;
}

int Gfc2Bevel::typeId() const
{
    return 10;
}

glodon::objectbuf::EntitySchema* Gfc2Bevel::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(10))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Surface::createSchema());
    pSchema->setName("Gfc2Bevel");
    pSchema->setId(10);
    m_pDocument->addSchema(pSchema, 10);

    pSchema->addAttribNames("Coord");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Height");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("RangeV");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Curve");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2Bevel::entityName() const
{
    return "Gfc2Bevel";
}

void Gfc2BevelFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Bevel_Coord = getFieldId(oFieldIdMap, "Gfc2Bevel::Coord");
    _FieldCache->_Gfc2Bevel_Height = getFieldId(oFieldIdMap, "Gfc2Bevel::Height");
    _FieldCache->_Gfc2Bevel_RangeV = getFieldId(oFieldIdMap, "Gfc2Bevel::RangeV");
    _FieldCache->_Gfc2Bevel_Curve = getFieldId(oFieldIdMap, "Gfc2Bevel::Curve");
}

