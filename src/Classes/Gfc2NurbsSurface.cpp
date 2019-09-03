#include "StdAfx.h"
#include "Gfc2NurbsSurface.h"
#include "Gfc2NurbsSurfaceBinarySerializer.h"
#include "Gfc2NurbsSurfaceTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2NurbsSurface,"Gfc2NurbsSurface",0)

OBJECTBUF_IMP_OBJECT(Gfc2NurbsSurfaceFieldCacheInitializer,"Gfc2NurbsSurface",0)

Gfc2NurbsSurface::Gfc2NurbsSurface()
{
    m_nDegreeU = 0;
    m_nDegreeV = 0;
    m_nCtrlPtCountU = 0;
    m_nCtrlPtCountV = 0;
}

bool Gfc2NurbsSurface::isInitialized() const
{
    if ((_has_bits_[0] & 0xf) != 0xf) return false;

    return true;
}

int Gfc2NurbsSurface::typeId() const
{
    return 72;
}

glodon::objectbuf::EntitySchema* Gfc2NurbsSurface::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(72))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Surface::createSchema());
    pSchema->setName("Gfc2NurbsSurface");
    pSchema->setId(72);
    m_pDocument->addSchema(pSchema, 72);

    pSchema->addAttribNames("DegreeU");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("DegreeV");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("CtrlPtCountU");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("CtrlPtCountV");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("CtrlPts");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("KnotsU");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("KnotsV");
    pSchema->addAttribIds(7);

    return pSchema;
}

std::string Gfc2NurbsSurface::entityName() const
{
    return "Gfc2NurbsSurface";
}

void Gfc2NurbsSurfaceFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2NurbsSurface_DegreeU = getFieldId(oFieldIdMap, "Gfc2NurbsSurface::DegreeU");
    _FieldCache->_Gfc2NurbsSurface_DegreeV = getFieldId(oFieldIdMap, "Gfc2NurbsSurface::DegreeV");
    _FieldCache->_Gfc2NurbsSurface_CtrlPtCountU = getFieldId(oFieldIdMap, "Gfc2NurbsSurface::CtrlPtCountU");
    _FieldCache->_Gfc2NurbsSurface_CtrlPtCountV = getFieldId(oFieldIdMap, "Gfc2NurbsSurface::CtrlPtCountV");
    _FieldCache->_Gfc2NurbsSurface_CtrlPts = getFieldId(oFieldIdMap, "Gfc2NurbsSurface::CtrlPts");
    _FieldCache->_Gfc2NurbsSurface_KnotsU = getFieldId(oFieldIdMap, "Gfc2NurbsSurface::KnotsU");
    _FieldCache->_Gfc2NurbsSurface_KnotsV = getFieldId(oFieldIdMap, "Gfc2NurbsSurface::KnotsV");
}

