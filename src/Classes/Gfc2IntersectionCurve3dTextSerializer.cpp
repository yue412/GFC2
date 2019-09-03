#include "StdAfx.h"
#include "Gfc2IntersectionCurve3dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2IntersectionCurve3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2IntersectionCurve3dTextSerializer,"Gfc2IntersectionCurve3dT",0)

std::string Gfc2IntersectionCurve3dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2IntersectionCurve3d* pEnt = (Gfc2IntersectionCurve3d*)pEntity;
    std::string sResult = Gfc2Curve3dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasBases1())
        stream<<",#"<<pEnt->getBases1();
    else
        stream<<",$";

    if (pEnt->hasBases2())
        stream<<",#"<<pEnt->getBases2();
    else
        stream<<",$";

    if (pEnt->hasRange())
        stream<<",#"<<pEnt->getRange();
    else
        stream<<",$";

    if (pEnt->hasChart())
        stream<<",#"<<pEnt->getChart();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2IntersectionCurve3dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2IntersectionCurve3d* pEnt = (Gfc2IntersectionCurve3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve3dTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setBases1(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setBases2(value);
        }
        break;
    case 2:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRange(value);
        }
        break;
    case 3:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setChart(value);
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

