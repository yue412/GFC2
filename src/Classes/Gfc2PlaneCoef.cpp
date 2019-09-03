#include "StdAfx.h"
#include "Gfc2PlaneCoef.h"
#include "Gfc2PlaneCoefBinarySerializer.h"
#include "Gfc2PlaneCoefTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PlaneCoef,"Gfc2PlaneCoef",0)

OBJECTBUF_IMP_OBJECT(Gfc2PlaneCoefFieldCacheInitializer,"Gfc2PlaneCoef",0)

Gfc2PlaneCoef::Gfc2PlaneCoef()
{
    m_dA = 0.0;
    m_dB = 0.0;
    m_dC = 0.0;
    m_dD = 0.0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2PlaneCoef::isInitialized() const
{
    if ((_has_bits_[0] & 0xf) != 0xf) return false;

    return true;
}

int Gfc2PlaneCoef::typeId() const
{
    return 79;
}

glodon::objectbuf::EntitySchema* Gfc2PlaneCoef::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(79))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2PlaneCoef");
    pSchema->setId(79);
    m_pDocument->addSchema(pSchema, 79);

    pSchema->addAttribNames("A");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("B");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("C");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("D");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2PlaneCoef::entityName() const
{
    return "Gfc2PlaneCoef";
}

void Gfc2PlaneCoefFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PlaneCoef_A = getFieldId(oFieldIdMap, "Gfc2PlaneCoef::A");
    _FieldCache->_Gfc2PlaneCoef_B = getFieldId(oFieldIdMap, "Gfc2PlaneCoef::B");
    _FieldCache->_Gfc2PlaneCoef_C = getFieldId(oFieldIdMap, "Gfc2PlaneCoef::C");
    _FieldCache->_Gfc2PlaneCoef_D = getFieldId(oFieldIdMap, "Gfc2PlaneCoef::D");
}

