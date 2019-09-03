#include "StdAfx.h"
#include "Gfc2Ellipse3d.h"
#include "Gfc2Ellipse3dBinarySerializer.h"
#include "Gfc2Ellipse3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Ellipse3d,"Gfc2Ellipse3d",0)

int Gfc2Ellipse3d::typeId() const
{
    return 38;
}

glodon::objectbuf::EntitySchema* Gfc2Ellipse3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(38))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2PlaneCurve3d::createSchema());
    pSchema->setName("Gfc2Ellipse3d");
    pSchema->setId(38);
    m_pDocument->addSchema(pSchema, 38);

    return pSchema;
}

std::string Gfc2Ellipse3d::entityName() const
{
    return "Gfc2Ellipse3d";
}

