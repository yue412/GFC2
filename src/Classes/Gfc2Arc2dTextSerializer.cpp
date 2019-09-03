#include "StdAfx.h"
#include "Gfc2Arc2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Arc2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Arc2dTextSerializer,"Gfc2Arc2dT",0)

std::string Gfc2Arc2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Arc2d* pEnt = (Gfc2Arc2d*)pEntity;
    std::string sResult = Gfc2Curve2dTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasCenterPt())
        stream<<",#"<<pEnt->getCenterPt();
    else
        stream<<",$";

    if (pEnt->hasRadius())
        stream<<","<<pEnt->getRadius();
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

glodon::objectbuf::EnParseFieldState Gfc2Arc2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Arc2d* pEnt = (Gfc2Arc2d*)pEntity;
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
            pEnt->setCenterPt(value);
        }
        break;
    case 1:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setRadius(value);
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

