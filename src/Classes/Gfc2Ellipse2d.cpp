#include "StdAfx.h"
#include "Gfc2Ellipse2d.h"
#include "Gfc2Ellipse2dBinarySerializer.h"
#include "Gfc2Ellipse2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Ellipse2d,"Gfc2Ellipse2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2Ellipse2dFieldCacheInitializer,"Gfc2Ellipse2d",0)

Gfc2Ellipse2d::Gfc2Ellipse2d()
{
    m_nCenterPt = 0;
    m_nMajorAxis = 0;
    m_ddMajorRad = 0.0;
    m_ddMinorRad = 0.0;
    m_nRange = 0;
    m_nClockSign = 0;
}

bool Gfc2Ellipse2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3f) != 0x3f) return false;

    return true;
}

int Gfc2Ellipse2d::typeId() const
{
    return 37;
}

glodon::objectbuf::EntitySchema* Gfc2Ellipse2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(37))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve2d::createSchema());
    pSchema->setName("Gfc2Ellipse2d");
    pSchema->setId(37);
    m_pDocument->addSchema(pSchema, 37);

    pSchema->addAttribNames("CenterPt");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("MajorAxis");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("dMajorRad");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("dMinorRad");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Range");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("ClockSign");
    pSchema->addAttribIds(6);

    return pSchema;
}

std::string Gfc2Ellipse2d::entityName() const
{
    return "Gfc2Ellipse2d";
}

void Gfc2Ellipse2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Ellipse2d_CenterPt = getFieldId(oFieldIdMap, "Gfc2Ellipse2d::CenterPt");
    _FieldCache->_Gfc2Ellipse2d_MajorAxis = getFieldId(oFieldIdMap, "Gfc2Ellipse2d::MajorAxis");
    _FieldCache->_Gfc2Ellipse2d_dMajorRad = getFieldId(oFieldIdMap, "Gfc2Ellipse2d::dMajorRad");
    _FieldCache->_Gfc2Ellipse2d_dMinorRad = getFieldId(oFieldIdMap, "Gfc2Ellipse2d::dMinorRad");
    _FieldCache->_Gfc2Ellipse2d_Range = getFieldId(oFieldIdMap, "Gfc2Ellipse2d::Range");
    _FieldCache->_Gfc2Ellipse2d_ClockSign = getFieldId(oFieldIdMap, "Gfc2Ellipse2d::ClockSign");
}

