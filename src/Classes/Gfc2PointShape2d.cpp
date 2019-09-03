#include "StdAfx.h"
#include "Gfc2PointShape2d.h"
#include "Gfc2PointShape2dBinarySerializer.h"
#include "Gfc2PointShape2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PointShape2d,"Gfc2PointShape2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2PointShape2dFieldCacheInitializer,"Gfc2PointShape2d",0)

Gfc2PointShape2d::Gfc2PointShape2d()
{
    m_nInsertPt = 0;
    m_dAngle = 0.0;
    m_bMirrorFlag = false;
}

bool Gfc2PointShape2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3d) != 0x3d) return false;

    return true;
}

int Gfc2PointShape2d::typeId() const
{
    return 84;
}

glodon::objectbuf::EntitySchema* Gfc2PointShape2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(84))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Shape2d::createSchema());
    pSchema->setName("Gfc2PointShape2d");
    pSchema->setId(84);
    m_pDocument->addSchema(pSchema, 84);

    pSchema->addAttribNames("InsertPt");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Angle");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("MirrorFlag");
    pSchema->addAttribIds(6);

    return pSchema;
}

std::string Gfc2PointShape2d::entityName() const
{
    return "Gfc2PointShape2d";
}

void Gfc2PointShape2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PointShape2d_InsertPt = getFieldId(oFieldIdMap, "Gfc2PointShape2d::InsertPt");
    _FieldCache->_Gfc2PointShape2d_Angle = getFieldId(oFieldIdMap, "Gfc2PointShape2d::Angle");
    _FieldCache->_Gfc2PointShape2d_MirrorFlag = getFieldId(oFieldIdMap, "Gfc2PointShape2d::MirrorFlag");
}

