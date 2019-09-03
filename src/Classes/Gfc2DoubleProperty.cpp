#include "StdAfx.h"
#include "Gfc2DoubleProperty.h"
#include "Gfc2DoublePropertyBinarySerializer.h"
#include "Gfc2DoublePropertyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2DoubleProperty,"Gfc2DoubleProperty",0)

OBJECTBUF_IMP_OBJECT(Gfc2DoublePropertyFieldCacheInitializer,"Gfc2DoubleProperty",0)

Gfc2DoubleProperty::Gfc2DoubleProperty()
{
    m_dValue = 0.0;
}

bool Gfc2DoubleProperty::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2DoubleProperty::typeId() const
{
    return 34;
}

glodon::objectbuf::EntitySchema* Gfc2DoubleProperty::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(34))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Property::createSchema());
    pSchema->setName("Gfc2DoubleProperty");
    pSchema->setId(34);
    m_pDocument->addSchema(pSchema, 34);

    pSchema->addAttribNames("Value");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2DoubleProperty::entityName() const
{
    return "Gfc2DoubleProperty";
}

void Gfc2DoublePropertyFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2DoubleProperty_Value = getFieldId(oFieldIdMap, "Gfc2DoubleProperty::Value");
}

