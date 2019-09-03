#include "StdAfx.h"
#include "Gfc2SinCurve2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2SinCurve2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2SinCurve2dTextSerializer,"Gfc2SinCurve2dT",0)

std::string Gfc2SinCurve2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SinCurve2d* pEnt = (Gfc2SinCurve2d*)pEntity;
    std::string sResult = Gfc2Curve2dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasPos())
        stream<<",#"<<pEnt->getPos();
    else
        stream<<",$";

    if (pEnt->hasDirX())
        stream<<",#"<<pEnt->getDirX();
    else
        stream<<",$";

    if (pEnt->hasA())
        stream<<","<<pEnt->getA();
    else
        stream<<",$";

    if (pEnt->hasB())
        stream<<","<<pEnt->getB();
    else
        stream<<",$";

    if (pEnt->hasRange())
        stream<<",#"<<pEnt->getRange();
    else
        stream<<",$";

    if (pEnt->hasClockSign())
        stream<<","<<pEnt->getClockSign();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2SinCurve2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SinCurve2d* pEnt = (Gfc2SinCurve2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve2dTextSerializer::parseField(input, nFieldNum, pEnt);
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
            pEnt->setPos(value);
        }
        break;
    case 1:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setDirX(value);
        }
        break;
    case 2:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setA(value);
        }
        break;
    case 3:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setB(value);
        }
        break;
    case 4:
        {
            glodon::objectbuf::EntityRef value;
            DO_((readEntityField(input, value)));
            pEnt->setRange(value);
        }
        break;
    case 5:
        {
            Gfc2Integer value;
            DO_((readIntField(input, value)));
            pEnt->setClockSign(value);
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

