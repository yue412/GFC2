#include "StdAfx.h"
#include "Gfc2OffsetCurve2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2OffsetCurve2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2OffsetCurve2dTextSerializer,"Gfc2OffsetCurve2dT",0)

std::string Gfc2OffsetCurve2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2OffsetCurve2d* pEnt = (Gfc2OffsetCurve2d*)pEntity;
    std::string sResult = Gfc2Curve2dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasOffDist())
        stream<<","<<pEnt->getOffDist();
    else
        stream<<",$";

    if (pEnt->hasInitCurve())
        stream<<",#"<<pEnt->getInitCurve();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2OffsetCurve2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2OffsetCurve2d* pEnt = (Gfc2OffsetCurve2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve2dTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 0:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setOffDist(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setInitCurve(value);
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

