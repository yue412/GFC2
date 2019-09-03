#include "StdAfx.h"
#include "Gfc2PointShapeTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2PointShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2PointShapeTextSerializer,"Gfc2PointShapeT",0)

std::string Gfc2PointShapeTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PointShape* pEnt = (Gfc2PointShape*)pEntity;
    std::string sResult = Gfc2SectionPointShapeTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasHeight())
        stream<<","<<pEnt->getHeight();
    else
        stream<<",$";

    if (pEnt->hasObliqueDir())
        stream<<",#"<<pEnt->getObliqueDir();
    else
        stream<<",$";

    if (pEnt->hasTopPoly())
        stream<<",#"<<pEnt->getTopPoly();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2PointShapeTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PointShape* pEnt = (Gfc2PointShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SectionPointShapeTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 9:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setHeight(value);
        }
        break;
    case 10:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setObliqueDir(value);
        }
        break;
    case 11:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setTopPoly(value);
        }
        break;
    default:
        return glodon::objectbuf::PFS_IGNORE;
    }
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

