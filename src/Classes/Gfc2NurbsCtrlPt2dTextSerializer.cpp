#include "StdAfx.h"
#include "Gfc2NurbsCtrlPt2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2NurbsCtrlPt2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCtrlPt2dTextSerializer,"Gfc2NurbsCtrlPt2dT",0)

std::string Gfc2NurbsCtrlPt2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2NurbsCtrlPt2d* pEnt = (Gfc2NurbsCtrlPt2d*)pEntity;
    std::string sResult = glodon::objectbuf::EntityTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasPoint())
        stream<<",#"<<pEnt->getPoint();
    else
        stream<<",$";

    if (pEnt->hasWeight())
        stream<<","<<pEnt->getWeight();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2NurbsCtrlPt2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2NurbsCtrlPt2d* pEnt = (Gfc2NurbsCtrlPt2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setPoint(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setWeight(value);
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

