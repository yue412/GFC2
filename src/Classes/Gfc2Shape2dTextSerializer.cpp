#include "StdAfx.h"
#include "Gfc2Shape2dTextSerializer.h"
#include "FieldCache.h"
#include "Gfc2Shape2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Shape2dTextSerializer,"Gfc2Shape2dT",0)

std::string Gfc2Shape2dTextSerializer::serialize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Shape2d* pEnt = (Gfc2Shape2d*)pEntity;
    std::string sResult = Gfc2ParametricShapeTextSerializer::serialize(pEnt);

    std::stringstream stream;
    stream.precision(numeric_limits<double>::digits10);
    if (pEnt->hasElev())
        stream<<","<<pEnt->getElev();
    else
        stream<<",$";

    sResult += stream.str();
    if(sResult[0] == ',')
        sResult = sResult.substr(1,sResult.length() - 1);
    return sResult;
}

glodon::objectbuf::EnParseFieldState Gfc2Shape2dTextSerializer::parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Shape2d* pEnt = (Gfc2Shape2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2ParametricShapeTextSerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    switch(nFieldNum)
    {
    case 2:
        {
            Gfc2Double value;
            DO_((readFloatField(input, value)));
            pEnt->setElev(value);
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

